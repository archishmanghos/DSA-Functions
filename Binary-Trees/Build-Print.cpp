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

void print(Node *root)
{
	if(root == NULL)
		return;
	cout << root->data << ' ';
	print(root->left);
	print(root->right);
}