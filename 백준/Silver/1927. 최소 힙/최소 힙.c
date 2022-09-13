#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
	int* Arr;
	int capacity;
	int count;
}Heap;

Heap* CreateHeap(int capacity) {
	Heap* h = (Heap*)malloc(sizeof(Heap));
	if (!h)
		return NULL;
	h->Arr = (int*)malloc(sizeof(int) * capacity);
	if (!h->Arr)
		return NULL;
	h->capacity = capacity;
	h->count = 0;
	return h;
}

void Resize(Heap * h) {
	int i;
	int Org_Size = h->capacity;
	int* temp = h->Arr;

	h->Arr = (int*)malloc(sizeof(int) * Org_Size * 2);
	if (!h->Arr)
		return;
	for (i = 0; i < Org_Size; i++) {
		h->Arr[i] = temp[i];
	}
	h->capacity *= 2;
	free(temp);
	return;
}

int LeftChild(Heap* h, int i) {
	int left = i * 2 + 1;
	if ((i < 0) || (left >= h->count))
		return -1;
	return left;
}

int RightChild(Heap* h, int i) {
	int right = i * 2 + 2;
	if ((i < 0) || (right >= h->count))
		return -1;
	return right;
}

void Heapify(Heap* h, int i) {
	int right, left, min, temp;
	right = RightChild(h, i);
	left = LeftChild(h, i);

	if ((left != -1) && (h->Arr[i] > h->Arr[left]))
		min = left;
	else
		min = i;
	if ((right != -1) && (h->Arr[min] > h->Arr[right]))
		min = right;

	if (min != i) {
		temp = h->Arr[i];
		h->Arr[i] = h->Arr[min];
		h->Arr[min] = temp;
		Heapify(h, min);
	}

	return;
}

void Push(Heap* h, int data) {
	int i;
	if (h->capacity == h->count)
		Resize(h);
	h->count++;
	i = h->count - 1;

	while ((i > 0) && (h->Arr[(i - 1) / 2] > data)) {
		h->Arr[i] = h->Arr[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	h->Arr[i] = data;

	return;	
}

int Pop(Heap* h) {
	int temp;
	if (h->count == 0)
		return 0;
	temp = h->Arr[0];
	h->Arr[0] = h->Arr[h->count - 1];
	Heapify(h, 0);
	h->count--;
	return temp;
}

int main(void) {
	int N;
	int i;
	int operation;
	Heap* h;

	scanf("%d", &N);

	h = CreateHeap(1);

	for (i = 0; i < N; i++) {
		scanf("%d", &operation);
		if (operation == 0) {
			printf("%d\n", Pop(h));
		}
		else {
			Push(h, operation);
		}
	}
	return 0;
}