#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"

using u64 = uint64_t;

struct vector {
	u64* data;
	size_t size, real_size;

	void pushback(u64 x) {
		if (real_size >= size) {
			++real_size;
			size *= 2;
			u64* new_data = new u64[size];
			for (u64 i = 0; i < real_size - 1; ++i) {
				new_data[i] = data[i];
			}
			delete[] data;
			new_data[real_size - 1] = x;
			data = new_data;
		}
		else {
			++real_size;
			data[real_size - 1] = x;
		}
	}

	void popback() {
		--real_size;
	}
};

vector makevector() {
	vector v;
	v.size = 1;
	v.real_size = 0;
	v.data = new u64[1];
	return v;
}

void destroyvector(vector* v) {
	v->size = 1;
	v->real_size = 0;
	delete[] v->data;
}

void printvector(vector* v) {
	for (u64 i = 0; i < v->real_size; ++i) {
		std::cout << v->data[i] << " ";
	}
	std::cout << "\n";
}

void mergesort(vector* v) {
	if (v->real_size > 1) {
		vector L = makevector(), R = makevector();
		for (u64 i = 0; i <= (v->real_size - 1) / 2; ++i) {
			L.pushback(v->data[i]);
		}
		for (u64 i = (v->real_size - 1) / 2 + 1; i <= v->real_size - 1; ++i) {
			R.pushback(v->data[i]);
		}
		mergesort(&L);
		mergesort(&R);
		u64 n_L = 0, n_R = 0;
		vector C = makevector();
		while (n_L < L.real_size && n_R < R.real_size) {
			if (L.data[n_L] <= R.data[n_R]) {
				C.pushback(L.data[n_L]);
				++n_L;
			}
			else {
				C.pushback(R.data[n_R]);
				++n_R;
			}
		}
		while (n_L < L.real_size) {
			C.pushback(L.data[n_L]);
			++n_L;
		}
		while (n_R < R.real_size) {
			C.pushback(R.data[n_R]);
			++n_R;
		}
		for (u64 i = 0; i < C.real_size; ++i) {
			v->data[i] = C.data[i];
		}
		destroyvector(&L);
		destroyvector(&R);
		destroyvector(&C);
	}
}

TEST_CASE("01") {
	vector v = makevector();
	for (u64 i = 0; i < 100; ++i) {
		v.pushback(std::rand() % 100);
	}
	mergesort(&v);
	for (u64 i = 0; i < 99; ++i) {
		REQUIRE(v.data[i] <= v.data[i + 1]);
	}
}
