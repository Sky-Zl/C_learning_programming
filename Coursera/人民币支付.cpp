#include <iostream>
using namespace std;
int main()
{
    int money;//���봦���Ǯ��
    cin >> money ;
    int deno[]={100,50,20,10,5,1};
    for(int i=0;i<6;i++)
    {
        cout << money/deno[i] << endl;
        money = money%deno[i];
    }
    return 0;
}

