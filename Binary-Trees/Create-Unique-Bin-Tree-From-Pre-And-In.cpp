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

void print(Node *root)
{
	if(root == NULL)
		return;
	cout << root->data << ' ';
	print(root->left);
	print(root->right);
}

Node *createBinTreeFromInorderAndPreorder(int inorderStart, int inorderEnd, int preorderStart, int preorderEnd, vector<int> &inOrder, vector<int> &preOrder, vector<int> &indexInInorder)
{
	if((preorderStart > preorderEnd) or (inorderStart > inorderEnd))
		return NULL;

	Node *newNode = new Node(preOrder[preorderStart]);
	int leftSubtreeSize = indexInInorder[preOrder[preorderStart]]; // 0-indexing

	newNode->left = createBinTreeFromInorderAndPreorder(inorderStart, indexInInorder[preOrder[preorderStart]] - 1, preorderStart + 1, preorderStart + leftSubtreeSize, inOrder, preOrder, indexInInorder);

	newNode->right = createBinTreeFromInorderAndPreorder(indexInInorder[preOrder[preorderStart]] + 1, inorderEnd, preorderStart + leftSubtreeSize + 1, preorderEnd, inOrder, preOrder, indexInInorder);

	return newNode;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> inOrder(N), preOrder(N), indexInInorder(100, 0);
    for(int i = 0; i < N; i++)
    {
    	cin >> inOrder[i];
    	indexInInorder[inOrder[i]] = i;
    }
    for(int i = 0; i < N; i++)
    	cin >> preOrder[i];

    Node *root = createBinTreeFromInorderAndPreorder(0, N - 1, 0, N - 1, inOrder, preOrder, indexInInorder);
    print(root);

    return 0;
}