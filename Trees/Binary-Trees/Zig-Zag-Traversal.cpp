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

void zigZagTraversal(Node *root, vector<deque<int>> &ans, int &j)
{
	queue<Node *> q;
	bool rotate = false;
	q.push(root);
	while(!q.empty())
	{
		int sz = q.size();
		for(int i = 1; i <= sz; i++)
		{
			Node *curNode = q.front();
			q.pop();
			if(rotate)
				ans[j].push_front(curNode->data);
			else
				ans[j].push_back(curNode->data);
			if(curNode->left != NULL)
				q.push(curNode->left);
			if(curNode->right != NULL)
				q.push(curNode->right);
		}
		j += 1;
		rotate = !rotate;
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    vector<deque<int>> ans(6);
    int j = 0;
    zigZagTraversal(root, ans, j);

    for(int i = 0; i < j; i++)
    {
    	while(!ans[i].empty())
    	{
    		cout << ans[i].front() << ' ';
    		ans[i].pop_front();
    	}
    	cout << '\n';
    }

    return 0;
}