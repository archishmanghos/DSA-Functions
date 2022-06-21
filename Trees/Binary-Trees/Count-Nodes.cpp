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

int countNodes(Node *root)
{
	if(root == NULL)
		return 0;

	Node *tempNode = root;
	int leftHeight = 0, rightHeight = 0;
	while(tempNode)
	{
		leftHeight += 1;
		tempNode = tempNode->left;
	}

	tempNode = root;
	while(tempNode)
	{
		rightHeight += 1;
		tempNode = tempNode->right;
	}

	if(leftHeight == rightHeight)
		return (int)(1 << leftHeight) - 1;
	else
		return 1 + countNodes(root->left) + countNodes(root->right);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    cout << countNodes(root);

    return 0;
}