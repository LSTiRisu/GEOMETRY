#include <iostream>
#include <graphics.h>		
#include <conio.h>
#include <vector>
#include "Level.h"

const Level level_6_1() {
    Grid G(640, 640, 40, 40, 80, 80, 8, 8);
    Point A(3.5, 3), B(4, 4);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B);
    std::vector<Point>lvl_points;
    lvl_points.push_back(b1);
    Circle Ca1(a1, 200);
    std::vector<Circle>lvl_circles;
    lvl_circles.push_back(Ca1);
    Point P(5, 1), Q(2, 5), R(5, 5), S(1, 3), T(6, 3), U(4.2, 5.4);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q);
    Point r1 = pointToGrid(G, R), s1 = pointToGrid(G, S);
    Point t1 = pointToGrid(G, T), u1 = pointToGrid(G, U);
    Line PQ(p1, q1), PR(p1, r1), QR(q1, r1), ST(s1, t1), SU(s1, u1), TU(t1, u1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(PQ);
    lvl_reallines.push_back(PR);
    lvl_reallines.push_back(QR);
    lvl_reallines.push_back(ST);
    lvl_reallines.push_back(SU);
    lvl_reallines.push_back(TU);
    std::string lvl_question = "6-1.��ֱ֪����������ͼ��ԲΪ���Բ,��ɫ��Ϊ����.��������������������.";
    Level level_6(G, lvl_points, std::vector<Line>(), lvl_circles, std::vector<Point>(), lvl_reallines, std::vector<Circle>(), lvl_question, false);
    return level_6;
}

const Level level_6_2() {
    Grid G(560, 560, 40, 40, 40, 40, 13, 13);
    Point A(2, 12), B(6, 9), C(7, 8.25);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B), c1 = pointToGrid(G, C);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    lvl_points.push_back(b1);
    lvl_points.push_back(c1);
    Line AC(a1, c1);
    std::vector<Line>lvl_lines;
    lvl_lines.push_back(AC);
    Point P(12, 12), Q(4.8, 2.4);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q);
    Line AQ(a1, q1), AP(a1, p1), PQ(p1, q1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(AP);
    lvl_reallines.push_back(AQ);
    lvl_reallines.push_back(PQ);
    std::string lvl_question = "6-2.ͼ�������Ĺ����������������������Ϊ�����εĶ���,���ĺ�����.��������������������.";
    Level level_6(G, lvl_points, lvl_lines, std::vector<Circle>(), std::vector<Point>(), lvl_reallines, std::vector<Circle>(), lvl_question, false);
    return level_6;
}

const Level level_6_3() {
    Grid G;
    Point A(2, 0), B(1, 1), C(2, 4), D(3, 3);
    Point a1 = pointToGrid(G, A), b1 = pointToGrid(G, B), c1 = pointToGrid(G, C), d1 = pointToGrid(G, D);
    std::vector<Point>lvl_points;
    lvl_points.push_back(a1);
    lvl_points.push_back(b1);
    lvl_points.push_back(c1);
    lvl_points.push_back(d1);
    Line AB(a1, b1), BC(b1, c1), CD(c1, d1), DA(d1, a1);
    std::vector<Line>lvl_lines;
    lvl_lines.push_back(AB);
    lvl_lines.push_back(BC);
    lvl_lines.push_back(CD);
    lvl_lines.push_back(DA);
    Point P(2, 1), Q(4, 1), R(2, 3), S(0, 3);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q), r1 = pointToGrid(G, R), s1 = pointToGrid(G, S);
    Line PQ(p1, q1), QR(q1, r1), RS(r1, s1), SP(s1, p1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(PQ);
    lvl_reallines.push_back(QR);
    lvl_reallines.push_back(RS);
    lvl_reallines.push_back(SP);
    std::string lvl_question = "6-3.��֪ƽ���ı��ε����Ĺ����������ߵĶԳƵ��γ���ͼ�е���ƽ���ı���.��ԭ����ƽ���ı���.";
    Level level_6(G, lvl_points, lvl_lines, std::vector<Point>(), lvl_reallines, lvl_question, false);
    return level_6;
}

const Level level_6_4() {
    Grid G(560, 560, 40, 40, 40, 40, 13, 13);
    Point A(3, 2), B(3, 10), C(11, 6);
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
    Point P(0, 6), Q(8, 2), R(8, 10);
    Point p1 = pointToGrid(G, P), q1 = pointToGrid(G, Q), r1 = pointToGrid(G, R);
    Line PQ(p1, q1), PR(p1, r1), QR(q1, r1);
    std::vector<Line>lvl_reallines;
    lvl_reallines.push_back(PQ);
    lvl_reallines.push_back(PR);
    lvl_reallines.push_back(QR);
    std::string lvl_question = "6-4.��֪���������Ĺ��������ߵĶԳƵ��γ�ͼ�е���������.��ԭ����������.";
    Level level_6(G, lvl_points, lvl_lines, std::vector<Point>(), lvl_reallines, lvl_question, false);
    return level_6;
}
