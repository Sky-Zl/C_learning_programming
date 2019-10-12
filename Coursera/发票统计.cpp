/*
描述
有一个小型的报账系统，它有如下功能：

（1）统计每个人所报发票的总钱数

（2）统计每类发票的总钱数

将此系统简化为如下：假设发票类别共有A、B、C三种;一共有三个人，ID分别为1、2、3。

输入
系统输入包含三行，每行第一个数为人员ID（整型，1或2或3），第二个数为发票总张数(张数不超过100)，之后是多个发票类别（字符型，A或B或C）和相应发票金额（单进度浮点型,不超过1000.0）。

输出
输出包含六行，前三行为每人（按ID由小到大输出）所报发票总钱数（保留两位小数），后三行为每类发票的总钱数（保留两位小数）。
*/ 
#include<iostream>
#include <iomanip>
using namespace std;
int main(){
	int name,num;
	char type;
	float money,money_all[3]={0},type_all[3]={0};
	for(int i=0;i<3;i++)
	{
		cin>>name>>num;
		for(int j=0;j<num;j++)
		{
			cin>>type>>money;
			if(type=='A')
				type_all[0]+=money;
			else if(type=='B')
				type_all[1]+=money;
			else if(type=='C')
				type_all[2]+=money; 
			money_all[name-1]+=money;
		}
	 } 
	for(int i=0;i<3;i++)
		cout<< fixed << setprecision(2)<<money_all[i]<<endl;
	for(int i=0;i<3;i++)
		cout<< fixed << setprecision(2)<<type_all[i]<<endl;
}
