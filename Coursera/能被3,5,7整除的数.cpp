/*
描述
输入一个整数，判断它能否被3，5，7整除，并输出以下信息：

1、能同时被3，5，7整除（直接输出3 5 7，每个数中间一个空格）；

2、能被其中两个数整除（输出两个数，小的在前，大的在后。例如：3 5或者 3 7或者5 7,中间用空格分隔）

3、能被其中一个数整除（输出这个除数）

4、不能被任何数整除；（输出小写字符'n',不包括单引号)

输入
一个数字

输出
一行数字,从小到大排列,包含3,5,7中为该输入的除数的数字,数字中间用空格隔开
*/ 
#include <iostream>
using namespace std;

//int main()
//{
//    int tmp;
//    while(cin>>tmp)
//    {
//        int k = (tmp%3 == 0) + (tmp%5 == 0)*2 +(tmp%7 == 0)*4;
//        switch(k)
//        {
//        case 0: cout<<"n"<<endl;break;
//        case 1: cout<<"3"<<endl;break;
//        case 2: cout<<"5"<<endl;break;
//        case 3: cout<<"3 5"<<endl;break;
//        case 4: cout<<"7"<<endl;break;
//        case 5: cout<<"3 7"<<endl;break;
//        case 6: cout<<"5 7"<<endl;break;
//        case 7: cout<<"3 5 7"<<endl;
//        }
//    }   
//    return 0;
//}

int main()
{
    int n;
    while(cin>>n)
    {
	    if (n%3!=0&&n%5!=0&&n%7!=0)
			cout << "n" ; 
	    if (n%3==0) 
			cout << "3 ";  
	    if (n%5==0) 
			cout << "5 ";  
	    if (n%7==0) 
			cout << "7 ";  
		cout <<endl;
    }   
    return 0;
}
