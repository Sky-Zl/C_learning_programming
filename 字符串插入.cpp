/*
����
�������ַ���str��substr��str���ַ�����������10��substr���ַ�����Ϊ3�����ַ������������ַ�����β����'\0'������substr���뵽str��ASCII�������Ǹ��ַ����棬���ж�������ֻ���ǵ�һ����

����
������������У�ÿһ��Ϊһ��������ݣ���ʽΪ

str substr

���
����ÿһ��������ݣ��������֮����ַ�����
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
