#include <iostream>
#include <graphics.h>		
#include <conio.h>
#include <vector>
#include "Level.h"

const Level level_3_1() {
    Grid G(720, 720, 60, 60, 100, 100, 7, 7);
    Point A(2, 3), B(4, 2), C(3, 2.5);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B), c1 = pointToGrid(G, C);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    lvl_points.push_back(b1);
    Circle Ca1(a1, c1), Cb1(b1, c1);
    std::vector<Circle>lvl_circles;
    lvl_circles.push_back(Ca1);
    lvl_circles.push_back(Cb1);
    Point P(1.75, 0), Q(4.75, 6), R(0, 2.75), S(5.5, 0), T(0, 5.25), U(6, 2.25);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q), 
          r1 = pointToGrid(G, R), s1 = pointToGrid(G, S), 
          t1 = pointToGrid(G, T), u1 = pointToGrid(G, U);
    Line PQ(p1, q1), RS(r1, s1), TU(t1, u1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(PQ);
    lvl_reallines.push_back(RS);
    lvl_reallines.push_back(TU);
    std::string lvl_question = "3-1.请作出图中两个圆的全部公切线.";
    Level level_3(G, lvl_points, std::vector<Line>(), lvl_circles, 
        std::vector<Point>(), lvl_reallines, std::vector<Circle>(), lvl_question, false);
    return level_3;
}

const Level level_3_2() {
    Grid G(720, 720, 60, 60, 100, 100, 7, 7);
    Point A(2, 3), B(4, 2);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    lvl_points.push_back(b1);
    Circle Ca1(a1, 100), Cb1(b1, 100);
    std::vector<Circle>lvl_circles;
    lvl_circles.push_back(Ca1);
    lvl_circles.push_back(Cb1);
    Point P(3, 0), Q(3, 6), R(0, 0.25), S(6, 4.75);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q),
        r1 = pointToGrid(G, R), s1 = pointToGrid(G, S);
    Line PQ(p1, q1), RS(r1, s1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(PQ);
    lvl_reallines.push_back(RS);
    std::string lvl_question = "3-2.请作出图中两个圆的全部内公切线.";
    Level level_3(G, lvl_points, std::vector<Line>(), lvl_circles,
        std::vector<Point>(), lvl_reallines, std::vector<Circle>(), lvl_question, false);
    return level_3;
}

const Level level_3_3() {
    Grid G(720, 720, 60, 60, 100, 100, 7, 7);
    Point A(1, 1), B(2, 4);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    Circle Cb1(b1, 100);
    std::vector<Circle>lvl_circles;
    lvl_circles.push_back(Cb1);
    Point M(1, 4), N(2.8, 3.4);
    Point m1 = pointToGrid(G, M), n1 = pointToGrid(G, N);
    std::vector<Point>lvl_realpoints;
    lvl_realpoints.push_back(m1);
    lvl_realpoints.push_back(n1);
    Point P(1, 1), Q(1, 5), R(1, 1), S(4, 5);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q),
          r1 = pointToGrid(G, R), s1 = pointToGrid(G, S);
    Line PQ(p1, q1), RS(r1, s1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(PQ);
    lvl_reallines.push_back(RS);
    std::string lvl_question = "3-3.过图上的红点作圆的两条切线,并标记切点.";
    Level level_3(G, lvl_points, std::vector<Line>(), lvl_circles,
        lvl_realpoints, lvl_reallines, std::vector<Circle>(), lvl_question, false);
    return level_3;
}

const Level level_3_4() {
    Grid G(800, 400, 40, 40, 80, 80, 5, 10);
    Point A(2, 2), B(7, 2);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    lvl_points.push_back(b1);
    Point C(2.5, 1), D(6.5, 1);
    Point c1 = pointToGrid(G, C), d1 = pointToGrid(G, D);
    Circle Ca1(a1, c1), Cb1(b1, d1);
    double radius = pointsDistance(A, C);
    std::vector<Circle>lvl_circles;
    lvl_circles.push_back(Ca1);
    lvl_circles.push_back(Cb1);
    Point P(2, 2-radius), Q(7, 2-radius), R(2, 2+radius), S(7, 2+radius), T(6.5, 3), U(2.5, 3);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q),
          r1 = pointToGrid(G, R), s1 = pointToGrid(G, S),
          t1 = pointToGrid(G, T), u1 = pointToGrid(G, U);
    lvl_points.push_back(p1);
    lvl_points.push_back(q1);
    lvl_points.push_back(r1);
    lvl_points.push_back(s1);
    Line PQ(p1, q1), RS(r1, s1), CT(c1, t1), DU(d1, u1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(PQ);
    lvl_reallines.push_back(RS);
    lvl_reallines.push_back(CT);
    lvl_reallines.push_back(DU);
    std::string lvl_question = "3-4.请作出图中两个圆的全部公切线.";
    Level level_3(G, lvl_points, std::vector<Line>(), lvl_circles,
        std::vector<Point>(), lvl_reallines, std::vector<Circle>(), lvl_question, false);
    return level_3;
}
