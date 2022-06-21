void postOrderTraversal(Node *root){
	if(!root) return;

	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->data << ' ';
}