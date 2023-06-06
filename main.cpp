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
    //���˵�
    std::cout << "��ӭ����GEOMETRY���ι���." << std::endl;
    bool newplayer = true;
    for (int i = 1;i <= LVL_SUM_1*LVL_SUM_2;i++) { //�ж��Ƿ�Ϊ�����,��ʽΪ��ȡ�浵,�����Ƿ��й���Ϊ��ʼֵ0�Ĳ�����¼
        char rec[1024] = { 0 };
        readRec(i, rec);
        if (*rec!='0')newplayer = false;
    }
    if (newplayer) {
        std::cout << "����һ��ƽ�漸����ͼС��Ϸ,�����ͨ��:" << std::endl
            << "(1)�������ͼ�еĽ���������Ƶ�," << std::endl
            << "(2)�Ⱥ����������ͬ��ֱ�߶ν�����������߶�," << std::endl
            << "(3)��ĳЩ��Ŀ�п��������Բ�ĺ��һ�Բ��һ�����Բ," << std::endl
            << "(3*)�����ҵ���ͬһλ�û�����Բ���㻭������Ȼ������ĵ�," << std::endl
            << "(4)�Ҽ�����������һ������," << std::endl
            << "(5)����Backspace�����¿�ʼ����," << std::endl
            << "(6)����Esc��ֱ���˳���Ϸ." << std::endl
            << "[ע��]����Ƶ�ֱ�߶λᵼ���µĽ�������(��Բ����)." << std::endl
            << "��׼���ÿ�ʼ����? (�������ȷ��)" << std::endl;
        _getch();
    }

    //�ؿ�ѡ��
    std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "�������ѡ�ؽ���.��ϷĿǰ��"<< LVL_SUM_1 <<"���,ÿ�������" << LVL_SUM_2 << "��С��.\n����ѡ����: (�ڴ˴�����������1~" << LVL_SUM_1 << ")" << std::endl;
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
    for (int i = LVL_SUM_2 * (Lvlnum1 - 1) + 1;i <= LVL_SUM_2 * Lvlnum1;i++) { //�жϱ���ص�С�ؽ��ȣ���ʽΪ��ȡ�浵��������Ϊ0��Ϊ��ͨ�أ���Ϸ����Ϊ������Ϊ0С����+1
        char rec[1024] = { 0 };
        readRec(i, rec);
        if (*rec != '0' && lvlmax < LVL_SUM_2)lvlmax++;
    }
    std::cout << "���������Ϸ����Ϊ" << Lvlnum1 << '-' << lvlmax << ",���ڿ���̨������1~" << lvlmax << "ѡ��С��." << std::endl;
    int Lvlnum2 = 1;
    while (true) {
        char key = _getch();
        if (key >= 49 && key <= 48 + lvlmax) {
            Lvlnum2 = key - 48;
            std::cout << key << std::endl;
            break;
        }
    }
    std::cout << "��ѡ����" << Lvlnum1 << '-' << Lvlnum2 << ", ������Ϸ��ʼ." << std::endl;
    Run(Lvlnum1, Lvlnum2); //��Ϸ���е���Ҫ����
    std::cout << "��Ϸ�����ѽ���.";
    return 0;
}
