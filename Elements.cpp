#include <iostream>
#include <graphics.h>		
#include <conio.h>
#include <vector>
#include "Elements.h"

std::vector<Point>pointarray; //储存屏幕上可以点击并用于绘制的点
std::vector<Line>linearray; //储存画面上所有的直线段
std::vector<Circle>circlearray; //储存圆
std::vector<Point>print_points; //储存所有画出来的点

Point::Point(double xx, double yy) :x(xx), y(yy) {}
Point::Point(const Point& p) { x = p.x; y = p.y; }
Point::Point() { x = 0; y = 0; }

double Point::getX() const { return x; } 
double Point::getY() const { return y; } 
void Point::drawPoint() const{ 
    print_points.push_back(*this); //储存画出的点
    fillcircle(int(x + 0.5), int(y + 0.5), 2); 
}
const double areaOfTriangle(const Point& p1, const Point& p2, const Point& p3) { 
    double dx1 = p2.x - p1.x, dy1 = p2.y - p1.y, 
           dx2 = p3.x - p1.x, dy2 = p3.y - p1.y;
    double _S = 0.5 * (dx1 * dy2 - dy1 * dx2);
    double S = _S >= 0 ? _S : -_S;
    return S;
}
const double pointsDistance(const Point& p1, const Point& p2) { 
    double l = sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
    return l;
}

Circle::Circle(const Point& P1, const Point& P2) :Point(P1) { //用圆心和圆上一点确定圆
    Line l(P1, P2);
    r = l.lengthOfLine();
}
Circle::Circle(const Point& P, const double& R) :Point(P), r(R) { } //用圆心和半径确定圆

void Circle::drawCircle() const { //把圆画出来
    circle(int(x + 0.5), int(y + 0.5), int(r + 0.5));
}

Line::Line(Point P1, Point P2) :p1(P1), p2(P2) {}
Line::Line(const Line& l) :p1(l.p1), p2(l.p2) {}
const Point& Line::getP1() const { return p1; }
const Point& Line::getP2() const { return p2; }
double Line::lengthOfLine() const { //求线段长
    return pointsDistance(p1, p2);
}
bool Line::linesCross(Line& l1) const { 
    double mx = l1.p1.x;
    double my = l1.p1.y;
    double nx = l1.p2.x;
    double ny = l1.p2.y;
    double px = p1.x;
    double py = p1.y;
    double qx = p2.x;
    double qy = p2.y;
    return ((my - ny) * px + (nx - mx) * py + mx * ny - nx * my)
         * ((my - ny) * qx + (nx - mx) * qy + mx * ny - nx * my) < 0
        && ((py - qy) * mx + (qx - px) * my + px * qy - qx * py)
         * ((py - qy) * nx + (qx - px) * ny + px * qy - qx * py) < 0;
}
Point Line::crossPoint(Line& l1) const { 
    double k = areaOfTriangle(p1, p2, l1.p1) / areaOfTriangle(p1, p2, l1.p2); //k是面积的比值，也是交点的分比
    double crossX = l1.p1.x * (1 / (k + 1)) + l1.p2.x * (k / (k + 1));
    double crossY = l1.p1.y * (1 / (k + 1)) + l1.p2.y * (k / (k + 1));
    Point crosspoint(crossX, crossY);
    return crosspoint;
}
void Line::drawLine() const{
    int px1 = int(p1.getX() + 0.5),
        py1 = int(p1.getY() + 0.5),
        px2 = int(p2.getX() + 0.5),
        py2 = int(p2.getY() + 0.5);

    line(px1, py1, px2, py2);
}

AddLine::AddLine(const Line& l) :Line(l) {
    int thiscross = 0;
    for (int i = 0;i < linearray.size();i++) {
        if (l.linesCross(linearray[i])) {
            Point P(int(l.crossPoint(linearray[i]).getX() + 0.5),
                int(l.crossPoint(linearray[i]).getY() + 0.5));
            pointarray.push_back(P);
            thiscross++;
        }
    }
    l_n = thiscross;
}

int AddLine::getLn() const { return l_n; } //记录因新增的直线段而新生成的交叉点个数,提供给Cancel()
