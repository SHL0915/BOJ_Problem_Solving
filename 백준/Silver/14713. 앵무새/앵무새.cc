#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

struct ListNode {
	char s[33];
	ListNode* next;
};

struct Queue {
	ListNode* front, * rear;
	int size;
};

Queue* createQueue();
void Push(Queue* Q, const char* s);
void Pop(Queue* Q);
char* front(Queue* Q);


int main(void) {
	int N, i, j;
	Queue** qArr;
	char s[33], c;
	cin >> N;
	qArr = new Queue * [N];
	c = getchar();
	for (i = 0; i < N; i++) {
		qArr[i] = createQueue();		
		j = 0;
		while (1) {
			c = getchar();
			if (c == '\n') {
				s[j] = '\0';				
				Push(qArr[i], s);
				break;
			}
			else if (c == ' ') {
				s[j] = '\0';				
				Push(qArr[i], s);
				j = 0;
			}
			else
				s[j++] = c;
		}
	}
	j = 0;
	while (1) {
		c = getchar();
		if (c == '\n') {
			s[j] = '\0';			
			for (i = 0; i < N; i++) {
				if (qArr[i]->size == 0)
					continue;
				else if (strcmp(front(qArr[i]), s) == 0) {					
					Pop(qArr[i]);
					break;
				}
			}
			if (i == N) {
				cout << "Impossible";
				return 0;
			}
			break;
		}
		else if (c == ' ') {
			s[j] = '\0';		
			for (i = 0; i < N; i++) {
				if (qArr[i]->size == 0)
					continue;
				else if (strcmp(front(qArr[i]), s) == 0) {					
					Pop(qArr[i]);
					break;
				}
			}
			if (i == N) {
				cout << "Impossible";
				return 0;
			}
			j = 0;
		}
		else
			s[j++] = c;
	}
	for (i = 0; i < N; i++) {
		if (qArr[i]->size != 0) {
			cout << "Impossible";
			return 0;
		}
	}
	cout << "Possible";
	return 0;
}

Queue* createQueue() {
	Queue* Q = new Queue;
	Q->front = nullptr;
	Q->rear = nullptr;
	Q->size = 0;
	return Q;
}

void Push(Queue* Q, const char* s) {
	ListNode* newNode = new ListNode;
	strcpy(newNode->s, s);
	newNode->next = nullptr;
	if(Q->size == 0){
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

void Pop(Queue* Q) {
	ListNode* temp = Q->front;
	if (Q->size == 1) {
		Q->rear = nullptr;
		Q->front = nullptr;
	}
	else {
		Q->front = temp->next;
	}
	Q->size--;
	delete temp;
	return;
}

char* front(Queue* Q) {
	return Q->front->s;
}