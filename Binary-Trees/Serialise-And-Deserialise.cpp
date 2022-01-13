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

void preorderTraversal(Node *root)
{
	if(root == NULL)
		return;
	cout << root->data << ' ';
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

string integertostring(int x)
{
    string ans = "";
    while (x > 0)
    {
        ans += (x % 10) + '0';
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string serialiseBinaryTree(Node *root)
{
	string ans = "";
	queue<Node *> q;
	q.push(root);

	while(!q.empty())
	{
		Node *curNode = q.front();
		q.pop();
		if(curNode == NULL)
		{
			ans += "#,";
			continue;
		}
		else
		{
			ans += integertostring(curNode->data);
			ans += ',';
			q.push(curNode->left);
			q.push(curNode->right);
		}
	}

	return ans;
}

int stringtointeger(string x)
{
    int ans = 0, j = 1;
 
    for (int i = x.size() - 1; i >= 0; i--)
    {
        ans += (x[i] - '0') * j;
        j *= 10;
    }
 
    return ans;
}

Node *deSerialiseBinaryTree(string S)
{
	if(S[0] == '#')
		return NULL;

	queue<Node *> q;
	int i = 0;
	string number = "";
	for(int j = 0; j < S.size(); j++)
	{
		if(S[j] == ',')
		{
			i = j + 1;
			break;
		}
		number += S[j];
	}

	Node *root = new Node(stringtointeger(number));
	q.push(root);

	while(!q.empty())
	{
		Node *curNode = q.front();
		q.pop();
		string number = "";
		for(int j = i; j < S.size(); j++)
		{
			if(S[j] == ',')
			{
				i = j + 1;
				break;
			}
			number += S[j];
		}

		if(number == "#")
			curNode->left = NULL;
		else
		{
			Node *newNode = new Node(stringtointeger(number));
			curNode->left = newNode;
			q.push(newNode);
		}

		number = "";
		for(int j = i; j < S.size(); j++)
		{
			if(S[j] == ',')
			{
				i = j + 1;
				break;
			}
			number += S[j];
		}

		if(number == "#")
			curNode->right = NULL;
		else
		{
			Node *newNode = new Node(stringtointeger(number));
			curNode->right = newNode;
			q.push(newNode);
		}
	}

	return root;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = buildTree();
    string s = serialiseBinaryTree(root);
    cout << s << '\n';
    Node *newRoot = deSerialiseBinaryTree(s);
    preorderTraversal(root);

    return 0;
}