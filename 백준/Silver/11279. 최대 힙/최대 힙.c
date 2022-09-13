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
	int* Arr = (int*)malloc(sizeof(int) * capacity);	
	if (!Arr)
		return NULL;
	h->Arr = Arr;
	h->capacity = capacity;
	h->count = 0;
	return h;
}

int LeftChild(Heap* h, int i) {
	int left = i*2 + 1;
	if ((left >= h->count) || (i < 0))
		return -1;
	return left;
}

int RightChild(Heap* h, int i) {
	int right = i * 2 + 2;
	if ((right >= h->count) || (i < 0))
		return -1;
	return right;
}

void Heapify(Heap* h, int i) {
	int left, right, max, temp;
	left = LeftChild(h, i);
	right = RightChild(h, i);
	if ((left != -1) && (h->Arr[left] > h->Arr[i]))
		max = left;
	else
		max = i;
	if ((right != -1) && (h->Arr[right] > h->Arr[max]))
		max = right;
	if (max != i) {
		temp = h->Arr[i];
		h->Arr[i] = h->Arr[max];
		h->Arr[max] = temp;
		Heapify(h, max);
	}
	return;
}

void Resize(Heap* h) {
	int i;
	int* temp = h->Arr;
	int* newArr = (int*)malloc(sizeof(int) * (h->capacity) * 2);

	for (i = 0; i < h->capacity; i++) {
		newArr[i] = temp[i];
	}
	free(temp);
	h->capacity *= 2;
	h->Arr = newArr;
	return;
}

void Push(Heap* h, int data) {
	int i;
	if (h->count == h->capacity)
		Resize(h);
	h->count++;
	i = h->count - 1;
	while ((i > 0) && (data > h->Arr[(i-1)/2])) {
		h->Arr[i] = h->Arr[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	h->Arr[i] = data;
	return;
}

int Pop(Heap* h) {
	int data;
	if (h->count == 0)
		return 0;
	data = h->Arr[0];
	h->Arr[0] = h->Arr[h->count - 1];
	Heapify(h, 0);
	h->count--;
	return data;
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

}