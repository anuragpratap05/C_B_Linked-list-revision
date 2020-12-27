#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int d;
	node* next;
	node(int data)
	{
		d = data;
		next = NULL;
	}
};

void insertathead(node* &head, int data)
{
	if (head == NULL)
	{
		head = new node(data);
		return;
	}

	node* n = new node(data);
	n->next = head;
	head = n;

}

void print(node* head)

{
	while (head != NULL)
	{
		cout << head->d << " ";
		head = head->next;
	}
}

int length(node* head)
{
	int cnt = 0;
	while (head != NULL)
	{
		head = head->next;
		cnt++;
	}
	return cnt;
}

void insertattail(node*&head, int data)
{
	if (head == NULL)
	{
		insertathead(head, data);
		return;
	}

	node*tail = head;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	node* n = new node(data);
	tail->next = n;
	return;
}

void insertatmiddle(node*&head, int data, int p)
{
	if (head == NULL or p == 0)
	{
		insertathead(head, data);
		return;
	}

	if (p > length(head))
	{
		insertattail(head, data);
	}

	int jump = 1;
	node* temp = head;
	while (jump <= p - 1)
	{
		temp = temp->next;
		jump++;
	}

	node* n = new node(data);
	n->next = temp->next;
	temp->next = n;
}

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* head = NULL;
	insertathead(head, 4);
	insertathead(head, 2);
	insertathead(head, 1);
	insertathead(head, 0);

	print(head);
	insertatmiddle(head, 3, 3);
	insertattail(head, 5);
	cout << endl;
	print(head);

}
