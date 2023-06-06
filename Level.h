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
    bool circleAllowed; //允许画圆与否
public:
    Level(const Grid& G, const std::vector<Point>& vP, const std::vector<Line>& vL, const std::vector<Circle>& vC, 
        const std::vector<Point>& aP, const std::vector<Line>& aL, const std::vector<Circle>& aC, const std::string& s, const bool& cA); //含圆的构造函数
    Level(const Grid& G, const std::vector<Point>& vP, const std::vector<Line>& vL,
        const std::vector<Point>& aP, const std::vector<Line>& aL, const std::string& s, const bool& cA);  //不含圆的构造函数
    friend void Run(int Lvlnum1, int Lvlnum2);
    void Start();  //开始游戏(会修改开始计时的时间,不加const)
    void Restart();  //重新开始(会调用Start(),不加const)
    void mouseLoop();  //鼠标操作循环(会调用Restart(),不加const)
    double Loop(); //关内大循环,返回所用时间(会修改截止计时的时间,不加const)
    void Cancel() const;  //取消上一步操作
    bool levelJudge() const; //判定题目是否完成
};

bool pointJudge(const Point& p); //判断点是否与正确答案重合
bool lineJudge(const int& orgnum, const Line& l); //判断线段是否与正确答案重合
bool circleJudge(const Circle& c); //判断圆是否与正确答案重合

void Swap(); //清空vector,进行内存的回收
void Run(int Lvlnum1, int Lvlnum2); //将每关从开始到结束完全打包

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