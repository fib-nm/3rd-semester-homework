#pragma once
#include "defs.hpp"
#include "enums.hpp"
#include "face.hpp"
#include <random>
#include <vector>
#include <stdexcept>

////////////////////////////// 6 базовых ходов представлены 6 кубами, полученными соответствующими поворотами собранного куба //////////////////////////////

// U1
// Чем заменен k-й угол
static const std::vector<Corner> cpU = { UBR, URF, UFL, ULB, DFR, DLF, DBL, DRB };
// Ориентация угла
// 0 - reference facelet угла совпадает с reference facelet'ом собранного куба, 1 - повернут по часовой стрелке, 2 - повернут против часовой стрелки
static const std::vector<int32_t> coU = { 0, 0, 0, 0, 0, 0, 0, 0 };
// Чем заменено k-е ребро
static const std::vector<Edge> epU = { UB, UR, UF, UL, DR, DF, DL, DB, FR, FL, BL, BR };
// Ориентация ребра
// 0 - reference facelet ребра совпадает с reference facelet'ом собранного куба, 1 - не совпадает
static const std::vector<int32_t> eoU = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// R1
static const std::vector<Corner> cpR = { DFR, UFL, ULB, URF, DRB, DLF, DBL, UBR };
static const std::vector<int32_t> coR = { 2, 0, 0, 1, 1, 0, 0, 2 };
static const std::vector<Edge> epR = { FR, UF, UL, UB, BR, DF, DL, DB, DR, FL, BL, UR };
static const std::vector<int32_t> eoR = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// F1
static const std::vector<Corner> cpF = { UFL, DLF, ULB, UBR, URF, DFR, DBL, DRB };
static const std::vector<int32_t> coF = { 1, 2, 0, 0, 2, 1, 0, 0 };
static const std::vector<Edge> epF = { UR, FL, UL, UB, DR, FR, DL, DB, UF, DF, BL, BR };
static const std::vector<int32_t> eoF = { 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0 };

// D1
static const std::vector<Corner> cpD = { URF, UFL, ULB, UBR, DLF, DBL, DRB, DFR };
static const std::vector<int32_t> coD = { 0, 0, 0, 0, 0, 0, 0, 0 };
static const std::vector<Edge> epD = { UR, UF, UL, UB, DF, DL, DB, DR, FR, FL, BL, BR };
static const std::vector<int32_t> eoD = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// L1
static const std::vector<Corner> cpL = { URF, ULB, DBL, UBR, DFR, UFL, DLF, DRB };
static const std::vector<int32_t> coL = { 0, 1, 2, 0, 0, 2, 1, 0 };
static const std::vector<Edge> epL = { UR, UF, BL, UB, DR, DF, FL, DB, FR, UL, DL, BR };
static const std::vector<int32_t> eoL = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// B1
static const std::vector<Corner> cpB = { URF, UFL, UBR, DRB, DFR, DLF, ULB, DBL };
static const std::vector<int32_t> coB = { 0, 0, 1, 2, 0, 0, 2, 1 };
static const std::vector<Edge> epB = { UR, UF, UL, BR, DR, DF, DL, BL, FR, FL, UB, DB };
static const std::vector<int32_t> eoB = { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1 };

static const bool CUBE_OK = true;

class CubieCube {
private:
	std::vector<Corner> cp;
	std::vector<int32_t> co;
	std::vector<Edge> ep;
	std::vector<int32_t> eo;

	void CornerMultiply(const CubieCube& b) {
		// Умножить углы этого куба на углы b.
		// (A*B)(x).c=A(B(x).c).c
		// (A*B)(x).o=A(B(x).c).o+B(x).o
		std::vector<Corner> c_perm(8, empty_corner);
		std::vector<int32_t> c_ori(8);
		for (int32_t c = 0; c < 8; ++c) {
			c_perm[c] = cp[b.cp[c]];
			int32_t ori_a = co[b.cp[c]];
			int32_t ori_b = b.co[c];
			c_ori[c] = (ori_a + ori_b) % 3;
		}
		for (int32_t c = 0; c < 8; ++c) {
			cp[c] = c_perm[c];
			co[c] = c_ori[c];
		}
	}

