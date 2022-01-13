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

void verticalOrderTraversal(Node *root)
{
	queue<pair<Node *, pair<int, int>>> q;
	q.push({root, {0, 0}});
	map<int, map<int, multiset<int>>> mp;

	while(!q.empty())
	{
		pair<int, int> cur = q.front().second;
		Node *curNode = q.front().first;
		q.pop();

		mp[cur.first][cur.second].insert(curNode->data);
		if(curNode->left != NULL)
			q.push({curNode->left, {cur.first - 1, cur.second + 1}});
		if(curNode->right != NULL)
			q.push({curNode->right, {cur.first + 1, cur.second + 1}});
	}

	vector<vector<int>> ans;
	for(auto i : mp)
	{
		vector<int> v;
		for(auto j : i.second)
		{
			for(int k : j.second)
				v.push_back(k);
		}
		ans.push_back(v);
	}

	for(auto i : ans)
	{
		for(int j : i)
			cout << j << ' ';
		cout << '\n';
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
  	verticalOrderTraversal(root);


    return 0;
}