#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct listnode
{
	char data;
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

void Push(Stack* S, char data)
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
	if (S->top == NULL) return 0;
	else return 1;
}

int Pop(Stack* S)
{
	ListNode* temp;

	if (IsStackEmpty(S)==0) return 1;
	temp = S->top;
	S->top = S->top->next;
	free(temp);
	return 0;
}

void InitializeStack(Stack* S)
{
	ListNode* p, * q;
	p = S->top;

	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	S->top = NULL;
	return;
}


int main(void)
{
	int T;
	int i, j;
	char str[51];
	int len = 0;
	Stack* S;
	int stop;

	S = CreateStack();

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%s", str);

		stop = 0;

		len = strlen(str);

		for (j = 0; j < len; j++)
		{
			if (str[j] == '(')
			{
				Push(S, '(');
			}
			else if (str[j]==')')
			{
				stop = Pop(S);
			}

			if (stop == 1)
			{
				printf("NO\n");
				stop = 2;
				break;
			}
		}

		if (stop == 2) continue;
		else if (IsStackEmpty(S) == 0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		InitializeStack(S);
	}

	return 0;
}