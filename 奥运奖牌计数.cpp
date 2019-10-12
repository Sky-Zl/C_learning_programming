#include <iostream>
using namespace std;
int main()
{
    int n;//n为比赛天数
    cin >> n;
    int gold=0,silver=0,bronze=0;
    for(int i=0;i<n;i++)
    {
        int temgold=0,temsilver=0,tembronze=0;
        cin >> temgold >> temsilver >> tembronze;
        gold +=temgold;
        silver +=temsilver;
        bronze +=tembronze;
    }
    cout << gold << " "
         << silver << " "
         << bronze << " "
         << gold+silver+bronze << " "<< endl;
    return 0;
}

