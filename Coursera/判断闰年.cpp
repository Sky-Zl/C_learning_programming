/*
����
�ж�ĳ���Ƿ������ꡣ

����
����ֻ��һ�У�����һ������a(0 < a < 3000)

���
һ�У������Ԫa�����������Y���������
*/ 

#include <iostream>
using namespace std;
int main(){
	int a;
	cin >> a ;
	if(a%400==0||(a%4==0&&a%100!=0))
		cout << "Y" <<endl;
	else 
		cout << "N" <<endl;
}
