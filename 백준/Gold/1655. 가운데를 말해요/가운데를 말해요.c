#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* Arr;
	int capacity;
	int count;
}Heap;

Heap* createHeap(int capacity) {
	Heap* h = (Heap*)malloc(sizeof(Heap));
	if (!h)
		return NULL;
	h->capacity = capacity;
	h->count = 0;
	h->Arr = (int*)malloc(sizeof(int) * capacity);
	if (!h->Arr)
		return NULL;
	return h;
}

void ResizeHeap(Heap* h) {
	int i;
	int* oldArray = h->Arr;
	h->Arr = (int*)malloc(sizeof(int) * (h->capacity) * 2);
	if (!h->Arr)
		return;
	for (i = 0; i < h->capacity; i++) {
		h->Arr[i] = oldArray[i];
	}
	h->capacity *= 2;
	free(oldArray);
	return;
}

int LeftChild(Heap* h, int i) {
	int left = (i * 2) + 1;
	if ((left < 0) || (left >= h->count))
		return -1;
	return left;
}

int RightChild(Heap* h, int i) {
	int right = (i * 2) + 2;
	if ((right < 0) || (right >= h->count))
		return -1;
	return right;
}

void HeapifyMin(Heap* h, int i) {
	int left, right, min, temp;
	left = LeftChild(h, i);
	right = RightChild(h, i);
	if ((left != -1) && (h->Arr[left] < h->Arr[i]))
		min = left;
	else 
		min = i;
	if ((right != -1) && (h->Arr[right] < h->Arr[min]))
		min = right;
	if (min != i) {
		temp = h->Arr[i];
		h->Arr[i] = h->Arr[min];
		h->Arr[min] = temp;
		HeapifyMin(h, min);
	}
	return;
}

int DeleteMin(Heap* h) {
	int data;
	if (h->count == 0)
		return -1;
	data = h->Arr[0];
	h->Arr[0] = h->Arr[h->count - 1];
	h->count--;
	HeapifyMin(h, 0);
	return data;
}

void HeapifyMax(Heap* h, int i) {
	int left, right, max, temp;
	left = LeftChild(h, i);
	right = RightChild(h, i);
	if ((left != -1) && (h->Arr[left] >= h->Arr[i]))
		max = left;
	else
		max = i;
	if ((right != -1) && (h->Arr[right] >= h->Arr[max]))
		max = right;
	if (max != i) {
		temp = h->Arr[i];
		h->Arr[i] = h->Arr[max];
		h->Arr[max] = temp;
		HeapifyMax(h, max);
	}
	return;
}

int DeleteMax(Heap* h) {
	int data;
	if (h->count == 0)
		return -1;
	data = h->Arr[0];
	h->Arr[0] = h->Arr[h->count - 1];
	h->count--;
	HeapifyMax(h, 0);
	return data;
}


void InsertMin(Heap* h, int data) {
	int i;
	if (h->count == h->capacity)
		ResizeHeap(h);
	h->count++;
	i = h->count - 1;
	while ((i > 0) && (data < h->Arr[(i - 1) / 2])) {
		h->Arr[i] = h->Arr[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	h->Arr[i] = data;
	return;
}

void InsertMax(Heap* h, int data) {
	int i;
	if (h->count == h->capacity)
		ResizeHeap(h);
	h->count++;
	i = h->count - 1;
	while ((i > 0) && (data > h->Arr[(i - 1) / 2])) {
		h->Arr[i] = h->Arr[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	h->Arr[i] = data;
	return;
}


int main(void) {
	int N, i;
	int midean;
	int data;

	Heap* minHeap, * maxHeap;
	minHeap = createHeap(1);
	maxHeap = createHeap(1);

	scanf("%d", &N);

	scanf("%d", &midean);
	printf("%d\n", midean);

	for (i = 1; i < N; i++) {
		scanf("%d", &data);
		if (data >= midean) {
			if (minHeap->count == maxHeap->count) 
				InsertMin(minHeap, data);
			
			else {
				InsertMin(minHeap, data);
				InsertMax(maxHeap, midean);
				midean = DeleteMin(minHeap);
			}
		}
		else {
			if (minHeap->count == maxHeap->count) {
				InsertMax(maxHeap, data);
				InsertMin(minHeap, midean);
				midean = DeleteMax(maxHeap);
			}
			else {
				InsertMax(maxHeap, data);
			}				
		}

		printf("%d\n", midean);
	}
}