#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int data;
	int key;
	struct ListNode* prev;
}ListNode;

typedef struct Stack {
	ListNode* top;
	int size;
}Stack;

Stack* CreateStack(void) {
	Stack* S;
	S = (Stack*)malloc(sizeof(Stack));
	if (!S)
		return NULL;
	S->size = 0;
	S->top = NULL;
	return S;
}

void Push(Stack* S, int data, int key) {
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	if (! newNode)
		return;
	newNode->data = data;
	newNode->key = key;
	if (S->size == 0) {
		newNode->prev = NULL;
	}
	else
		newNode->prev = S->top;

	S->top = newNode;
	S->size += 1;
	return;
}

ListNode* Pop(Stack* S) {
	ListNode* temp;	

	if (S->size == 0)
		return NULL;
	temp = S->top;
	
	S->top = temp->prev;

	S->size -= 1;
	return temp;
}


int main(void) {
	int N;
	int* Arr;
	int i;
	Stack* S = CreateStack();
	int data;
	ListNode* temp;

	scanf("%d", &N);

	Arr = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		Arr[i] = -1;
	}

	for (i = 0; i < N; i++) {
		scanf("%d", &data);
		if ((S->size) == 0) {
			Push(S, data, i);
		}
		else {			
			while ((S->size != 0) && (data > S->top->data)) {				
				temp = Pop(S);				
				Arr[temp->key] = data;
				free(temp);
			}
			Push(S, data, i);
		}		
	}

	for (i = 0; i < N; i++) {
		printf("%d ", Arr[i]);
	}
	return 0;
}