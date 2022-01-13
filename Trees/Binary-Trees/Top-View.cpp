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

void topView(Node *root)
{
	queue<pair<Node *, int>> q;
	map<int, int> mp;
	q.push({root, 0});

	while(!q.empty())
	{
		pair<Node *, int> curNode = q.front();
		q.pop();

		if(mp.find(curNode.second) == mp.end())
			mp[curNode.second] = curNode.first->data;

		if(curNode.first->left)
			q.push({curNode.first->left, curNode.second - 1});
		if(curNode.first->right)
			q.push({curNode.first->right, curNode.second + 1});
	}

	for(auto i : mp)
		cout << i.second << ' ';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
  	topView(root);

    return 0;
}