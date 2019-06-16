#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;
struct Node
{
	int val;
	node* next;
}Node;

void printList(node* head)
{
	node* trav = head;

	while(trav != NULL)
	{
		printf("%d ", trav->val);

		trav = trav->next;
	}
	printf("\n");
}

void addToHead(node** head, int num)
{
	if (head == NULL)
		return;

	node* new = (node*)malloc(sizeof(node));
	
	if (new == NULL)
		return;

	new->val = num;
	new->next = *head;

	*head = new;
}

void addToTail(node** head, int num)
{
	if (head == NULL)
		return;

	node* new = (node*)malloc(sizeof(node));

	if (new == NULL)
		return;

	new->val = num;
	new->next = NULL;
	
	/** If this is the first node */
	if (*head == NULL)
	{
		*head = new;
		return;
	}

	/** Traverse to the end of the list */
	node* trav = *head;

	while(trav->next != NULL)
		trav = trav->next;

	trav->next = new;
}

void addAfter(node* head, int num, int after)
{
	if (head == NULL)
		return;

	node* new = (node*)malloc(sizeof(node));
	if (new == NULL)
		return;

	new->val = num;
	node* trav = head;

	while(trav != NULL)
	{
		if (trav->val == after)
		{
			new->next = trav->next;
			trav->next = new;
			return;
		}
		trav = trav->next;
	}
	
	/** Couldn't find a node with value equal to after */
	free(new);
}

void addBefore(node** head, int num, int before)
{
	if (head == NULL || *head == NULL)
		return;

	node* new = (node*)malloc(sizeof(node));
	if (new == NULL)
		return;

	new->val = num;
	if ((*head)->val == before)
	{
		new->next = *head;
		*head = new;
	}

	node* trav = *head;
	node* prev = *head;
	while (trav != NULL)
	{
		if(trav->val == before)
		{
			new->next = prev->next;
			prev->next = new;
			return;
		}
		prev = trav;
		trav = trav->next;
	}
}

void removeHead(node** head)
{
	if (head == NULL || *head == NULL)
		return;

	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
		return;
	}

	node* tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

void removeTail(node** head)
{
	if (head == NULL || *head == NULL)
		return;

	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
		return;
	}

	node* trav = *head;
	node* prev = *head;

	while(trav->next != NULL)
	{
		prev = trav;
		trav = trav->next;
	}

	free(trav);
	prev->next = NULL;
}

void removeNode(node** head, int num)
{
	if (head == NULL || *head == NULL)
		return;

	if ((*head)->val == num)
	{
		node* tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}

	node* trav = *head;
	node* prev = *head;
	while(trav->next != NULL)
	{
		if (trav->val == num)
		{
			node* tmp = trav->next;
			free(trav);
			prev->next = tmp;
			return;
		}
		prev = trav;
		trav = trav->next;
	}
}

int main()
{	
	node* head = NULL;

	addToHead(&head, 5);
	printList(head);
	addToHead(&head, 4);
	printList(head);
	addToHead(&head, 3);
	printList(head);
	addToHead(&head, 2);
	printList(head);
	addToHead(&head, 1);
	printList(head);
	addToTail(&head, 6);
	printList(head);
	addToTail(&head, 8);
	printList(head);
	addAfter(head, 7, 6);
	printList(head);
	addAfter(head, 10, 8);
	printList(head);
	addBefore(&head, 9, 10);
	printList(head);
	removeHead(&head);
	printList(head);
	removeTail(&head);
	printList(head);
	removeNode(&head, 5);
	printList(head);
}
