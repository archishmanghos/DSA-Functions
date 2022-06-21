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

void bfs(Node *root) {
    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 1; i <= sz; i++) {
            Node *curNode = q.front();
            cout << curNode->data << ' ';
            q.pop();
            if (curNode->left != NULL)
                q.push(curNode->left);
            if (curNode->right != NULL)
                q.push(curNode->right);
        }
        cout << '\n';
    }
}

Node *
createBSTfromPreOrderUsingSortingMethod(int preOrderStart, int preOrderEnd, vector<int> &preOrder, int inOrderStart,
                                        int inOrderEnd, vector<int> &inOrder, vector<int> &indexInInorder) {
    if ((preOrderStart > preOrderEnd) or (inOrderStart > inOrderEnd)) {
        return NULL;
    }

    Node *newNode = new Node(preOrder[preOrderStart]);
    int index = indexInInorder[preOrder[preOrderStart]];
    int leftSubtreeSize = index - inOrderStart;

    int newPreOrderStart = preOrderStart + 1;
    int newPreOrderEnd = preOrderStart + leftSubtreeSize;
    int newInOrderStart = inOrderStart;
    int newInOrderEnd = index - 1;

    newNode->left = createBSTfromPreOrderUsingSortingMethod(newPreOrderStart, newPreOrderEnd, preOrder, newInOrderStart,
                                                            newInOrderEnd, inOrder, indexInInorder);

    newPreOrderStart = preOrderStart + leftSubtreeSize + 1;
    newPreOrderEnd = preOrderEnd;
    newInOrderStart = index + 1;
    newInOrderEnd = inOrderEnd;

    newNode->right = createBSTfromPreOrderUsingSortingMethod(newPreOrderStart, newPreOrderEnd, preOrder,
                                                             newInOrderStart, newInOrderEnd, inOrder, indexInInorder);

    return newNode;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N;
    cin >> N;
    vector<int> preOrder(N), inOrder(N);
    for (int i = 0; i < N; i++) {
        cin >> preOrder[i];
        inOrder[i] = preOrder[i];
    }
    sort(inOrder.begin(), inOrder.end());
    int maxElement = inOrder[N - 1];
    vector<int> indexInInorder(maxElement + 2, 0);
    for (int i = 0; i < N; i++) {
        indexInInorder[inOrder[i]] = i;
    }

    Node *root = createBSTfromPreOrderUsingSortingMethod(0, N - 1, preOrder, 0, N - 1, inOrder, indexInInorder);
    bfs(root);

    return 0;
}