void maxNode(struct Node *p)
{
	int ans = -INF;
	while(p != NULL)
	{
		ans = max(ans, p->data);
		p = p->next;
	}

	cout << ans << '\n';
}