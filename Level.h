#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include "Grid.h"
class Level :public Grid {
protected:
    std::string question;
    std::vector<Point>starterpoints;
    std::vector<Line>starterlines;
    std::vector<Circle>startercircles;
    std::vector<Point>answerpoints;
    std::vector<Line>answerlines;
    std::vector<Circle>answercircles;
    clock_t start = 0, end = 0;
    bool circleAllowed; //����Բ���
public:
    Level(const Grid& G, const std::vector<Point>& vP, const std::vector<Line>& vL, const std::vector<Circle>& vC, 
        const std::vector<Point>& aP, const std::vector<Line>& aL, const std::vector<Circle>& aC, const std::string& s, const bool& cA); //��Բ�Ĺ��캯��
    Level(const Grid& G, const std::vector<Point>& vP, const std::vector<Line>& vL,
        const std::vector<Point>& aP, const std::vector<Line>& aL, const std::string& s, const bool& cA);  //����Բ�Ĺ��캯��
    friend void Run(int Lvlnum1, int Lvlnum2);
    void Start();  //��ʼ��Ϸ(���޸Ŀ�ʼ��ʱ��ʱ��,����const)
    void Restart();  //���¿�ʼ(�����Start(),����const)
    void mouseLoop();  //������ѭ��(�����Restart(),����const)
    double Loop(); //���ڴ�ѭ��,��������ʱ��(���޸Ľ�ֹ��ʱ��ʱ��,����const)
    void Cancel() const;  //ȡ����һ������
    bool levelJudge() const; //�ж���Ŀ�Ƿ����
};

bool pointJudge(const Point& p); //�жϵ��Ƿ�����ȷ���غ�
bool lineJudge(const int& orgnum, const Line& l); //�ж��߶��Ƿ�����ȷ���غ�
bool circleJudge(const Circle& c); //�ж�Բ�Ƿ�����ȷ���غ�

void Swap(); //���vector,�����ڴ�Ļ���
void Run(int Lvlnum1, int Lvlnum2); //��ÿ�شӿ�ʼ��������ȫ���

const Level level_1_1();
const Level level_1_2();
const Level level_1_3();
const Level level_1_4();

const Level level_2_1();
const Level level_2_2();
const Level level_2_3();
const Level level_2_4();

const Level level_3_1();
const Level level_3_2();
const Level level_3_3();
const Level level_3_4();

const Level level_4_1();
const Level level_4_2();
const Level level_4_3();
const Level level_4_4();

const Level level_5_1();
const Level level_5_2();
const Level level_5_3();
const Level level_5_4();

const Level level_6_1();
const Level level_6_2();
const Level level_6_3();
const Level level_6_4();