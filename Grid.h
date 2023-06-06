#pragma once
#include <iostream>
#include <vector>
#include "Elements.h"

enum Shape { point_, line_, circle_ };  //枚举类，用于区分所画的图形

class Grid {
protected:
    int length, width;
    int startX, startY;
    int blocklength, blockwidth;
    int numX, numY; //numX是横线的条数，numY是竖线的条数
public:
    Grid(int l, int w, int X, int Y, int bl, int bw, int nX, int nY);
    Grid();
    friend Point pointToGrid(const Grid& G, const Point& p);
    void drawGrid() const; //画网格
    void createGrid() const; //创建画布，绘制网格，并储存网格线(使之可以被交叉)和格点(使之可以被点击)
};

Point pointToGrid(const Grid& G, const Point& p); //把数学坐标转化为图形界面上的坐标，仅起数学转换，便于题目设计的作用
Point pointToArray(const Point& p); //把图形界面上普通的点坐标转化为距其最近的可点击交叉点

