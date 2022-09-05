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

Stack* createStack();

void Push(Stack* S, char data);

char Pop(Stack* S);

int main(void) {
	char c; // 문자마다 입력받음
	int flag = 0; // 태그 여부를 기록
	Stack* S = createStack();
	while (1) {
		c = getchar();
		if (c == '\n') {
			while (S->size != 0)
				printf("%c", Pop(S));
			break;
		}
		else if (c == '<') { // 태그의 시작
			while (S->size != 0)
				printf("%c", Pop(S));
			printf("%c", c);
			flag = 1;
		}
		else if (c == '>') { // 태그의 끝
			printf("%c", c);
			flag = 0;
		}
		else {
			if (flag == 1) { // 태그 안에 존재하는 문자인 경우
				printf("%c", c);
			}
			else { // 태그 밖에 존재하는 문자인 경우
				if (c == ' ') {
					while (S->size != 0)
						printf("%c", Pop(S));
					printf(" ");
				}
				else {
					Push(S, c);
				}
			}
		}
	}
	return 0;
}

Stack* createStack() {
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
	free(temp);
	S->size--;
	return data;
}