void displayLoop(struct Node *p)
{
	while(p != NULL)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << '\n';
}

void displayRecursive(struct Node *p)
{
	if(p == NULL)
	{
		cout << '\n';
		return;
	}

	cout << p->data << ' ';
	displayRecursive(p->next);
}