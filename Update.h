#pragma once
#include<string>
void readRec(int lineNum, char* data); //读取指定行的纪录数据
int strToNum(const std::string& s); //将数字串转化为整型
void resetRec(int lineNum, int newrec); //修改指定行的纪录数据
void Update(int Lvlnum); //完成整个纪录更新操作