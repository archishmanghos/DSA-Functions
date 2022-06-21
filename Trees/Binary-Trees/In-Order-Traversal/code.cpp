void inOrderTraversal(Node *root){
	if(!root) return;

	inOrderTraversal(root->left);
	cout << root->data << ' ';
	inOrderTraversal(root->right);
}