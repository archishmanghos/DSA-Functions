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

bool checkIfIdentical(Node *root1, Node *root2)
{
	if(root1 == NULL || root2 == NULL)
		return root1 == root2;
	return ((root1->data == root2->data) && checkIfIdentical(root1->left, root2->left) && checkIfIdentical(root1 -> right, root2->right));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root1 = buildTree();
    Node *root2 = buildTree();
    cout << checkIfIdentical(root1, root2);

    return 0;
}