#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int value;

struct Node {
    int data;
    struct Node *left, *right;

    Node(int input) {
        data = input;
        left = right = NULL;
    }
};

Node *buildTree() {
    cin >> value;
    if (value == -1)
        return NULL;

    Node *root = new Node(value);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

class BSTIterator {
    stack<Node *> st;
    bool reverse;
public:
    BSTIterator(Node *root, bool rev) {
        reverse = rev;
        storeEverything(root);
    }

    bool hasElement() {
        return !st.empty();
    }

    Node *element() {
        Node *ans = st.top();
        st.pop();
        if (reverse) {
            storeEverything(ans->left);
        } else {
            storeEverything(ans->right);
        }
        return ans;
    }

private:
    void storeEverything(Node *root) {
        while (root) {
            st.push(root);
            root = (reverse ? root->right : root->left);
        }
    }
};

class Solution {
public:
    bool twoSumInBST(Node *root, int givenSum) {
        BSTIterator low(root, false);
        BSTIterator high(root, true);

        Node *i = low.element();
        Node *j = high.element();

        while (i->data < j->data) {
            int sum = i->data + j->data;
            if (sum == givenSum) {
                return true;
            } else {
                if (sum < givenSum) {
                    i = low.element();
                } else {
                    j = high.element();
                }
            }
        }

        return false;
    }

    int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif

        Node *root = buildTree();
        cout << twoSumInBST(root, 11);

        return 0;
    }
};