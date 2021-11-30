void sumOfNodes(struct Node *p)
{
	int ans = 0;
	while(p != NULL)
	{
		ans += p->data;
		p = p->next;
	}

	cout << ans << '\n';
}