	void EdgeMultiply(const CubieCube& b) {
		// Умножить ребра этого куба на углы b.
		// (A*B)(x).e=A(B(x).e).e
		// (A*B)(x).o=A(B(x).c).o+B(x).o
		std::vector<Edge> e_perm(12, empty_edge);
		std::vector<int32_t> e_ori(12);
		for (int32_t e = 0; e < 12; ++e) {
			e_perm[e] = ep[b.ep[e]];
			e_ori[e] = (b.eo[e] + eo[b.ep[e]]) % 2;
		}
		for (int32_t e = 0; e < 12; ++e) {
			ep[e] = e_perm[e];
			eo[e] = e_ori[e];
		}
	}

public:
	CubieCube(std::vector<Corner> cpi = { URF, UFL, ULB, UBR, DFR, DLF, DBL, DRB },
		std::vector<int32_t> coi = { 0, 0, 0, 0, 0, 0, 0, 0 },
		std::vector<Edge> epi = { UR, UF, UL, UB, DR, DF, DL, DB, FR, FL, BL, BR },
		std::vector<int32_t> eoi = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }) : cp{ cpi }, co{ coi }, ep{ epi }, eo{ eoi } {}

	bool operator==(const CubieCube& rhs) const {
		return (*this).cp == rhs.cp && (*this).co == rhs.co && (*this).ep == rhs.ep && (*this).eo == rhs.eo;
	}

	FaceCube ToFaceletCube() const {
		FaceCube fc;
		for (int32_t i = 0; i < 8; ++i) {
			Corner j = cp[i];
			int32_t ori = co[i];
			for (int32_t k = 0; k < 3; ++k) { // элементы f FaceCube'а, отвечающие facelet'ам углов, приравниваются к цветам соответствующих углов CubieCube'а
				fc.get_f()[corner_facelet[i][(k + ori) % 3]] = corner_color[j][k];
			}
		}
		for (int32_t i = 0; i < 12; ++i) {
			Edge j = ep[i];
			int32_t ori = eo[i];
			for (int32_t k = 0; k < 2; ++k) { // элементы f FaceCube'а, отвечающие facelet'ам ребер, приравниваются к цветам соответствующих ребер CubieCube'а
				fc.get_f()[edge_facelet[i][(k + ori) % 2]] = edge_color[j][k];
			}
		}
		return fc;
	}

	void Multiply(const CubieCube& b) {
		CornerMultiply(b);
		EdgeMultiply(b);
	}

	uint32_t CornerParity() const {
		// Четность числа перестановок углов
		uint32_t s = 0;
		for (int32_t i = DRB; i != URF; --i) {
			for (int32_t j = i - 1; j != URF - 1; --j) {
				if (cp[j] > cp[i]) {
					++s;
				}
			}
		}
		return s % 2;
	}

	uint32_t EdgeParity() const {
		// Четность числа перестановок ребер. У решаемого куба EdgeParity и CornerParity одинаковые
		uint32_t s = 0;
		for (int32_t i = BR; i != UR; --i) {
			for (int32_t j = i - 1; j != UR - 1; --j) {
				if (ep[j] > ep[i]) {
					++s;
				}
			}
		}
		return s % 2;
	}

	bool Verify() const {
		// Проверка правильности куба
		std::vector<int32_t> edge_count(12);
		for (auto i : edge_list) {
			++edge_count[ep[i]];
		}
		for (auto i : edge_list) {
			if (edge_count[i] != 1) {
				throw std::runtime_error("Some edges are undefined");
			}
		}

		int32_t s = 0;
		for (auto i : edge_list) {
			s += eo[i];
		}
		if (s % 2 != 0) {
			throw std::runtime_error("Total edge flip is wrong");
		}
		std::vector<int32_t> corner_count(8);
		for (auto i : corner_list) {
			++corner_count[cp[i]];
		}
		for (auto i : edge_list) {
			if (edge_count[i] != 1) {
				throw std::runtime_error("Some corners are undefined");
			}
		}
		s = 0;
		for (auto i : corner_list) {
			s += co[i];
		}
		if (s % 3 != 0) {
			throw std::runtime_error("Total corner twist is wrong");
		}
		if (EdgeParity() != CornerParity()) {
			throw std::runtime_error("Wrong edge and corner parity");
		}
		return CUBE_OK;
	}

	std::vector<Corner>& get_cp() {
		return cp;
	}

	std::vector<int32_t>& get_co() {
		return co;
	}

	std::vector<Edge>& get_ep() {
		return ep;
	}

	std::vector<int32_t>& get_eo() {
		return eo;
	}
};

