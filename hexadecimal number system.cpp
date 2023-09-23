#include <iostream>
#include <string>

std::string to_sixteen(uint32_t x) {
	if (x == 0) {
		return "0";
	}
	std::string ans, num;
	uint32_t t, i = 1 << 28;
	while (i > x) {
		i /= 16;
	}
	while (i >= 1) {
		if (i > x) {
			ans += '0';
		}
		else {
			t = x / i;
			if (t < 10) {
				num = std::to_string(t);
			}
			if (t == 10) {
				num = "A";
			}
			if (t == 11) {
				num = "B";
			}
			if (t == 12) {
				num = "C";
			}
			if (t == 13) {
				num = "D";
			}
			if (t == 14) {
				num = "E";
			}
			if (t == 15) {
				num = "F";
			}
			ans += num;
			x -= i * t;
		}
		i /= 16;
	}
	return ans;
}

void main() {
	uint32_t a;
	std::cin >> a;
	std::cout << to_sixteen(a);
}
