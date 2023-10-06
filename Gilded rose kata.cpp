#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "catch.hpp"

class item {
public:
	std::string name;
	int32_t quality, sell_in;
	bool is_conjured;

	virtual void update_quality() {
		int32_t multiplier = 1;
		if (is_conjured) {
			multiplier = 2;
		}

		if (sell_in == 0) {
			quality -= 2*multiplier;
		}
		else {
			--sell_in;
			quality -= multiplier;
		}
		if (quality < 0) {
			quality = 0;
		}
	}

	virtual void print() {
		if (is_conjured) {
			std::cout << "name=" << name << " quality=" << quality << " sell_in=" << sell_in << " type=conjured_item" << "\n";
		}
		else {
			std::cout << "name=" << name << " quality=" << quality << " sell_in=" << sell_in << " type=not_conjured_item" << "\n";
		}
	}

	item(std::string name1, int32_t quality1, int32_t sell_in1, bool is_conjured1) {
		name = name1;
		is_conjured = is_conjured1;
		if (quality1 > 50) {
			quality = 50;
		}
		else if (quality1 < 0) {
			quality = 0;
		}
		else {
			quality = quality1;
		}
		if (sell_in1 < 0) {
			sell_in = 0;
		}
		else {
			sell_in = sell_in1;
		}
	}
};

class aged_brie :public item {
public:
	void update_quality() override {
		++quality;
		if (sell_in > 0) {
			--sell_in;
		}
		if (quality > 50) {
			quality = 50;
		}
	}

	void print() override {
		std::cout << "name=" << name << " quality=" << quality << " sell_in=" << sell_in << " type=aged_brie" << "\n";
	}

	aged_brie(std::string name1, int32_t quality1, int32_t sell_in1) : item(name1, quality1, sell_in1, 0) {}
};

class sulfuras :public item {
public:
	void update_quality() override {}

	void print() override {
		std::cout << "name=" << name << " quality=" << quality << " sell_in=inf" << " type=sulfuras" << "\n";
	}

	sulfuras(std::string name1) : item(name1, 0, 0, 0) {
		quality = 80;
		sell_in = -1;
	}
};

class backstage_pass :public item {
public:
	void update_quality() override {
		if (sell_in <= 10) {
			quality += 2;
		}
		if (sell_in <= 5) {
			++quality;
		}
		if (sell_in == 0) {
			quality = 0;
		}
		if (quality > 50) {
			quality = 50;
		}
		if (sell_in > 0) {
			--sell_in;
		}
	}

	void print() override {
		std::cout << "name=" << name << " quality=" << quality << " sell_in=" << sell_in << " type=backstage_passes" << "\n";
	}

	backstage_pass(std::string name1, int32_t quality1, int32_t sell_in1) : item(name1, quality1, sell_in1, 0) {}
};

class gilded_rose {
private:
	std::vector<item*> item_list;
public:
	void add_item(item* item1) {
		item_list.push_back(item1);
	}
	void print_item_list() {
		for (item* i: item_list) {
			(*i).print();
		}
		std::cout << "\n";
	}
	void update_quality() {
		for (item* i : item_list) {
			(*i).update_quality();
		}
	}
};

