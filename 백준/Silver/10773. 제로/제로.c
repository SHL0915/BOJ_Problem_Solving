#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct listnode
{
	int data;
	struct listnode* next;
}ListNode;

typedef struct
{
	ListNode* top;
}Stack;

Stack* CreateStack()
{
	Stack* S;
	S = (Stack*)malloc(sizeof(Stack));

	S->top = NULL;
	return S;
}

void Push(Stack* S,int data)
{
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode));

	if (!newNode) return;

	newNode->data = data;
	newNode->next = S->top;
	S->top = newNode;
	return;
}

void Pop(Stack* S)
{
	ListNode* temp;
	temp = S->top;
	S->top = S->top->next;
	free(temp);
	return;
}

int AddAllNumberInStack(Stack* S)
{
	ListNode * p;
	int sum = 0;

	p = S->top;

	while (p)
	{
		sum += p->data;
		p = p->next;
	}

	return sum;
}

int main(void)
{
	int K;
	int i;
	int data;
	int sum;
	Stack* S;

	S = CreateStack();

	scanf("%d", &K);

	for (i = 0; i < K; i++)
	{
		scanf("%d", &data);

		if (data == 0)
		{
			Pop(S);
		}
		else
		{
			Push(S, data);
		}
	}

	sum = AddAllNumberInStack(S);

	printf("%d", sum);

	return 0;
}