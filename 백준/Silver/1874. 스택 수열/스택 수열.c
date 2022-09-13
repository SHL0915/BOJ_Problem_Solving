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

int IsStackEmpty(Stack* S)
{
	return (S->top == NULL);
}

int Top(Stack* S)
{
	if (!S->top) return -1;
	return S->top->data;
}

int Pop(Stack* S)
{
	int data;
	ListNode* temp;
	if (IsStackEmpty(S)) return -1;

	temp = S->top;
	data = temp->data;
	S->top = S->top->next;
	free(temp);

	return data;
}

int main(void)
{
	int n;
	int i, j=0, k=0;
	int seq[100000];
	char oper[200000];
	Stack* S;
	int data;

	S = CreateStack();

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &seq[i]);
	}

	for (i = 1; i <= n+1; i++)
	{
		data = Top(S);
		if (data >= seq[j])
		{
			if (data == seq[j])
			{
				data = Pop(S);
				j++;
				oper[k] = '-';
				k++;
				i--;
			}
			else
			{
				printf("NO");
				return 0;
			}
		}
		else
		{
			Push(S, i);
			oper[k] = '+';
			k++;
		}
	}

	for (i = 0; i < 2*n; i++)
	{
		printf("%c\n", oper[i]);
	}
}
