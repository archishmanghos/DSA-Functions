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

int lowestCommonAncestor(Node *root, int &lca1, int &lca2)
{
	if(root == NULL)
		return -1;
	if(root->data == lca1 || root->data == lca2)
		return root->data;
	int ret1 = lowestCommonAncestor(root->left, lca1, lca2);
	int ret2 = lowestCommonAncestor(root->right, lca1, lca2);
	if(ret1 != -1 && ret2 != -1)
		return root->data;
	if(ret1 != -1)
		return ret1;
	if(ret2 != -1)
		return ret2;
	return -1;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    int lca1 = 4, lca2 = 7;
  	cout << lowestCommonAncestor(root, lca1, lca2);

    return 0;
}