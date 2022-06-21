#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int value;

struct Node
{
	int data;
	struct Node *left, *right;
	Node(int input)
	{
		data = input;
		left = right = NULL;
	}
};

Node* buildTree()
{
	cin >> value;
	if(value == -1)
		return NULL;

	Node* root = new Node(value);
	root->left = buildTree();
	root->right = buildTree();
}

void print(Node *root)
{
	if(root == NULL)
		return;
	cout << root->data << ' ';
	print(root->left);
	print(root->right);
}

void insertNodeInBST(Node *root, int &val)
{
	if(!root)
	{
	    Node *newNode = new Node(val);
	    root = newNode;
	    return;
	}
	
	Node *cur = root;
	while(1)
	{
	    if(val < cur->data)
	    {
	        if(cur->left)
	            cur = cur->left;
	        else
	        {
	            Node *newNode = new Node(val);
	            cur->left = newNode;
	            return;
	        }
	    }
	    else
	    {
	        if(cur->right)
	            cur = cur->right;
	        else
	        {
	            Node *newNode = new Node(val);
	            cur->right = newNode;
	            return;
	        }
	    }
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    int val = 5;
  	insertNodeInBST(root, val);
  	print(root);

    return 0;
}