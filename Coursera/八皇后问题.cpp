

#include<stdio.h>
#include<iostream>
using namespace std;
//dfs，每行只能放一个元素，遍历每行的每个位置，用一个一维数组记录，最后检查是否符合要求
int ans;
int vis[10];
bool check(int row,int column){
    for(int i = 1;i<row;i++){
        if(vis[i] == column) return false;//当前列已放置皇后 
        if(vis[i] - column == row - i || vis[i] - column == i - row) return false;//检查对角线  待检查点和已放置点行间距和列间距是否相等 
    }
    return true;
}
void printQueens()
{
	for(int i=1;i<=8;i++)
	{
		for(int j=1;j<=8;j++)
		{
			if(vis[i]==j)
				cout << "* ";
			else
				cout << "1 ";
		}
		cout <<endl;
	}
	cout <<endl<<endl;
}
void dfs(int r){
    if(r > 8){
        ans++;
        printQueens(); 
        return;
    }
    for(int i = 1;i<=8;i++){
        if(check(r,i)){
            vis[r] = i;
            dfs(r+1);
            vis[r] = 0;
        }
    }
}

main(){
    dfs(1);
    cout<<ans<<endl;
}

//
//#include<iostream>
//int n_queen(int col,int ld,int rd,int board){
//    if(col == board) return 1;
//    int tot = 0;
//    for(int pos = board & (~(col | ld | rd)); pos != 0;pos -= (pos & (-pos))) tot+=n_queen(col | (pos & (-pos)) , (ld | (pos & (-pos))) << 1,(rd | (pos & (-pos))) >> 1,board);
//    return tot;
//}
//int main(){
//    std::cout<<n_queen(0,0,0,(1<<8)-1);
//}
