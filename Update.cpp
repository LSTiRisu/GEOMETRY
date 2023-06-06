#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Grid.h"

extern std::vector<Shape>operations;

void readRec(int lineNum, char* data) {
    std::ifstream ifs;
    ifs.open("record.txt"); //���ļ�
    int line = 1;
    while (ifs.getline(data, 1024)) {
        if (lineNum == line)break; //��ָ���е����ݴ����ַ���data��
        line++;
    }
    ifs.close();
}

int strToNum(const std::string& s) {
    std::stringstream geek(s);
    int n = 0;
    geek >> n; //���ַ����е������ַ�ת��Ϊ���ֺϲ���n��
    return n;
}

void resetRec(int lineNum, int newrec) {
    std::ifstream ifs;
    ifs.open("record.txt");
    std::string strRec = ""; //�����µ����ݴ�
    int line = 1;
    char tmpRec[1024] = { 0 }; 
    while (ifs.getline(tmpRec, sizeof(tmpRec))){ //��ȡ����������
        if (line == lineNum){
            strRec += std::to_string(newrec); //����¼������ת��Ϊ�ַ���д��
            strRec += "\n";  //�ָ�
        }
        else{
            strRec += tmpRec; //�����б���ԭ������
            strRec += "\n";
        }
        line++;
    }
    ifs.close();
    std::ofstream ofs;
    ofs.open("record.txt");
    ofs.flush(); //���ԭ��������
    ofs << strRec; //д���޸ĺ��������
    ofs.close();
}

void Update(int Lvlnum) { 
    char tempData[1024] = { 0 };
    readRec(Lvlnum, tempData);
    int rec = strToNum(tempData);
    if (rec == 0 || operations.size() < rec) {
        std::cout << "�µ����ٲ���: " << operations.size() << "!" << std::endl;
        char tempRec[1024] = { 0 };//�����operations.size()ת��Ϊ�ַ���
        resetRec(Lvlnum, operations.size());
    }
}
