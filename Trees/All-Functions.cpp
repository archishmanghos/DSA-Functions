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

void print(Node *root) {
    if (root == NULL)
        return;
    cout << root->data << ' ';
    print(root->left);
    print(root->right);
}

void preorderTraversal(Node *root) {
    if (root == NULL)
        return;
    cout << root->data << ' ';
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node *root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->data << ' ';
    inorderTraversal(root->right);
}

void postorderTraversal(Node *root) {
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << ' ';
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

void preorderIterativeTraversal(Node *root) {
    stack<Node *> st;
    st.push(root);

    while (!st.empty()) {
        Node *curNode = st.top();
        st.pop();
        cout << curNode->data << ' ';
        if (curNode->right != NULL)
            st.push(curNode->right);
        if (curNode->left != NULL)
            st.push(curNode->left);
    }
}

void inorderIterativeTraversal(Node *root) {
    stack<Node *> st;
    struct Node *curNode = root;
    while (1) {
        if (curNode == NULL) {
            if (st.empty())
                break;
            Node *nowNode = st.top();
            st.pop();
            cout << nowNode->data << ' ';
            curNode = nowNode->right;
        } else {
            st.push(curNode);
            curNode = curNode->left;
        }
    }
}

void iterativePostOrderTraversal1(Node *root) {
    stack<Node *> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        Node *curNode = st1.top();
        st1.pop();

        st2.push(curNode);
        if (curNode->left != NULL)
            st1.push(curNode->left);
        if (curNode->right != NULL)
            st1.push(curNode->right);
    }

    while (!st2.empty()) {
        cout << st2.top()->data << ' ';
        st2.pop();
    }
}

void iterativePostOrderTraversal2(Node *root) {
    stack<Node *> st;
    Node *cur = root;
    vector<Node *> ans;
    while (cur != NULL || !st.empty()) {
        if (cur != NULL) {
            st.push(cur);
            cur = cur->left;
        } else {
            Node *temp = st.top()->right;
            if (temp != NULL)
                cur = temp;
            else {
                temp = st.top();
                st.pop();
                ans.push_back(temp);
                while (!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp);
                }
            }
        }
    }

    for (Node *i: ans)
        cout << i->data << ' ';
}

void allTraversals(Node *root) {
    vector<int> preOrder, inOrder, postOrder;
    stack<pair<Node *, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        pair<Node *, int> curNode = st.top();
        st.pop();
        if (curNode.second == 1) {
            preOrder.push_back(curNode.first->data);
            curNode.second += 1;
            st.push(curNode);
            if (curNode.first->left != NULL)
                st.push({curNode.first->left, 1});
        } else if (curNode.second == 2) {
            inOrder.push_back(curNode.first->data);
            curNode.second += 1;
            st.push(curNode);
            if (curNode.first->right != NULL)
                st.push({curNode.first->right, 1});
        } else
            postOrder.push_back(curNode.first->data);
    }

    for (int i: preOrder)
        cout << i << ' ';
    cout << '\n';
    for (int i: inOrder)
        cout << i << ' ';
    cout << '\n';
    for (int i: postOrder)
        cout << i << ' ';
    cout << '\n';
}

int heightOfTreeRecursion(Node *root) {
    if (root == NULL)
        return 0;

    return 1 + max(heightOfTreeRecursion(root->left), heightOfTreeRecursion(root->right));
}

bool pathFromRootToNode(vector<int> &path, Node *root, int &dest) {
    if (root == NULL)
        return false;

    path.push_back(root->data);
    if (root->data == dest)
        return true;

    if (pathFromRootToNode(path, root->left, dest) || pathFromRootToNode(path, root->right, dest))
        return true;

    path.pop_back();
    return false;
}

int balancedBinaryTree(Node *root) {
    if (root == NULL)
        return 0;

    int leftHeight = balancedBinaryTree(root->left);
    int rightHeight = balancedBinaryTree(root->right);

    if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
        return -1;
    return 1 + max(leftHeight, rightHeight);
}

int diameterOfTree(Node *root, int &ans) {
    if (root == NULL)
        return 0;

    int leftHeight = diameterOfTree(root->left, ans);
    int rightHeight = diameterOfTree(root->right, ans);

    ans = max(ans, (leftHeight + rightHeight));
    return 1 + max(leftHeight, rightHeight);
}

