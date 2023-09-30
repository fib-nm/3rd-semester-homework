#include <iostream>
#include <string>
#include <vector>

class item {
public:
	std::string name;
	int32_t quality, sell_in;
	bool is_conjured;

	virtual void aging() {
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
	void aging() override {
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
	void aging() override {}

	void print() override {
		std::cout << "name=" << name << " quality=" << quality << " sell_in=inf" << " type=sulfuras" << "\n";
	}

	sulfuras(std::string name1) : item(name1, 0, 0, 0) {
		quality = 80;
	}
};

class backstage_passes :public item {
public:
	void aging() override {
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

	backstage_passes(std::string name1, int32_t quality1, int32_t sell_in1) : item(name1, quality1, sell_in1, 0) {}
};

class gilded_rose {
private:
	std::vector<item> item_list = {};
	std::vector<aged_brie> aged_brie_list = {};
	std::vector<sulfuras> sulfuras_list = {};
	std::vector<backstage_passes> backstage_passes_list = {};
public:
	void add_item(item item1) {
		item_list.push_back(item1);
	}
	void add_aged_brie(aged_brie aged_brie1) {
		aged_brie_list.push_back(aged_brie1);
	}
	void add_sulfuras(sulfuras sulfuras1) {
		sulfuras_list.push_back(sulfuras1);
	}
	void add_backstage_passes(backstage_passes backstage_passes1) {
		backstage_passes_list.push_back(backstage_passes1);
	}
	void print_item_list() {
		std::cout << "\\/ \n";
		for (item i: item_list) {
			i.print();
		}
		std::cout << "/\\ \n";
	}
};

int main() {
	gilded_rose rose;
	item a("item_a", 22, 6, false), b("item_b", 22, 6, true);
	rose.add_item(a);
	rose.print_item_list();
	rose.add_item(b);
	rose.print_item_list();
	aged_brie c("aged_brie_c", 11, 5);
	sulfuras d("sulfuras_d");
	backstage_passes e("backstage_passes_e", 13, 11);
}