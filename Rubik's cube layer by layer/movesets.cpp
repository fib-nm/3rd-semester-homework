#include "cube.hpp"

void Cube::MoveSet1(Edge edge, std::vector<Move>& sol, CubieCube& cc, Edge pos) {
	// DR, DF, DL, DB
	std::vector<Move> moves_used = moves_f;
	std::vector<Edge> edges_used = edges_f;
	Edge pos_used = pos;
	switch (edge) {
	case DF:
		moves_used = moves_l;
		edges_used = edges_l;
		pos_used = edges_l[pos];
		break;
	case DL:
		moves_used = moves_b;
		edges_used = edges_b;
		pos_used = edges_b[pos];
		break;
	case DB:
		moves_used = moves_r;
		edges_used = edges_r;
		pos_used = edges_r[pos];
		break;
	}
	{
		if (pos_used == UR) {
			sol.push_back(moves_used[R2]);
			cc.Multiply(move_cube[moves_used[R2]]);
			if (cc.get_eo()[edge] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[R2]);
				cc.Multiply(move_cube[moves_used[R2]]);
			}
		}
		else if (pos_used == UF) {
			sol.push_back(moves_used[U3]);
			cc.Multiply(move_cube[moves_used[U3]]);
			sol.push_back(moves_used[R2]);
			cc.Multiply(move_cube[moves_used[R2]]);
			if (cc.get_eo()[edge] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[R2]);
				cc.Multiply(move_cube[moves_used[R2]]);
			}
		}
		else if (pos_used == UL) {
			sol.push_back(moves_used[U2]);
			cc.Multiply(move_cube[moves_used[U2]]);
			sol.push_back(moves_used[R2]);
			cc.Multiply(move_cube[moves_used[R2]]);
			if (cc.get_eo()[edge] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[R2]);
				cc.Multiply(move_cube[moves_used[R2]]);
			}
		}
		else if (pos_used == UB) {
			sol.push_back(moves_used[U1]);
			cc.Multiply(move_cube[moves_used[U1]]);
			sol.push_back(moves_used[R2]);
			cc.Multiply(move_cube[moves_used[R2]]);
			if (cc.get_eo()[edge] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[R2]);
				cc.Multiply(move_cube[moves_used[R2]]);
			}
		}
		else if (pos_used == DR) {
			if (cc.get_eo()[edge] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[R2]);
				cc.Multiply(move_cube[moves_used[R2]]);
			}
		}
		else if (pos_used == DF) {
			sol.push_back(moves_used[F3]);
			cc.Multiply(move_cube[moves_used[F3]]);
			sol.push_back(moves_used[R3]);
			cc.Multiply(move_cube[moves_used[R3]]);
			if (cc.get_eo()[edge] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[R2]);
				cc.Multiply(move_cube[moves_used[R2]]);
			}
		}
		else if (pos_used == DL) {
			sol.push_back(moves_used[L2]);
			cc.Multiply(move_cube[moves_used[L2]]);
			sol.push_back(moves_used[U2]);
			cc.Multiply(move_cube[moves_used[U2]]);
			sol.push_back(moves_used[R2]);
			cc.Multiply(move_cube[moves_used[R2]]);
			if (cc.get_eo()[edge] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[R2]);
				cc.Multiply(move_cube[moves_used[R2]]);
			}
		}
		else if (pos_used == DB) {
			sol.push_back(moves_used[B1]);
			cc.Multiply(move_cube[moves_used[B1]]);
			sol.push_back(moves_used[R1]);
			cc.Multiply(move_cube[moves_used[R1]]);
			if (cc.get_eo()[edge] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[R2]);
				cc.Multiply(move_cube[moves_used[R2]]);
			}
		}
		else if (pos_used == FR) {
			sol.push_back(moves_used[R3]);
			cc.Multiply(move_cube[moves_used[R3]]);
			if (cc.get_eo()[edge] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[R2]);
				cc.Multiply(move_cube[moves_used[R2]]);
			}
		}
		else if (pos_used == FL) {
			sol.push_back(moves_used[F1]);
			cc.Multiply(move_cube[moves_used[F1]]);
			sol.push_back(moves_used[U3]);
			cc.Multiply(move_cube[moves_used[U3]]);
			sol.push_back(moves_used[F3]);
			cc.Multiply(move_cube[moves_used[F3]]);
			sol.push_back(moves_used[R2]);
			cc.Multiply(move_cube[moves_used[R2]]);
			if (cc.get_eo()[edge] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[R2]);
				cc.Multiply(move_cube[moves_used[R2]]);
			}
		}
		else if (pos_used == BL) {
			sol.push_back(moves_used[B3]);
			cc.Multiply(move_cube[moves_used[B3]]);
			sol.push_back(moves_used[U1]);
			cc.Multiply(move_cube[moves_used[U1]]);
			sol.push_back(moves_used[B1]);
			cc.Multiply(move_cube[moves_used[B1]]);
			sol.push_back(moves_used[R2]);
			cc.Multiply(move_cube[moves_used[R2]]);
			if (cc.get_eo()[edge] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[R2]);
				cc.Multiply(move_cube[moves_used[R2]]);
			}
		}
		else if (pos_used == BR) {
			sol.push_back(moves_used[R1]);
			cc.Multiply(move_cube[moves_used[R1]]);
			if (cc.get_eo()[edge] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[R2]);
				cc.Multiply(move_cube[moves_used[R2]]);
			}
		}
	}
}
void Cube::MoveSet2(Corner corner, std::vector<Move>& sol, CubieCube& cc, Corner pos) {
	// DFR, DLF, DBL, DRB
	std::vector<Move> moves_used = moves_f;
	std::vector<Corner> corners_used = corners_f;
	Corner pos_used = pos;
	switch (corner) {
	case DLF:
		moves_used = moves_l;
		corners_used = corners_l;
		pos_used = corners_l[pos];
		break;
	case DBL:
		moves_used = moves_b;
		corners_used = corners_b;
		pos_used = corners_b[pos];
		break;
	case DRB:
		moves_used = moves_r;
		corners_used = corners_r;
		pos_used = corners_r[pos];
		break;
	}
	{
		if (pos_used == URF) {
			sol.push_back(moves_used[R1]);
			cc.Multiply(move_cube[moves_used[R1]]);
			sol.push_back(moves_used[U1]);
			cc.Multiply(move_cube[moves_used[U1]]);
			sol.push_back(moves_used[R3]);
			cc.Multiply(move_cube[moves_used[R3]]);
			while (cc.get_co()[corner] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
			}
		}
		else if (pos_used == UFL) {
			sol.push_back(moves_used[R1]);
			cc.Multiply(move_cube[moves_used[R1]]);
			sol.push_back(moves_used[U3]);
			cc.Multiply(move_cube[moves_used[U3]]);
			sol.push_back(moves_used[R3]);
			cc.Multiply(move_cube[moves_used[R3]]);
			while (cc.get_co()[corner] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
			}
		}
		else if (pos_used == ULB) {
			sol.push_back(moves_used[R1]);
			cc.Multiply(move_cube[moves_used[R1]]);
			sol.push_back(moves_used[U2]);
			cc.Multiply(move_cube[moves_used[U2]]);
			sol.push_back(moves_used[R3]);
			cc.Multiply(move_cube[moves_used[R3]]);
			while (cc.get_co()[corner] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
			}
		}
		else if (pos_used == UBR) {
			sol.push_back(moves_used[U3]);
			cc.Multiply(move_cube[moves_used[U3]]);
			sol.push_back(moves_used[R1]);
			cc.Multiply(move_cube[moves_used[R1]]);
			sol.push_back(moves_used[U2]);
			cc.Multiply(move_cube[moves_used[U2]]);
			sol.push_back(moves_used[R3]);
			cc.Multiply(move_cube[moves_used[R3]]);
			while (cc.get_co()[corner] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
			}
		}
		else if (pos_used == DFR) {
			while (cc.get_co()[corner] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
			}
		}
		else if (pos_used == DLF) {
			sol.push_back(moves_used[L3]);
			cc.Multiply(move_cube[moves_used[L3]]);
			sol.push_back(moves_used[U3]);
			cc.Multiply(move_cube[moves_used[U3]]);
			sol.push_back(moves_used[L1]);
			cc.Multiply(move_cube[moves_used[L1]]);
			sol.push_back(moves_used[R1]);
			cc.Multiply(move_cube[moves_used[R1]]);
			sol.push_back(moves_used[U1]);
			cc.Multiply(move_cube[moves_used[U1]]);
			sol.push_back(moves_used[R3]);
			cc.Multiply(move_cube[moves_used[R3]]);
			while (cc.get_co()[corner] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
			}
		}
		else if (pos_used == DBL) {
			sol.push_back(moves_used[L1]);
			cc.Multiply(move_cube[moves_used[L1]]);
			sol.push_back(moves_used[U3]);
			cc.Multiply(move_cube[moves_used[U3]]);
			sol.push_back(moves_used[L3]);
			cc.Multiply(move_cube[moves_used[L3]]);
			sol.push_back(moves_used[R1]);
			cc.Multiply(move_cube[moves_used[R1]]);
			sol.push_back(moves_used[U2]);
			cc.Multiply(move_cube[moves_used[U2]]);
			sol.push_back(moves_used[R3]);
			cc.Multiply(move_cube[moves_used[R3]]);
			while (cc.get_co()[corner] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
			}
		}
		else if (pos_used == DRB) {
			sol.push_back(moves_used[B1]);
			cc.Multiply(move_cube[moves_used[B1]]);
			sol.push_back(moves_used[U3]);
			cc.Multiply(move_cube[moves_used[U3]]);
			sol.push_back(moves_used[B3]);
			cc.Multiply(move_cube[moves_used[B3]]);
			sol.push_back(moves_used[U3]);
			cc.Multiply(move_cube[moves_used[U3]]);
			sol.push_back(moves_used[R1]);
			cc.Multiply(move_cube[moves_used[R1]]);
			sol.push_back(moves_used[U2]);
			cc.Multiply(move_cube[moves_used[U2]]);
			sol.push_back(moves_used[R3]);
			cc.Multiply(move_cube[moves_used[R3]]);
			while (cc.get_co()[corner] != 0) {
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
			}
		}
	}
}
void Cube::MoveSet3(Edge edge, std::vector<Move>& sol, CubieCube& cc, Edge pos) {
	// FR, FL, BL, BR
	std::vector<Move> moves_used = moves_f;
	std::vector<Edge> edges_used = edges_f;
	Edge pos_used = pos;
	switch (edge) {
	case FL:
		moves_used = moves_l;
		edges_used = edges_l;
		pos_used = edges_l[pos];
		break;
	case BL:
		moves_used = moves_b;
		edges_used = edges_b;
		pos_used = edges_b[pos];
		break;
	case BR:
		moves_used = moves_r;
		edges_used = edges_r;
		pos_used = edges_r[pos];
		break;
	}
	{
		if (pos_used == UR) {
			CubieCube buffer = cc;
			buffer.Multiply(move_cube[moves_used[U3]]);
			buffer.Multiply(move_cube[moves_used[F3]]);
			buffer.Multiply(move_cube[moves_used[U1]]);
			buffer.Multiply(move_cube[moves_used[F1]]);
			buffer.Multiply(move_cube[moves_used[U1]]);
			buffer.Multiply(move_cube[moves_used[R1]]);
			buffer.Multiply(move_cube[moves_used[U3]]);
			buffer.Multiply(move_cube[moves_used[R3]]);
			if (buffer.get_eo()[edge] == 0) {
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
			}
			else {
				sol.push_back(moves_used[U2]);
				cc.Multiply(move_cube[moves_used[U2]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
			}
		}
		else if (pos_used == UF) {
			sol.push_back(moves_used[U3]);
			cc.Multiply(move_cube[moves_used[U3]]);
			CubieCube buffer = cc;
			buffer.Multiply(move_cube[moves_used[U3]]);
			buffer.Multiply(move_cube[moves_used[F3]]);
			buffer.Multiply(move_cube[moves_used[U1]]);
			buffer.Multiply(move_cube[moves_used[F1]]);
			buffer.Multiply(move_cube[moves_used[U1]]);
			buffer.Multiply(move_cube[moves_used[R1]]);
			buffer.Multiply(move_cube[moves_used[U3]]);
			buffer.Multiply(move_cube[moves_used[R3]]);
			if (buffer.get_eo()[edge] == 0) {
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
			}
			else {
				sol.push_back(moves_used[U2]);
				cc.Multiply(move_cube[moves_used[U2]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
			}
		}
		else if (pos_used == UL) {
			sol.push_back(moves_used[U2]);
			cc.Multiply(move_cube[moves_used[U2]]);
			CubieCube buffer = cc;
			buffer.Multiply(move_cube[moves_used[U3]]);
			buffer.Multiply(move_cube[moves_used[F3]]);
			buffer.Multiply(move_cube[moves_used[U1]]);
			buffer.Multiply(move_cube[moves_used[F1]]);
			buffer.Multiply(move_cube[moves_used[U1]]);
			buffer.Multiply(move_cube[moves_used[R1]]);
			buffer.Multiply(move_cube[moves_used[U3]]);
			buffer.Multiply(move_cube[moves_used[R3]]);
			if (buffer.get_eo()[edge] == 0) {
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
			}
			else {
				sol.push_back(moves_used[U2]);
				cc.Multiply(move_cube[moves_used[U2]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
			}
		}
		else if (pos_used == UB) {
			sol.push_back(moves_used[U1]);
			cc.Multiply(move_cube[moves_used[U1]]);
			CubieCube buffer = cc;
			buffer.Multiply(move_cube[moves_used[U3]]);
			buffer.Multiply(move_cube[moves_used[F3]]);
			buffer.Multiply(move_cube[moves_used[U1]]);
			buffer.Multiply(move_cube[moves_used[F1]]);
			buffer.Multiply(move_cube[moves_used[U1]]);
			buffer.Multiply(move_cube[moves_used[R1]]);
			buffer.Multiply(move_cube[moves_used[U3]]);
			buffer.Multiply(move_cube[moves_used[R3]]);
			if (buffer.get_eo()[edge] == 0) {
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
			}
			else {
				sol.push_back(moves_used[U2]);
				cc.Multiply(move_cube[moves_used[U2]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
			}
		}
		else if (pos_used == FR) {
			if (cc.get_eo()[edge] != 0) {
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
				sol.push_back(moves_used[U2]);
				cc.Multiply(move_cube[moves_used[U2]]);
				CubieCube buffer = cc;
				buffer.Multiply(move_cube[moves_used[U3]]);
				buffer.Multiply(move_cube[moves_used[F3]]);
				buffer.Multiply(move_cube[moves_used[U1]]);
				buffer.Multiply(move_cube[moves_used[F1]]);
				buffer.Multiply(move_cube[moves_used[U1]]);
				buffer.Multiply(move_cube[moves_used[R1]]);
				buffer.Multiply(move_cube[moves_used[U3]]);
				buffer.Multiply(move_cube[moves_used[R3]]);
				if (buffer.get_eo()[edge] == 0) {
					sol.push_back(moves_used[U3]);
					cc.Multiply(move_cube[moves_used[U3]]);
					sol.push_back(moves_used[F3]);
					cc.Multiply(move_cube[moves_used[F3]]);
					sol.push_back(moves_used[U1]);
					cc.Multiply(move_cube[moves_used[U1]]);
					sol.push_back(moves_used[F1]);
					cc.Multiply(move_cube[moves_used[F1]]);
					sol.push_back(moves_used[U1]);
					cc.Multiply(move_cube[moves_used[U1]]);
					sol.push_back(moves_used[R1]);
					cc.Multiply(move_cube[moves_used[R1]]);
					sol.push_back(moves_used[U3]);
					cc.Multiply(move_cube[moves_used[U3]]);
					sol.push_back(moves_used[R3]);
					cc.Multiply(move_cube[moves_used[R3]]);
				}
				else {
					sol.push_back(moves_used[U2]);
					cc.Multiply(move_cube[moves_used[U2]]);
					sol.push_back(moves_used[R1]);
					cc.Multiply(move_cube[moves_used[R1]]);
					sol.push_back(moves_used[U3]);
					cc.Multiply(move_cube[moves_used[U3]]);
					sol.push_back(moves_used[R3]);
					cc.Multiply(move_cube[moves_used[R3]]);
					sol.push_back(moves_used[U3]);
					cc.Multiply(move_cube[moves_used[U3]]);
					sol.push_back(moves_used[F3]);
					cc.Multiply(move_cube[moves_used[F3]]);
					sol.push_back(moves_used[U1]);
					cc.Multiply(move_cube[moves_used[U1]]);
					sol.push_back(moves_used[F1]);
					cc.Multiply(move_cube[moves_used[F1]]);
				}
			}
		}
		else if (pos_used == FL) {
			sol.push_back(moves_used[L3]);
			cc.Multiply(move_cube[moves_used[L3]]);
			sol.push_back(moves_used[U1]);
			cc.Multiply(move_cube[moves_used[U1]]);
			sol.push_back(moves_used[L1]);
			cc.Multiply(move_cube[moves_used[L1]]);
			sol.push_back(moves_used[U1]);
			cc.Multiply(move_cube[moves_used[U1]]);
			sol.push_back(moves_used[F1]);
			cc.Multiply(move_cube[moves_used[F1]]);
			sol.push_back(moves_used[U3]);
			cc.Multiply(move_cube[moves_used[U3]]);
			sol.push_back(moves_used[F3]);
			cc.Multiply(move_cube[moves_used[F3]]);
			sol.push_back(moves_used[U1]);
			cc.Multiply(move_cube[moves_used[U1]]);
			CubieCube buffer = cc;
			buffer.Multiply(move_cube[moves_used[U3]]);
			buffer.Multiply(move_cube[moves_used[F3]]);
			buffer.Multiply(move_cube[moves_used[U1]]);
			buffer.Multiply(move_cube[moves_used[F1]]);
			buffer.Multiply(move_cube[moves_used[U1]]);
			buffer.Multiply(move_cube[moves_used[R1]]);
			buffer.Multiply(move_cube[moves_used[U3]]);
			buffer.Multiply(move_cube[moves_used[R3]]);
			if (buffer.get_eo()[edge] == 0) {
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
			}
			else {
				sol.push_back(moves_used[U2]);
				cc.Multiply(move_cube[moves_used[U2]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
			}
		}
		else if (pos_used == BL) {
			sol.push_back(moves_used[B3]);
			cc.Multiply(move_cube[moves_used[B3]]);
			sol.push_back(moves_used[U1]);
			cc.Multiply(move_cube[moves_used[U1]]);
			sol.push_back(moves_used[B1]);
			cc.Multiply(move_cube[moves_used[B1]]);
			sol.push_back(moves_used[U1]);
			cc.Multiply(move_cube[moves_used[U1]]);
			sol.push_back(moves_used[L1]);
			cc.Multiply(move_cube[moves_used[L1]]);
			sol.push_back(moves_used[U3]);
			cc.Multiply(move_cube[moves_used[U3]]);
			sol.push_back(moves_used[L3]);
			cc.Multiply(move_cube[moves_used[L3]]);
			CubieCube buffer = cc;
			buffer.Multiply(move_cube[moves_used[U3]]);
			buffer.Multiply(move_cube[moves_used[F3]]);
			buffer.Multiply(move_cube[moves_used[U1]]);
			buffer.Multiply(move_cube[moves_used[F1]]);
			buffer.Multiply(move_cube[moves_used[U1]]);
			buffer.Multiply(move_cube[moves_used[R1]]);
			buffer.Multiply(move_cube[moves_used[U3]]);
			buffer.Multiply(move_cube[moves_used[R3]]);
			if (buffer.get_eo()[edge] == 0) {
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
			}
			else {
				sol.push_back(moves_used[U2]);
				cc.Multiply(move_cube[moves_used[U2]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
			}
		}
		else if (pos_used == BR) {
			sol.push_back(moves_used[R3]);
			cc.Multiply(move_cube[moves_used[R3]]);
			sol.push_back(moves_used[U1]);
			cc.Multiply(move_cube[moves_used[U1]]);
			sol.push_back(moves_used[R1]);
			cc.Multiply(move_cube[moves_used[R1]]);
			sol.push_back(moves_used[U1]);
			cc.Multiply(move_cube[moves_used[U1]]);
			sol.push_back(moves_used[B1]);
			cc.Multiply(move_cube[moves_used[B1]]);
			sol.push_back(moves_used[U3]);
			cc.Multiply(move_cube[moves_used[U3]]);
			sol.push_back(moves_used[B3]);
			cc.Multiply(move_cube[moves_used[B3]]);
			sol.push_back(moves_used[U3]);
			cc.Multiply(move_cube[moves_used[U3]]);
			CubieCube buffer = cc;
			buffer.Multiply(move_cube[moves_used[U3]]);
			buffer.Multiply(move_cube[moves_used[F3]]);
			buffer.Multiply(move_cube[moves_used[U1]]);
			buffer.Multiply(move_cube[moves_used[F1]]);
			buffer.Multiply(move_cube[moves_used[U1]]);
			buffer.Multiply(move_cube[moves_used[R1]]);
			buffer.Multiply(move_cube[moves_used[U3]]);
			buffer.Multiply(move_cube[moves_used[R3]]);
			if (buffer.get_eo()[edge] == 0) {
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
			}
			else {
				sol.push_back(moves_used[U2]);
				cc.Multiply(move_cube[moves_used[U2]]);
				sol.push_back(moves_used[R1]);
				cc.Multiply(move_cube[moves_used[R1]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[R3]);
				cc.Multiply(move_cube[moves_used[R3]]);
				sol.push_back(moves_used[U3]);
				cc.Multiply(move_cube[moves_used[U3]]);
				sol.push_back(moves_used[F3]);
				cc.Multiply(move_cube[moves_used[F3]]);
				sol.push_back(moves_used[U1]);
				cc.Multiply(move_cube[moves_used[U1]]);
				sol.push_back(moves_used[F1]);
				cc.Multiply(move_cube[moves_used[F1]]);
			}
		}
	}
}
void Cube::MoveSet4(Color front_color, std::vector<Move>& sol, CubieCube& cc) {
	// UR, UF, UL, UB
	std::vector<Move> moves_used = moves_f;
	switch (front_color) {
	case R:
		moves_used = moves_r;
		break;
	case L:
		moves_used = moves_l;
		break;
	case B:
		moves_used = moves_b;
		break;
	}
	sol.push_back(moves_used[F1]);
	cc.Multiply(move_cube[moves_used[F1]]);
	sol.push_back(moves_used[R1]);
	cc.Multiply(move_cube[moves_used[R1]]);
	sol.push_back(moves_used[U1]);
	cc.Multiply(move_cube[moves_used[U1]]);
	sol.push_back(moves_used[R3]);
	cc.Multiply(move_cube[moves_used[R3]]);
	sol.push_back(moves_used[U3]);
	cc.Multiply(move_cube[moves_used[U3]]);
	sol.push_back(moves_used[F3]);
	cc.Multiply(move_cube[moves_used[F3]]);
}
void Cube::MoveSet5(Color front_color, std::vector<Move>& sol, CubieCube& cc) {
	// UR, UF, UL, UB
	std::vector<Move> moves_used = moves_f;
	switch (front_color) {
	case R:
		moves_used = moves_r;
		break;
	case L:
		moves_used = moves_l;
		break;
	case B:
		moves_used = moves_b;
		break;
	}
	sol.push_back(moves_used[R1]);
	cc.Multiply(move_cube[moves_used[R1]]);
	sol.push_back(moves_used[U1]);
	cc.Multiply(move_cube[moves_used[U1]]);
	sol.push_back(moves_used[R3]);
	cc.Multiply(move_cube[moves_used[R3]]);
	sol.push_back(moves_used[U1]);
	cc.Multiply(move_cube[moves_used[U1]]);
	sol.push_back(moves_used[R1]);
	cc.Multiply(move_cube[moves_used[R1]]);
	sol.push_back(moves_used[U2]);
	cc.Multiply(move_cube[moves_used[U2]]);
	sol.push_back(moves_used[R3]);
	cc.Multiply(move_cube[moves_used[R3]]);
	sol.push_back(moves_used[U1]);
	cc.Multiply(move_cube[moves_used[U1]]);
}
void Cube::MoveSet6(Color front_color, std::vector<Move>& sol, CubieCube& cc) {
	// URF, UFL, ULB, UBR
	std::vector<Move> moves_used = moves_f;
	switch (front_color) {
	case R:
		moves_used = moves_r;
		break;
	case L:
		moves_used = moves_l;
		break;
	case B:
		moves_used = moves_b;
		break;
	}
	sol.push_back(moves_used[U1]);
	cc.Multiply(move_cube[moves_used[U1]]);
	sol.push_back(moves_used[R1]);
	cc.Multiply(move_cube[moves_used[R1]]);
	sol.push_back(moves_used[U3]);
	cc.Multiply(move_cube[moves_used[U3]]);
	sol.push_back(moves_used[L3]);
	cc.Multiply(move_cube[moves_used[L3]]);
	sol.push_back(moves_used[U1]);
	cc.Multiply(move_cube[moves_used[U1]]);
	sol.push_back(moves_used[R3]);
	cc.Multiply(move_cube[moves_used[R3]]);
	sol.push_back(moves_used[U3]);
	cc.Multiply(move_cube[moves_used[U3]]);
	sol.push_back(moves_used[L1]);
	cc.Multiply(move_cube[moves_used[L1]]);
}
void Cube::MoveSet7(Color front_color, std::vector<Move>& sol, CubieCube& cc) {
	// URF, UFL, ULB, UBR
	std::vector<Move> moves_used = moves_f;
	switch (front_color) {
	case R:
		moves_used = moves_r;
		break;
	case L:
		moves_used = moves_l;
		break;
	case B:
		moves_used = moves_b;
		break;
	}
	sol.push_back(moves_used[R3]);
	cc.Multiply(move_cube[moves_used[R3]]);
	sol.push_back(moves_used[D3]);
	cc.Multiply(move_cube[moves_used[D3]]);
	sol.push_back(moves_used[R1]);
	cc.Multiply(move_cube[moves_used[R1]]);
	sol.push_back(moves_used[D1]);
	cc.Multiply(move_cube[moves_used[D1]]);
}