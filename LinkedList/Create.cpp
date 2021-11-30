struct Node
{
	int data;
	struct Node *next;
};

Node *head;

void create(int A[], int N)
{
	struct Node *temp;
	struct Node *last = (struct Node *)malloc(sizeof(struct Node));
	head = (struct Node *)malloc(sizeof(struct Node));
	head->data = A[0];
	head->next = NULL;
	last = head;

	for(int i = 1; i < N; i++)
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = A[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}