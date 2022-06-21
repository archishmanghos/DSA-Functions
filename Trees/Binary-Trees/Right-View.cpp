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

void rightView(Node *root, int level, vector<int> &ans)
{
	if(root == NULL)
		return;

	if(level == ans.size())
		ans.push_back(root->data);
	rightView(root->right, level + 1, ans);
	rightView(root->left, level + 1, ans);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
  	vector<int> ans;
  	rightView(root, 0, ans);
  	for(int i : ans)
  		cout << i << ' ';

    return 0;
}