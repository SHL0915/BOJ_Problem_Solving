#include <iostream>
using namespace std;

typedef struct ListNode{
	struct ListNode* next, *prev;
	int data;
}ListNode;

typedef struct {
	ListNode* front, * rear;
	int size;
}Deque;

Deque* createDeque(void) {
	Deque* D = new Deque;
	if (!D)
		return nullptr;
	D->front = nullptr;
	D->rear = nullptr;
	D->size = 0;
	return D;
}

void PushFront(Deque * D, int data) {
	ListNode* newNode = new ListNode;
	if (!newNode)
		return;
	newNode->data = data;
	newNode->prev = nullptr;
	if (D->size == 0) {	
		newNode->next = nullptr;
		D->rear = newNode;
	}
	else {
		D->front->prev = newNode;
		newNode->next = D->front;
	}
	D->front = newNode;
	D->size++;
	return;
}

void PushRear(Deque* D, int data) {
	ListNode* newNode = new ListNode;
	if (!newNode)
		return;
	newNode->data = data;
	newNode->next = nullptr;
	if (D->size == 0) {
		D->front = newNode;
		newNode->prev = nullptr;
	}
	else {
		D->rear->next = newNode;
		newNode->prev = D->rear;
	}
	D->rear = newNode;
	D->size++;
	return;
}

int PopFront(Deque* D) {
	if (D->size == 0)
		return -1;
	ListNode* temp = D->front;
	int data = temp->data;
	if (D->size == 1) {
		D->front = nullptr;
		D->rear = nullptr;
	}
	else {
		D->front = D->front->next;
		D->front->prev = nullptr;
	}
	D->size--;
	delete temp;
	return data;
}

int PopRear(Deque* D) {
	if (D->size == 0)
		return -1;
	ListNode* temp = D->rear;
	int data = temp->data;
	if (D->size == 1) {
		D->front = nullptr;
		D->rear = nullptr;
	}
	else {
		D->rear = D->rear->prev;
		D->rear->next = nullptr;
	}
	D->size--;
	delete temp;
	return data;
}

int main(void) {
	Deque* D = createDeque();
	int N, K, M, reverse = 0, m = 0;
	cin >> N >> K >> M;
	for (int i = 1; i <= N; i++)
		PushRear(D, i);	
	while (1) {
		if (D->size == 0)
			break;
		if (reverse == 0) { // 순방향
			for (int i = 0; i < K - 1; i++) 
				PushRear(D, PopFront(D));
			cout << PopFront(D) << endl;
		}
		else { // 역방향
			for (int i = 0; i < K - 1; i++)
				PushFront(D, PopRear(D));
			cout << PopRear(D) << endl;
		}
		m ++;
		if (m == M) {
			reverse += 1;
			reverse = reverse % 2;
			m = 0;
		}
	}
	return 0;
}