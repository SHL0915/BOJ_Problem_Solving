#include <bits/stdc++.h>
using namespace std;

typedef struct ListNode {
	char data;
	struct ListNode* next;
}ListNode;

typedef struct {
	ListNode* top;
	int size;
}Stack;

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
	char data;
	ListNode* temp;
	if (S->size == 0)
		return -1;
	temp = S->top;
	S->top = temp->next;
	data = temp->data;
	free(temp);
	S->size--;
	return data;
}

char Top(Stack* S) {
	return S->top->data;
}

int Recursive(char* inFix, int i, Stack* S) {
	int pos = S->size;
	char temp;
	S->size = 0;
	while (1) {
		i++;
		if (inFix[i] == '(') {
			i = Recursive(inFix, i, S);
		}
		else if (inFix[i] == ')')
			break;
		else if ((inFix[i] >= 'A') && (inFix[i] <= 'Z'))
			printf("%c", inFix[i]);
		else {
			if (S->size == 0)
				Push(S, inFix[i]);
			else {
				temp = Top(S);
				if ((inFix[i] == '+') || (inFix[i] == '-')) {
					while (S->size != 0)
						printf("%c", Pop(S));
					Push(S, inFix[i]);
				}
				else {
					if ((temp == '+') || (temp == '-'))
						Push(S, inFix[i]);
					else {
						printf("%c", Pop(S));
						Push(S, inFix[i]);
					}
				}
			}
		}
	}
	while (S->size != 0)
		printf("%c", Pop(S));
	S->size = pos;
	return i;
}

int main(void) {
	char inFix[101];
	int i, len;
	char temp;
	Stack* S;
	S = createStack();
	scanf("%s", inFix);
	len = strlen(inFix);
	for (i = 0; i < len; i++) {
		if ((inFix[i] >= 'A') && (inFix[i] <= 'Z'))
			printf("%c", inFix[i]);
		else if (inFix[i] == '(') {
			i = Recursive(inFix, i, S);
		}
		else {
			if (S->size == 0)
				Push(S, inFix[i]);
			else {
				temp = Top(S);
				if ((inFix[i] == '+') || (inFix[i] == '-')) {
					while (S->size != 0)
						printf("%c", Pop(S));
					Push(S, inFix[i]);
				}
				else {
					if ((temp == '+') || (temp == '-'))
						Push(S, inFix[i]);
					else {
						printf("%c", Pop(S));
						Push(S, inFix[i]);
					}
				}
			}
		}
	}
	while (S->size != 0)
		printf("%c", Pop(S));
	return 0;
}