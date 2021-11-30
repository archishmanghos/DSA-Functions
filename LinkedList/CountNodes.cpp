void countNodes(struct Node *p)
{
	int ans = 0;
	while(p != NULL)
	{
		ans += 1;
		p = p->next;
	}

	cout << ans << '\n';
}