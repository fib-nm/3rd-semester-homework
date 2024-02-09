#pragma once
#include "enums.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

class FaceCube {
private:
	std::vector<Color> f; // f - вектор цветов facelet'ов кубика

public:
	FaceCube() {
		for (uint32_t i = 0; i < 9; ++i) {
			f.push_back(U);
		}
		for (uint32_t i = 0; i < 9; ++i) {
			f.push_back(R);
		}
		for (uint32_t i = 0; i < 9; ++i) {
			f.push_back(F);
		}
		for (uint32_t i = 0; i < 9; ++i) {
			f.push_back(D);
		}
		for (uint32_t i = 0; i < 9; ++i) {
			f.push_back(L);
		}
		for (uint32_t i = 0; i < 9; ++i) {
			f.push_back(B);
		}
	}

	FaceCube(std::string s) {
		if (s.length() < 54) {
			throw std::runtime_error("Cube definition string contains less than 54 elements");
		}
		if (s.length() > 54) {
			throw std::runtime_error("Cube definition string contains more than 54 elements");
		}
		std::vector<int32_t> cnt(6);
		for (int32_t i = 0; i < 54; ++i) {
			switch (s[i]) {
			case 'U':
				f.push_back(U);
				++cnt[U];
				break;
			case 'R':
				f.push_back(R);
				++cnt[R];
				break;
			case 'F':
				f.push_back(F);
				++cnt[F];
				break;
			case 'D':
				f.push_back(D);
				++cnt[D];
				break;
			case 'L':
				f.push_back(L);
				++cnt[L];
				break;
			case 'B':
				f.push_back(B);
				++cnt[B];
				break;
			default:
				throw std::runtime_error("Cube definition string contains characters other than 'U', 'R', 'F', 'D', 'L', 'B'");
			}
		}
		if (!(std::all_of(cnt.begin(), cnt.end(), [](int32_t i) {return i == 9; }))) {
			throw std::runtime_error("Cube definition string does not contain exactly 9 facelets of each color");
		}
	}

	// Записывает куб в виде строки
	std::string ToString() {
		std::string s;
		for (auto i : f) {
			switch (i) {
			case U:
				s.append(1, 'U');
				break;
			case R:
				s.append(1, 'R');
				break;
			case F:
				s.append(1, 'F');
				break;
			case D:
				s.append(1, 'D');
				break;
			case L:
				s.append(1, 'L');
				break;
			case B:
				s.append(1, 'B');
				break;
			}
		}
		return s;
	}

	// Развертка куба
	std::string To2dString() {
		std::string s = (*this).ToString();
		std::string r = "    " + s.substr(0, 3) + "\n    " + s.substr(3, 3) + "\n    " + s.substr(6, 3) + "\n";
		r += s.substr(36, 3) + " " + s.substr(18, 3) + " " + s.substr(9, 3) + " " + s.substr(45, 3) + "\n" +
			s.substr(39, 3) + " " + s.substr(21, 3) + " " + s.substr(12, 3) + " " + s.substr(48, 3) + "\n" +
			s.substr(42, 3) + " " + s.substr(24, 3) + " " + s.substr(15, 3) + " " + s.substr(51, 3) + "\n";
		r += "    " + s.substr(27, 3) + "\n    " + s.substr(30, 3) + "\n    " + s.substr(33, 3) + "\n";
		return r;
	}

	std::vector<Color>& get_f() {
		return f;
	}

	std::vector<Color> get_f() const {
		return f;
	}

	bool operator==(const FaceCube& rhs) const {
		return f == rhs.f;
	}
};

static std::ostream& operator<<(std::ostream& os, FaceCube fc) {
	os << fc.To2dString();
	return os;
}