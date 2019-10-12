/*
约瑟夫问题
编号为1-N的N个人围坐在一起形成一个圈，从第P个人开始，依次按照顺时针的方向报数，数到第M的人出列，直到剩下最后一个人；
输出依次出列的人的编号； 
*/
#include<iostream>
using namespace std;
struct Node
{
	int num;
	Node *ahead;
	Node *next;
};

Node *Create(int N);
Node *Search(Node *head, int P);
Node *Release(Node*head, int M);

int main()
{
	int N,P,M=0;
	cin >> N >> P >> M;
	Node *head = Create(N);
	head = Search(head,P);
	while(head->next != head)
	{
		head=Release(head,M); 
	} 
	cout << head->num;
	return 0;
}

Node *Create(int N)
{
	int n=1;
	Node *node=new Node;
	node->num=n;
	Node *head=node;
	Node *tail=head;
	while(n++<N)
	{
		node=new Node;//新建节点
		node->num=n;//赋值
		tail->next=node;//接入新节点
		node->ahead=tail;
		tail=tail->next;  
	}
	tail->next=head;
	head->ahead=tail;
	return head;
}

Node *Search(Node *head, int P)
{
	while(head->num!=P)
	{
		head=head->next;
	}
	return head;
}

Node *Release(Node *head, int M)
{
	int count = 1;
	Node *temp=head;
	while(count<M)//寻找第M个节点 
	{
		temp=temp->next;
		count++;
	}
	temp->ahead->next=temp->next;
	temp->next->ahead=temp->ahead;
	cout << temp->num <<",";
	head=temp->next;
	delete temp;
	return head; 
}
