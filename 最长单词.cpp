/*
描述
一个以'.'结尾的简单英文句子，单词之间用空格分隔，没有缩写形式和其它特殊形式

输入
一个以'.'结尾的简单英文句子（长度不超过500），单词之间用空格分隔，没有缩写形式和其它特殊形式

输出
该句子中最长的单词。如果多于一个，则输出第一个
*/ 
//该程序仅实现了以句点结尾的句子，如果不以句点结尾，则无法计算最后一个单词
#include <iostream>
using namespace std;
int main()
{
    int maxlen=0;//用来记录最长单词
    char s[500];
    cin.getline(s,500);
    int tmplen=0;//记录当前单词的长度
    int last=0;//记录最长单词结束时的下标
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='.')//判断遇到句点的情况
        {
            if(maxlen<tmplen)
            {
                maxlen=tmplen;
                tmplen=0;
                last=i;
            }
            break;
        }
        else if(s[i]!=' ')
            tmplen++;
        else //遇到空格 
        {
            if(maxlen<tmplen)
            {
                maxlen=tmplen;
                last=i;
            }
            tmplen=0;
        }
    } 
    //输出结果
    cout << "该句子中最长单词为：" ;
    for(int i=last-maxlen;i<last;i++)
        cout << s[i] ;
    return 0;
}

