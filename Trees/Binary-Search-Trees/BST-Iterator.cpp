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

void storeEverythingOnLeft(Node *root, stack<Node *> &stNext) {
    while (root) {
        stNext.push(root);
        root = root->left;
    }
}

void storeEverythingOnRight(Node *root, stack<Node *> &stBefore) {
    while (root) {
        stBefore.push(root);
        root = root->right;
    }
}

Node *nextt(stack<Node *> &stNext) {
    if (!stNext.empty()) {
        Node *ans = stNext.top();
        stNext.pop();
        if (ans->right) {
            storeEverythingOnLeft(ans->right, stNext);
        }
        return ans;
    } else {
        return NULL;
    }
}

Node *beforee(stack<Node *> &stBefore) {
    if (!stBefore.empty()) {
        Node *ans = stBefore.top();
        stBefore.pop();
        if (ans->left) {
            storeEverythingOnRight(ans->left, stBefore);
        }
        return ans;
    } else {
        return NULL;
    }
}

bool hasNext(stack<Node *> st) {
    return !st.empty();
}

bool hasBefore(stack<Node *> st) {
    return !st.empty();
}

void binarySearchTreeIterator(Node *root, vector<string> &instructions) {
    stack<Node *> stNext, stBefore;
    storeEverythingOnLeft(root, stNext);
    storeEverythingOnRight(root, stBefore);
    for (string instruction: instructions) {
        if (instruction == "N") {
            Node *ans = nextt(stNext);
            cout << (ans ? ans->data : -1) << '\n';
        } else if (instruction == "B") {
            Node *ans = beforee(stBefore);
            cout << (ans ? ans->data : -1) << '\n';
        } else if (instruction == "HN") {
            cout << (hasNext(stNext) ? "Yes, next available" : "No next") << '\n';
        } else {
            cout << (hasBefore(stBefore) ? "Yes, previous available" : "No previous") << '\n';
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
    vector<string> instructions1 = {"HN", "N", "N", "N", "HN", "N", "N", "N", "N", "HN", "N", "N", "N", "N",
                                    "HN"}; // HN represents hasNext() function and N represent next() function
    vector<string> instructions2 = {"HB", "B", "B", "B", "HB", "B", "B", "B", "B", "HB", "B", "B", "B", "B",
                                    "HB"}; // HB represents hasBefore() function and B represent before() function
    binarySearchTreeIterator(root, instructions2);

    return 0;
}