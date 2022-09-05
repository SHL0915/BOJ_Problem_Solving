#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode{
	double data;
	struct ListNode* next;	
}ListNode;

typedef struct {
	ListNode* top;
	int size;
}Stack;

Stack* createStack();

void Push(Stack* S, double data);

double Pop(Stack* S);

int main(void) {
	int N, len, i; // 피연산자의 개수 N, 후위표기식의 길이 len
	double A, B; // 연산의 대상이 되는 두 실수
	double* data;
	char line[101]; // 후위표기식을 문자열로 입력 받음
	Stack* S = createStack();
	scanf("%d", &N);
	data = (double*)malloc(sizeof(double) * N);
	scanf("%s", line);
	len = strlen(line);
	for (i = 0; i < N; i++) // 값 입력
		scanf("%lf", &data[i]);
	for (i = 0; i < len; i++) {
		if (line[i] >= 'A' && line[i] <= 'Z') { // 피연산자의 경우			
			Push(S, data[line[i]-'A']); // 피연산자에 해당하는 값 대입
		}
		else { // 연산자의 경우
			B = Pop(S);
			A = Pop(S);
			if (line[i] == '*')
				Push(S, A * B);
			else if (line[i] == '/')
				Push(S, A / B);
			else if (line[i] == '+')
				Push(S, A + B);
			else
				Push(S, A - B);
		}
	}
	printf("%.2lf", Pop(S));
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

void Push(Stack* S, double data) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return;
	newNode->data = data;
	newNode->next = S->top;
	S->top = newNode;
	S->size++;
	return;
}

double Pop(Stack* S) {
	ListNode* temp;
	double data;
	if (S->size == 0)
		return -1;
	temp = S->top;
	data = temp->data;
	S->top = temp->next;
	S->size--;
	free(temp);
	return data;
}