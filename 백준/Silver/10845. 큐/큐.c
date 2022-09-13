#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int data;
	struct ListNode* next;
}ListNode;

typedef struct Queue
{
	ListNode* front, * rear;
	int size;
}Queue;

Queue* CreateQueue()
{
	Queue* Q;
	Q = (Queue*)malloc(sizeof(Queue));
	if (!Q)
		return NULL;

	Q->front = NULL;
	Q->rear = NULL;
	Q->size = 0;

	return Q;
}

void Push(Queue * Q, int data)
{
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return;

	newNode->data = data;
	newNode->next = NULL;

	if (Q->size == 0)
	{
		Q->front = newNode;
		Q->rear = newNode;
	}
	else
	{
		Q->rear->next = newNode;
		Q->rear = newNode;
	}

	Q->size += 1;

	return;
}

int Empty(Queue* Q)
{
	return (Q->size == 0);
}

int Size(Queue* Q)
{
	return (Q->size);
}

int Pop(Queue* Q)
{
	int data;
	ListNode* temp;

	if (Empty(Q))
		return -1;

	temp = Q->front;
	data = Q->front->data;

	if (Q->size == 1)
	{
		Q->front = NULL;
		Q->rear = NULL;
	}
	else
	{
		Q->front = temp->next;
	}
	Q->size -= 1;
	free(temp);
	return data;
}

int Front(Queue* Q)
{
	if (Empty(Q))
		return -1;

	return Q->front->data;
}

int Back(Queue* Q)
{
	if (Empty(Q))
		return -1;

	return Q->rear->data;
}

int main(void)
{
	int N;
	int i;
	Queue* Q;
	char command[10];
	int data;

	Q = CreateQueue();

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%s", command);
		if (command[0] == 's')
		{
			printf("%d\n", Size(Q));
		}
		else if (command[0] == 'e')
		{
			printf("%d\n", Empty(Q));
		}
		else if (command[0] == 'f')
		{
			printf("%d\n", Front(Q));
		}
		else if (command[0] == 'b')
		{
			printf("%d\n", Back(Q));
		}
		else if (command[1] == 'o')
		{
			printf("%d\n", Pop(Q));
		}
		else
		{
			scanf("%d", &data);
			Push(Q, data);
		}
	}

	return 0;
}