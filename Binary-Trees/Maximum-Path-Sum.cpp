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

int maximumPathSum(Node *root, int &ans)
{
	if(root == NULL)
		return 0;

	int leftPathSum = max((int)0, maximumPathSum(root->left, ans));
	int rightPathSum = max((int)0, maximumPathSum(root->right, ans));

	ans = max(ans, root->data + leftPathSum + rightPathSum);
	return (root->data + max(leftPathSum, rightPathSum));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    int ans = -INF;
    int height = maximumPathSum(root, ans);
    cout << ans;

    return 0;
}