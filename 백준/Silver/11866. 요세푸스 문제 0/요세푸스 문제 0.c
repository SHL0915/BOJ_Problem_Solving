#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
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


void Push(Queue* Q, int data)
{
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode));

	if (!newNode)
		return;

	newNode->data = data;
	

	if ((Q->size) == 0)
	{
		Q->front = newNode;
		Q->rear = newNode;
		newNode->next = Q->front;
	}
	else
	{
		Q->rear->next = newNode;
		Q->rear = newNode;
		newNode->next = Q->front;
	}

	Q->size += 1;
	return;
}

int Pop(Queue* Q)
{
	ListNode* temp;
	int data;

	if (Q->size == 0)
		return -1;

	temp = Q->front;
	data = temp->data;
	Q->size -= 1;



	if ((Q->size) == 0)
	{
		Q->front = NULL;
		Q->rear = NULL;
		free(temp);
		return data;
	}
	else
	{
		Q->front = temp->next;
		Q->rear->next = Q->front;
		free(temp);
		return data;
	}
}

void RotateQueue(Queue* Q)
{
	if (Q->size == 0)
		return;

	Q->front = Q->front->next;
	Q->rear = Q->rear->next;
	return;
}

int main(void)
{
	int N;
	int K;
	Queue* Q;
	int i, j;
	int data;

	Q = CreateQueue();

	scanf("%d %d", &N, &K);

	for (i = 1; i <= N; i++)
	{
		Push(Q, i);
	}

	printf("<");

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < K-1; j++)
			RotateQueue(Q);
		data = Pop(Q);
		printf("%d", data);

		if (i != N - 1)
			printf(", ");
		else
			printf(">");
	}
	

	return 0;
}