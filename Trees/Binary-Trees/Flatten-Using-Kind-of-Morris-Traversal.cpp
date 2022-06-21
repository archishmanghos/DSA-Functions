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

void flattenTreeUsingKindOfMorrisTraversal(Node *root)
{
	Node *curNode = root;
	while(curNode)
	{
		if(curNode->left)
		{
			Node *lastNodeonLeftSubTree = curNode->left;
			while(lastNodeonLeftSubTree->right)
				lastNodeonLeftSubTree = lastNodeonLeftSubTree->right;
			lastNodeonLeftSubTree->right = curNode->right;
			curNode->right = curNode->left;
			curNode->left = NULL;
		}
		curNode = curNode->right;
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    flattenTreeUsingKindOfMorrisTraversal(root);
    while(root)
    {
    	cout << root->data << ' ';
    	root = root->right;
    }

    return 0;
}