int maximumPathSum(Node *root, int &ans) {
    if (root == NULL)
        return 0;

    int leftPathSum = max((int) 0, maximumPathSum(root->left, ans));
    int rightPathSum = max((int) 0, maximumPathSum(root->right, ans));

    ans = max(ans, root->data + leftPathSum + rightPathSum);
    return (root->data + max(leftPathSum, rightPathSum));
}

bool checkIfIdentical(Node *root1, Node *root2) {
    if (root1 == NULL || root2 == NULL)
        return root1 == root2;
    return ((root1->data == root2->data) && checkIfIdentical(root1->left, root2->left) &&
            checkIfIdentical(root1->right, root2->right));
}

void zigZagTraversal(Node *root, vector<deque<int>> &ans, int &j) {
    queue<Node *> q;
    bool rotate = false;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 1; i <= sz; i++) {
            Node *curNode = q.front();
            q.pop();
            if (rotate)
                ans[j].push_front(curNode->data);
            else
                ans[j].push_back(curNode->data);
            if (curNode->left != NULL)
                q.push(curNode->left);
            if (curNode->right != NULL)
                q.push(curNode->right);
        }
        j += 1;
        rotate = !rotate;
    }

    for (int i = 0; i < j; i++) {
        while (!ans[i].empty()) {
            cout << ans[i].front() << ' ';
            ans[i].pop_front();
        }
        cout << '\n';
    }
}

void leftBoundaryTraversal(Node *root, queue<int> &ans) {
    if (root->left == NULL && root->right == NULL)
        return;

    ans.push(root->data);
    if (root->left != NULL)
        leftBoundaryTraversal(root->left, ans);
    else
        leftBoundaryTraversal(root->right, ans);
}

void leafNodeTraversal(Node *root, queue<int> &ans) {
    if (root->left == NULL && root->right == NULL) {
        ans.push(root->data);
        return;
    }

    if (root->left != NULL)
        leafNodeTraversal(root->left, ans);
    if (root->right != NULL)
        leafNodeTraversal(root->right, ans);
}

void rightBoundaryTraversal(Node *root, stack<int> &ans) {
    if (root->left == NULL && root->right == NULL)
        return;

    ans.push(root->data);
    if (root->right != NULL)
        rightBoundaryTraversal(root->right, ans);
    else
        rightBoundaryTraversal(root->left, ans);
}

void boundaryTraversal(Node *root) {
    queue<int> ans;
    stack<int> st;
    leftBoundaryTraversal(root, ans);
    leafNodeTraversal(root, ans);
    if (root->right != NULL)
        rightBoundaryTraversal(root->right, st);

    while (!st.empty()) {
        ans.push(st.top());
        st.pop();
    }

    while (!ans.empty()) {
        cout << ans.front() << ' ';
        ans.pop();
    }
}

void verticalOrderTraversal(Node *root) {
    queue<pair<Node *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    map<int, map<int, multiset<int>>> mp;

    while (!q.empty()) {
        pair<int, int> cur = q.front().second;
        Node *curNode = q.front().first;
        q.pop();

        mp[cur.first][cur.second].insert(curNode->data);
        if (curNode->left != NULL)
            q.push({curNode->left, {cur.first - 1, cur.second + 1}});
        if (curNode->right != NULL)
            q.push({curNode->right, {cur.first + 1, cur.second + 1}});
    }

    vector<vector<int>> ans;
    for (auto i: mp) {
        vector<int> v;
        for (auto j: i.second) {
            for (int k: j.second)
                v.push_back(k);
        }
        ans.push_back(v);
    }

    for (auto i: ans) {
        for (int j: i)
            cout << j << ' ';
        cout << '\n';
    }
}

void topView(Node *root) {
    queue<pair<Node *, int>> q;
    map<int, int> mp;
    q.push({root, 0});

    while (!q.empty()) {
        pair<Node *, int> curNode = q.front();
        q.pop();

        if (mp.find(curNode.second) == mp.end())
            mp[curNode.second] = curNode.first->data;

        if (curNode.first->left)
            q.push({curNode.first->left, curNode.second - 1});
        if (curNode.first->right)
            q.push({curNode.first->right, curNode.second + 1});
    }

    for (auto i: mp)
        cout << i.second << ' ';
}

void bottomView(Node *root) {
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    map<int, Node *> ans;

    while (!q.empty()) {
        pair<Node *, int> curNode = q.front();
        q.pop();

        ans[curNode.second] = curNode.first;
        if (curNode.first->left)
            q.push({curNode.first->left, curNode.second - 1});
        if (curNode.first->right)
            q.push({curNode.first->right, curNode.second + 1});
    }

    for (auto i: ans)
        cout << i.second->data << ' ';
}

