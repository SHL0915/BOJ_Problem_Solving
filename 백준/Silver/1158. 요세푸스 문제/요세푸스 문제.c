#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int data;
	struct ListNode* next;
}ListNode;

typedef struct CirArray {
	ListNode* start;
	ListNode* end;
	int size;
}CirArray;

CirArray* CreateCirArray() {
	CirArray* C = (CirArray*)malloc(sizeof(CirArray));
	if (!C)
		return NULL;
	C->start = NULL;
	C->end = NULL;
	C->size = 0;
	return C;
}

void Push(CirArray * C, int data) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return;
	newNode->data = data;
	if (C->size == 0) {
		newNode->next = newNode;
		C->start = newNode;
		C->end = newNode;
	}
	else {
		newNode->next = C->start;
		C->end->next = newNode;
		C->end = newNode;
	}
	C->size++;
	return;
}

int Pop(CirArray* C, int k) {
	ListNode* temp;
	int data;
	int i;
	if (C->size == 0)
		return -1;
	for (i = 0; i < k - 1; i++) {
		C->start = C->start->next;
		C->end = C->end->next;
	}

	temp = C->start;
	if (C->size == 1) {
		C->start = NULL;
		C->end = NULL;
	}
	else {
		C->start = C->start->next;
		C->end->next = C->start;
	}	
	data = temp->data;
	free(temp);
	return data;
}

int main(void) {
	int N, K;
	int i;
	CirArray* C = CreateCirArray();
	
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		Push(C, i);
	}

	printf("<%d", Pop(C, K));

	for (i = 0; i < N-1; i++) {
		printf(", %d", Pop(C, K));
	}
	printf(">");
	return 0;
}