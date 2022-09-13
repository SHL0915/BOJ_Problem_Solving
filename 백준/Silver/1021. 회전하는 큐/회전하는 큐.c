#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

typedef struct
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

void EnQueue(Queue* Q, int data)
{
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return;

	newNode->data = data;
	newNode->next = NULL;

	if (Q->size == 0)
	{
		newNode->prev = NULL;
		Q->front = newNode;
		Q->rear = newNode;
	}
	else
	{
		newNode->prev = Q->rear;
		Q->rear->next = newNode;
		Q->rear = newNode;
	}

	Q->size += 1;
	return;
}

int isEmptyQueue(Queue* Q)
{
	return (Q->size == 0);
}

int DeQueue(Queue* Q)
{
	int data;
	ListNode* temp;

	if (isEmptyQueue(Q))
		return -1;

	temp = Q->front;
	data = temp->data;
	if (Q->size == 1)
	{
		Q->front = NULL;
		Q->rear = NULL;
	}
	else
	{
		Q->front = temp->next;
		Q->front->prev = NULL;
	}

	Q->size -= 1;
	free(temp);
	return data;
}

void TurnRight(Queue* Q)
{
	ListNode* temp;
	if (isEmptyQueue(Q))
		return;

	temp = Q->front;
	Q->front = temp->next;
	Q->front->prev = NULL;
	temp->prev = Q->rear;
	temp->next = NULL;
	Q->rear->next = temp;
	Q->rear = temp;

	return;
}


void TurnLeft(Queue* Q)
{
	ListNode* temp;
	if (isEmptyQueue(Q))
		return;

	temp = Q->rear;
	temp->next = Q->front;
	Q->front->prev = temp;
	Q->front = temp;
	Q->rear = temp->prev;
	Q->rear->next = NULL;
	temp->prev = NULL;

	return;
}


int main(void)
{
	int N, M;
	int pos;
	int result = 0;
	int temp;
	Queue* Q;
	int i;

	scanf("%d %d", &N, &M);

	Q = CreateQueue();

	for(i = 1; i <= N; i++)
	{
		EnQueue(Q, i);
	}

	for(i = 0; i < M;i++)
	{
		temp = 0;
		scanf("%d", &pos);

		while (Q->front->data != pos)
		{
			TurnRight(Q);
			temp += 1;
		}

		if (temp <= (Q->size) / (2.0))
			result += temp;
		else
			result += (Q->size - temp);

		temp = DeQueue(Q);
	}

	printf("%d", result);
	return 0;
}