void rightView(Node *root, int level, vector<int> &ans) {
    if (root == NULL)
        return;

    if (level == ans.size())
        ans.push_back(root->data);
    rightView(root->right, level + 1, ans);
    rightView(root->left, level + 1, ans);
}

void leftView(Node *root, int level, vector<int> &ans) {
    if (root == NULL)
        return;

    if (level == ans.size())
        ans.push_back(root->data);
    leftView(root->left, level + 1, ans);
    leftView(root->right, level + 1, ans);
}

bool symmetricTree(Node *root1, Node *root2) {
    if (root1 == NULL || root2 == NULL)
        return root1 == root2;
    if (root1->data != root2->data)
        return false;

    return (symmetricTree(root1->left, root2->right) and symmetricTree(root1->right, root2->left));
}

int lowestCommonAncestor(Node *root, int &lca1, int &lca2) {
    if (root == NULL)
        return -1;
    if (root->data == lca1 || root->data == lca2)
        return root->data;
    int ret1 = lowestCommonAncestor(root->left, lca1, lca2);
    int ret2 = lowestCommonAncestor(root->right, lca1, lca2);
    if (ret1 != -1 && ret2 != -1)
        return root->data;
    if (ret1 != -1)
        return ret1;
    if (ret2 != -1)
        return ret2;
    return -1;
}

void maximumWidthOfBinaryTree(Node *root) {
    int ans = 1;
    queue<pair<Node *, int>> q;
    q.push({root, 1});
    while (!q.empty()) {
        int minn, sz = q.size();
        for (int i = 1; i <= sz; i++) {
            pair<Node *, int> index = q.front();
            q.pop();
            if (i == 1)
                minn = index.second;
            else
                ans = max(ans, index.second - minn + 1);

            if (index.first->left)
                q.push({index.first->left, index.second * 2 - 1});
            if (index.first->right)
                q.push({index.first->right, index.second * 2});
        }
    }

    cout << ans << '\n';
}

void childrenSumProperty(Node *root) {
    if (root == NULL)
        return;

    int child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;

    if (child <= root->data) {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    } else
        root->data = child;

    childrenSumProperty(root->left);
    childrenSumProperty(root->right);

    child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;
    if (root->left or root->right)
        root->data = child;
}

Node *findNode(Node *root, int target) {
    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 1; i <= sz; i++) {
            Node *curNode = q.front();
            q.pop();
            if (curNode->data == target)
                return curNode;
            if (curNode->left)
                q.push(curNode->left);
            if (curNode->right)
                q.push(curNode->right);
        }
    }
}

map<Node *, Node *> assignParent(Node *root) {
    map<Node *, Node *> parent;
    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 1; i <= sz; i++) {
            Node *curNode = q.front();
            q.pop();

            if (curNode->left) {
                parent[curNode->left] = curNode;
                q.push(curNode->left);
            }
            if (curNode->right) {
                parent[curNode->right] = curNode;
                q.push(curNode->right);
            }
        }
    }

    return parent;
}

void nodesAtDistanceOfK(Node *root, int target, int distance) {
    Node *targetNode = findNode(root, target);
    map<Node *, Node *> parent = assignParent(root);

    queue<Node *> q;
    int dist = 0;
    map<Node *, int> visited;
    q.push(targetNode);

    while (!q.empty()) {
        int sz = q.size();

        if (dist == distance)
            break;
        dist += 1;
        for (int i = 1; i <= sz; i++) {
            Node *curNode = q.front();
            visited[curNode] = 1;
            q.pop();

            if (parent[curNode] and !visited[parent[curNode]])
                q.push(parent[curNode]);
            if (curNode->left and !visited[curNode->left])
                q.push(curNode->left);
            if (curNode->right and !visited[curNode->right])
                q.push(curNode->right);
        }
    }

    while (!q.empty()) {
        cout << q.front()->data << ' ';
        q.pop();
    }
}

int timeToBurnNodes(Node *root, int given) {
    Node *givenNode = findNode(root, given);
    map<Node *, Node *> parent = assignParent(root);

    queue<Node *> q;
    q.push(givenNode);
    int ans = -1;
    map<Node *, int> visited;

    while (!q.empty()) {
        int sz = q.size();
        ans += 1;
        for (int i = 1; i <= sz; i++) {
            Node *curNode = q.front();
            q.pop();
            visited[curNode] = 1;

            if (parent[curNode] and !visited[parent[curNode]])
                q.push(parent[curNode]);
            if (curNode->left and !visited[curNode->left])
                q.push(curNode->left);
            if (curNode->right and !visited[curNode->right])
                q.push(curNode->right);
        }
    }

    return ans;
}

