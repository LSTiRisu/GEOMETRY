#pragma once
class Point {
protected:
    double x, y;
public:
    Point(double xx, double yy);
    Point(const Point& p);
    Point();
    friend class Line;
    friend const double areaOfTriangle(const Point& p1, const Point& p2, const Point& p3); //���������������ε����
    friend const double pointsDistance(const Point& p1, const Point& p2); //����������
    friend bool pointJudge(const Point& p); //�ж��Ƿ��Ѿ���������ȷ���еĵ�
    double getX() const; //����x����
    double getY() const; //����y����
    void drawPoint() const; //���㲢����
};
const double areaOfTriangle(const Point& p1, const Point& p2, const Point& p3);
const double pointsDistance(const Point& p1, const Point& p2);

class Circle :public Point {
private:
    double r;
public:
    Circle(const Point& P1, const Point& P2); //��Բ�ĺ�Բ��һ��ȷ��Բ
    Circle(const Point& P, const double& R); //��Բ�ĺͰ뾶ȷ��Բ
    void drawCircle() const; //��Բ������
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
    bool linesCross(Line& l1) const; //�жϸ��߶�(�������ӳ���)����һ�߶��Ƿ��н����
    Point crossPoint(Line& l1) const; //���߶�����һ�߶εĽ����
    void drawLine() const; //����
};

class AddLine :public Line {
protected:
    int l_n = 0; //�����߶εĽ������
public:
    AddLine(const Line& l);
    int getLn() const; //��¼��������ֱ�߶ζ������ɵĽ�������,�ṩ��Cancel()
};
