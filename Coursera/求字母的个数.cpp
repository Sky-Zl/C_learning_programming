/*
����
��һ���ַ������ҳ�Ԫ����ĸa,e,i,o,u���ֵĴ�����

����
����һ���ַ������ַ����п����пո�����cin.getline(s,counts)������һ���ַ������뵽�ַ�����s�У�����counts��s����󳤶ȣ�������������ֱ��д80�������ַ�������С��80���ַ���

���
���һ�У��������a,e,i,o,u�������ַ����г��ֵĴ���������֮���ÿո�ָ���
*/ 
#include<iostream>
using namespace std;
int main(){
	char s[80];
	int a=0,b=0,c=0,d=0,e=0;
	cin.getline(s,80);
	for(int i=0;i<80;++i){
		switch(s[i]){
			case '\0':
				break;
			case 'a' :
				++a;break;
			case 'e' :
				++b;break;
			case 'i' :
				++c;break;
			case 'u':
				++d;break;
			case 'o':
				++e;break;
			}
    }
    cout << a << " "<<b <<" "<<c<<" " <<e<<" "<<d<<endl;
    return 0;
}
