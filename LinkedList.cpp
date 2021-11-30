#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

struct Node
{
	int data;
	struct Node *next;
};

Node *head;

// creation

void create(int A[], int N)
{
	struct Node *temp;
	struct Node *last = (struct Node *)malloc(sizeof(struct Node));
	head = (struct Node *)malloc(sizeof(struct Node));
	head->data = A[0];
	head->next = NULL;
	last = head;

	for(int i = 1; i < N; i++)
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = A[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

// display by for loop 

void displayLoop(struct Node *p)
{
	while(p != NULL)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << '\n';
}

// display by recursion 

void displayRecursive(struct Node *p)
{
	if(p == NULL)
	{
		cout << '\n';
		return;
	}

	cout << p->data << ' ';
	displayRecursive(p->next);
}

// counting nodes

void countNodes(struct Node *p)
{
	int ans = 0;
	while(p != NULL)
	{
		ans += 1;
		p = p->next;
	}

	cout << ans << '\n';
}

// sum of values of every node

void sumOfNodes(struct Node *p)
{
	int ans = 0;
	while(p != NULL)
	{
		ans += p->data;
		p = p->next;
	}

	cout << ans << '\n';
}

// finding the max value of the linked list

void maxNode(struct Node *p)
{
	int ans = -INF;
	while(p != NULL)
	{
		ans = max(ans, p->data);
		p = p->next;
	}

	cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++)
    	cin >> A[i];

    create(A, N);
    displayLoop(head);
    displayRecursive(head);
    countNodes(head);
    sumOfNodes(head);
    maxNode(head);

    return 0;
}