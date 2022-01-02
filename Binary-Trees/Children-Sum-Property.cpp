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

int childrenSumProperty(Node *root)
{
	if(root == NULL)
		return 0;

	int leftChild, rightChild;
	if(root->left != NULL && root->right != NULL)
	{
		leftChild = root->left->data;
		rightChild = root->right->data;
		int sum = leftChild + rightChild;
		if(sum <= root->data)
			root->left->data = root->right->data = root->data;
		else
			root->data = sum;
	}
	
	leftChild = childrenSumProperty(root->left);
	rightChild = childrenSumProperty(root->right);
	root->data = max(root->data, leftChild + rightChild);
	return root->data;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
  	int rootData = childrenSumProperty(root);
  	preorderTraversal(root);

    return 0;
}