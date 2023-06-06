#include <iostream>
#include <graphics.h>		
#include <conio.h>
#include <vector>
#include "Level.h"

const Level level_4_1() {
    Grid G(720, 720, 60, 60, 150, 100, 7, 5);
    Point A(0, 2), B(2, 6);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    lvl_points.push_back(b1);
    Line L1(a1, b1);
    std::vector<Line>lvl_lines;
    lvl_lines.push_back(L1);
    Point P(0, 5.125), Q(4, 0.625);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q);
    Line real_l(p1, q1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(real_l);
    std::string lvl_question = "4-1.请在每个小格长:宽=3:2的网格中作出线段的垂直平分线.";
    Level level_4(G, lvl_points, lvl_lines, std::vector<Point>(), lvl_reallines, lvl_question, false);
    return level_4;
}

const Level level_4_2() {
    Grid G(720, 720, 60, 60, 150, 100, 7, 5);
    Point A(0, 2), B(2, 6), C(1, 4), D(11.0/3, 1);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B), c1 = pointToGrid(G, C), d1 = pointToGrid(G, D);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    lvl_points.push_back(b1);
    lvl_points.push_back(c1);
    lvl_points.push_back(d1);
    Line L1(a1, b1);
    Line L2(c1, d1);
    std::vector<Line>lvl_lines;
    lvl_lines.push_back(L1);
    lvl_lines.push_back(L2);
    Point P(7.0/3, 2.5);
    Point p1 = pointToGrid(G, P);
    Line PA(p1, a1), PB(p1, b1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(PA);
    lvl_reallines.push_back(PB);
    std::string lvl_question = "4-2.在4-1中线段的垂直平分线上取点,作出以原线段为斜边的等腰直角三角形.";
    Level level_4(G, lvl_points, lvl_lines, std::vector<Circle>(), 
        std::vector<Point>(), lvl_reallines, std::vector<Circle>(), lvl_question, false);
    return level_4;
}

const Level level_4_3() {
    Grid G(720, 720, 60, 60, 150, 100, 7, 5);
    Point A(0, 2), B(2, 6);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    lvl_points.push_back(b1);
    Line L1(a1, b1);
    std::vector<Line>lvl_lines;
    lvl_lines.push_back(L1);
    Point P(4, 2);
    Point p1 = pointToGrid(G, P);
    Line PA(p1, a1), PB(p1, b1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(PA);
    lvl_reallines.push_back(PB);
    std::string lvl_question = "4-3.在4-1的格点(不包括其他交叉点)上选一点,与所给线段构成等腰三角形.";
    Level level_4(G, lvl_points, lvl_lines, std::vector<Point>(), lvl_reallines, lvl_question, false);
    return level_4;
}

const Level level_4_4() {
    Grid G(720, 720, 60, 60, 150, 100, 7, 5);
    Point A(0, 2), B(2, 6), C(4, 2);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B), c1 = pointToGrid(G, C);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    lvl_points.push_back(b1);
    lvl_points.push_back(c1);
    Line AB(a1, b1), AC(a1, c1), BC(b1, c1);
    std::vector<Line>lvl_lines;
    lvl_lines.push_back(AB);
    lvl_lines.push_back(AC);
    lvl_lines.push_back(BC);
    Point P(2, 3.5), Q(2, 2.875);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q);
    std::vector<Point>lvl_realpoints;
    lvl_realpoints.push_back(p1);
    lvl_realpoints.push_back(q1);
    std::string lvl_question = "4-4.作出4-3中等腰三角形的外心和内心.";
    Level level_4(G, lvl_points, lvl_lines, lvl_realpoints, std::vector<Line>(), lvl_question, false);
    return level_4;
}