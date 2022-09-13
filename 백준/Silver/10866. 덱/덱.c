#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int data;
	struct ListNode* next, *prev;
}ListNode;

typedef struct
{
	ListNode* front, * back;
	int size;
}Deque;

Deque* CreateDeque()
{
	Deque* D;
	D = (Deque*)malloc(sizeof(Deque));
	if (!D)
		return NULL;

	D->front = NULL;
	D->back = NULL;
	D->size = 0;

	return D;
}

int empty(Deque* D)
{
	return (D->size == 0);
}

int size(Deque* D)
{
	return D->size;
}

void push_front(Deque* D, int data)
{
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return;

	newNode->data = data;

	if (empty(D))
	{
		D->front = newNode;
		D->back = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	else
	{
		newNode->next = D->front;
		D->front->prev = newNode;
		newNode->prev = NULL;
		D->front = newNode;
	}

	D->size += 1;
	return;
}

void push_back(Deque* D, int data)
{
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return;

	newNode->data = data;

	if (empty(D))
	{
		D->front = newNode;
		D->back = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	else
	{
		newNode->next = NULL;
		D->back->next = newNode;
		newNode->prev = D->back;
		D->back = newNode;
	}

	D->size += 1;
	return;
}

int pop_front(Deque* D)
{
	ListNode* temp;
	int data;

	if ((D->size) == 0)
		return -1;

	temp = D->front;
	data = temp->data;

	if ((D->size) == 1)
	{
		D->front = NULL;
		D->back = NULL;
	}
	else
	{
		D->front = temp->next;
		D->front->prev = NULL;
	}

	free(temp);
	D->size -= 1;
	return data;
}

int pop_back(Deque* D)
{
	ListNode* temp;
	int data;

	if ((D->size) == 0)
		return -1;

	temp = D->back;
	data = temp->data;

	if ((D->size) == 1)
	{
		D->front = NULL;
		D->back = NULL;
	}
	else
	{
		D->back = temp->prev;
		D->back->next = NULL;
	}

	free(temp);
	D->size -= 1;
	return data;
}

int front(Deque* D)
{
	if ((D->size) == 0)
		return -1;
	return D->front->data;
}

int back(Deque* D)
{
	if ((D->size) == 0)
		return -1;
	return D->back->data;
}


int main(void)
{
	int N;
	int i;
	Deque* D;
	char command[15];
	int data;

	D = CreateDeque();
	
	scanf("%d", &N);


	for (i = 0; i < N; i++)
	{
		scanf("%s", command);

		if (command[0] == 's')
			printf("%d\n", size(D));
		else if (command[0] == 'e')
			printf("%d\n", empty(D));
		else if (command[0] == 'f')
			printf("%d\n", front(D));
		else if (command[0] == 'b')
			printf("%d\n", back(D));
		else if (command[0] == 'p')
		{
			if (command[4] == 'f')
				printf("%d\n", pop_front(D));
			else if (command[4] == 'b')
				printf("%d\n", pop_back(D));
			else if (command[5] == 'f')
			{
				scanf("%d", &data);
				push_front(D, data);
			}
			else
			{
				scanf("%d", &data);
				push_back(D, data);
			}
		}
	}

	return 0;
}