#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
	char data;
	struct ListNode* next;
}ListNode;

typedef struct Stack {
	ListNode* top;
	int size;
}Stack;

Stack* CreateStack() {
	Stack* S = (Stack*)malloc(sizeof(S));
	if (!S)
		return NULL;
	S->top = NULL;
	S->size = 0;
	return S;
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

void Pop(Stack* S) {
	ListNode* temp;
	if (S->size == 0)
		return;
	temp = S->top;
	S->top = temp->next;
	S->size--;
	free(temp);
	return;
}

int main(void) {
	char Arr[100001];
	char temp;
	int i;
	int len, total = 0;
	Stack* S = CreateStack();

	scanf("%s", Arr);
	len = strlen(Arr);

	for (i = 0; i < len; i++) {
		if (Arr[i] == '(') {
			Push(S, Arr[i]);
			temp = Arr[i];
		}
		else {
			Pop(S);
			if (temp == '(')
				total += S->size;
			else
				total += 1;
			temp = Arr[i];
		}
	}

	printf("%d", total);

}