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

void iterativePostOrderTraversal2(Node *root)
{
    stack<Node *> st;
    Node *cur = root;
    vector<Node *> ans;
    while(cur != NULL || !st.empty())
    {
        if(cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            Node *temp = st.top()->right;
            if(temp != NULL)
                cur = temp;
            else
            {
                temp = st.top();
                st.pop();
                ans.push_back(temp);
                while(!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp);
                }
            }
        }
    }

    for(Node *i : ans)
        cout << i->data << ' ';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    iterativePostOrderTraversal2(root);

    return 0;
}