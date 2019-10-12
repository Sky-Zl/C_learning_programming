/*
��Ŀ����

�������̵Ĵ�С��һ������p��q�����������������н������ϰ����������ж����������߷���ͬ��

����

��һ������n��ʾ��n��������ݡ�

ÿ��������ݵ�һ������2������p,q����ʾ���̵Ĵ�С(1<=p,q<=100)��
?ÿ��������ݵڶ�������4����������ʾ������λ�����յ�λ�á�(λ�õ�ȡֵ��Χͬp,q)
����������m��ʾͼ���ж����ϰ���
?���Ÿ���m�У���ʾ�ϰ������ꡣ

���

�������ߵ��յ��������С������
?������߲����յ㣬�����롰can not reach!��

��������
2
9 10
1 1 2 3
0
9 10
1 1 2 3
8
1 2
2 2
3 3
3 4
1 4
3 2
2 4
1 3
�������
1
can not reach!

��ʾ

������һ�������⣬����DFS��BFS������ѡ��BFS(����)��һ��ʼ�������ʼ�������У�Ȼ���ù��ѵ�˼��Ѵ˵��ܵ���������������У�������Ҫһ������������¼�˵���֮ǰ�Ƿ��Ѿ�������У������������е��У��Ͳ���Ҫ�ټ����ˣ�ֱ���������Ԫ��Ϊ�գ��������������յ㣬������ֹͣ��Ȼ�������Ӧ�𰸼��ɡ�


˼·�����������·�����⣬·����2�����ã�

1��·����ռ�ĵط���������Ϊ������͵���㣬1��λ�á�

2��·�Ͽ���ban�������·�ߣ�8��λ��

����ҿ����Լ�����ͼ������¡���

�������8�����򣬿��Զ���һ����������

position dir[8]={{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};

��Ӧ��һ���ϰ�ҲBan 8��������������·��

bar cir[8]={{-1,0},{-1,0},{0,1},{0,1},{1,0},{1,0},{0,-1},{0,-1}};



*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
//���巽������dir Ϊ8�������ƫ����
struct position
{
    int x,y;
};
struct bar
{
    int x,y;
};
struct node
{
    int x,y,sum;
};
int barrier [105][105];
position dir[8]={{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};
bar  cir[8]={{-1,0},{-1,0},{0,1},{0,1},{1,0},{1,0},{0,-1},{0,-1}};
int  vis[102][102];
int p,q,srow,scol,erow,ecol,m,a,b,ans,flag; //��ʵ����λ��
queue<node>que;
 
int  in(int a,int b){
    if(a>0&&a<=p&&b>0&&b<=q)
        return 1;
    return 0;
}
 
int BFS()
{
    int col,row;//�����У��У�������
    ans=flag=0;
    node t,m;
    t.x=srow; t.y=scol; t.sum=ans;
    que.push(t);
    vis[srow][scol]=1;
 
    while(!que.empty())
    {
        t=que.front(); que.pop();
         row=t.x;  col=t.y;
        if(col==ecol&&row==erow) //����Ŀ��״̬
          {
              flag=1;
              ans=t.sum;
              return ans;
          }
 
        for(int i=0;i<8;i++) //��8��������չ
        {
           if(!barrier[t.x+cir[i].x][t.y+cir[i].y])
            {  //�ж�����·�����Ƿ����ϰ�
               if(in(t.x+dir[i].x, t.y+dir[i].y)&&!vis[t.x+dir[i].x][t.y+dir[i].y]&&!barrier[t.x+dir[i].x][t.y+dir[i].y]){
                //3���ж� 
                //1 �ж��Ƿ���Խ��
                //2 �ж��Ƿ����߹�
                //3 �жϵ�����Ƿ����ϰ�
                m.x=t.x+dir[i].x;
                m.y=t.y+dir[i].y;
                m.sum=t.sum+1;
                //printf("%d",t.sum);
                que.push(m);
                vis[t.x+dir[i].x][t.y+dir[i].y]=1;//��¼��λ��
            }
 
           }
 
        }
    }
}
 
int main()
{
    int icase;
    scanf("%d",&icase);
    while(icase--)
    {
        while(!que.empty())
            que.pop();
 
        memset(vis,0,sizeof(vis));
        memset(barrier,0,sizeof(barrier));
 
        scanf("%d%d",&p,&q);
        scanf("%d%d%d%d",&srow,&scol,&erow,&ecol);
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            vis[a][b]=1;      //�ϰ�������1
            barrier[a][b]=1;  //�ϰ�������2
        }
        BFS();
        if(flag==1)
            printf("%d",ans);
        else
            printf("can not reach!");
        printf("\n");
 
 
    }
}

