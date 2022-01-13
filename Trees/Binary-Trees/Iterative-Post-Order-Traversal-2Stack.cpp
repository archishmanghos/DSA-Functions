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

void iterativePostOrderTraversal1(Node *root)
{
    stack<Node *> st1, st2;
    st1.push(root);

    while(!st1.empty())
    {
        Node *curNode = st1.top();
        st1.pop();

        st2.push(curNode);
        if(curNode->left != NULL)
            st1.push(curNode->left);
        if(curNode->right != NULL)
            st1.push(curNode->right);
    }

    while(!st2.empty())
    {
        cout << st2.top()->data << ' ';
        st2.pop();
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    iterativePostOrderTraversal1(root);

    return 0;
}