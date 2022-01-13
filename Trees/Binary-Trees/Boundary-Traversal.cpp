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

void leftBoundaryTraversal(Node *root, queue<int> &ans)
{
	if(root->left == NULL && root->right == NULL)
		return;

	ans.push(root->data);
	if(root->left != NULL)
		leftBoundaryTraversal(root->left, ans);
	else
		leftBoundaryTraversal(root->right, ans);
}

void leafNodeTraversal(Node *root, queue<int> &ans)
{
	if(root->left == NULL && root->right == NULL)
	{
		ans.push(root->data);
		return;
	}

	if(root->left != NULL)
		leafNodeTraversal(root->left, ans);
	if(root -> right != NULL)
		leafNodeTraversal(root->right, ans);
}

void rightBoundaryTraversal(Node *root, stack<int> &ans)
{
	if(root->left == NULL && root->right == NULL)
		return;

	ans.push(root->data);
	if(root->right != NULL)
		rightBoundaryTraversal(root->right, ans);
	else
		rightBoundaryTraversal(root->left, ans);
}

void boundaryTraversal(Node *root)
{
	queue<int> ans;
	stack<int> st;
	leftBoundaryTraversal(root, ans);
	leafNodeTraversal(root, ans);
	if(root->right != NULL)
		rightBoundaryTraversal(root->right, st);

	while(!st.empty())
	{
		ans.push(st.top());
		st.pop();
	}

	while(!ans.empty())
	{
		cout << ans.front() << ' ';
		ans.pop();
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
  	boundaryTraversal(root);


    return 0;
}