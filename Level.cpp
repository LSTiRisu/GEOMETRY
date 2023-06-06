#include <iostream>
#include <graphics.h>		
#include <conio.h>
#include <vector>
#include "Level.h"
#include "Update.h"

extern std::vector<Point>pointarray;
extern std::vector<Line>linearray;
extern std::vector<Circle>circlearray;
extern std::vector<Point>print_points;
extern std::vector<AddLine>add_lines;
extern std::vector<Shape>operations;

const int LVL_SUM_1 = 6, LVL_SUM_2 = 4;
Level LEVELS[LVL_SUM_1][LVL_SUM_2] = 
  { {level_1_1(),level_1_2(),level_1_3(),level_1_4()},
    {level_2_1(),level_2_2(),level_2_3(),level_2_4()},
    {level_3_1(),level_3_2(),level_3_3(),level_3_4()},
    {level_4_1(),level_4_2(),level_4_3(),level_4_4()},
    {level_5_1(),level_5_2(),level_5_3(),level_5_4()},
    {level_6_1(),level_6_2(),level_6_3(),level_6_4()} }; //��Źؿ���������

Level::Level(const Grid& G,   //��Բ�Ĺ��캯��
    const std::vector<Point>& vP, 
    const std::vector<Line>& vL, 
    const std::vector<Circle>& vC,
    const std::vector<Point>& aP,
    const std::vector<Line>& aL, 
    const std::vector<Circle>& aC, 
    const std::string& s, 
    const bool& cA) :
    Grid(G), 
    starterpoints(vP),
    starterlines(vL),
    startercircles(vC),
    answerpoints(aP), 
    answerlines(aL), 
    answercircles(aC), 
    question(s), 
    circleAllowed(cA) {} 
Level::Level(const Grid& G, //����Բ�Ĺ��캯��
    const std::vector<Point>& vP, 
    const std::vector<Line>& vL,
    const std::vector<Point>& aP,
    const std::vector<Line>& aL,
    const std::string& s,
    const bool& cA) :
    Grid(G), 
    starterpoints(vP), 
    starterlines(vL), 
    answerpoints(aP), 
    answerlines(aL), 
    question(s), 
    circleAllowed(cA) {} 
