struct Node
{
	Node *left, *right;
	int data;
	Node(int value){
		data = value;
		left = right = NULL;
	}
};

Node *buildTree(){
	int value;
	cin >> value;
	if(value == -1) return NULL;

	Node *root = new Node(value);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}