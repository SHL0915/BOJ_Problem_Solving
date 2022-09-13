#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int vertex;
	int path;
	char operation;
}listdata;

typedef struct ListNode {
	listdata data;
	struct ListNode* next;
}ListNode;

typedef struct {
	ListNode* front, * rear;
	int size;
}Queue;

Queue* createQueue() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	Q->size = 0;
	return Q;
}

int D(int N) {
	return (N * 2) % 10000;
}
int S(int N) {
	if (N == 0)
		return 9999;
	else
		return N - 1;
}
int L(int N) {
	int d1 = 0;
	int d2 = 0;
	int d3 = 0;
	int d4 = 0;
	int temp = N;
	d4 = temp % 10;
	temp = temp / 10;
	d3 = temp % 10;
	temp = temp / 10;
	d2 = temp % 10;
	temp = temp / 10;
	d1 = temp % 10;
	temp = d1;
	d1 = d2;
	d2 = d3;
	d3 = d4;
	d4 = temp;
	return ((d1 * 10 + d2) * 10 + d3) * 10 + d4;
}
int R(int N) {
	int d1 = 0;
	int d2 = 0;
	int d3 = 0;
	int d4 = 0;
	int temp = N;
	d4 = temp % 10;
	temp = temp / 10;
	d3 = temp % 10;
	temp = temp / 10;
	d2 = temp % 10;
	temp = temp / 10;
	d1 = temp % 10;
	temp = d4;
	d4 = d3;
	d3 = d2;
	d2 = d1;
	d1 = temp;
	return ((d1 * 10 + d2) * 10 + d3) * 10 + d4;
}

void EnQueue(Queue* Q, listdata data) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->next = NULL;
	if (Q->size == 0) {
		Q->front = newNode;
		Q->rear = newNode;
	}
	else {
		Q->rear->next = newNode;
		Q->rear = newNode;
	}
	Q->size++;
	return;
}

listdata DeQueue(Queue* Q) {
	ListNode* temp = Q->front;
	listdata data = temp->data;
	if (Q->size == 1) {
		Q->front = NULL;
		Q->rear = NULL;
	}
	else
		Q->front = temp->next;
	Q->size--;
	free(temp);
	return data;
}

int flag;

void BFS(Queue* Q, int* mark, int* path, char* operation, int B) {
	listdata temp = DeQueue(Q);	
	listdata input;
	if (flag == 1)
		return;
	if (mark[temp.vertex] != 0)
		return;
	
	int D_vertex = D(temp.vertex);
	int S_vertex = S(temp.vertex);
	int L_vertex = L(temp.vertex);
	int R_vertex = R(temp.vertex);

	mark[temp.vertex] = 1;
	path[temp.vertex] = temp.path;
	operation[temp.vertex] = temp.operation;

	if (mark[D_vertex] == 0) {
		if (D_vertex == B) {			
			flag = 1;
			path[D_vertex] = temp.vertex;
			operation[D_vertex] = 'D';
			return;
		}
		else {			
			input.vertex = D_vertex;
			input.path = temp.vertex;
			input.operation = 'D';
			EnQueue(Q, input);
		}
	}
	
	if (mark[S_vertex] == 0) {
		if (S_vertex == B) {
			flag = 1;
			path[S_vertex] = temp.vertex;
			operation[S_vertex] = 'S';
			return;
		}
		else {
			input.vertex = S_vertex;
			input.path = temp.vertex;
			input.operation = 'S';
			EnQueue(Q, input);
		}
	}

	if (mark[L_vertex] == 0) {
		if (L_vertex == B) {
			flag = 1;
			path[L_vertex] = temp.vertex;
			operation[L_vertex] = 'L';
			return;
		}
		else {
			input.vertex = L_vertex;
			input.path = temp.vertex;
			input.operation = 'L';
			EnQueue(Q, input);
		}
	}

	if (mark[R_vertex] == 0) {
		if (R_vertex == B) {
			flag = 1;
			path[R_vertex] = temp.vertex;
			operation[R_vertex] = 'R';
			return;
		}
		else {
			input.vertex = R_vertex;
			input.path = temp.vertex;
			input.operation = 'R';
			EnQueue(Q, input);
		}
	}
}

int main(void) {
	int T, A, B;
	int i, j, k, temp;
	listdata input;
	int mark[10000];
	int path[10000];
	char operation[10000];
	char route[10000];
	Queue* Q = createQueue();
		
	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%d %d", &A, &B);		

		for (j = 0; j < 10000; j++) {
			mark[j] = 0;
			path[j] = 0;
		}
		input.vertex = A;		
		EnQueue(Q, input);
		flag = 0;
		while (Q->size != 0)
			BFS(Q, mark, path, operation, B);

		temp = B;		
		k = 0;		
		while (temp != A) {
			route[k] = operation[temp];
			k++;
			temp = path[temp];
		}

		for (j = 0; j < k; j++)
			printf("%c", route[k-j-1]);
		printf("\n");
	}


}