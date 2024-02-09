#include "cube.hpp"

std::vector<Move> Cube::WhiteCross() {
	// собираем и ориентируем грани DR, DF, DL, DB
	std::vector<Move> solution;
	CubieCube cc = cubie_cube;
	Edge DR_pos = empty_edge, DF_pos = empty_edge, DL_pos = empty_edge, DB_pos = empty_edge;
	for (auto i : edge_list) {
		if (cc.get_ep()[i] == DR) {
			DR_pos = i;
		}
	}
	MoveSet1(DR, solution, cc, DR_pos);

	for (auto i : edge_list) {
		if (cc.get_ep()[i] == DF) {
			DF_pos = i;
		}
	}
	MoveSet1(DF, solution, cc, DF_pos);

	for (auto i : edge_list) {
		if (cc.get_ep()[i] == DL) {
			DL_pos = i;
		}
	}
	MoveSet1(DL, solution, cc, DL_pos);

	for (auto i : edge_list) {
		if (cc.get_ep()[i] == DB) {
			DB_pos = i;
		}
	}
	MoveSet1(DB, solution, cc, DB_pos);

	return solution;
}
std::vector<Move> Cube::WhiteCorners(std::vector<Move> solution) {
	// собираем и ориентируем углы DFR, DLF, DBL, DRB
	Cube cb = (*this);
	cb.Multiply(solution);
	CubieCube cc = cb.get_cubie_cube();
	Corner DFR_pos = empty_corner, DLF_pos = empty_corner, DBL_pos = empty_corner, DRB_pos = empty_corner;
	for (auto i : corner_list) {
		if (cc.get_cp()[i] == DFR) {
			DFR_pos = i;
		}
	}
	MoveSet2(DFR, solution, cc, DFR_pos);

	for (auto i : corner_list) {
		if (cc.get_cp()[i] == DLF) {
			DLF_pos = i;
		}
	}
	MoveSet2(DLF, solution, cc, DLF_pos);

	for (auto i : corner_list) {
		if (cc.get_cp()[i] == DBL) {
			DBL_pos = i;
		}
	}
	MoveSet2(DBL, solution, cc, DBL_pos);

	for (auto i : corner_list) {
		if (cc.get_cp()[i] == DRB) {
			DRB_pos = i;
		}
	}
	MoveSet2(DRB, solution, cc, DRB_pos);

	return solution;
}
std::vector<Move> Cube::SecondLayer(std::vector<Move> solution) {
	// собираем и ориентируем грани FR, FL, BL, BR
	Cube cb = (*this);
	cb.Multiply(solution);
	CubieCube cc = cb.get_cubie_cube();
	Edge FR_pos = empty_edge, FL_pos = empty_edge, BL_pos = empty_edge, BR_pos = empty_edge;
	for (auto i : edge_list) {
		if (cc.get_ep()[i] == FR) {
			FR_pos = i;
		}
	}
	MoveSet3(FR, solution, cc, FR_pos);

	for (auto i : edge_list) {
		if (cc.get_ep()[i] == FL) {
			FL_pos = i;
		}
	}
	MoveSet3(FL, solution, cc, FL_pos);

	for (auto i : edge_list) {
		if (cc.get_ep()[i] == BL) {
			BL_pos = i;
		}
	}
	MoveSet3(BL, solution, cc, BL_pos);

	for (auto i : edge_list) {
		if (cc.get_ep()[i] == BR) {
			BR_pos = i;
		}
	}
	MoveSet3(BR, solution, cc, BR_pos);

	return solution;
}
std::vector<Move> Cube::YellowCross(std::vector<Move> solution) {
	Cube cb = (*this);
	cb.Multiply(solution);
	CubieCube cc = cb.get_cubie_cube();
	FaceCube fc = cb.get_facelet_cube();
	std::vector<Color> upper_facelets_colors = { fc.get_f()[u2], fc.get_f()[u4], fc.get_f()[u6], fc.get_f()[u8] };
	uint32_t yellow_facelets_number = 0;
	for (auto i : upper_facelets_colors) {
		if (i == U) {
			++yellow_facelets_number;
		}
	}
	if (yellow_facelets_number == 0) {
		MoveSet4(F, solution, cc);
		solution.push_back(U2);
		cc.Multiply(move_cube[U2]);
		MoveSet4(F, solution, cc);
		MoveSet4(F, solution, cc);
	}
	if (yellow_facelets_number == 2) {
		if (upper_facelets_colors[0] == U && upper_facelets_colors[1] == U) {
			MoveSet4(F, solution, cc);
			MoveSet4(F, solution, cc);
		}
		if (upper_facelets_colors[1] == U && upper_facelets_colors[3] == U) {
			MoveSet4(R, solution, cc);
			MoveSet4(R, solution, cc);
		}
		if (upper_facelets_colors[2] == U && upper_facelets_colors[3] == U) {
			MoveSet4(B, solution, cc);
			MoveSet4(B, solution, cc);
		}
		if (upper_facelets_colors[0] == U && upper_facelets_colors[2] == U) {
			MoveSet4(L, solution, cc);
			MoveSet4(L, solution, cc);
		}
		if (upper_facelets_colors[0] == U && upper_facelets_colors[3] == U) {
			MoveSet4(R, solution, cc);
		}
		if (upper_facelets_colors[1] == U && upper_facelets_colors[2] == U) {
			MoveSet4(F, solution, cc);
		}
	}
	return solution;
}
std::vector<Move> Cube::YellowEdges(std::vector<Move> solution) {
	// собираем грани UR, UF, UL, UB
	Cube cb = (*this);
	cb.Multiply(solution);
	CubieCube cc = cb.get_cubie_cube();
	FaceCube fc = cc.ToFaceletCube();
	std::vector<Color> upper_side_facelets = { fc.get_f()[r2], fc.get_f()[f2], fc.get_f()[l2], fc.get_f()[b2] };
	std::vector<Color> upper_side_facelets_goal = { R, F, L, B };
	uint32_t not_mathing_edges = 0;
	for (int32_t i = 0; i < 4; ++i) {
		if (upper_side_facelets[i] != upper_side_facelets_goal[i]) {
			++not_mathing_edges;
		}
	}
	while (not_mathing_edges > 2) {
		solution.push_back(U1);
		cc.Multiply(move_cube[U1]);
		not_mathing_edges = 0;
		fc = cc.ToFaceletCube();
		upper_side_facelets = { fc.get_f()[r2], fc.get_f()[f2], fc.get_f()[l2], fc.get_f()[b2] };
		for (int32_t i = 0; i < 4; ++i) {
			if (upper_side_facelets[i] != upper_side_facelets_goal[i]) {
				++not_mathing_edges;
			}
		}
	}
	if (upper_side_facelets[0] != upper_side_facelets_goal[0] && upper_side_facelets[1] != upper_side_facelets_goal[1]) {
		MoveSet5(R, solution, cc);
	}
	if (upper_side_facelets[2] != upper_side_facelets_goal[2] && upper_side_facelets[1] != upper_side_facelets_goal[1]) {
		MoveSet5(F, solution, cc);
	}
	if (upper_side_facelets[0] != upper_side_facelets_goal[0] && upper_side_facelets[3] != upper_side_facelets_goal[3]) {
		MoveSet5(B, solution, cc);
	}
	if (upper_side_facelets[2] != upper_side_facelets_goal[2] && upper_side_facelets[3] != upper_side_facelets_goal[3]) {
		MoveSet5(L, solution, cc);
	}
	if (upper_side_facelets[0] != upper_side_facelets_goal[0] && upper_side_facelets[2] != upper_side_facelets_goal[2]) {
		solution.push_back(U1);
		cc.Multiply(move_cube[U1]);
		MoveSet5(F, solution, cc);
		MoveSet5(B, solution, cc);
	}
	if (upper_side_facelets[1] != upper_side_facelets_goal[1] && upper_side_facelets[3] != upper_side_facelets_goal[3]) {
		solution.push_back(U1);
		cc.Multiply(move_cube[U1]);
		MoveSet5(L, solution, cc);
		MoveSet5(R, solution, cc);
	}
	return solution;
}
std::vector<Move> Cube:: YellowCornersPerm(std::vector<Move> solution) {
	// собираем углы URF, UFL, ULB, UBR
	Cube cb = (*this);
	cb.Multiply(solution);
	CubieCube cc = cb.get_cubie_cube();
	while (cc.get_cp()[URF] != URF && cc.get_cp()[UFL] != UFL && cc.get_cp()[ULB] != ULB && cc.get_cp()[UBR] != UBR) {
		MoveSet6(F, solution, cc);
	}
	while (cc.get_cp()[URF] != URF || cc.get_cp()[UFL] != UFL || cc.get_cp()[ULB] != ULB || cc.get_cp()[UBR] != UBR) {
		if (cc.get_cp()[URF] == URF) {
			MoveSet6(F, solution, cc);
		}
		if (cc.get_cp()[UFL] == UFL) {
			MoveSet6(L, solution, cc);
		}
		if (cc.get_cp()[ULB] == ULB) {
			MoveSet6(B, solution, cc);
		}
		if (cc.get_cp()[UBR] == UBR) {
			MoveSet6(R, solution, cc);
		}
	}
	return solution;
}
std::vector<Move> Cube::YellowCornersOri(std::vector<Move> solution) {
	// ориентируем углы URF, UFL, ULB, UBR
	Cube cb = (*this);
	cb.Multiply(solution);
	CubieCube cc = cb.get_cubie_cube();
	while (!(cc.get_co()[URF] == 0 && cc.get_cp()[URF] == URF)) {
		MoveSet7(F, solution, cc);
	}
	solution.push_back(U3);
	cc.Multiply(move_cube[U3]);
	while (!(cc.get_co()[URF] == 0 && cc.get_cp()[URF] == UFL)) {
		MoveSet7(F, solution, cc);
	}
	solution.push_back(U3);
	cc.Multiply(move_cube[U3]);
	while (!(cc.get_co()[URF] == 0 && cc.get_cp()[URF] == ULB)) {
		MoveSet7(F, solution, cc);
	}
	solution.push_back(U3);
	cc.Multiply(move_cube[U3]);
	while (!(cc.get_co()[URF] == 0 && cc.get_cp()[URF] == UBR)) {
		MoveSet7(F, solution, cc);
	}
	solution.push_back(U3);
	cc.Multiply(move_cube[U3]);
	return solution;
}