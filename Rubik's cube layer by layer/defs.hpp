#pragma once
#include "enums.hpp"
#include <vector>
#include <string>

static const std::vector<std::vector<Facelet>> corner_facelet = { {u9, r1, f3}, {u7, f1, l3}, {u1, l1, b3}, {u3, b1, r3},
	{d3, f9, r7}, {d1, l9, f7}, {d7, b9, l7}, {d9, r9, b7} };

static const std::vector<std::vector<Facelet>> edge_facelet = { {u6, r2}, {u8, f2}, {u4, l2}, {u2, b2}, {d6, r8}, {d2, f8},
	{d4, l8}, {d8, b8}, {f6, r4}, {f4, l6}, {b6, l4}, {b4, r6} };

static const std::vector<std::vector<Color>> corner_color = { {U, R, F}, {U, F, L}, {U, L, B}, {U, B, R}, {D, F, R}, {D, L, F}, {D, B, L}, {D, R, B} };

static const std::vector<std::vector<Color>> edge_color = { {U, R}, {U, F}, {U, L}, {U, B}, {D, R}, {D, F}, {D, L}, {D, B}, {F, R}, {F, L}, {B, L}, {B, R} };

static const std::vector<Facelet> facelet_list = { u1, u2, u3, u4, u5, u6, u7, u8, u9,
    r1, r2, r3, r4, r5, r6, r7, r8, r9,
    f1, f2, f3, f4, f5, f6, f7, f8, f9,
    d1, d2, d3, d4, d5, d6, d7, d8, d9,
    l1, l2, l3, l4, l5, l6, l7, l8, l9,
    b1, b2, b3, b4, b5, b6, b7, b8, b9 };
static const std::vector<Color> color_list = { U, R, F, D, L, B };
static const std::vector<Corner> corner_list = { URF, UFL, ULB, UBR, DFR, DLF, DBL, DRB };
static const std::vector<Edge> edge_list = { UR, UF, UL, UB, DR, DF, DL, DB, FR, FL, BL, BR };
static const std::vector<Move> move_list = { U1, U2, U3, R1, R2, R3, F1, F2, F3, D1, D2, D3, L1, L2, L3, B1, B2, B3 };

// moves_i - move_list, если за f принять i
static const std::vector<Move> moves_f = { U1, U2, U3, R1, R2, R3, F1, F2, F3, D1, D2, D3, L1, L2, L3, B1, B2, B3 };
static const std::vector<Move> moves_r = { U1, U2, U3, B1, B2, B3, R1, R2, R3, D1, D2, D3, F1, F2, F3, L1, L2, L3 }; // r->b, f->r, l->f, b->l
static const std::vector<Move> moves_b = { U1, U2, U3, L1, L2, L3, B1, B2, B3, D1, D2, D3, R1, R2, R3, F1, F2, F3 }; // r->l, f->b, l->r, b->f
static const std::vector<Move> moves_l = { U1, U2, U3, F1, F2, F3, L1, L2, L3, D1, D2, D3, B1, B2, B3, R1, R2, R3 }; // r->f, f->l, l->b, b->r
// edges_i - edge_list, если за f принять i
static const std::vector<Edge> edges_f = { UR, UF, UL, UB, DR, DF, DL, DB, FR, FL, BL, BR };
static const std::vector<Edge> edges_r = { UF, UL, UB, UR, DF, DL, DB, DR, FL, BL, BR, FR }; // r->f, f->l, l->b, b->r
static const std::vector<Edge> edges_b = { UL, UB, UR, UF, DL, DB, DR, DF, BL, BR, FR, FL }; // r->l, f->b, l->r, b->f
static const std::vector<Edge> edges_l = { UB, UR, UF, UL, DB, DR, DF, DL, BR, FR, FL, BL }; // r->b, f->r, l->f, b->l
// corners_i - corner_list, если за f принять i
static const std::vector<Corner> corners_f = { URF, UFL, ULB, UBR, DFR, DLF, DBL, DRB };
static const std::vector<Corner> corners_r = { UFL, ULB, UBR, URF, DLF, DBL, DRB, DFR }; // r->f, f->l, l->b, b->r
static const std::vector<Corner> corners_b = { ULB, UBR, URF, UFL, DBL, DRB, DFR, DLF }; // r->l, f->b, l->r, b->f
static const std::vector<Corner> corners_l = { UBR, URF, UFL, ULB, DRB, DFR, DLF, DBL }; // r->b, f->r, l->f, b->l

static std::ostream& operator<<(std::ostream& os, Edge e) {
    switch (e) {
    case UR:
        os << "UR";
        break;
    case UF:
        os << "UF";
        break;
    case UL:
        os << "UL";
        break;
    case UB:
        os << "UB";
        break;
    case DR:
        os << "DR";
        break;
    case DF:
        os << "DF";
        break;
    case DL:
        os << "DL";
        break;
    case DB:
        os << "DB";
        break;
    case FR:
        os << "FR";
        break;
    case FL:
        os << "FL";
        break;
    case BL:
        os << "BL";
        break;
    case BR:
        os << "BR";
        break;
    }
    return os;
}

static std::ostream& operator<<(std::ostream& os, Move m) {
    switch (m) {
    case U1:
        os << "U1";
        break;
    case U2:
        os << "U2";
        break;
    case U3:
        os << "U3";
        break;
    case R1:
        os << "R1";
        break;
    case R2:
        os << "R2";
        break;
    case R3:
        os << "R3";
        break;
    case F1:
        os << "F1";
        break;
    case F2:
        os << "F2";
        break;
    case F3:
        os << "F3";
        break;
    case D1:
        os << "D1";
        break;
    case D2:
        os << "D2";
        break;
    case D3:
        os << "D3";
        break;
    case L1:
        os << "L1";
        break;
    case L2:
        os << "L2";
        break;
    case L3:
        os << "L3";
        break;
    case B1:
        os << "B1";
        break;
    case B2:
        os << "B2";
        break;
    case B3:
        os << "B3";
        break;
    }
    return os;
}

static std::ostream& operator<<(std::ostream& os, std::vector<Move> m) {
    std::string s;
    for (auto i : m) {
        switch (i) {
        case U1:
            s += "U1 ";
            break;
        case U2:
            s += "U2 ";
            break;
        case U3:
            s += "U3 ";
            break;
        case R1:
            s += "R1 ";
            break;
        case R2:
            s += "R2 ";
            break;
        case R3:
            s += "R3 ";
            break;
        case F1:
            s += "F1 ";
            break;
        case F2:
            s += "F2 ";
            break;
        case F3:
            s += "F3 ";
            break;
        case D1:
            s += "D1 ";
            break;
        case D2:
            s += "D2 ";
            break;
        case D3:
            s += "D3 ";
            break;
        case L1:
            s += "L1 ";
            break;
        case L2:
            s += "L2 ";
            break;
        case L3:
            s += "L3 ";
            break;
        case B1:
            s += "B1 ";
            break;
        case B2:
            s += "B2 ";
            break;
        case B3:
            s += "B3 ";
            break;
        }
    }
    s = s.substr(0, s.size() - 1);
    os << s;
    return os;
}