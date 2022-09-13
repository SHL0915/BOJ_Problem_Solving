#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	char data;
	struct ListNode* next;
}ListNode;

typedef struct Stack {
	int size;
	ListNode* top;
}Stack;

Stack* CreateStack() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	if (!S)
		return NULL;
	S->top = NULL;
	S->size = 0;
	return S;
}

char Pop(Stack* S) {
	ListNode* temp;
	char data;
	if (S->size == 0)
		return -1;
	temp = S->top;
	S->top = temp->next;
	data = temp->data;
	free(temp);
	S->size--;
	return data;
}

void Push(Stack* S, char data) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return;
	newNode->data = data;
	newNode->next = S->top;
	S->top = newNode;
	S->size++;
	return;
}

int main(void) {
	char str[600001];
	int M, i;
	char operation[2];
	char data[2];
	Stack* S, *temp;

	S = CreateStack();
	temp = CreateStack();

	scanf("%s", str);
	scanf("%d", &M);

	for (i = 0; str[i] != '\0'; i++) {
		Push(S, str[i]);
	}

	for (i = 0; i < M; i++) {
		scanf("%s", &operation);
		if (operation[0] == 'L') {
			if (S->size == 0)
				continue;
			else
				Push(temp, Pop(S));
		}
		else if (operation[0] == 'D') {
			if (temp->size == 0)
				continue;
			else
				Push(S, Pop(temp));
		}
		else if (operation[0] == 'B') {
			Pop(S);
		}
		else {
			scanf("%s", &data);
			Push(S, data[0]);
		}
	}

	while (temp->size != 0) {
		Push(S, Pop(temp));
	}
	while (S->size != 0) {
		Push(temp, Pop(S));
	}
	
	for (i = 0; temp->size != 0; i++) {
		str[i] = Pop(temp);
	}
	str[i] = '\0';
	printf("%s",str);
	return 0;	
}