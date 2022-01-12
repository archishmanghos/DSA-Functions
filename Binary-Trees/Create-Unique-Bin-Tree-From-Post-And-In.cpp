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

Node *createBinTreeFromInorderAndPostorder(int inorderStart, int inorderEnd, int postOrderStart, int postOrderEnd, vector<int> &inOrder, vector<int> &postOrder, vector<int> &indexInInorder)
{
	if((postOrderStart > postOrderEnd) or (inorderStart > inorderEnd))
		return NULL;

	Node *newNode = new Node(postOrder[postOrderEnd]);
	int leftSubtreeSize = indexInInorder[postOrder[postOrderEnd]]; // 0-indexing
	int numsLeft = leftSubtreeSize - inorderStart;

	newNode->left = createBinTreeFromInorderAndPostorder(inorderStart, leftSubtreeSize - 1, postOrderStart, postOrderStart + numsLeft - 1, inOrder, postOrder, indexInInorder);

	newNode->right = createBinTreeFromInorderAndPostorder(leftSubtreeSize + 1, inorderEnd, postOrderStart + numsLeft, postOrderEnd - 1, inOrder, postOrder, indexInInorder);

	return newNode;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Node *root = buildTree();
    int N;
    cin >> N;
    vector<int> inOrder(N), postOrder(N), indexInInorder(100, 0);
    for(int i = 0; i < N; i++)
    {
    	cin >> inOrder[i];
    	indexInInorder[inOrder[i]] = i;
    }
    for(int i = 0; i < N; i++)
    	cin >> postOrder[i];

    Node *root = createBinTreeFromInorderAndPostorder(0, N - 1, 0, N - 1, inOrder, postOrder, indexInInorder);
    print(root);

    return 0;
}