int countNodes(Node *root) {
    if (root == NULL)
        return 0;

    Node *tempNode = root;
    int leftHeight = 0, rightHeight = 0;
    while (tempNode) {
        leftHeight += 1;
        tempNode = tempNode->left;
    }

    tempNode = root;
    while (tempNode) {
        rightHeight += 1;
        tempNode = tempNode->right;
    }

    if (leftHeight == rightHeight)
        return (int) (1 << leftHeight) - 1;
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}

Node *createBinTreeFromInorderAndPreorder(int inorderStart, int inorderEnd, int preorderStart, int preorderEnd,
                                          vector<int> &inOrder, vector<int> &preOrder, vector<int> &indexInInorder) {
    if ((preorderStart > preorderEnd) or (inorderStart > inorderEnd))
        return NULL;

    Node *newNode = new Node(preOrder[preorderStart]);
    int index = indexInInorder[preOrder[preorderStart]]; // 0-indexing
    int leftSubtreeSize = index - inorderStart;

    newNode->left = createBinTreeFromInorderAndPreorder(inorderStart, index - 1, preorderStart + 1,
                                                        preorderStart + leftSubtreeSize, inOrder, preOrder,
                                                        indexInInorder);

    newNode->right = createBinTreeFromInorderAndPreorder(index + 1, inorderEnd, preorderStart + leftSubtreeSize + 1,
                                                         preorderEnd, inOrder, preOrder, indexInInorder);

    return newNode;
}

Node *createBinTreeFromInorderAndPostorder(int inorderStart, int inorderEnd, int postOrderStart, int postOrderEnd,
                                           vector<int> &inOrder, vector<int> &postOrder, vector<int> &indexInInorder) {
    if ((postOrderStart > postOrderEnd) or (inorderStart > inorderEnd))
        return NULL;

    Node *newNode = new Node(postOrder[postOrderEnd]);
    int index = indexInInorder[postOrder[postOrderEnd]]; // 0-indexing
    int leftSubtreeSize = index - inorderStart;

    newNode->left = createBinTreeFromInorderAndPostorder(inorderStart, index - 1, postOrderStart,
                                                         postOrderStart + leftSubtreeSize - 1, inOrder, postOrder,
                                                         indexInInorder);

    newNode->right = createBinTreeFromInorderAndPostorder(index + 1, inorderEnd, postOrderStart + leftSubtreeSize,
                                                          postOrderEnd - 1, inOrder, postOrder, indexInInorder);

    return newNode;
}

