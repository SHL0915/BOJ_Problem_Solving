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

void push(Queue* Q, int data)
{
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return;
	Q->size += 1;
	newNode->data = data;
	newNode->next = NULL;

	if ((Q->front) == NULL)
	{
		Q->front = newNode;
		Q->rear = newNode;
	}
	else
	{
		Q->rear->next = newNode;
		Q->rear = newNode;
	}
}

int empty(Queue* Q)
{
	return ((Q->front) == NULL);
}

int pop(Queue* Q)
{
	int data = -1;
	ListNode* temp;

	if (empty(Q))
		return data;

	temp = Q->front;
	data = temp->data;
	Q->size -= 1;
	Q->front = temp->next;

	if (Q->front == NULL)
	{
		Q->rear = NULL;
	}

	return data;
}

int size(Queue* Q)
{
	return (Q->size);
}

int front(Queue* Q)
{
	if (empty(Q))
		return -1;
	return Q->front->data;
}

int back(Queue* Q)
{
	if (empty(Q))
		return -1;
	return Q->rear->data;
}


int main(void)
{
	int N;
	int i;
	char command[6];
	int data;
	Queue* Q;

	Q = CreateQueue();
	
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%s", command);
		if (command[0] == 's')
			printf("%d\n",size(Q));
		else if(command[0] == 'e')
			printf("%d\n", empty(Q));
		else if (command[0] == 'f')
			printf("%d\n", front(Q));
		else if (command[0] == 'b')
			printf("%d\n", back(Q));
		else if (command[1] == 'o')
			printf("%d\n", pop(Q));
		else
		{
			scanf("%d", &data);
			push(Q, data);
		}
	}

	return 0;
}
