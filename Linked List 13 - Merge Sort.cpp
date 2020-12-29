# C_B_Linked-list-revision#include<bits/stdc++.h>
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

void deleteathead(node*&head)
{
	if (head == NULL)
	{
		return;
	}

	node*temp = head->next;
	delete head;
	head = temp;
	return;
}

void deleteatmiddle(node*&head, int p)
{
	if (head == NULL)
	{
		return;
	}
	if (p == 0)
	{
		deleteathead(head);
		return;
	}

	node*prev = head;
	node* curr = head->next;

	int jump = 2;
	while (jump <= p - 1)
	{
		curr = curr->next;
		prev = prev->next;
		jump++;
	}
	prev->next = curr->next;
	delete curr;
	return;

}

bool search(node*head, int key)
{
	if (head == NULL)
	{
		return false;
	}

	while (head != NULL)
	{
		if (head->d == key)
		{
			return true;
		}
		head = head->next;
	}
	return false;
}

bool searchrecursive(node*head, int key)
{
	if (head == NULL)
	{
		return false;
	}
	if (head->d == key)
	{
		return true;
	}
	else
	{
		return searchrecursive(head->next, key);
	}
}

node* takeinput()
{
	int data;
	cin >> data;
	node*head = NULL;
	while (data != -1)
	{
		insertathead(head, data);
		cin >> data;
	}
	return head;
}



void reverse(node*&head)
{
	node*curr = head;
	node* prev = NULL;
	node* n;
	while (curr != NULL)
	{
		n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;
	}
	head = prev;
}

node* recreverse(node* head)
{
	if (head->next == NULL or head == NULL)
	{
		return head;
	}

	node* shead = recreverse(head->next);

	node*temp = head->next;
	temp->next = head;
	head->next = NULL;
	return shead;
}
node* midpoint(node* head)
{
	if (head == NULL or head->next == NULL)
	{
		return head;
	}
	node*slow = head;
	node* fast = head->next;
	while (fast != NULL and fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

node* kthnode_from_end(node* head, int p)
{
	if (head == NULL or head->next == NULL)
	{
		return head;
	}
	node* slow = head;
	node* fast = head;
	while (head != NULL)
	{
		if (p > 0)
		{
			fast = fast->next;
			p--;
		}
		else
		{
			slow = slow->next;
			fast = fast->next;
		}
		head = head->next;
	}
	return slow;
}
node* merge(node*a, node* b)
{
	if (a == NULL)
	{
		return b;
	}
	if (b == NULL)
	{
		return a;
	}

	node* c;
	if (a->d < b->d)
	{
		c = a;
		c->next = merge(a->next, b);
	}
	else
	{
		c = b;
		c->next = merge(a, b->next);
	}
	return c;
}
node* mergesort(node* head)
{
	if (head == NULL or head->next == NULL)
	{
		return head;
	}

	node* mid = midpoint(head);
	node* a = head;
	node* b = mid->next;

	mid->next = NULL;

	a = mergesort(a);
	b = mergesort(b);
	node* c = merge(a, b);
	return c;


}

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* head = takeinput();
	print(head);
	cout << endl;
	node* ans = mergesort(head);
	print(ans);
	cout << endl;
	//node* c = merge(a, b);
	//print(c);
	//cout << endl;
	//node* ans = recreverse(head);
	//print(ans);
	//node* mid = midpoint(head);
	//node* last = kthnode_from_end(head, 5);
	//cout << last->d;
	/*insertathead(head, 4);
	insertathead(head, 2);
	insertathead(head, 1);
	insertathead(head, 0);

	print(head);
	insertatmiddle(head, 3, 3);
	insertattail(head, 5);
	cout << endl;
	print(head);
	deleteathead(head);
	cout << endl;
	print(head);
	deleteatmiddle(head, 4);
	cout << endl;
	print(head);
	cout << endl;
	if (searchrecursive (head, 1))
	{
		cout << "found";
	}
	else
	{
		cout << "not found";
	}*/

}
