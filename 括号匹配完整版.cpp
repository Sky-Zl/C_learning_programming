
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1000;//都看得懂 
const char outc[]= {' ','$','?'};//要打印的东西 
char a[maxn];//字符数组 
int map[maxn],n;//n表示字符数组的长度 ， map表示栈，存下所左括号位置， 与右括号最近的左括号就是栈顶 
int mark[maxn];//当前左括号的的状态 
void find(int i,int dep)//递归做法 i表示位置，dep表示有几个未匹配的左括号，先假设左括号全未匹配 
{
    // ( ( A B C D ( x )
// 0 1 2 3 4 5 6 7 8
// i==6, dep==3
// map: 0:0 1:1 2:6
// mark: 0 1 2 3 4 5 6 7 8
//       1 1 0 0 0 0 1 0 0
// i==8, dep==3
// mark [ map[dep-1] ]=0
// i==9 dep==2
// map: 0:0 1:1
// mark: 0 1 2 3 4 5 6 7 8 '\n'
//       1 1 0 0 0 0 0 0 0

	if(a[i]=='(')//如果找到一个左括号 
	{
		map[dep]=i;//标记一下 
		mark[i]=1;//标记一下 
		find(i+1,dep+1);//递归寻找下一个 
	}
	else if(a[i]==')')//如果找到一个右括号 
	{
		if(dep>0)//如果有左括号 
		{
		mark[map[dep-1]]=0;//将这个最近的左括号 的状态变为0 要减一因为数组从零开始的，第三个左括号改变状态 
		find(i+1,dep-1);//已经匹配了一个左括号，所以dep的个数要减一 
		}
		else//如果没有左括号用来匹配了 
		{
			mark[i]=2;//说明这个右括号不能匹配了 就赋值为2 
			find(i+1,0);//从下一个位置开始找 
		}
	}
	else if(i==n) 
		return;//边界条件 
	else 
		find(i+1,dep);//如果既不是左括号也不是右括号就直接跳过 
}

int main()
{
  while(cin>>a)
  {
    cout<<a<<endl;
    n=strlen(a);
    find(0,0);
    for(int i=0; i<n; i++)
    {
      cout<<outc[mark[i]];
      mark[i]=0;
    }
    cout<<endl;
  }
  return 0;
}
