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

Node *findNode(Node *root, int target)
{
	queue<Node *> q;
	q.push(root);

	while(!q.empty())
	{
		int sz = q.size();
		for(int i = 1; i <= sz; i++)
		{
			Node *curNode = q.front();
			q.pop();
			if(curNode->data == target)
				return curNode;
			if(curNode->left)
				q.push(curNode->left);
			if(curNode->right)
				q.push(curNode->right);
		}
	}
}

map<Node *, Node *> assignParent(Node *root)
{
	map<Node *, Node *> parent;
	queue<Node *> q;
	q.push(root);

	while(!q.empty())
	{
		int sz = q.size();
		for(int i = 1; i <= sz; i++)
		{
			Node *curNode = q.front();
			q.pop();

			if(curNode->left)
			{
				parent[curNode->left] = curNode;
				q.push(curNode->left);
			}
			if(curNode->right)
			{
				parent[curNode->right] = curNode;
				q.push(curNode->right);
			}
		}
	}

	return parent;
}

void nodesAtDistanceOfK(Node *root, int target, int distance)
{
	Node *targetNode = findNode(root, target);
	map<Node *, Node *> parent = assignParent(root);
	
	queue<Node *> q;
	int dist = 0;
	map<Node *, int> visited;
	q.push(targetNode);

	while(!q.empty())
	{
		int sz = q.size();

		if(dist == distance)
			break;
		dist += 1;
		for(int i = 1; i <= sz; i++)
		{
			Node *curNode = q.front();
			visited[curNode] = 1;
			q.pop();

			if(parent[curNode] and !visited[parent[curNode]])
				q.push(parent[curNode]);
			if(curNode->left and !visited[curNode->left])
				q.push(curNode->left);
			if(curNode->right and !visited[curNode->right])
				q.push(curNode->right);
		}
	}

	while(!q.empty())
	{
		cout << q.front()->data << ' ';
		q.pop();
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
  	nodesAtDistanceOfK(root, 1, 4);

    return 0;
}