string integertostring(int x) {
    string ans = "";
    while (x > 0) {
        ans += (x % 10) + '0';
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string serialiseBinaryTree(Node *root) {
    string ans = "";
    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        Node *curNode = q.front();
        q.pop();
        if (curNode == NULL) {
            ans += "#,";
            continue;
        } else {
            ans += integertostring(curNode->data);
            ans += ',';
            q.push(curNode->left);
            q.push(curNode->right);
        }
    }

    return ans;
}

int stringtointeger(string x) {
    int ans = 0, j = 1;

    for (int i = x.size() - 1; i >= 0; i--) {
        ans += (x[i] - '0') * j;
        j *= 10;
    }

    return ans;
}

Node *deSerialiseBinaryTree(string S) {
    if (S.size() == 0)
        return NULL;

    queue<Node *> q;
    int i = 0;
    string number = "";
    for (int j = 0; j < S.size(); j++) {
        if (S[j] == ',') {
            i = j + 1;
            break;
        }
        number += S[j];
    }

    Node *root = new Node(stringtointeger(number));
    q.push(root);

    while (!q.empty()) {
        Node *curNode = q.front();
        q.pop();
        string number = "";
        for (int j = i; j < S.size(); j++) {
            if (S[j] == ',') {
                i = j + 1;
                break;
            }
            number += S[j];
        }

        if (number == "#")
            curNode->left = NULL;
        else {
            Node *newNode = new Node(stringtointeger(number));
            curNode->left = newNode;
            q.push(newNode);
        }

        number = "";
        for (int j = i; j < S.size(); j++) {
            if (S[j] == ',') {
                i = j + 1;
                break;
            }
            number += S[j];
        }

        if (number == "#")
            curNode->right = NULL;
        else {
            Node *newNode = new Node(stringtointeger(number));
            curNode->right = newNode;
            q.push(newNode);
        }
    }

    return root;
}

void morrisTraversalInorder(Node *root) {
    Node *curNode = root;
    while (curNode != NULL) {
        if (curNode->left == NULL) {
            cout << curNode->data << ' ';
            curNode = curNode->right;
            continue;
        }

        Node *lastNodeonLeftSubTree = curNode->left;
        while (lastNodeonLeftSubTree->right and lastNodeonLeftSubTree->right != curNode)
            lastNodeonLeftSubTree = lastNodeonLeftSubTree->right;

        if (lastNodeonLeftSubTree->right == curNode) {
            cout << curNode->data << ' ';
            lastNodeonLeftSubTree->right = NULL;
            curNode = curNode->right;
        } else {
            lastNodeonLeftSubTree->right = curNode;
            curNode = curNode->left;
        }
    }
}

void morrisTraversalPreorder(Node *root) {
    Node *curNode = root;
    while (curNode != NULL) {
        if (curNode->left == NULL) {
            cout << curNode->data << ' ';
            curNode = curNode->right;
            continue;
        }

        Node *lastNodeonLeftSubTree = curNode->left;
        while (lastNodeonLeftSubTree->right and lastNodeonLeftSubTree->right != curNode)
            lastNodeonLeftSubTree = lastNodeonLeftSubTree->right;

        if (lastNodeonLeftSubTree->right == curNode) {
            lastNodeonLeftSubTree->right = NULL;
            curNode = curNode->right;
        } else {
            cout << curNode->data << ' ';
            lastNodeonLeftSubTree->right = curNode;
            curNode = curNode->left;
        }
    }
}

void flattenTreeUsingRec(Node *root, Node *&pre) {
    if (root == NULL)
        return;

    flattenTreeUsingRec(root->right, pre);
    flattenTreeUsingRec(root->left, pre);

    root->right = pre;
    root->left = NULL;
    pre = root;
}

void flattenTreeUsingStack(Node *root, Node *&pre) {
    stack<Node *> st;
    st.push(root);

    while (!st.empty()) {
        Node *curNode = st.top();
        st.pop();

        if (curNode->right)
            st.push(curNode->right);
        if (curNode->left)
            st.push(curNode->left);

        if (!st.empty())
            curNode->right = st.top();
        curNode->left = NULL;
    }
}

void flattenTreeUsingKindOfMorrisTraversal(Node *root) {
    Node *curNode = root;
    while (curNode) {
        if (curNode->left) {
            Node *lastNodeonLeftSubTree = curNode->left;
            while (lastNodeonLeftSubTree->right)
                lastNodeonLeftSubTree = lastNodeonLeftSubTree->right;
            lastNodeonLeftSubTree->right = curNode->right;
            curNode->right = curNode->left;
            curNode->left = NULL;
        }
        curNode = curNode->right;
    }
}

Node *searchNodeInBST(Node *root, Node *searchNode) {
    while (root and root->data != searchNode->data)
        root = (searchNode->data < root->data ? root->left : root->right);

    return root;
}

int ceilInBST(Node *root, int val) // smallest value such that value is >= given val
{
    int ans = INF;
    while (root) {
        ans = root->data >= val ? min(ans, root->data) : ans;
        root = root->data >= val ? root->left : root->right;
    }

    return (ans == INF ? -1 : ans);
}

int floorInBST(Node *root, int val) // greatest value such that value is <= given val
{
    int ans = -INF;
    while (root) {
        ans = root->data <= val ? max(ans, root->data) : ans;
        root = root->data >= val ? root->left : root->right;
    }

    return (ans == -INF ? -1 : ans);
}

void insertNodeInBST(Node *root, int &val) {
    if (!root) {
        Node *newNode = new Node(val);
        root = newNode;
        return;
    }

    Node *cur = root;
    while (1) {
        if (val < cur->data) {
            if (cur->left)
                cur = cur->left;
            else {
                Node *newNode = new Node(val);
                cur->left = newNode;
                return;
            }
        } else {
            if (cur->right)
                cur = cur->right;
            else {
                Node *newNode = new Node(val);
                cur->right = newNode;
                return;
            }
        }
    }
}

Node *findParent(Node *root, Node *toFindNode) {
    Node *curNode = root;
    while (curNode) {
        if (curNode->left == toFindNode or curNode->right == toFindNode) {
            return root;
        }
        curNode = (toFindNode->data < curNode->data ? curNode->left : curNode->right);
    }
}

Node *findMaxNode(Node *root) {
    while (root->right or root->left) {
        root = (root->right ? root->right : root->left);
    }
    return root;
}

Node *deleteNodeInBST(Node *root, Node *deleteNode) {
    Node *curNode = searchNodeInBST(root, deleteNode);
    if (curNode) {
        if (curNode != root) {
            Node *parentNode = findParent(root, curNode);
            if (parentNode->left == curNode) {
                parentNode->left = curNode->left;
            } else {
                parentNode->right = curNode->left;
            }
            Node *maxNodeOnLeftSubtree = findMaxNode(curNode->left);
            maxNodeOnLeftSubtree->right = curNode->right;
            return root;
        } else {
            if (root->left) {
                Node *maxNodeOnLeftSubtree = findMaxNode(curNode->left);
                maxNodeOnLeftSubtree->right = curNode->right;
                root->right = NULL;
                root = root->left;
                return root;
            } else {
                return root->right;
            }
        }
    }
}

Node *kthSmallestNodeInBST(Node *root, int K) {
    Node *curNode = root;
    int cnt = 0;
    while (curNode != NULL) {
        if (curNode->left == NULL) {
            cnt += 1;
            if (cnt == K)
                return curNode;
            curNode = curNode->right;
            continue;
        }

        Node *lastNodeonLeftSubTree = curNode->left;
        while (lastNodeonLeftSubTree->right and lastNodeonLeftSubTree->right != curNode)
            lastNodeonLeftSubTree = lastNodeonLeftSubTree->right;

        if (lastNodeonLeftSubTree->right == curNode) {
            cnt += 1;
            if (cnt == K)
                return curNode;
            lastNodeonLeftSubTree->right = NULL;
            curNode = curNode->right;
        } else {
            lastNodeonLeftSubTree->right = curNode;
            curNode = curNode->left;
        }
    }
}

bool validBSTorNot(Node *root, int rangeMin, int rangeMax) {
    if (!root) {
        return true;
    }
    if (root->data > rangeMin and root->data < rangeMax) {
        return validBSTorNot(root->left, rangeMin, root->data) && validBSTorNot(root->right, root->data, rangeMax);
    }

    return false;
}

Node *lcaInBST(Node *root, pair<Node *, Node *> lca) {
    while (root) {
        if (lca.first->data == root->data or lca.second->data == root->data)
            return root;
        if (lca.first->data < root->data and lca.second->data > root->data)
            return root;
        root = (lca.first->data < root->data ? root->left : root->right);
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

Node *createBSTfromPreOrderUsingBoundMethod(int upperBound, int &index, vector<int> &preOrder) {
    if (index >= preOrder.size() or preOrder[index] >= upperBound) {
        return NULL;
    }

    Node *newNode = new Node(preOrder[index]);
    index += 1;
    newNode->left = createBSTfromPreOrderUsingBoundMethod(newNode->data, index, preOrder);
    newNode->right = createBSTfromPreOrderUsingBoundMethod(upperBound, index, preOrder);

    return newNode;
}

Node *inorderSuccessorinBST(Node *root, Node *givenNode) {
    Node *successor = NULL;
    while (root) {
        if (root->data > givenNode->data) {
            successor = root;
        }
        root = (root->data > givenNode->data ? root->left : root->right);
    }

    return successor;
}

Node *inorderPredecessorinBST(Node *root, Node *givenNode) {
    Node *predecessor = NULL;
    while (root) {
        if (root->data < givenNode->data) {
            predecessor = root;
        }
        root = (root->data < givenNode->data ? root->right : root->left);
    }

    return predecessor;
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

void binarySearchTreeIterator(Node *root, stack<Node *> &stNext, stack<Node *> &stBefore) {
    storeEverythingOnLeft(root, stNext);
    storeEverythingOnRight(root, stBefore);
}

bool twoSumInBST(Node *root, int givenSum) {
    stack<Node *> stNext, stBefore;
    binarySearchTreeIterator(root, stNext, stBefore);

    Node *low = nextt(stNext);
    Node *high = beforee(stBefore);

    while (low->data < high->data) {
        int sum = low->data + high->data;
        if (sum == givenSum) {
            return true;
        } else {
            if (sum < givenSum) {
                low = nextt(stNext);
            } else {
                high = beforee(stBefore);
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