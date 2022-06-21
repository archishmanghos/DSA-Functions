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

int balancedBinaryTree(Node *root)
{
	if(root == NULL)
		return 0;

	int leftHeight = balancedBinaryTree(root->left);
	int rightHeight = balancedBinaryTree(root->right);

	if(leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
		return -1;
	return 1 + max(leftHeight, rightHeight);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    cout << balancedBinaryTree(root);

    return 0;
}