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

void flattenTreeUsingRec(Node *root, Node *&pre)
{
	if(root == NULL)
		return;

	flattenTreeUsingRec(root->right, pre);
	flattenTreeUsingRec(root->left, pre);

	root->right = pre;
	root->left = NULL;
	pre = root;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    Node *pre = NULL;
    flattenTreeUsingRec(root, pre);
    while(root)
    {
    	cout << root->data << ' ';
    	root = root->right;
    }

    return 0;
}