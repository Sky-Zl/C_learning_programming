

#include<stdio.h>
#include<iostream>
using namespace std;
//dfs��ÿ��ֻ�ܷ�һ��Ԫ�أ�����ÿ�е�ÿ��λ�ã���һ��һά�����¼��������Ƿ����Ҫ��
int ans;
int vis[10];
bool check(int row,int column){
    for(int i = 1;i<row;i++){
        if(vis[i] == column) return false;//��ǰ���ѷ��ûʺ� 
        if(vis[i] - column == row - i || vis[i] - column == i - row) return false;//���Խ���  ��������ѷ��õ��м����м���Ƿ���� 
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
