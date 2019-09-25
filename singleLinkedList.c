/// program for single linked list  without head node

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node* createList(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start, int data);
struct node* addAtBeg(struct node *start, int data);
struct node* addAtEnd(struct node *start, int data);
struct node* addAfter(struct node *start, int data, int item);
struct node* addBefore(struct node *start, int data, int item);
struct node* addAtPos(struct node *start, int data, int pos);
struct node* del(struct node* start, int data);
struct node* reverse(struct node *start);

int main()
{

	struct node *start = NULL;
	int choice, data, item, pos;
	choice = data = item = pos = 0;

	while (1)
	{
		printf("1.Create List\n");
		printf("2.Display\n");
		printf("3.Count\n");
		printf("4.Search\n");
		printf("5.Add at Begining\n");
		printf("6.Add at End\n");
		printf("7.Add After Node\n");
		printf("8.Add before Node\n");
		printf("9.Add at Position\n");
		printf("10.Delete\n");
		printf("11.Reverse\n");
		printf("12.Quit\n");
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
			count(start);
			break;
		case 4:
			printf("Enter the element to be searched\n");
			scanf("%d", &data);
			search(start, data);
			break;
		case 5:
			printf("Enter the element to be inserted\n");
			scanf("%d", &data);
			start = addAtBeg(start, data);
			break;
		case 6:
			printf("Enter the element to be inserted\n");
			scanf("%d", &data);
			start = addAtEnd(start, data);
			break;
		case 7:
			printf("Enter the element to be inserted\n");
			scanf("%d", &data);
			printf("Enter the element after which to insert\n");
			scanf("%d", &item);
			start = addAfter(start, data, item);
			break;
		case 8:
			printf("Enter the element to be inserted\n");
			scanf("%d", &data);
			printf("Enter the element before which to insert\n");
			scanf("%d", &item);
			start = addBefore(start, data, item);
			break;
		case 9:
			printf("Enter the element to be inserted\n");
			scanf("%d", &data);
			printf("Enter the position at which to insert\n");
			scanf("%d", &pos);
			start = addAtPos(start, data, item);
			break;
		case 10:
			printf("Enter the element to be deleted \n");
			scanf("%d", &data);
			start = del(start, data);
			break;
		case 11:
			start = reverse(start);
			break;
		case 12:
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
		p = p->link;
	}
	printf("[NULL]\n\n");
}// display


void count(struct node* start)
{
	struct node *p = NULL;
	int cnt = 0;
	p = start;
	while (p != NULL)
	{
		p = p->link;
		cnt++;
	}
	printf("number of elements are = %d \n\n", cnt);
}

void search(struct node *start, int item)
{
	struct node *p = start;
	int pos = 1;
	while (p != NULL)
	{
		if (p->info == item)
		{
			printf("item %d found at position %d\n\n", item, pos);
			return;
		}
		p = p->link;
		pos++;
	}
	printf("item %d not found in list\n\n", item);
}

struct node* addAtBeg(struct node *start, int data)
{
	struct node* tmp = NULL;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->info = data;
	tmp->link = start;
	start = tmp;
	return start;
}


struct node* addAtEnd(struct node *start, int data)
{
	struct node *p = NULL, *tmp = NULL;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->info = data;
	p = start;
	while (p->link != NULL)
	{
		p = p->link;
	}
	p->link = tmp;
	tmp->link = NULL;
	return start;
}




struct node* addAfter(struct node *start, int data, int item)
{
	struct node *tmp = NULL, *p = NULL;
	p = start;
	while (p != NULL)
	{
		if (p->info == item)
		{
			tmp = (struct node*)malloc(sizeof(struct node));
			tmp->info = data;
			tmp->link = p->link;
			p->link = tmp;
			return start;
		}
		p = p->link;
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
		tmp->link = start;
		start = tmp;
		return start;
	}

	p = start;

	while (p->link != NULL)
	{
		if (p->link->info == item)
		{
			tmp = (struct node*)malloc(sizeof(struct node));
			tmp->info = data;
			tmp->link = p->link;
			p->link = tmp;
			return start;
		}
		p = p->link;
	}
	printf("%d not present int the list \n", item);
	return start;
}


struct node* addAtPos(struct node *start, int data, int pos)
{
	struct node *p = NULL, *tmp = NULL;
	int i = 0;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->info = data;
	if (pos == 1)
	{
		tmp->link = start;
		start = tmp;
		return start;
	}

	p = start;
	for (i = 1; (i < pos - 1) && (p != NULL);i++)
	{
		p = p->link;
	}
	if (p == NULL)
	{
		printf("there are less than %d elements \n", pos);
	}
	else
	{
		tmp->link = p->link;
		p->link = tmp;
	}
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
	start = addAtBeg(start, data);
	for (i = 2;i <= n;i++)
	{
		printf("enter the element %d to be inserted\n",i);
		scanf("%d", &data);
		start = addAtEnd(start, data);
	}
	printf("\n");
	return start;
}

struct node* del(struct node* start, int data)
{

	struct node *tmp = NULL, *p = NULL;
	if (start == NULL)
	{
		printf("list is empty \n");
		return start;
	}
	if (start->info == data)
	{
		tmp = start;
		start = start->link;
		free(tmp);
		return start;
	}
	p = start;

	while (p->link != NULL)
	{
		if (p->link->info == data)
		{
			tmp = p->link;
			p->link = tmp->link;
			free(tmp);
			return start;
		}
		p = p->link;
	}
	printf("element %d not found \n", data);
	return start;
}


struct node* reverse(struct node* start)
{
	struct node *prev = NULL, *ptr = NULL, *next = NULL;
	ptr = start;
	while (ptr != NULL)
	{
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
	}
	start = prev;
	return start;
}

