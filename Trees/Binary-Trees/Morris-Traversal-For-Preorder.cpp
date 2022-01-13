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

void morrisTraversalPreorder(Node *root)
{
	Node *curNode = root;
	while(curNode != NULL)
	{
		if(curNode->left == NULL)
		{
			cout << curNode->data << ' ';
			curNode = curNode->right;
			continue;
		}

		Node *lastNodeonLeftSubTree = curNode->left;
		while(lastNodeonLeftSubTree->right and lastNodeonLeftSubTree->right != curNode)
				lastNodeonLeftSubTree = lastNodeonLeftSubTree->right;

		if(lastNodeonLeftSubTree->right == curNode)
		{
			lastNodeonLeftSubTree->right = NULL;
			curNode = curNode->right;
		}
		else
		{
			cout << curNode->data << ' ';
			lastNodeonLeftSubTree->right = curNode;
			curNode = curNode->left;
		}
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    morrisTraversalPreorder(root);

    return 0;
}