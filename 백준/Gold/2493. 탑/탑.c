#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int data;
	int index;
	struct ListNode* next;
}ListNode;

typedef struct {
	ListNode* top;
	int size;
}Stack;

Stack* CreateStack() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	if (!S)
		return NULL;
	S->top = NULL;
	S->size = 0;
	return S;
}

void Push(Stack* S, int data, int i) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->index = i;
	if (S->size == 0) {
		newNode->next = NULL;
		S->top = newNode;
	}
	else {
		newNode->next = S->top;
		S->top = newNode;
	}
	S->size++;
	return;
}

void Pop(Stack* S) {
	ListNode* temp;
	if (S->size == 0)
		return;
	temp = S->top;
	S->top = temp->next;
	free(temp);
	S->size--;
	return;
}

int main(void) {
	int N;
	int* data;
	int* key;
	int i;
	Stack* S = CreateStack();

	scanf("%d", &N);

	key = (int*)malloc(sizeof(int) * N);
	data = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		key[i] = 0;
	}

	for (i = 0; i < N; i++) {
		scanf("%d", &data[i]);
	}

	for (i = 0; i < N; i++) {
		if (S->size == 0) {
			Push(S, data[i], i);
		}
		else {
			if (S->top->data >= data[i]) {
				key[i] = (S->top->index)+1;
				Push(S, data[i], i);
			}
			else {
				Pop(S);
				i--;
			}
		}
	}

	for (i = 0; i < N; i++) {
		printf("%d ", key[i]);
	}
}