void Level::Start(){ 
    createGrid(); 
    setlinecolor(RED);
    setfillcolor(RED);
    for (int i = 0;i < starterpoints.size();i++) { //���Ƴ�ʼ�㲢����(��ɫ)
        pointarray.push_back(starterpoints[i]);
        starterpoints[i].drawPoint();
    }
    for (int i = 0;i < starterlines.size();i++) { //���Ƴ�ʼ�߶β�����(��ɫ)
        linearray.push_back(starterlines[i]);
        AddLine(Al)(starterlines[i]);
        add_lines.push_back(Al);
        starterlines[i].drawLine();
    }
    setlinecolor(BLUE);
    setfillcolor(BLUE);
    for (int i = 0;i < startercircles.size();i++) { //���Ƴ�ʼԲ������(��ɫ)
        circlearray.push_back(startercircles[i]);
        startercircles[i].drawCircle();
    }
    start = clock();//��ʼ��ʱ
}
void Level::Restart() {
    Swap(); //����ڴ�
    clearrectangle(0, 0, length, width); //��������
    Start(); //��ʼ
}
void Level::mouseLoop() {
    Point M, array_M;
    ExMessage m;
    while (true) {  //��һ��ѭ����,mΪ��ȡ�����ⲿ��Ϣ
        m = getmessage(EX_MOUSE | EX_KEY);
        if (m.message == WM_LBUTTONDOWN || m.message == WM_RBUTTONDOWN || m.vkcode == 0x08 || m.vkcode == 0x1B) { //��һ����
            if (m.message == WM_LBUTTONDOWN) {
                Point M1(m.x, m.y);
                M = M1;
                array_M = pointToArray(M);
                array_M.drawPoint(); //������һ���㲢����
                break;
            }
            else if (m.message == WM_RBUTTONDOWN) {
                Cancel();
                break;
            }
            else if (m.vkcode == 0x08) {
                Restart();
                break;
            }
            else if (m.vkcode == 0x1B) {
                Swap();
                closegraph();
                std::cout << "��Ϸ���˳�,��رտ���̨.��ӭ�´�����." << std::endl;
                break;
            }
        }
    }
    while (true) { //�ڶ���ѭ���壬nΪ��ȡ�����ⲿ��Ϣ
        if (m.message == WM_RBUTTONDOWN || m.vkcode == 0x08 || m.vkcode == 0x1B) {
            break;
        }
        ExMessage n = getmessage(EX_MOUSE);
        if (n.message == WM_LBUTTONDOWN || n.message == WM_RBUTTONDOWN) { //�ڶ�����
            if (n.message == WM_LBUTTONDOWN) {
                Point N(n.x, n.y), array_N = pointToArray(N);
                if ((array_N.getX() - array_M.getX()) * (array_N.getX() - array_M.getX()) +
                    (array_N.getY() - array_M.getY()) * (array_N.getY() - array_M.getY()) > 1) { //�������㲻�غϵ������
                    array_N.drawPoint();
                    Line L(array_M, array_N);
                    linearray.push_back(L);
                    AddLine AL(L);
                    add_lines.push_back(AL);
                    L.drawLine();  //�����߶�
                    operations.push_back(line_);
                    break;
                }
                else { //����������غϾͲ��ٶ���ֱ�Ӽ�¼����
                    operations.push_back(point_);
                    break;
                }
            }
            else if (n.message == WM_RBUTTONDOWN && circleAllowed) { //ȷ��Բ�ĵڶ�����
                Point N(n.x, n.y), array_N = pointToArray(N);
                if ((array_N.getX() - array_M.getX()) * (array_N.getX() - array_M.getX()) +
                    (array_N.getY() - array_M.getY()) * (array_N.getY() - array_M.getY()) > 1) { //�������㲻�غϵ��������Բ      
                    Circle C(array_M, array_N);
                    circlearray.push_back(C);
                    C.drawCircle();  //����Բ
                    operations.push_back(circle_);
                    break;
                }
                else { //�����غ�����Ϊ���Ƶ�����
                    operations.push_back(point_);
                    break;
                }
            }
            else if (n.message == WM_RBUTTONDOWN && !circleAllowed) { //������Բ�������,��������һ�Ҳ��Ϊ���Ƶ�����
                operations.push_back(point_);
                break;
            }
        }
    }
}
double Level::Loop() {
    while (true) {
        mouseLoop();
        if (levelJudge()) { //����ؿ�ͨ��,�������д�ͼ��
            setlinecolor(GREEN);
            setfillcolor(GREEN);
            for (int i = 0;i < answerpoints.size();i++) { //��
                answerpoints[i].drawPoint();
            }
            for (int i = 0;i < answerlines.size();i++) { //��(���˵�)
                answerlines[i].drawLine();
                fillcircle(int(answerlines[i].getP1().getX() + 0.5), int(answerlines[i].getP1().getY() + 0.5), 2);
                fillcircle(int(answerlines[i].getP2().getX() + 0.5), int(answerlines[i].getP2().getY() + 0.5), 2);
            }
            for (int i = 0;i < answercircles.size();i++) {//Բ
                answercircles[i].drawCircle();
            }
            setfillcolor(BLUE);
            setlinecolor(BLUE);
            end = clock(); //ֹͣ��ʱ
            break;
        }
    }
    double timecost = (double)(end - start) / CLOCKS_PER_SEC; //������ʱ
    std::cout << "��,������ɱ���,��ʱ" << int(timecost) << "��,���ò���Ϊ" << operations.size() << "." << std::endl;
    return timecost;
}
void Level::Cancel() const {
    if (operations.size() > 0) {
        clearrectangle(0, 0, length, width);
        switch (operations[operations.size() - 1]) { //operations[0]��Ӧ��operationnumberΪ1,ָ��Ϊ(���� - 1)
        case point_: {
            print_points.pop_back(); //ȥ������ĵ�
            break;
        }
        case line_: {
            print_points.pop_back(); //ȥ���ڶ�������ĵ�
            print_points.pop_back(); //ȥ����һ������ĵ�
            linearray.pop_back(); //ȥ��Line����߶���
            int m = add_lines[add_lines.size() - 1].getLn();
            for (int i = 0;i < m;i++) {
                pointarray.pop_back(); //��һȥ�������ɵĽ����
            }
            add_lines.pop_back(); //ȥ��AddLine�����
            break;
        }
        case circle_: {
            print_points.pop_back(); //ȥ������ĵ�
            circlearray.pop_back(); //ȥ��������Բ
            break;
        }
        }
        operations.pop_back(); //������һ������
        for (int i = 0;i < circlearray.size();i++) { //���»�Բ
            circlearray[i].drawCircle();
        }

        for (int i = 0;i < numX + numY;i++) { //���»�������
            linearray[i].drawLine();
        }
        for (int i = numX + numY;i < numX + numY + starterlines.size();i++) { //���»���Ŀ��ʼͼ��
            setlinecolor(RED);
            setfillcolor(RED);
            linearray[i].drawLine();
            setlinecolor(BLUE);
            setfillcolor(BLUE);
        }
        for (int i = numX + numY + starterlines.size();i < linearray.size();i++) {//���»�������֮ǰ���Ƶ���
            linearray[i].drawLine();
        }

        for (int i = 0;i < starterpoints.size();i++) { //���»���Ŀ��ʼ��
            setlinecolor(RED);
            setfillcolor(RED);
            fillcircle(int(print_points[i].getX() + 0.5), int(print_points[i].getY() + 0.5), 2);
            setlinecolor(BLUE);
            setfillcolor(BLUE);
        }
        for (int i = starterpoints.size();i < print_points.size();i++) { //���»�������֮ǰ���Ƶĵ�
            fillcircle(int(print_points[i].getX() + 0.5), int(print_points[i].getY() + 0.5), 2);
        }
    }
}
bool Level::levelJudge() const {
    bool levelclear = true;
    for (int i = 0;i < answerpoints.size();i++) {
        if (!pointJudge(answerpoints[i]))levelclear = false;
    }
    for (int i = 0;i < answerlines.size();i++) {
        if (!lineJudge(numX + numY + starterlines.size(), answerlines[i]))levelclear = false;
    }
    for (int i = 0;i < answercircles.size();i++) {
        if (!circleJudge(answercircles[i]))levelclear = false;
    }
    return levelclear;
}

