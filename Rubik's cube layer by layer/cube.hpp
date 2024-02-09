#pragma once
#include "face.hpp"
#include "cubie.hpp"
#include <string>
#include <iostream>
#include <vector>

class Cube {
private:
	FaceCube face_cube;
	CubieCube cubie_cube;
	// цвета: U - желтый, R - зеленый, F - красный, D - белый, L - синий, B - оранжевый
	void MoveSet1(Edge, std::vector<Move>&, CubieCube&, Edge);
	void MoveSet2(Corner, std::vector<Move>&, CubieCube&, Corner);
	void MoveSet3(Edge, std::vector<Move>&, CubieCube&, Edge);
	void MoveSet4(Color, std::vector<Move>&, CubieCube&);
	void MoveSet5(Color, std::vector<Move>&, CubieCube&);
	void MoveSet6(Color, std::vector<Move>&, CubieCube&);
	void MoveSet7(Color, std::vector<Move>&, CubieCube&);

	std::vector<Move> WhiteCross();
	std::vector<Move> WhiteCorners(std::vector<Move>);
	std::vector<Move> SecondLayer(std::vector<Move>);
	std::vector<Move> YellowCross(std::vector<Move>);
	std::vector<Move> YellowEdges(std::vector<Move>);
	std::vector<Move> YellowCornersPerm(std::vector<Move>);
	std::vector<Move> YellowCornersOri(std::vector<Move>);
	
public:
	Cube() : face_cube(), cubie_cube() {}
	Cube(std::string cs) : face_cube{ cs }, cubie_cube{ FaceletToCubie(FaceCube{cs}) } {}
	Cube(FaceCube fc) : face_cube{ fc }, cubie_cube{ FaceletToCubie(fc) } {}
	Cube(CubieCube cc) : cubie_cube{ cc }, face_cube{ cc.ToFaceletCube() } {}

	FaceCube& get_facelet_cube() {
		return face_cube;
	}

	CubieCube& get_cubie_cube() {
		return cubie_cube;
	}

	void Randomize() {
		std::random_device rd;
		std::mt19937 mt{ rd() };
		std::uniform_int_distribution<> ud(0, 17);
		for (int32_t i = 0; i < 100; ++i) {
			cubie_cube.Multiply(move_cube[ud(mt)]);
		}
		face_cube = cubie_cube.ToFaceletCube();
	}

	void Multiply(const CubieCube& b) {
		cubie_cube.Multiply(b);
		face_cube = cubie_cube.ToFaceletCube();
	}
	void Multiply(std::vector<Move> mv_lst) {
		for (auto i : mv_lst) {
			cubie_cube.Multiply(move_cube[i]);
		}
		face_cube = cubie_cube.ToFaceletCube();
	}
	void Multiply(Move mv) {
		cubie_cube.Multiply(move_cube[mv]);
		face_cube = cubie_cube.ToFaceletCube();
	}

	std::vector<Move> Solve() {
		std::vector<Move> solution = WhiteCross();
		solution = WhiteCorners(solution);
		solution = SecondLayer(solution);
		solution = YellowCross(solution);
		solution = YellowEdges(solution);
		solution = YellowCornersPerm(solution);
		solution = YellowCornersOri(solution);
		return solution;
	}

	bool operator==(const Cube& rhs) const {
		return face_cube == rhs.face_cube && cubie_cube == rhs.cubie_cube;
	}
};

static std::ostream& operator<<(std::ostream& os, Cube c) {
	os << c.get_facelet_cube().To2dString();
	return os;
}