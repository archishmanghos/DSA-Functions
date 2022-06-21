void preOrderTraversal(Node *root){
	if(!root) return;

	cout << root->data << ' ';
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}