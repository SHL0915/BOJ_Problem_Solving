#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int data;
	struct ListNode* next;
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

int isEmptyQueue(Queue* Q)
{
	return (Q->size == 0);
}

void Push(Queue* Q, int data)
{
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode));

	if (!newNode)
		return;

	newNode->data = data;
	newNode->next = NULL;

	if (isEmptyQueue(Q))
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

int Pop(Queue* Q)
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
	}

	Q->size -= 1;
	free(temp);
	return data;
}

int SearchQueue(Queue * Q,ListNode * node, int data)
{
	if (node == NULL)
		return Pop(Q)/10;

	if (data % 10 < (node->data) % 10)
	{
		Push(Q, Pop(Q));
		return -1;
	}
	else
	{
		return SearchQueue(Q,node->next, data);
	}
}

void DeQueue(Queue* Q)
{
	int temp;
	while (Q->size != 0)
	{
		temp = Pop(Q);
	}
	return;
}

int main(void)
{
	int K, N, M;
	Queue* Q;
	int i, j;
	int data;
	int temp;
	int result;

	Q = CreateQueue();

	scanf("%d", &K);
	
	for (i = 0; i < K; i++)
	{
		temp = -1;
		result = 0;
		scanf("%d %d", &N, &M);

		for (j = 0; j < N; j++)
		{
			scanf("%d", &data);
			Push(Q, ((10 * j) + data));
		}

		while (temp != M)
		{
			temp = SearchQueue(Q, Q->front, Q->front->data);
			if(temp != -1)
				result += 1;
		}

		printf("%d\n", result);
		DeQueue(Q);
	}

	return 0;
}