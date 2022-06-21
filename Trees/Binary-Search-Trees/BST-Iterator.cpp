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
    int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif

        Node *root = buildTree();
        vector<string> instructions = {"HN", "N", "N", "N", "HN", "N", "N", "N", "N", "HN", "N", "N", "N", "N",
                                       "HN", "HB", "B", "B", "B", "HB", "B", "B", "B", "B", "HB", "B", "B", "B", "B",
                                       "HB"}; // HN represents hasNext() function and N represent next() function, HB represents hasBefore() function and B represent before() function

        BSTIterator nextElement(root, false);
        BSTIterator prevElement(root, true);

        for (string instruction: instructions) {
            if (instruction == "N") {
                Node *ans = nextElement.element();
                cout << (ans ? ans->data : -1) << '\n';
            } else if (instruction == "B") {
                Node *ans = prevElement.element();
                cout << (ans ? ans->data : -1) << '\n';
            } else if (instruction == "HN") {
                cout << (nextElement.hasElement() ? "Yes, next available" : "No next") << '\n';
            } else {
                cout << (prevElement.hasElement() ? "Yes, previous available" : "No previous") << '\n';
            }
        }

        return 0;
    }
};