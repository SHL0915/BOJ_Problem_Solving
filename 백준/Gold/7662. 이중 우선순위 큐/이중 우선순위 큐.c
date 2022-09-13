#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int* Arr;
	int capacity;
	int count;
}Heap;

Heap* createHeap(int capacity) {
	Heap* H = (Heap*)malloc(sizeof(Heap));
	H->Arr = (int*)malloc(sizeof(int) * capacity);
	H->capacity = capacity;
	H->count = 0;
	return H;
}

void Resize(Heap* H) {
	int* orgArr = H->Arr;
	H->Arr = (int*)malloc(sizeof(int) * (H->capacity) * 2);
	for (int i = 0; i < H->capacity; i++)
		H->Arr[i] = orgArr[i];
	H->capacity *= 2;
	return;
}

void InsertMin(Heap* H, int data) {
	int i;
	if (H->capacity == H->count)
		Resize(H);
	H->count++;
	i = H->count - 1;
	while (i > 0 && data < H->Arr[(i - 1) / 2]) {
		H->Arr[i] = H->Arr[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	H->Arr[i] = data;
	return;
}

void InsertMax(Heap* H, int data) {
	int i;
	if (H->capacity == H->count)
		Resize(H);
	H->count++;
	i = H->count - 1;
	while (i > 0 && data > H->Arr[(i - 1) / 2]) {
		H->Arr[i] = H->Arr[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	H->Arr[i] = data;
	return;
}

int LeftChild(Heap* H, int i) {
	int left = i * 2 + 1;
	if (i < 0 || left >= H->count)
		return -1;
	return left;
}

int RightChild(Heap* H, int i) {
	int right = i * 2 + 2;
	if (i < 0 || right >= H->count)
		return -1;
	return right;
}

void HeapifyMin(Heap* H, int i) {
	int left, right, min, temp;
	left = LeftChild(H, i);
	right = RightChild(H, i);
	if (left != -1 && H->Arr[left] < H->Arr[i])
		min = left;
	else
		min = i;
	if (right != -1 && H->Arr[right] < H->Arr[min])
		min = right;

	if (min != i) {
		temp = H->Arr[i];
		H->Arr[i] = H->Arr[min];
		H->Arr[min] = temp;
		HeapifyMin(H, min);
	}
	return;
}

int DeleteMin(Heap* H) {
	int data = H->Arr[0];
	H->Arr[0] = H->Arr[H->count - 1];
	H->count--;
	HeapifyMin(H, 0);
	return data;
}

void HeapifyMax(Heap* H, int i) {
	int left, right, max, temp;
	left = LeftChild(H, i);
	right = RightChild(H, i);
	if (left != -1 && H->Arr[left] > H->Arr[i])
		max = left;
	else
		max = i;
	if (right != -1 && H->Arr[right] > H->Arr[max])
		max = right;

	if (max != i) {
		temp = H-> Arr[i];
		H->Arr[i] = H->Arr[max];
		H->Arr[max] = temp;
		HeapifyMax(H, max);
	}
	return;
}

int DeleteMax(Heap* H) {
	int data = H->Arr[0];
	H->Arr[0] = H->Arr[H->count - 1];
	H->count--;
	HeapifyMax(H, 0);
	return data;
}

int main(void) {
	int T, k, i, j, data;
	char operation;
	Heap* minHeap, * maxHeap, * min_del_Heap, * max_del_Heap;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d", &k);
		minHeap = createHeap(1);
		maxHeap = createHeap(1);
		min_del_Heap = createHeap(1);
		max_del_Heap = createHeap(1);
		for (j = 0; j < k; j++) {
			operation = getchar();
			while (operation != 'I' && operation != 'D') {
				operation = getchar();
			}
			if (operation == 'I') {
				scanf("%d", &data);
				InsertMax(maxHeap, data);
				InsertMin(minHeap, data);
			}
			else {
				scanf("%d",&data);
				if (data == 1) {
					if (maxHeap->count == 0)
						continue;
					if (min_del_Heap->count == 0) {
						InsertMin(max_del_Heap, DeleteMax(maxHeap));
					}
					else {						
						while (1) {
							if (min_del_Heap->count == 0)
								break;
							if (maxHeap->count == 0)
								break;
							if (min_del_Heap->Arr[0] != maxHeap->Arr[0])
								break;
							data = DeleteMax(min_del_Heap);
							data = DeleteMax(maxHeap);
						}
						if (maxHeap->count == 0)
							continue;
						InsertMin(max_del_Heap, DeleteMax(maxHeap));
					}
				}
				else {
					if (minHeap->count == 0)
						continue;
					if (max_del_Heap->count == 0) {
						InsertMax(min_del_Heap, DeleteMin(minHeap));
					}
					else {
						while (1) {
							if (max_del_Heap->count == 0)
								break;
							if (minHeap->count == 0)
								break;
							if (max_del_Heap->Arr[0] != minHeap->Arr[0])
								break;
							data = DeleteMin(max_del_Heap);
							data = DeleteMin(minHeap);							
						}
						if (minHeap->count == 0)
							continue;
						InsertMax(min_del_Heap, DeleteMin(minHeap));						
					}					
				}
			}			
		}
		while (1) {
			if (max_del_Heap->count == 0)
				break;
			if (minHeap->count == 0)
				break;
			if (max_del_Heap->Arr[0] != minHeap->Arr[0])
				break;
			data = DeleteMin(max_del_Heap);
			data = DeleteMin(minHeap);
		}
		while (1) {
			if (min_del_Heap->count == 0)
				break;
			if (maxHeap->count == 0)
				break;
			if (min_del_Heap->Arr[0] != maxHeap->Arr[0])
				break;
			data = DeleteMax(min_del_Heap);
			data = DeleteMax(maxHeap);			
		}

		if (minHeap->count == 0)
			printf("EMPTY\n");
		else {
			printf("%d %d\n", maxHeap->Arr[0], minHeap->Arr[0]);
		}

		free(minHeap->Arr);
		free(minHeap);
		free(max_del_Heap->Arr);
		free(max_del_Heap);
		free(maxHeap->Arr);
		free(maxHeap);
		free(min_del_Heap->Arr);
		free(min_del_Heap);
	}
}
