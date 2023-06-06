#pragma once
class Point {
protected:
    double x, y;
public:
    Point(double xx, double yy);
    Point(const Point& p);
    Point();
    friend class Line;
    friend const double areaOfTriangle(const Point& p1, const Point& p2, const Point& p3); //求三点所成三角形的面积
    friend const double pointsDistance(const Point& p1, const Point& p2); //求两点间距离
    friend bool pointJudge(const Point& p); //判断是否已经画出了正确答案中的点
    double getX() const; //返回x坐标
    double getY() const; //返回y坐标
    void drawPoint() const; //画点并储存
};
const double areaOfTriangle(const Point& p1, const Point& p2, const Point& p3);
const double pointsDistance(const Point& p1, const Point& p2);

class Circle :public Point {
private:
    double r;
public:
    Circle(const Point& P1, const Point& P2); //用圆心和圆上一点确定圆
    Circle(const Point& P, const double& R); //用圆心和半径确定圆
    void drawCircle() const; //把圆画出来
    friend bool circleJudge(const Circle& c);
};

class Line {
protected:
    Point p1, p2;
public:
    Line(Point P1, Point P2);
    Line(const Line& l);
    friend bool lineJudge(const int& orgnum, const Line& l);
    const Point& getP1() const;
    const Point& getP2() const;
    double lengthOfLine() const;
    bool linesCross(Line& l1) const; //判断该线段(不包括延长线)与另一线段是否有交叉点
    Point crossPoint(Line& l1) const; //求线段与另一线段的交叉点
    void drawLine() const; //画线
};

class AddLine :public Line {
protected:
    int l_n = 0; //新增线段的交点个数
public:
    AddLine(const Line& l);
    int getLn() const; //记录因新增的直线段而新生成的交叉点个数,提供给Cancel()
};
