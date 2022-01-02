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

void preorderTraversal(Node *root)
{
	if(root == NULL)
		return;
	cout << root->data << ' ';
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

void childrenSumProperty(Node *root)
{
	if(root == NULL)
		return;

	int child = 0;
	if(root->left)
		child += root->left->data;
	if(root->right)
		child += root->right->data;

	if(child <= root->data)
	{
		if(root->left)
			root->left->data = root->data;
		if(root->right)
			root->right->data = root->data;
	}
	else
		root->data = child;
	
	childrenSumProperty(root->left);
	childrenSumProperty(root->right);
	
	child = 0;
	if(root->left)
		child += root->left->data;
	if(root->right)
		child += root->right->data;
	if(root->left or root->right)
		root->data = child;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
  	childrenSumProperty(root);
  	preorderTraversal(root);

    return 0;
}