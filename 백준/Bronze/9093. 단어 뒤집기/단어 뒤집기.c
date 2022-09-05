#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	char data;
	struct ListNode* next;
}ListNode;

typedef struct {
	ListNode* top;
	int size;
}Stack;

Stack* createStack(void);

void Push(Stack* S, char data);

char Pop(Stack* S);

int main(void) {
	int T, i; // 테스트 케이스의 개수 T
	char c; // 문자 단위로 입력을 받음
	Stack* S = createStack();
	scanf("%d", &T);
	c = getchar(); // 가장 처음의 개행을 받는다.
	for (i = 0; i < T; i++) {
		while (1) {
			c = getchar();
			if (c == '\n') {
				while (S->size != 0)
					printf("%c", Pop(S));
				printf("\n");
				break;
			}
			else if (c == ' ') {
				while (S->size != 0)
					printf("%c", Pop(S));
				printf(" ");
			}
			else {
				Push(S, c);
			}
		}
	}
	return 0;
}

Stack* createStack(void) {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	if (!S)
		return NULL;
	S->size = 0;
	S->top = NULL;
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

char Pop(Stack* S) {
	ListNode* temp;
	char data;
	if (S->size == 0)
		return -1;
	temp = S->top;
	data = temp->data;
	S->top = temp->next;
	S->size--;
	free(temp);
	return data;
}