
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1000;//�����ö� 
const char outc[]= {' ','$','?'};//Ҫ��ӡ�Ķ��� 
char a[maxn];//�ַ����� 
int map[maxn],n;//n��ʾ�ַ�����ĳ��� �� map��ʾջ��������������λ�ã� ������������������ž���ջ�� 
int mark[maxn];//��ǰ�����ŵĵ�״̬ 
void find(int i,int dep)//�ݹ����� i��ʾλ�ã�dep��ʾ�м���δƥ��������ţ��ȼ���������ȫδƥ�� 
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

	if(a[i]=='(')//����ҵ�һ�������� 
	{
		map[dep]=i;//���һ�� 
		mark[i]=1;//���һ�� 
		find(i+1,dep+1);//�ݹ�Ѱ����һ�� 
	}
	else if(a[i]==')')//����ҵ�һ�������� 
	{
		if(dep>0)//����������� 
		{
		mark[map[dep-1]]=0;//���������������� ��״̬��Ϊ0 Ҫ��һ��Ϊ������㿪ʼ�ģ������������Ÿı�״̬ 
		find(i+1,dep-1);//�Ѿ�ƥ����һ�������ţ�����dep�ĸ���Ҫ��һ 
		}
		else//���û������������ƥ���� 
		{
			mark[i]=2;//˵����������Ų���ƥ���� �͸�ֵΪ2 
			find(i+1,0);//����һ��λ�ÿ�ʼ�� 
		}
	}
	else if(i==n) 
		return;//�߽����� 
	else 
		find(i+1,dep);//����Ȳ���������Ҳ���������ž�ֱ������ 
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
