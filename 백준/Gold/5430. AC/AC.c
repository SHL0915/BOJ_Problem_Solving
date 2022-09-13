#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
	int data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

typedef struct Queue {
	int size;
	ListNode* front;
	ListNode* rear;
}Queue;

Queue* CreateQueue(void) {
	Queue * Q;
	Q = (Queue*)malloc(sizeof(Queue));
	if (!Q)
		return NULL;
	Q->front = NULL;
	Q->rear = NULL;
	Q->size = 0;
	return Q;
}

void Push(Queue* Q, int data) {
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	if (! newNode)
		return;
	newNode->data = data;
	newNode->next = NULL;
	
	if (Q->size == 0) {
		Q->front = newNode;
		Q->rear = newNode;
		newNode->prev = NULL;
	}
	else {
		Q->rear->next = newNode;
		newNode->prev = Q->rear;
		Q->rear = newNode;
	}	
	Q->size += 1;
	return;
}

int Pop(Queue* Q, int flag) {
	int data;
	ListNode* temp;

	if (Q->size == 0) {
		return -1;
	}
	if (flag == 0) {
		temp = Q->front;
		data = temp->data;
		if (Q->size == 1) {
			Q->front = NULL;
			Q->rear = NULL;
		}
		else {
			temp->next->prev = NULL;
			Q->front = temp->next;
		}		
	}
	else {
		temp = Q->rear;
		data = temp->data;
		if (Q->size == 1) {
			Q->front = NULL;
			Q->rear = NULL;
		}
		else {
			temp->prev->next = NULL;
			Q->rear = temp->prev;
		}				
	}

	free(temp);
	Q->size -= 1;
	return data;
}


int main(void) {
	int T,N;
	int i, j, k;
	int result;
	char operation[100001];
	char Arr[400000];
	char* temp;
	Queue* Q;
	int flag;

	Q = CreateQueue();

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		result = 0;

		scanf("%s", operation);
		scanf("%d", &N);
		scanf("%s", Arr);
		
		temp = strtok(Arr, ",[]");
		
		while (temp != NULL) {
			Push(Q, atoi(temp));
			temp = strtok(NULL, ",[]");
		}

		flag = 0;
		j = 0;
		while(operation[j] != '\0') {
			if (operation[j] == 'R') {
				flag += 1;
				flag = flag % 2;
			}
			else if (operation[j] == 'D'){
				result = Pop(Q, flag);				
				if (result == -1) {
					printf("error\n");
					break;
				}
			}
			j++;
		}
		

		if (result == -1)
			continue;
		else if (Q->size == 0) {
			printf("[]\n");
		}
		else {
			printf("[%d",Pop(Q,flag));
			k = Q->size;
			for (j = 0; j < k; j++) {
				printf(",%d", Pop(Q, flag));
			}
			printf("]\n");
		}
	}
}
