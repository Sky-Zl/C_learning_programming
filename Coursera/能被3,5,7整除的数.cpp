/*
����
����һ���������ж����ܷ�3��5��7�����������������Ϣ��

1����ͬʱ��3��5��7������ֱ�����3 5 7��ÿ�����м�һ���ո񣩣�

2���ܱ����������������������������С����ǰ������ں����磺3 5���� 3 7����5 7,�м��ÿո�ָ���

3���ܱ�����һ����������������������

4�����ܱ��κ��������������Сд�ַ�'n',������������)

����
һ������

���
һ������,��С��������,����3,5,7��Ϊ������ĳ���������,�����м��ÿո����
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
