#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <graphics.h>		
#include <conio.h>
#include <vector>
#include "patch.h"
#include "Level.h"
#include "Update.h"

extern std::vector<Point>pointarray;       
extern std::vector<Line>linearray;
extern std::vector<Circle>circlearray;
extern std::vector<Point>print_points;
extern std::vector<AddLine>add_lines;
extern std::vector<Shape>operations;

extern const int LVL_SUM_1 = 6, LVL_SUM_2 = 4;
extern Level LEVELS[LVL_SUM_1][LVL_SUM_2];

int main() {
    //主菜单
    std::cout << "欢迎来到GEOMETRY几何构建." << std::endl;
    bool newplayer = true;
    for (int i = 1;i <= LVL_SUM_1*LVL_SUM_2;i++) { //判断是否为新玩家,方式为读取存档,检索是否有过不为初始值0的步数纪录
        char rec[1024] = { 0 };
        readRec(i, rec);
        if (*rec!='0')newplayer = false;
    }
    if (newplayer) {
        std::cout << "这是一个平面几何作图小游戏,你可以通过:" << std::endl
            << "(1)两次左击图中的交叉点来绘制点," << std::endl
            << "(2)先后左击两个不同的直线段交叉点来绘制线段," << std::endl
            << "(3)在某些题目中可以先左击圆心后右击圆上一点绘制圆," << std::endl
            << "(3*)若左右单击同一位置或不允许画圆，你画出的仍然是左击的点," << std::endl
            << "(4)右键单击撤销上一步操作," << std::endl
            << "(5)单击Backspace键重新开始本局," << std::endl
            << "(6)单击Esc键直接退出游戏." << std::endl
            << "[注意]你绘制的直线段会导致新的交叉点产生(而圆不会)." << std::endl
            << "你准备好开始了吗? (按任意键确认)" << std::endl;
        _getch();
    }

    //关卡选择
    std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "下面进入选关界面.游戏目前有"<< LVL_SUM_1 <<"大关,每个大关有" << LVL_SUM_2 << "个小关.\n请先选择大关: (在此窗口输入数字1~" << LVL_SUM_1 << ")" << std::endl;
    int Lvlnum1 = 0;
    while (true) {
        char key = _getch();
        if (key >= 49 && key <= 48 + LVL_SUM_1) {
            Lvlnum1 = key - 48;
            std::cout << key << std::endl;
            break;
        }
    }
    int lvlmax = 1;
    for (int i = LVL_SUM_2 * (Lvlnum1 - 1) + 1;i <= LVL_SUM_2 * Lvlnum1;i++) { //判断本大关的小关进度，方式为读取存档，步数不为0即为已通关，游戏进度为步数不为0小关数+1
        char rec[1024] = { 0 };
        readRec(i, rec);
        if (*rec != '0' && lvlmax < LVL_SUM_2)lvlmax++;
    }
    std::cout << "本关你的游戏进度为" << Lvlnum1 << '-' << lvlmax << ",请在控制台上输入1~" << lvlmax << "选择小关." << std::endl;
    int Lvlnum2 = 1;
    while (true) {
        char key = _getch();
        if (key >= 49 && key <= 48 + lvlmax) {
            Lvlnum2 = key - 48;
            std::cout << key << std::endl;
            break;
        }
    }
    std::cout << "你选择了" << Lvlnum1 << '-' << Lvlnum2 << ", 下面游戏开始." << std::endl;
    Run(Lvlnum1, Lvlnum2); //游戏运行的主要部分
    std::cout << "游戏进程已结束.";
    return 0;
}
