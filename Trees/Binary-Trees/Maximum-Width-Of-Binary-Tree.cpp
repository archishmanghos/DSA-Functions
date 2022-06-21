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

void maximumWidthOfBinaryTree(Node *root)
{
	int ans = 1;
	queue<pair<Node *, int>> q;
	q.push({root, 1});
	while(!q.empty())
	{
		int minn, sz = q.size();
		for(int i = 1; i <= sz; i++)
		{
			pair<Node *, int> index = q.front();
			q.pop();
			if(i == 1)
				minn = index.second;
			else
				ans = max(ans, index.second - minn + 1);

			if(index.first->left)
				q.push({index.first->left, index.second * 2 - 1});
			if(index.first->right)
				q.push({index.first->right, index.second * 2});
		}
	}

	cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
  	maximumWidthOfBinaryTree(root);

    return 0;
}