bool pointJudge(const Point& p) {
    for (int i = 0;i < print_points.size();i++) {
        bool pointCoincide =
            (print_points[i].x - p.x) * (print_points[i].x - p.x) +
            (print_points[i].y - p.y) * (print_points[i].y - p.y) < 1;
        if (pointCoincide) {
            return true;
        }
    }
    return false;
}
bool lineJudge(const int& orgnum, const Line& l) {
    for (int i = orgnum;i < linearray.size();i++) {
        bool lineCoincide =
            (linearray[i].p1.getX() - linearray[i].p2.getX()) * (l.p1.getY() - l.p2.getY()) -
            (linearray[i].p1.getY() - linearray[i].p2.getY()) * (l.p1.getX() - l.p2.getX()) < 1 &&
            areaOfTriangle(l.p1, l.p2, linearray[i].p1) < 1 &&
            areaOfTriangle(l.p1, l.p2, linearray[i].p2) < 1;
        if (lineCoincide) {
            return true;
        }
    }
    return false;
}
bool circleJudge(const Circle& c) {
    for (int i = 0;i < circlearray.size();i++) {
        bool circleCoincide =
            (circlearray[i].x - c.x) * (circlearray[i].x - c.x) +
            (circlearray[i].y - c.y) * (circlearray[i].y - c.y) < 1 &&
            (circlearray[i].r - c.r) * (circlearray[i].r - c.r) < 1;
        if (circleCoincide) {
            return true;
        }
    }
    return false;
}
void Swap() {
    std::vector<Point>().swap(pointarray);
    std::vector<Line>().swap(linearray);
    std::vector<Circle>().swap(circlearray);
    std::vector<Point>().swap(print_points);
    std::vector<AddLine>().swap(add_lines);
    std::vector<Shape>().swap(operations);
}
void Run(int Lvlnum1, int Lvlnum2) {
    std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << LEVELS[Lvlnum1 - 1][Lvlnum2 - 1].question << std::endl;
    LEVELS[Lvlnum1-1][Lvlnum2-1].Start();
    LEVELS[Lvlnum1-1][Lvlnum2-1].Loop();
    Update(LVL_SUM_2 * (Lvlnum1 - 1) + Lvlnum2);
    Swap();
    std::cout << "�����������..." << std::endl;
    _getch();
    closegraph();
    if (Lvlnum2 < LVL_SUM_2) { //�л��ؿ��ж�
        std::cout << "�Ƿ������һ��? (�� Enter|�� Esc)" << std::endl;
        while (true) {
            char key = _getch();
            if (key == 13) { 
                Run(Lvlnum1, Lvlnum2 + 1); 
                break;
            }
            else if (key == 27) {
                break;
            }
        }
    }
    else { //�������С����ʾ�˳�
        std::cout << "��,���Ѿ�����˱���ص�����С��.�밴Esc�˳�." << std::endl;
        while (true) {
            char key = _getch();
            if (key == 27) {
                break;
            }
        }
    }
}


