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

int floorInBST(Node *root, int val) // greatest value such that value is <= given val
{
	int ans = -INF;
	while(root)
	{
		ans = root->data <= val ? max(ans, root->data) : ans;
		root = root->data >= val ? root->left : root->right;
	}

	return (ans == -INF ? -1 : ans);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    cout << floorInBST(root, 14);

    return 0;
}