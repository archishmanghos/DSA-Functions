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

void bottomView(Node *root)
{
	queue<pair<Node *, int>> q;
	q.push({root, 0});
	map<int, Node *> ans;

	while(!q.empty())
	{
		pair<Node *, int> curNode = q.front();
		q.pop();

		ans[curNode.second] = curNode.first;
		if(curNode.first->left)
			q.push({curNode.first->left, curNode.second - 1});
		if(curNode.first->right)
			q.push({curNode.first->right, curNode.second + 1});
	}

	for(auto i : ans)
		cout << i.second->data << ' ';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
  	bottomView(root);


    return 0;
}