#include <iostream>
#include <graphics.h>		
#include <conio.h>
#include <vector>
#include "Level.h"

const Level level_5_1() {
    Grid G(720, 720, 60, 60, 100, 100, 7, 7);
    Point A(4, 0), B(3, 2), C(4, 2);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B), c1 = pointToGrid(G, C);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    lvl_points.push_back(b1);
    lvl_points.push_back(c1);
    Line L1(a1, b1), L2(a1, c1), L3(b1, c1);
    std::vector<Line>lvl_lines;
    lvl_lines.push_back(L1);
    lvl_lines.push_back(L2);
    lvl_lines.push_back(L3);
    Point P(10.0/3, 4.0/3), Q(2, 4);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q);
    Circle Cp1(p1, 200.0 / 3), Cq1(q1, 200);
    std::vector<Circle>lvl_realcircles;
    lvl_realcircles.push_back(Cp1);
    lvl_realcircles.push_back(Cq1);
    std::string lvl_question = "5-1.图中给出了一个直角三角形.请在其斜边所在直线上取点作圆,与两直角边所在直线均相切.";
    Level level_5(G, lvl_points, lvl_lines, std::vector<Circle>(), std::vector<Point>(), std::vector<Line>(), lvl_realcircles, lvl_question, true);
    return level_5;
}

const Level level_5_2() {
    Grid G(648, 648, 36, 36, 36, 36, 17, 17);
    Point A(8, 1), B(3, 13), C(13, 13);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B), c1 = pointToGrid(G, C);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    lvl_points.push_back(b1);
    lvl_points.push_back(c1);
    Line L1(a1, b1), L2(a1, c1), L3(b1, c1);
    std::vector<Line>lvl_lines;
    lvl_lines.push_back(L1);
    lvl_lines.push_back(L2);
    lvl_lines.push_back(L3);
    Point P(8, 8 + 1.0 / 24), Q(8, 10 - 1.0 / 3);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q);
    Circle Cp1(p1, 253.5), Cq1(q1, 120);
    std::vector<Circle>lvl_realcircles;
    lvl_realcircles.push_back(Cp1);
    lvl_realcircles.push_back(Cq1);
    std::string lvl_question = "5-2.作出图中三角形的内切圆和外接圆.";
    Level level_5(G, lvl_points, lvl_lines, std::vector<Circle>(), std::vector<Point>(), std::vector<Line>(), lvl_realcircles, lvl_question, true);
    return level_5;
}

const Level level_5_3() {
    Grid G(648, 648, 36, 36, 36, 36, 17, 17);
    Point A(8, 1), B(3, 13), C(13, 13);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B), c1 = pointToGrid(G, C);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    lvl_points.push_back(b1);
    lvl_points.push_back(c1);
    Line L1(a1, b1), L2(a1, c1), L3(b1, c1);
    std::vector<Line>lvl_lines;
    lvl_lines.push_back(L1);
    lvl_lines.push_back(L2);
    lvl_lines.push_back(L3);
    Point P(3, 3 + 1.0 / 12), Q(13, 3 + 1.0 / 12), R(8, 15 + 1.0 / 12);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q), r1 = pointToGrid(G, R);
    Line PA(p1, a1), PB(p1, b1), PC(p1, c1), QA(q1, a1), QB(q1, b1), QC(q1, c1), RA(r1, a1), RB(r1, b1), RC(r1, c1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(PA);
    lvl_reallines.push_back(PB);
    lvl_reallines.push_back(PC);
    lvl_reallines.push_back(QA);
    lvl_reallines.push_back(QB);
    lvl_reallines.push_back(QC);
    lvl_reallines.push_back(RA);
    lvl_reallines.push_back(RB);
    lvl_reallines.push_back(RC);
    lvl_reallines.push_back(L1);
    lvl_reallines.push_back(L2);
    lvl_reallines.push_back(L3);
    std::string lvl_question = "5-3.作出与图中三角形共用外接圆的直角三角形.";
    Level level_5(G, lvl_points, lvl_lines, std::vector<Point>(), lvl_reallines, lvl_question, false);
    return level_5;
}

const Level level_5_4() {
    Grid G(792, 612, 36, 36, 36, 36, 16, 21);
    Point A(10, 1), B(6, 9), C(14, 9);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B), c1 = pointToGrid(G, C);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    lvl_points.push_back(b1);
    lvl_points.push_back(c1);
    Line L1(a1, b1), L2(a1, c1), L3(b1, c1);
    std::vector<Line>lvl_lines;
    lvl_lines.push_back(L1);
    lvl_lines.push_back(L2);
    lvl_lines.push_back(L3);
    Point P(0, 1), Q(20, 1), R(10, 14 + 1.0 / 3);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q), r1 = pointToGrid(G, R);
    Line PQ(p1, q1), PR(p1, r1), QR(q1, r1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(PQ);
    lvl_reallines.push_back(PR);
    lvl_reallines.push_back(QR);
    std::string lvl_question = "5-4.图中给出了一个三角形.另求一个三角形,其三边分别过图中三角形的三个顶点,且其内切圆是图中三角形的外接圆.";
    Level level_5(G, lvl_points, lvl_lines, std::vector<Point>(), lvl_reallines, lvl_question, false);
    return level_5;
}

