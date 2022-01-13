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

void allTraversals(Node *root)
{
	vector<int> preOrder, inOrder, postOrder;
	stack<pair<Node *, int>> st;
	st.push({root, 1});

	while(!st.empty())
	{
		pair<Node *, int> curNode = st.top();
		st.pop();
		if(curNode.second == 1)
		{
			preOrder.push_back(curNode.first->data);
			curNode.second += 1;
			st.push(curNode);
			if(curNode.first->left != NULL)
				st.push({curNode.first->left, 1});
		}
		else if(curNode.second == 2)
		{
			inOrder.push_back(curNode.first->data);
			curNode.second += 1;
			st.push(curNode);
			if(curNode.first->right != NULL)
				st.push({curNode.first->right, 1});
		}
		else
			postOrder.push_back(curNode.first->data);
	}

	for(int i : preOrder)
		cout << i << ' ';
	cout << '\n';
	for(int i : inOrder)
		cout << i << ' ';
	cout << '\n';
	for(int i : postOrder)
		cout << i << ' ';
	cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    allTraversals(root);

    return 0;
}