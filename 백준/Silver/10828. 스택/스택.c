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

void Push(Stack* S, int data)
{
	ListNode* newNode;

	newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode) return;

	newNode->data = data;
	newNode->next = S->top;
	S->top = newNode;
	return;
}
	
int IsEmptyStack(Stack* S)
{
	if (S->top == NULL) return 1;
	else return 0;
}

int Top(Stack* S)
{
	if (IsEmptyStack(S) == 1) return -1;
	else
	{
		return S->top->data;
	}
}

int Pop(Stack* S)
{
	ListNode* temp;
	int data;
	if (IsEmptyStack(S) == 1) return -1;
	else
	{
		temp = S->top;
		data = temp->data;
		S->top = S->top->next;
		free(temp);
		return data;
	}
}

int Size(Stack* S)
{
	ListNode* p;
	int size = 0;
	p = S->top;

	while (p)
	{
		size++;
		p = p->next;
	}

	return size;
}

int main(void)
{
	int N;
	int i;
	char command[10];
	int data;
	Stack* S;
	char push[10] = "push";
	char pop[10] = "pop";
	char size[10] = "size";
	char empty[10] = "empty";

	S = CreateStack();

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%s", command);
		if (strcmp(command, push)==0)
		{
			scanf("%d\n", &data);
			Push(S, data);
		}
		else if (strcmp(command, pop)==0)
		{
			printf("%d\n",Pop(S));
		}
		else if (strcmp(command, size) == 0)
		{
			printf("%d\n", Size(S));
		}
		else if (strcmp(command, empty) == 0)
		{
			printf("%d\n", IsEmptyStack(S));
		}
		else
		{
			printf("%d\n", Top(S));
		}
	}

	return 0;
}