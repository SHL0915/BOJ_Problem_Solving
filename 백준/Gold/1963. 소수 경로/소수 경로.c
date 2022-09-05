#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int vertex, depth;
}listdata;

typedef struct ListNode {
	listdata data;
	struct ListNode* next;
}ListNode;

typedef struct {
	ListNode* front, * rear;
	int size;
}Queue;

Queue* createQueue(void) {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	if (!Q)
		return NULL;
	Q->front = NULL;
	Q->rear = NULL;
	Q->size = 0;
	return Q;
}

void EnQueue(Queue* Q, listdata data) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return;
	newNode->data.vertex = data.vertex;
	newNode->data.depth = data.depth;
	newNode->next = NULL;
	if (Q->size == 0) 
		Q->front = newNode;			
	else 
		Q->rear->next = newNode;
	Q->rear = newNode;
	Q->size++;
	return;
}

listdata DeQueue(Queue* Q) {
	ListNode* temp = Q->front;
	listdata data;
	data.vertex = temp->data.vertex;
	data.depth = temp->data.depth;
	if (Q->size == 1)
		Q->rear = NULL;
	Q->front = temp->next;
	Q->size--;
	free(temp);
	return data;
}

int min = -1;

void BFS(int B, Queue* Q, int* mark, int* primenum) {
	listdata temp = DeQueue(Q);
	int i, temp1, temp2;
	listdata input;
	if (temp.vertex == B) {
		if (min == -1)
			min = temp.depth;
		else if (min >= temp.depth)
			min = temp.depth;
		return;
	}
	mark[temp.vertex] = 1;
	temp1 = temp.vertex / 10;
	for (i = 0; i < 10; i++) { // 1의 자리를 바꿔가며 EnQueue
		if (primenum[temp1 * 10 + i] == 0) { // 소수인지 판별
			if (mark[temp1 * 10 + i] == 0) {		
				input.vertex = temp1 * 10 + i;
				input.depth = temp.depth + 1;
				EnQueue(Q, input);				
			}
		}
	}
	temp1 = temp.vertex / 100;
	temp2 = temp.vertex % 10;
	for (i = 0; i < 10; i++) { // 10의 자리를 바꿔가며 EnQueue
		if (primenum[temp1 * 100 + i * 10 + temp2] == 0) { // 소수인지 판별
			if (mark[temp1 * 100 + i * 10 + temp2] == 0) {
				input.vertex = temp1 * 100 + i * 10 + temp2;
				input.depth = temp.depth + 1;
				EnQueue(Q, input);
			}
		}
	}
	temp1 = temp.vertex / 1000;
	temp2 = temp.vertex % 100;
	for (i = 0; i < 10; i++) { // 100의 자리를 바꿔가며 EnQueue
		if (primenum[temp1 * 1000 + i * 100 + temp2] == 0) { // 소수인지 판별
			if (mark[temp1 * 1000 + i * 100 + temp2] == 0) {
				input.vertex = temp1 * 1000 + i * 100 + temp2;
				input.depth = temp.depth + 1;
				EnQueue(Q, input);
			}
		}
	}	
	temp2 = temp.vertex % 1000;
	for (i = 1; i < 10; i++) { // 1000의 자리를 바꿔가며 EnQueue
		if (primenum[i * 1000 + temp2] == 0) { // 소수인지 판별
			if (mark[i * 1000 + temp2] == 0) {
				input.vertex = i * 1000 + temp2;
				input.depth = temp.depth + 1;
				EnQueue(Q, input);
			}
		}
	}
}

int main(void) {
	int T, i, j, A, B, k; // 테스트 케이스의 수 T, 두 수 A와 B
	int primenum[10000] = { 0 }; // 소수 여부를 저장하는 배열
	int mark[10000]; // BFS에서 mark로 사용
	Queue* Q = createQueue();
	listdata input;	
	primenum[0] = 1;
	primenum[1] = 1;
	for (i = 2; i < 10000; i++) { // 에라토스테네스의 체를 이용하여 소수 여부를 저장
		if (primenum[i] == 0) {
			k = i * 2;
			while (k < 10000) {
				primenum[k] = 1;
				k += i;
			}
		}
	}
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		min = -1;
		scanf("%d %d", &A, &B);
		for (j = 0; j < 10000; j++)
			mark[j] = 0;
		input.vertex = A;
		input.depth = 0;
		EnQueue(Q, input);
		while (Q->size != 0)
			BFS(B, Q, mark, primenum);		
		if (min == -1)
			printf("Impossible\n");		
		else
			printf("%d\n", min);		
	}
}