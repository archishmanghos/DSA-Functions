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

void storeEverythingOnLeft(Node *root, stack<Node *> &st) {
    while (root) {
        st.push(root);
        root = root->left;
    }
}

Node *nextt(stack<Node *> &st) {
    if (!st.empty()) {
        Node *ans = st.top();
        st.pop();
        if (ans->right) {
            storeEverythingOnLeft(ans->right, st);
        }
        return ans;
    } else {
        return NULL;
    }
}

bool hasNext(stack<Node *> st) {
    return !st.empty();
}

void binarySearchTreeIterator(Node *root, vector<char> &instructions) {
    stack<Node *> st;
    storeEverythingOnLeft(root, st);
    for (char instruction: instructions) {
        if (instruction == 'N') {
            Node *ans = nextt(st);
            cout << (ans ? ans->data : -1) << '\n';
        } else {
            cout << (hasNext(st) ? "Yes, next available" : "No next") << '\n';
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node *root = buildTree();
    vector<char> instructions = {'H', 'N', 'N', 'N', 'H', 'N', 'N', 'N', 'N', 'H', 'N', 'N', 'N', 'H'}; // H represents hasNext() function and N represent next() function
    binarySearchTreeIterator(root, instructions);

    return 0;
}