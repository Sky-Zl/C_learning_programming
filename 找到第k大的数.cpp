#include <iostream>
using namespace std;
int main()
{
    int n=0,k;//nΪ���ݵĸ��������k�����
    cin >> n >> k;
    int a[n];
    for(int i=0;i<n;i++)//¼������
        cin >> a[i];
    //������������
    for(int i=0;i<n;i++)
    {
        int num=0;//��¼�м���������ѡ���������
        for(int j=0;j<n;j++)
        {
            if(a[i]<a[j])
                num++;
        }
        if(num==k-1)
        {
        	cout << a[i] << endl;
    		break; 
		}
    }
    return 0;
}


