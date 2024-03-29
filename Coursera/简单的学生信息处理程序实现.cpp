/*
问题描述
在一个学生信息处理程序中，要求实现一个代表学生的类，并且所有成员变量都应该是私有的。
（注：评测系统无法自动判断变量是否私有。我们会在结束之后统一对作业进行检查，请同学们严格按照题目要求完成，否则可能会影响作业成绩。）
输入
姓名，年龄，学号，第一学年平均成绩，第二学年平均成绩，第三学年平均成绩，第四学年平均成绩。
其中姓名、学号为字符串，不含空格和逗号；年龄为正整数；成绩为非负整数。
各部分内容之间均用单个英文逗号”,”隔开，无多余空格。
输出
一行，按顺序输出：姓名，年龄，学号，四年平均成绩（向下取整）。
各部分内容之间均用单个英文逗号”,”隔开，无多余空格。
样例输入

Tom,18,7817,80,80,90,70
1
样例输出

Tom,18,7817,80
*/ 

#include <iostream>
#include <string.h>
using namespace std;

class Student
{
private:
    char stName[30];
    int stAge;
    char stID[10];
    int stGrade[4];
public:
    void setName(const char* Name);
    void getName(char* Name);
    void setAge(int Age);
    void getAge(int& Age);
    void setID(const char* ID);
    void getID(char* ID);
    void setGrade(int* Grade);
    void getAverageGrade(int& AverageGrade);
};

void Student::setName(const char* Name)
{
    strcpy(stName, Name);
}

void Student::getName(char* Name)
{
    strcpy(Name, stName);
}
void Student::setAge(int Age)
{
    stAge = Age;
}
void Student::getAge(int& Age)
{
    Age = stAge;
}
void Student::setID(const char* ID)
{
    strcpy(stID, ID);
}
void Student::getID(char* ID)
{
    strcpy(ID, stID);
}
void Student::setGrade(int* Grade)
{
    for (int i = 0; i < 4; i++)
    {
        stGrade[i] = Grade[i];
    }
}
void Student::getAverageGrade(int& AverageGrade)
{
    AverageGrade = (stGrade[0]+stGrade[1]+stGrade[2]+stGrade[3])/4;
}

int main()
{
    Student NY;
    char Name[30];
    int Age;
    char ID[10];
    int Grade[4];
    int AverageGrade;
    char mark;
    cin.getline(Name, 30, ',');
    cin >> Age >> mark;
    cin.getline(ID, 10, ',');
    cin >> Grade[0] >> mark >> Grade[1] >> mark >> Grade[2] >> mark >> Grade[3];
    NY.setName(Name);
    NY.setAge(Age);
    NY.setID(ID);
    NY.setGrade(Grade);
    memset(Name, '\0', sizeof(Name));
    Age = 0;
    memset(ID, '\0', sizeof(ID));
    AverageGrade = 0;
    NY.getName(Name);
    NY.getAge(Age);
    NY.getID(ID);
    NY.getAverageGrade(AverageGrade);
    cout << Name << ',' << Age << ',' << ID << ',' << AverageGrade << endl;
    return 0;
}
