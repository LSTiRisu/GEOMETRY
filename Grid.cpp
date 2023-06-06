#include <graphics.h>		
#include <conio.h>
#include <vector>
#include "Grid.h"

extern std::vector<Point>pointarray;
extern std::vector<Point>print_points;
extern std::vector<Line>linearray;
extern std::vector<Circle>circlearray;
std::vector<AddLine>add_lines; //储存画线操作
std::vector<Shape>operations; //储存各步操作所画图形的类型

Grid::Grid(int l, int w, int X, int Y, int bl, int bw, int nX, int nY) :
    length(l), width(w),
    startX(X), startY(Y),
    blocklength(bl), blockwidth(bw),
    numX(nX), numY(nY) {}
Grid::Grid() :
    length(480), width(480),
    startX(40), startY(40),
    blocklength(100), blockwidth(100),
    numX(5), numY(5) {}
void Grid::drawGrid() const { 
    int x = startX, y = startY;
    for (int i = 0; i < numX; i++) {
        Point A1(startX, y), A2(startX + (numY - 1) * blocklength, y);
        Line l_A(A1, A2);
        line(startX, y, startX + (numY - 1) * blocklength, y);
        y += blockwidth;
    }
    for (int j = 0; j < numY; j++) {
        Point B1(x, startY), B2(x, startY + (numX - 1) * blockwidth);
        Line l_B(B1, B2);
        line(x, startY, x, startY + (numX - 1) * blockwidth);
        x += blocklength;
    }
}
void Grid::createGrid() const {
    initgraph(length, width);
    setbkcolor(WHITE);
    cleardevice();
    setlinecolor(BLUE);
    setfillcolor(BLUE);
    int x = startX, y = startY;
    for (int i = 0; i < numX; i++) {//画横线并储存
        Point A1(startX, y), A2(startX + (numY - 1) * blocklength, y);
        Line l_A(A1, A2);
        linearray.push_back(l_A);
        line(startX, y, startX + (numY - 1) * blocklength, y);
        y += blockwidth;
    }
    for (int j = 0; j < numY; j++) {//画竖线并储存
        Point B1(x, startY), B2(x, startY + (numX - 1) * blockwidth);
        Line l_B(B1, B2);
        linearray.push_back(l_B);
        line(x, startY, x, startY + (numX - 1) * blockwidth);
        x += blocklength;
    }
    for (int i = 0;i < numX;i++) {//储存所有格点
        for (int j = 0;j < numY;j++) {
            Point Q(startX + j * blocklength + 0.0, startY + i * blockwidth + 0.0);
            pointarray.push_back(Q);
        }
    }
}
Point pointToGrid(const Grid& G, const Point& p) {//把数学坐标转化为图形界面坐标
    Point q(G.startX + p.getX() * G.blocklength, G.startY + p.getY() * G.blockwidth);
    return q;
}
Point pointToArray(const Point& p) { //把图形界面上普通的点坐标转化为距其最近的可点击交叉点
    double X = p.getX(), Y = p.getY();
    double distance = 96000;
    Point nearest;
    for (int i = 0;i < pointarray.size();i++) {
        if (pointsDistance(p, pointarray[i]) < distance) {
            distance = pointsDistance(p, pointarray[i]);
            nearest = pointarray[i];
        }
    }
    Point Q(nearest.getX(), nearest.getY());
    return Q;
}