TEST_CASE("correct update_quality") {
	gilded_rose shop1;
	int a1_quality, a1_sell_in, a2_quality, a2_sell_in, b_quality, b_sell_in, d_quality, d_sell_in;

	std::cout << "1. enter conjured item's quality\n";
	std::cin >> a1_quality;
	std::cout << "1. enter conjured item's sell_in\n";
	std::cin >> a1_sell_in;
	item a1("pie", a1_quality, a1_quality, true);

	std::cout << "1. enter not conjured item's quality\n";
	std::cin >> a2_quality;
	std::cout << "1. enter not conjured item's sell_in\n";
	std::cin >> a2_sell_in;
	item a2("carrot", a2_quality, a2_sell_in, false);

	std::cout << "1. enter aged brie's quality\n";
	std::cin >> b_quality;
	std::cout << "1. enter aged brie's sell_in\n";
	std::cin >> b_sell_in;
	aged_brie b("blue cheese", b_quality, b_sell_in);

	sulfuras c("stick");

	std::cout << "1. enter backstage_pass's quality\n";
	std::cin >> d_quality;
	std::cout << "1. enter backstage_pass's sell_in\n";
	std::cin >> d_sell_in;
	backstage_pass d("passss", d_quality, d_sell_in);

	shop1.add_item(&a1);
	shop1.add_item(&a2);
	shop1.add_item(&b);
	shop1.add_item(&c);
	shop1.add_item(&d);

	a1_quality = a1.quality;
	a1_sell_in = a1.sell_in;
	a2_quality = a2.quality;
	a2_sell_in = a2.sell_in;
	b_quality = b.quality;
	b_sell_in = b.sell_in;
	int c_quality = c.quality;
	int c_sell_in = c.sell_in;
	d_quality = d.quality;
	d_sell_in = d.sell_in;

	shop1.update_quality();

	REQUIRE(a1.quality == std::max(0, a1_quality - 2));
	REQUIRE(a1.sell_in == std::max(0, a1_sell_in - 1));

	REQUIRE(a2.quality == std::max(0, a2_quality - 1));
	REQUIRE(a2.sell_in == std::max(0, a2_sell_in - 1));

	REQUIRE(b.quality == std::min(50, b_quality + 1));
	REQUIRE(b.sell_in == std::max(0, b_sell_in - 1));

	REQUIRE(c.quality == c_quality);
	REQUIRE(c.sell_in == c_sell_in);

	if (d_sell_in == 0) {
		REQUIRE(d.quality == 0);
	}
	else if (d_sell_in <= 5) {
		REQUIRE(d.quality == std::min(50, d_quality + 3));
	}
	else if (d_sell_in <= 10) {
		REQUIRE(d.quality == std::min(50, d_quality + 2));
	}
	else {
		REQUIRE(d.quality == d_quality);
	}
	REQUIRE(d.sell_in == std::max(0, d_sell_in - 1));
}

TEST_CASE("correct boundaries") {
	gilded_rose shop2;
	int quality, sell_in;

	std::cout << "2. enter conjured item's quality\n";
	std::cin >> quality;
	std::cout << "2. enter conjured item's sell_in\n";
	std::cin >> sell_in;
	item a1("pie", quality, sell_in, true);

	std::cout << "2. enter not conjured item's quality\n";
	std::cin >> quality;
	std::cout << "2. enter not conjured item's sell_in\n";
	std::cin >> sell_in;
	item a2("carrot", quality, sell_in, false);

	std::cout << "2. enter aged brie's quality\n";
	std::cin >> quality;
	std::cout << "2. enter aged brie's sell_in\n";
	std::cin >> sell_in;
	aged_brie b("blue cheese", quality, sell_in);

	sulfuras c("stick");

	std::cout << "2. enter backstage_pass's quality\n";
	std::cin >> quality;
	std::cout << "2. enter backstage_pass's sell_in\n";
	std::cin >> sell_in;
	backstage_pass d("passss", quality, sell_in);

	shop2.add_item(&a1);
	shop2.add_item(&a2);
	shop2.add_item(&b);
	shop2.add_item(&c);
	shop2.add_item(&d);

	REQUIRE((0 <= a1.quality <= 50));
	REQUIRE((0 <= a2.quality <= 50));
	REQUIRE((0 <= b.quality <= 50));
	REQUIRE(c.quality == 80);
	REQUIRE((0 <= d.quality <= 50));

	REQUIRE(0 <= a1.sell_in);
	REQUIRE(0 <= a2.sell_in);
	REQUIRE(0 <= b.sell_in);
	REQUIRE(c.sell_in == -1);
	REQUIRE(0 <= d.sell_in);

	for (uint32_t i = 0; i < 100; ++i) {
		shop2.update_quality();
	}

	REQUIRE((0 <= a1.quality <= 50));
	REQUIRE((0 <= a2.quality <= 50));
	REQUIRE((0 <= b.quality <= 50));
	REQUIRE(c.quality == 80);
	REQUIRE((0 <= d.quality <= 50));

	REQUIRE(0 <= a1.sell_in);
	REQUIRE(0 <= a2.sell_in);
	REQUIRE(0 <= b.sell_in);
	REQUIRE(c.sell_in == -1);
	REQUIRE(0 <= d.sell_in);
}
