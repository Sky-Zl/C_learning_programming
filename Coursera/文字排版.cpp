/*
����
��һ��Ӣ�Ķ��ģ�����֮���Կո�ָ���ÿ�����ʰ�����ǰ����ڵı����ţ����뽫���������Ű棬Ҫ�����£�

ÿ�в�����80���ַ���ÿ�����ʾ���ͬһ���ϣ���ͬһ�еĵ���֮����һ���ո�ָ������׺���β��û�пո�

����
��һ����һ������n����ʾӢ�Ķ����е��ʵ���Ŀ. �����n���Կո�ָ���Ӣ�ĵ��ʣ����ʰ�����ǰ����ڵı����ţ���ÿ�����ʳ��ȶ�������40����ĸ����

���
�Ű��Ķ����ı���ÿ���ı��ַ������80���ַ�������֮����һ���ո�ָ���ÿ���ı���β��û�пո�

�������룺

84
One sweltering day, I was scooping ice cream into cones and told my four children they could "buy" a cone from me for a hug. Almost immediately, the kids lined up to make their purchases. The three youngest each gave me a quick hug, grabbed their cones and raced back outside. But when my teenage son at the end of the line finally got his turn to "buy" his ice cream, he gave me two hugs. "Keep the changes," he said with a smile.?

���������

One sweltering day, I was scooping ice cream into cones and told my four
children they could "buy" a cone from me for a hug. Almost immediately, the kids
lined up to make their purchases. The three youngest each gave me a quick hug,
grabbed their cones and raced back outside. But when my teenage son at the end
of the line finally got his turn to "buy" his ice cream, he gave me two hugs.
"Keep the changes," he said with a smile.
*/ 
//
//#include <iostream>
//#include <cstring>
//using namespace std;
//int main()
//{
//	char words[1000][41]; //���ڱ���ÿһ������
//	int wordsLen[1000]; // ��¼ÿһ�����ʵĳ���
//	int n,sum=0; // ��Ҫ����ĵ�������
//	cin >> n;
////	cin.get();//cin֮��Ҫ��cin.get()��ȡ���з���һ��ʼûע�⵽������������ǻ������ο�
////	for (int i = 0; i < n;i++) //���뵥�����ݣ������õ�ÿ�����ʵĳ���
////	{
////		char temp;
////		for (int j = 0; j < 40;j++) {
////			cin.get(temp); 				
////				if (temp != ' '&&temp != '\n') {
////					words[i][j] = temp;					
////				}
////				else
////				{
////					wordsLen[i] = j;
////					break;
////				}
////			}
////		
////	}
//    for (int i = 0; i < n; i++)
//        cin >> words[i];
//	//�������һ������
//	int length = wordsLen[0];
//
////	for (int j = 0; j < wordsLen[0]; j++)
////		cout << words[0][j];
//	cout<<words[0];
//	for (int i = 1; i < n; i++)
//	{
//		//����õ��ʣ���ͬǰ���һ���ո����󲻻��У�������ո�͸õ���
//		if (length + 1 + wordsLen[i] <= 80)
//		{
//			length = length + 1 + wordsLen[i];
//			cout << ' ';
////			for (int j = 0; j < wordsLen[i]; j++)
////				cout << words[i][j];
//			cout<< words[i];
//		}
//		else//����õ��ʣ���ͬǰ���һ���ո������У�������س��͸õ��ʣ��������ñ������г���Ϊ���ʳ���
//		{
//			cout << endl;
//			length = wordsLen[i];
////			for (int j = 0; j < wordsLen[i]; j++)
////				cout << words[i][j];
//			cout<< words[i];
//		}
//	}
//	return 0;
//}


#include<iostream>  
#include<cstring>
using namespace std;

int main() {
    char a[1000][41];
    int n, sum = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sum += strlen(a[0]);
    cout << a[0] << ' ';

    for (int i = 1; i < n; i++){
        sum += strlen(a[i]) + 1;
        if (sum > 80){
            cout << endl;
            sum = 0;
            sum += strlen(a[i]);
        }
        cout << a[i] << ' ';
    }
    cout << endl;

    return 0;
}
