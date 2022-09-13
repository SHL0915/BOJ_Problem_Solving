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

void Push(Stack* S, int data, int index) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return;
	newNode->data = data;
	newNode->next = S->top;
	newNode->index = index;
	S->top = newNode;
	S->size += 1;
	return;
}

int Pop(Stack* S) {
	int data;
	ListNode* temp;
	if (S->size == 0)
		return -1;
	data = S->top->data;
	temp = S->top;
	if (S->size == 1) {
		S->top = NULL;
	}
	else {
		S->top = temp->next;
	}
	S->size--;
	free(temp);
	return data;
}



int main(void) {
	int N;
	int max = 0;
	ListNode* temp;
	int i;
	Stack* S;
	int* Arr; //수열
	int* num; //등장 횟수
	int* key; //출력 값

	S = CreateStack();

	scanf("%d", &N);
	
	Arr = (int*)malloc(sizeof(int) * N);
	num = (int*)malloc(sizeof(int) * 1000001);
	key = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		key[i] = -1;
	}

	for (i = 0; i <= 1000000; i++) {
		num[i] = 0;
	}

	for (i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
		num[Arr[i]] += 1;
	}

	for (i = 0; i < N; i++) {
		if (S->size == 0)
			Push(S, Arr[i], i);
		else {
			if (num[Arr[i]] > num[S->top->data]) {
				temp = S->top;
				key[S->top->index] = Arr[i];
				Pop(S);
				i--;
			}
			else {
				Push(S, Arr[i],i);
			}
		}
	}

	for (i = 0; i < N; i++) {
		printf("%d ", key[i]);
	}

	return 0;

}