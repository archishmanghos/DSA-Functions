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

bool pathFromRootToNode(vector<int> &path, Node *root, int &dest)
{
    if(root == NULL)
        return false;

    path.push_back(root->data);
    if(root->data == dest)
        return true;

    if(pathFromRootToNode(path, root->left, dest) || pathFromRootToNode(path, root->right, dest))
        return true;

    path.pop_back();
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    vector<int> path;
    int dest;
    cin >> dest;

    bool ans = pathFromRootToNode(path, root, dest);
    if(ans)
    {
    	for(int i : path)
    		cout << i << ' ';
    }
    else
    	cout << -1;

    return 0;
}