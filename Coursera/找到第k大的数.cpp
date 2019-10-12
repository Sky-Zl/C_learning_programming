#include <iostream>
using namespace std;
int main()
{
    int n=0,k;//n为数据的个数，求第k大的数
    cin >> n >> k;
    int a[n];
    for(int i=0;i<n;i++)//录入数据
        cin >> a[i];
    //遍历整个数组
    for(int i=0;i<n;i++)
    {
        int num=0;//记录有几个数比所选的这个数大
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