static CubieCube FaceletToCubie(const FaceCube fc) {
	CubieCube cc;
	cc.get_cp() = std::vector<Corner>(8, empty_corner);
	cc.get_ep() = std::vector<Edge>(12, empty_edge);

	for (auto i : corner_list) {
		std::vector<Facelet> facelets = corner_facelet[i]; // facelet'ы i-го угла собранного кубика
		int32_t ori = 0;
		for (ori = 0; ori < 3; ++ori) {
			if (fc.get_f()[facelets[ori]] == U or fc.get_f()[facelets[ori]] == D) {
				break;
			}
		} // сейчас ori - ориентация i-го угла, найденная по определению ориентации
		Color col1 = fc.get_f()[facelets[(ori + 1) % 3]]; // определяющие цвета i-го угла (цвета, не являющиеся U или D)
		Color col2 = fc.get_f()[facelets[(ori + 2) % 3]];
		for (auto j : corner_list) { // поиск угла, определяющие цвета которого совпадали бы с определяющими цветами угла нашего кубика
			std::vector<Color> col = corner_color[j];
			if (col1 == col[1] and col2 == col[2]) {
				cc.get_cp()[i] = j;
				cc.get_co()[i] = ori;
				break;
			}
		}
	}

	for (auto i : edge_list) {
		for (auto j : edge_list) { // поиск ребра, совпадающего с нашим
			if (fc.get_f()[edge_facelet[i][0]] == edge_color[j][0] and fc.get_f()[edge_facelet[i][1]] == edge_color[j][1]) {
				cc.get_ep()[i] = j;
				cc.get_eo()[i] = 0;
				break;
			}
			if (fc.get_f()[edge_facelet[i][0]] == edge_color[j][1] and fc.get_f()[edge_facelet[i][1]] == edge_color[j][0]) {
				cc.get_ep()[i] = j;
				cc.get_eo()[i] = 1;
				break;
			}
		}
	}
	return cc;
}

// Эти кубы представляют базовые 6 ходов
static const CubieCube u_cube{ cpU, coU, epU, eoU }, r_cube{ cpR, coR, epR, eoR }, f_cube{ cpF, coF, epF, eoF }, 
d_cube{ cpD, coD, epD, eoD }, l_cube{ cpL, coL, epL, eoL }, b_cube{ cpB, coB, epB, eoB };
static const std::vector<CubieCube> basic_move_cube{ u_cube, r_cube, f_cube, d_cube, l_cube, b_cube };

// Эти кубы представляют все 18 возможных ходов
namespace {
	std::vector<CubieCube> MakeMyVector() {
		std::vector<CubieCube> v(18);
		for (auto c1 : color_list) {
			CubieCube cc;
			for (int32_t k1 = 0; k1 < 3; ++k1) {
				cc.Multiply(basic_move_cube[c1]);
				v[3 * c1 + k1] = cc;
			}
		}
		return v;
	}
}
static const std::vector<CubieCube> move_cube = MakeMyVector();