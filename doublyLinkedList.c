/// chapter 2 linked lists , k shrivastava
/// program for doubly linked list 

#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *prev;
	int info;
	struct node *next;
};

struct node* createList(struct node *start);
void display(struct node *start);
struct node* addToEmpty(struct node *start, int data);
struct node* addAtBeg(struct node *start, int data);
struct node* addAtEnd(struct node *start, int data);
struct node* addAfter(struct node *start, int data, int item);
struct node* addBefore(struct node *start, int data, int item);
struct node* del(struct node* start, int data);
struct node* reverse(struct node *start);

int main()
{

	struct node *start = NULL;
	int choice, data, item;
	choice = data = item = 0;

	while (1)
	{
		printf("1.Create List\n");
		printf("2.Display\n");
		printf("3.Add to empty list\n");
		printf("4.Add at begining\n");
		printf("5.Add at End\n");
		printf("6.Add After Node\n");
		printf("7.Add before Node\n");
		printf("8.Delete\n");
		printf("9.Reverse\n");
		printf("10.Quit\n");
		printf("Enter Your Choice \n\n");
		scanf("%d", &choice);
		printf("\n");

		switch (choice)
		{
		case 1:
			start = createList(start);
			break;
		case 2:
			display(start);
			break;
		case 3:
			printf("Enter the element to be inserted\n");
			scanf("%d", &data);
			start = addToEmpty(start,data);
			break;
		case 4:
			printf("Enter the element to be inserted\n");
			scanf("%d", &data);
			start = addAtBeg(start, data);
			break;
		case 5:
			printf("Enter the element to be inserted\n");
			scanf("%d", &data);
			start = addAtEnd(start, data);
			break;
		case 6:
			printf("Enter the element to be inserted\n");
			scanf("%d", &data);
			printf("Enter the element after which to insert\n");
			scanf("%d", &item);
			start = addAfter(start, data, item);
			break;
		case 7:
			printf("Enter the element to be inserted\n");
			scanf("%d", &data);
			printf("Enter the element before which to insert\n");
			scanf("%d", &item);
			start = addBefore(start, data, item);
			break;
		case 8:
			printf("Enter the element to be deleted \n");
			scanf("%d", &data);
			start = del(start, data);
			break;
		case 9:
			start = reverse(start);
			break;
		case 10:
			exit(0);
		default:
			printf("wrong choice\n");
		}// switch					
	}///while
}// main


 ///////////////////////////////////////////////////////////////////////////
 /// function definitions
 ///

void display(struct node *start)
{
	struct node *p = NULL;
	if (start == NULL)
	{
		printf("List Is Empty\n");
		return;
	}
	p = start;
	printf("List is: \n");
	while (p != NULL)
	{
		printf("[%d]->", p->info);
		p = p->next;
	}
	printf("[NULL]\n\n");
}// display

struct node* addToEmpty(struct node *start, int data)
{
	struct node *tmp = NULL;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->info = data;
	tmp->prev = NULL;
	tmp->next = NULL;
	start = tmp;
	return start;
}


struct node* addAtBeg(struct node *start, int data)
{
	struct node* tmp = NULL;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->info = data;
	tmp->prev = NULL;
	tmp->next = start;
	start->prev = tmp;
	start = tmp;
	return start;
}


struct node* addAtEnd(struct node *start, int data)
{
	struct node *p = NULL, *tmp = NULL;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->info = data;
	p = start;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = tmp;
	tmp->next = NULL;
	tmp->prev = p;
	return start;
}

struct node* addAfter(struct node *start, int data, int item)
{
	struct node *tmp = NULL, *p = NULL;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->info = data;
	p = start;

	while (p != NULL)
	{
		if (p->info == item)
		{
			tmp->prev = p;
			tmp->next = p->next;
			if (p->next != NULL)
			{
				p->next->prev = tmp;
			}
			p->next = tmp;
			return start;
		}
		p = p->next;
	}
	printf("%d not present in the list \n", item);
	return start;
}


struct node* addBefore(struct node *start, int data, int item)
{
	struct node *p = NULL, *tmp = NULL;
	if (start == NULL)
	{
		printf("List is Empty \n");
		return start;
	}

	if (item == start->info)
	{
		tmp = (struct node*)malloc(sizeof(struct node));
		tmp->info = data;
		tmp->prev = NULL;
		tmp->next = start;
		start->prev = tmp;
		start = tmp;
		return start;
	}
	p = start;

	while (p != NULL)
	{
		if (p->info == item)
		{
			tmp = (struct node*)malloc(sizeof(struct node));
			tmp->info = data;
			tmp->prev = p->prev;
			tmp->next = p;
			p->prev->next = tmp;
			p->prev = tmp;
			return start;
		}
		p = p->next;
	}
	printf("%d not present int the list \n", item);
	return start;
}

struct node* createList(struct node* start)
{
	int i = 0, n = 0, data = 0;
	printf("enter the number of nodes \n");
	scanf("%d", &n);
	start = NULL;
	if (n == 0)
	{
		return start;
	}
	printf("enter the element 1 to be inserted\n");
	scanf("%d", &data);
	start = addToEmpty(start, data);
	for (i = 2;i <= n;i++)
	{
		printf("enter the element %d to be inserted\n", i);
		scanf("%d", &data);
		start = addAtEnd(start, data);
	}
	printf("\n");
	return start;
}

struct node* del(struct node* start, int data)
{

	struct node *tmp = NULL;//, *p = NULL;
	if (start == NULL)
	{
		printf("list is empty \n");
		return start;
	}
	if (start->next == NULL)
	{
		if (start->info == data)
		{
			tmp = start;
			start = NULL;
			free(tmp);
			return start;
		}
		else
		{
			printf("Element %d not found\n");
			return start;
		}
	}
	if (start->info == data)
	{
		tmp = start;
		start = start->next;
		start->prev = NULL;
		free(tmp);
		return start;
	}
	
	tmp = start->next;
	while (tmp->next != NULL)
	{
		if (tmp->info == data)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			free(tmp);
			return start;
		}
		tmp = tmp->next;
	}

	if (tmp->info == data)
	{
		tmp->prev->next = NULL;
		free(tmp);
		return start;
	}
	printf("element %d not found \n", data);
	return start;
}


struct node* reverse(struct node* start)
{
	struct node *p1 = NULL, *p2 = NULL;//, *next = NULL;
	p1 = start;
	p2 = p1->next;
	p1->next = NULL;
	p1->prev = p2;
	while (p2 != NULL)
	{
		p2->prev = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p2->prev;
	}
	start = p1;
	printf("list reversed \n");
	return start;
}


