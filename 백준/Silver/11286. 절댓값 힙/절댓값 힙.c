#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* arr;
	int capacity;
	int count;
}Heap;

int Abs(int data) {
	if (data < 0)
		return data * (-1);
	return data;
}

Heap* CreateHeap(int capacity) {
	Heap* h = (Heap*)malloc(sizeof(Heap));
	if (!h)
		return NULL;
	h->capacity = capacity;
	h->count = 0;
	h->arr = (int*)malloc(sizeof(int) * capacity);
	if (!h->arr)
		return NULL;
	return h;
}

void Resize(Heap* h) {
	int i;
	int Org_size = h->capacity;
	int* temp = h->arr;
	h->arr = (int*)malloc(sizeof(int) * Org_size * 2);
	if (!h->arr)
		return;
	for (i = 0; i < Org_size; i++) {
		h->arr[i] = temp[i];
	}
	h->capacity *= 2;
	free(temp);
	return;
}

void Push(Heap* h, int data) {
	int i;
	if (h->count == h->capacity)
		Resize(h);
	h->count++;
	i = h->count - 1;
	while ((i > 0) && (Abs(data) <= Abs(h->arr[(i - 1) / 2]))) {
		if (Abs(data) == Abs(h->arr[(i - 1) / 2])){
			if (data > h->arr[(i - 1) / 2])
				break;
		}
		h->arr[i] = h->arr[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	h->arr[i] = data;
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
	int min, left, right, temp;
	left = LeftChild(h, i);
	right = RightChild(h, i);
	if ((left != -1) && (Abs(h->arr[i]) >= Abs(h->arr[left]))) {
		if (Abs(h->arr[i]) == Abs(h->arr[left])) {
			if (h->arr[i] > h->arr[left])
				min = left;
			else
				min = i;
		}
		else
			min = left;
	}
	else
		min = i;
	if ((right != -1) && (Abs(h->arr[min]) >= Abs(h->arr[right]))) {
		if (Abs(h->arr[min]) == Abs(h->arr[right])) {
			if (h->arr[min] > h->arr[right])
				min = right;
		}
		else
			min = right;
	}
	if (min != i) {
		temp = h->arr[i];
		h->arr[i] = h->arr[min];
		h->arr[min] = temp;
		Heapify(h, min);
	}
	return;
}

int Pop(Heap* h) {
	int data;
	if (h->count == 0)
		return 0;
	data = h->arr[0];
	h->arr[0] = h->arr[h->count - 1];
	h->count--;
	Heapify(h, 0);	
	return data;
}


int main(void) {
	int N;
	int i;
	int data;
	Heap* h = CreateHeap(1);
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &data);

		if (data == 0)
			printf("%d\n", Pop(h));
		else
			Push(h, data);
	}
	return 0;
}