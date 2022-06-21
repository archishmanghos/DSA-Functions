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

int diameterOfTree(Node *root, int &ans)
{
	if(root == NULL)
		return 0;
	
	int leftHeight = diameterOfTree(root->left, ans);
	int rightHeight = diameterOfTree(root->right, ans);

	ans = max(ans, (leftHeight + rightHeight));
	return 1 + max(leftHeight, rightHeight);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    int ans = 0;
    int height = diameterOfTree(root, ans);
    cout << ans;

    return 0;
}