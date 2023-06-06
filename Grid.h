#pragma once
#include <iostream>
#include <vector>
#include "Elements.h"

enum Shape { point_, line_, circle_ };  //ö���࣬��������������ͼ��

class Grid {
protected:
    int length, width;
    int startX, startY;
    int blocklength, blockwidth;
    int numX, numY; //numX�Ǻ��ߵ�������numY�����ߵ�����
public:
    Grid(int l, int w, int X, int Y, int bl, int bw, int nX, int nY);
    Grid();
    friend Point pointToGrid(const Grid& G, const Point& p);
    void drawGrid() const; //������
    void createGrid() const; //�����������������񣬲�����������(ʹ֮���Ա�����)�͸��(ʹ֮���Ա����)
};

Point pointToGrid(const Grid& G, const Point& p); //����ѧ����ת��Ϊͼ�ν����ϵ����꣬������ѧת����������Ŀ��Ƶ�����
Point pointToArray(const Point& p); //��ͼ�ν�������ͨ�ĵ�����ת��Ϊ��������Ŀɵ�������

