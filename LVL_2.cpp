#include <iostream>
#include <graphics.h>		
#include <conio.h>
#include <vector>
#include "Level.h"

const Level level_2_1() {
    Grid G;
    Point A(2, 0), B(1, 3);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    lvl_points.push_back(b1);
    Line L1(a1, b1);
    std::vector<Line>lvl_lines;
    lvl_lines.push_back(L1);
    Point P(0, 1), Q(3, 2);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q);
    Line real_l(p1, q1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(real_l);
    std::string lvl_question = "2-1.请作出图中线段的垂直平分线.";
    Level level_2(G, lvl_points, lvl_lines, std::vector<Point>(), lvl_reallines, lvl_question, false);
    return level_2;
}

const Level level_2_2() {
    Grid G;
    Point A(2, 1), B(1, 3);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    lvl_points.push_back(b1);
    Line L1(a1, b1);
    std::vector<Line>lvl_lines;
    lvl_lines.push_back(L1);
    Point P(0.5, 1.5), Q(2.5, 2.5);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q);
    Line real_l(p1, q1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(real_l);
    std::string lvl_question = "2-2.请作出图中线段的垂直平分线.";
    Level level_2(G, lvl_points, lvl_lines, std::vector<Point>(), lvl_reallines, lvl_question, false);
    return level_2;
}

const Level level_2_3() {
    Grid G;
    Point A(0, 0), B(2, 2), C(3, 0), D(2, 4);
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
    Point P(1, 1), Q(2.5, 2);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q);
    Line real_l(p1, q1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(real_l);
    std::string lvl_question = "2-3.请作出一条线段,平分图中的两条线段.";
    Level level_2(G, lvl_points, lvl_lines, std::vector<Point>(), lvl_reallines, lvl_question, false);
    return level_2;
}

const Level level_2_4() {
    Grid G;
    Point A(1, 2), B(2.5, 2.5);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    Circle Ca1(a1, 100), Cb1(b1, 50);
    std::vector<Circle>lvl_circles;
    lvl_circles.push_back(Ca1);
    lvl_circles.push_back(Cb1);
    Point P(1, 2), Q(2.5, 2.5);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q);
    Line real_l(p1, q1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(real_l);
    std::string lvl_question = "2-4.请作出一条线段,平分图中的两个圆.";
    Level level_2(G, lvl_points, std::vector<Line>(), lvl_circles, std::vector<Point>(), lvl_reallines, std::vector<Circle>(), lvl_question, false);
    return level_2;
}