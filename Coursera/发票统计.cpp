/*
����
��һ��С�͵ı���ϵͳ���������¹��ܣ�

��1��ͳ��ÿ����������Ʊ����Ǯ��

��2��ͳ��ÿ�෢Ʊ����Ǯ��

����ϵͳ��Ϊ���£����跢Ʊ�����A��B��C����;һ���������ˣ�ID�ֱ�Ϊ1��2��3��

����
ϵͳ����������У�ÿ�е�һ����Ϊ��ԱID�����ͣ�1��2��3�����ڶ�����Ϊ��Ʊ������(����������100)��֮���Ƕ����Ʊ����ַ��ͣ�A��B��C������Ӧ��Ʊ�������ȸ�����,������1000.0����

���
����������У�ǰ����Ϊÿ�ˣ���ID��С���������������Ʊ��Ǯ����������λС������������Ϊÿ�෢Ʊ����Ǯ����������λС������
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
