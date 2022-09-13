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

int Pop(Stack* S)
{
	ListNode* temp;
	
	if (IsStackEmpty(S)) return 1;
	temp = S->top;
	S->top = S->top->next;
	free(temp);
	return 0;
}

void InitializeStack(Stack* S)
{
	ListNode* p, * q;
	p = S->top;

	while(p)
	{
		q = p;
		p = p->next;
		free(q);
	}

	S->top = NULL;
}

int main(void)
{
	int i, j;
	char str[101];
	int len;
	Stack* S;
	int stop;

	S = CreateStack();

	for (i = 0;; i++)
	{
		gets(str);
		len = strlen(str);
		str[len] = '\n';
		if ((str[0] == '.') & (str[1] == '\n')) break;		
		stop = 0;

		len +=1;

		for (j = 0; j < len; j++)
		{
			if (str[j] == '(')
			{
				Push(S, 1);
			}
			else if (str[j] == ')')
			{
				if (S->top == NULL)
				{
					printf("no\n");
					stop = 2;
					break;
				}
				else if (S->top->data == 1)
				{
					stop = Pop(S);
				}
				else
				{
					printf("no\n");
					stop = 2;
					break;
				}
			}
			else if (str[j] == '[')
			{
				Push(S, 0);
			}
			else if (str[j] == ']')
			{
				if (S->top == NULL)
				{
					printf("no\n");
					stop = 2;
					break;
				}
				else if (S->top->data == 0)
				{
					stop = Pop(S);
				}
				else
				{
					printf("no\n");
					stop = 2;
					break;
				}
			}

			if (stop == 1)
			{
				printf("no\n");
				stop = 2;
				break;
			}
		}

		if (stop == 2)
		{
			InitializeStack(S);
			continue;
		}
		if (IsStackEmpty(S))
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}

		InitializeStack(S);
	}

	return 0;
}