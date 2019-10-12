/*
描述
有两个字符串str和substr，str的字符个数不超过10，substr的字符个数为3。（字符个数不包括字符串结尾处的'\0'。）将substr插入到str中ASCII码最大的那个字符后面，若有多个最大则只考虑第一个。

输入
输入包括若干行，每一行为一组测试数据，格式为

str substr

输出
对于每一组测试数据，输出插入之后的字符串。
*/

#include <iostream>
#include <cstring> 
using namespace std;
int main(){
	char str[11],substr[4],strall[15];
	while(cin>>str>>substr){
		int len1,len2,max=0,j=0; 
		len1=strlen(str);
		len2=strlen(substr);
		for(int i=0;i<len1;i++)
			if(str[max]<str[i])
				max=i ;
		for(int i=0;i<len1+len2;i++)
		{
			if(i<=max)
				strall[i]=str[i];
			else if(i>max&&i<=max+len2)
				strall[i]=substr[j++];
			else
				strall[i]=str[i-len2];			
		}
		strall[len1+len2]='\0';
		cout<<strall <<endl; 
	} 
	
} 
