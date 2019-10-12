/*
描述
在一个字符串中找出元音字母a,e,i,o,u出现的次数。

输入
输入一行字符串（字符串中可能有空格，请用cin.getline(s,counts)方法把一行字符串输入到字符数组s中，其中counts是s的最大长度，这道题里面可以直接写80。），字符串长度小于80个字符。

输出
输出一行，依次输出a,e,i,o,u在输入字符串中出现的次数，整数之间用空格分隔。
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
