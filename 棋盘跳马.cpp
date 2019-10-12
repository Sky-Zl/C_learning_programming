/*
题目描述

现在棋盘的大小不一定，由p，q给出，并且在棋盘中将出现障碍物（限制马的行动，与象棋走法相同）

输入

第一行输入n表示有n组测试数据。

每组测试数据第一行输入2个整数p,q，表示棋盘的大小(1<=p,q<=100)。
?每组测试数据第二行输入4个整数，表示马的起点位置与终点位置。(位置的取值范围同p,q)
第三行输入m表示图中有多少障碍。
?接着跟着m行，表示障碍的坐标。

输出

马从起点走到终点所需的最小步数。
?如果马走不到终点，则输入“can not reach!”

样例输入
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
样例输出
1
can not reach!

提示

此题是一个搜索题，可用DFS或BFS，建议选择BFS(广搜)。一开始把马的起始点加入队列，然后用广搜的思想把此点能到达的其他点加入队列，这里需要一个数组用来记录此点在之前是否已经加入队列，如果加入过队列当中，就不需要再加入了，直到队列里的元素为空，或者搜索到了终点，搜索即停止，然后输出相应答案即可。


思路：经典的棋盘路障问题，路障有2个作用，

1）路障所占的地方不可以作为出发点和到达点，1个位置。

2）路障可以ban马的行走路线，8个位置

（大家可以自己画个图，理解下。）

马可以跳8个方向，可以定义一个方向数组

position dir[8]={{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};

相应的一个障碍也Ban 8个方向的马的行走路线

bar cir[8]={{-1,0},{-1,0},{0,1},{0,1},{1,0},{1,0},{0,-1},{0,-1}};



*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
//定义方向数组dir 为8个方向的偏移量
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
int p,q,srow,scol,erow,ecol,m,a,b,ans,flag; //其实结束位置
queue<node>que;
 
int  in(int a,int b){
    if(a>0&&a<=p&&b>0&&b<=q)
        return 1;
    return 0;
}
 
int BFS()
{
    int col,row;//定义列，行，计数器
    ans=flag=0;
    node t,m;
    t.x=srow; t.y=scol; t.sum=ans;
    que.push(t);
    vis[srow][scol]=1;
 
    while(!que.empty())
    {
        t=que.front(); que.pop();
         row=t.x;  col=t.y;
        if(col==ecol&&row==erow) //到达目标状态
          {
              flag=1;
              ans=t.sum;
              return ans;
          }
 
        for(int i=0;i<8;i++) //向8个方向扩展
        {
           if(!barrier[t.x+cir[i].x][t.y+cir[i].y])
            {  //判断行走路线上是否有障碍
               if(in(t.x+dir[i].x, t.y+dir[i].y)&&!vis[t.x+dir[i].x][t.y+dir[i].y]&&!barrier[t.x+dir[i].x][t.y+dir[i].y]){
                //3重判断 
                //1 判断是否普越界
                //2 判断是否行走过
                //3 判断到达点是否有障碍
                m.x=t.x+dir[i].x;
                m.y=t.y+dir[i].y;
                m.sum=t.sum+1;
                //printf("%d",t.sum);
                que.push(m);
                vis[t.x+dir[i].x][t.y+dir[i].y]=1;//记录此位置
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
            vis[a][b]=1;      //障碍的作用1
            barrier[a][b]=1;  //障碍的作用2
        }
        BFS();
        if(flag==1)
            printf("%d",ans);
        else
            printf("can not reach!");
        printf("\n");
 
 
    }
}

