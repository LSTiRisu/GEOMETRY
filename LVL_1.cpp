#include <iostream>
#include <graphics.h>		
#include <conio.h>
#include <vector>
#include "Level.h"

const Level level_1_1() {
    Grid G;
    Point A(1, 0), B(0, 2), C(2, 4), D(4, 3);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B), c1 = pointToGrid(G, C), d1 = pointToGrid(G, D);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    lvl_points.push_back(b1);
    lvl_points.push_back(c1);
    lvl_points.push_back(d1);
    Line L1(a1, b1), L2(c1, d1);
    std::vector<Line>lvl_lines;
    lvl_lines.push_back(L1);
    lvl_lines.push_back(L2);
    Point P(0, 4), Q(4, 0);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q);
    Line real_l(p1, q1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(real_l);
    std::string lvl_question = "1-1.请作出图中两条线段所成角的平分线.";
    Level level_1(G, lvl_points, lvl_lines, std::vector<Point>(), lvl_reallines, lvl_question, false);
    return level_1;
}

const Level level_1_2() {
    Grid G;
    Point A(2, 0), B(1, 2), C(1, 2), D(3, 3);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B), c1 = pointToGrid(G, C), d1 = pointToGrid(G, D);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    lvl_points.push_back(b1);
    lvl_points.push_back(c1);
    lvl_points.push_back(d1);
    Line L1(a1, b1), L2(c1, d1);
    std::vector<Line>lvl_lines;
    lvl_lines.push_back(L1);
    lvl_lines.push_back(L2);
    Point P(1, 2), Q(4, 1);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q);
    Line real_l(p1, q1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(real_l);
    std::string lvl_question = "1-2.请作出图中两条线段所成角的平分线.";
    Level level_1(G, lvl_points, lvl_lines, std::vector<Point>(), lvl_reallines, lvl_question, false);
    return level_1;
}

const Level level_1_3() {
    Grid G;
    Point A(0, 4), B(3, 0), C(0, 4), D(3, 4);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B), c1 = pointToGrid(G, C), d1 = pointToGrid(G, D);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    lvl_points.push_back(b1);
    lvl_points.push_back(c1);
    lvl_points.push_back(d1);
    Line L1(a1, b1), L2(c1, d1);
    std::vector<Line>lvl_lines;
    lvl_lines.push_back(L1);
    lvl_lines.push_back(L2);
    Point P(0, 4), Q(4, 2);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q);
    Line real_l(p1, q1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(real_l);
    std::string lvl_question = "1-3.请作出图中两条线段所成角的平分线.";
    Level level_1(G, lvl_points, lvl_lines, std::vector<Point>(), lvl_reallines, lvl_question, false);
    return level_1;
}

const Level level_1_4() {
    Grid G;
    Point A(1, 0), B(0, 2), C(1, 3), D(3, 4);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B), c1 = pointToGrid(G, C), d1 = pointToGrid(G, D);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    lvl_points.push_back(b1);
    lvl_points.push_back(c1);
    lvl_points.push_back(d1);
    Line L1(a1, b1), L2(c1, d1);
    std::vector<Line>lvl_lines;
    lvl_lines.push_back(L1);
    lvl_lines.push_back(L2);
    Point P(0, 2.33333), Q(4, 1);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q);
    Line real_l(p1, q1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(real_l);
    std::string lvl_question = "1-4.请作出图中两条线段所成角的平分线.";
    Level level_1(G, lvl_points, lvl_lines, std::vector<Point>(), lvl_reallines, lvl_question, false);
    return level_1;
}