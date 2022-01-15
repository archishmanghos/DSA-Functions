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

void flattenTreeUsingStack(Node *root, Node *&pre)
{
	stack<Node *> st;
	st.push(root);

	while(!st.empty())
	{
		Node *curNode = st.top();
		st.pop();

		if(curNode->right)
			st.push(curNode->right);
		if(curNode->left)
			st.push(curNode->left);

		if(!st.empty())
			curNode->right = st.top();
		curNode->left = NULL;
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    Node *pre = NULL;
    flattenTreeUsingStack(root, pre);
    while(root)
    {
    	cout << root->data << ' ';
    	root = root->right;
    }

    return 0;
}