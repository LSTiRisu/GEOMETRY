#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Grid.h"

extern std::vector<Shape>operations;

void readRec(int lineNum, char* data) {
    std::ifstream ifs;
    ifs.open("record.txt"); //打开文件
    int line = 1;
    while (ifs.getline(data, 1024)) {
        if (lineNum == line)break; //将指定行的数据存入字符串data中
        line++;
    }
    ifs.close();
}

int strToNum(const std::string& s) {
    std::stringstream geek(s);
    int n = 0;
    geek >> n; //将字符串中的数字字符转化为数字合并到n中
    return n;
}

void resetRec(int lineNum, int newrec) {
    std::ifstream ifs;
    ifs.open("record.txt");
    std::string strRec = ""; //创建新的数据串
    int line = 1;
    char tmpRec[1024] = { 0 }; 
    while (ifs.getline(tmpRec, sizeof(tmpRec))){ //获取所有行数据
        if (line == lineNum){
            strRec += std::to_string(newrec); //将纪录的数字转化为字符串写入
            strRec += "\n";  //分隔
        }
        else{
            strRec += tmpRec; //其他行保留原有数据
            strRec += "\n";
        }
        line++;
    }
    ifs.close();
    std::ofstream ofs;
    ofs.open("record.txt");
    ofs.flush(); //清除原来的数据
    ofs << strRec; //写入修改后的新数据
    ofs.close();
}

void Update(int Lvlnum) { 
    char tempData[1024] = { 0 };
    readRec(Lvlnum, tempData);
    int rec = strToNum(tempData);
    if (rec == 0 || operations.size() < rec) {
        std::cout << "新的最少步数: " << operations.size() << "!" << std::endl;
        char tempRec[1024] = { 0 };//这里把operations.size()转化为字符串
        resetRec(Lvlnum, operations.size());
    }
}
