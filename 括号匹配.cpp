#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool b=false;
int f(char str[],int s)
{
    if(strlen(str)==s)
    {
        return (b=true,-1);
    }
    else
    {
        if(str[s]=='(')
        {
            int n;
            (b,n) = f(str,s+1);
            if(b==false)
            {
                return (b=false,n);
            }
            else 
            {
                if(str[n]==')')
                    return f(str ,n+1);
                else
                    return (b=false,n);
            }  

        }
        else 
            return (b=true,s);
    }
}
int main()
{
	char s[20];
    cin.getline(s,20);
    int n=f(s,0);
    if(b==true&&n==-1)
    	cout << "yes" <<endl;
    else
    	cout << "no" <<endl;  
}
