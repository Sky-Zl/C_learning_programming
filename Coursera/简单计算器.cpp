/*
����
һ����򵥵ļ�������֧��+, -, *, / �������㡣���迼���������Ϊ��������������ݺ����������ᳬ��int��ʾ�ķ�Χ��

����
����ֻ��һ�У������������������е�1��2������Ϊ��������3������Ϊ��������+,-,*,/����

���
���ֻ��һ�У�һ��������Ϊ��������Ȼ����

1. ������ֳ���Ϊ0��������������Divided by zero!

2. ���������Ч�Ĳ�����(����Ϊ +, -, *, / ֮һ�����������Invalid operator!
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
	int n1,n2,result;
	char c;
	cin >> n1 >> n2 >>c; 
 
	if(c=='+')
		result=n1+n2;
	else if(c=='-')
		result=n1-n2;
	else if(c=='*')
		result=n1*n2;
	else if(c=='/')
	{
		if(n2==0){
			cout <<"Divided by zero!"<<endl; 
			return 0;
		}
		result=n1/n2; 
	}
	else
	{
		cout <<"Invalid operator!"<<endl; 
		return 0;
	}
	cout << result <<endl;
	return 0; 
}
 
