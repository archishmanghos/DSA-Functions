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

void searchNodeInBST(Node *root, Node *searchNode)
{
	while(root and root->data != searchNode->data)
		root = (searchNode->data < root->data ? root->left : root->right);

	cout << (root ? root->data : -1);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    Node *searchNode = new Node(9);
    searchNodeInBST(root, searchNode);

    return 0;
}