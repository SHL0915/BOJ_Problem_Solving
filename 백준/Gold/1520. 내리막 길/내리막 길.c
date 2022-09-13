#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y, val;
}data;

typedef struct {
	data* Arr;
	int capacity;
	int count;
}Heap;

Heap* createHeap(int capacity) {
	Heap* H = (Heap*)malloc(sizeof(Heap));
	if (!H)
		return NULL;
	H->capacity = capacity;
	H->count = 0;
	H->Arr = (data*)malloc(sizeof(data) * capacity);
	if (!H->Arr)
		return NULL;
	return H;
}

void Resize(Heap* H) {
	data* OrgArr = H->Arr;
	H->Arr = (data*)malloc(sizeof(data) * (H->capacity) * 2);
	if (!H->Arr)
		return;
	for (int i = 0; i < H->capacity; i++) {
		H->Arr[i].x = OrgArr[i].x;
		H->Arr[i].y = OrgArr[i].y;
		H->Arr[i].val = OrgArr[i].val;
	}
	H->capacity = H->capacity * 2;
	return;
}

void Insert(Heap* H, data d) {
	int i;	
	if (H->capacity == H->count)
		Resize(H);
	H->count++;
	i = H->count - 1;
	while ((i > 0) && (d.val > H->Arr[(i - 1) / 2].val)) {
		H->Arr[i].x = H->Arr[(i - 1) / 2].x;
		H->Arr[i].y = H->Arr[(i - 1) / 2].y;
		H->Arr[i].val = H->Arr[(i - 1) / 2].val;
		i = (i - 1) / 2;
	}
	H->Arr[i].x = d.x;
	H->Arr[i].y = d.y;
	H->Arr[i].val = d.val;
	return;
}

int LeftChild(Heap* H, int i) {
	int left = i * 2 + 1;
	if ((i < 0) || (left >= H->count))
		return -1;
	return left;
}

int RightChild(Heap* H, int i) {
	int right = i * 2 + 2;
	if ((i < 0) || (right >= H->count))
		return -1;
	return right;
}


void Heapify(Heap* H, int i) {
	int left, right, max;
	data temp;
	left = LeftChild(H, i);
	right = RightChild(H, i);
	if ((left != -1) && (H->Arr[left].val > H->Arr[i].val))
		max = left;
	else
		max = i;
	if ((right != -1) && (H->Arr[right].val > H->Arr[max].val))
		max = right;
	if (max != i) {
		temp.x = H->Arr[max].x;
		temp.y = H->Arr[max].y;
		temp.val = H->Arr[max].val;
		H->Arr[max].x = H->Arr[i].x;
		H->Arr[max].y = H->Arr[i].y;
		H->Arr[max].val = H->Arr[i].val;
		H->Arr[i].x = temp.x;
		H->Arr[i].y = temp.y;
		H->Arr[i].val = temp.val;
		Heapify(H, max);
	}
	return;
}

data DeleteMax(Heap* H) {
	data output;	
	output.x = H->Arr[0].x;
	output.y = H->Arr[0].y;
	output.val = H->Arr[0].val;
	H->Arr[0].x = H->Arr[H->count - 1].x;
	H->Arr[0].y = H->Arr[H->count - 1].y;
	H->Arr[0].val = H->Arr[H->count - 1].val;
	H->count--;
	Heapify(H, 0);
	return output;
}

int path[500][500] = { 0 };

void BFS(Heap* H, int** map, int M, int N) {
	data temp = DeleteMax(H);
	data input;
	if (path[temp.y][temp.x] != 0)
		return;
	if (temp.x - 1 >= 0) {
		if (map[temp.y][temp.x] > map[temp.y][temp.x - 1]) {
			input.x = temp.x - 1;
			input.y = temp.y;
			input.val = map[temp.y][temp.x - 1];
			Insert(H, input);
		}
		else if (map[temp.y][temp.x] < map[temp.y][temp.x - 1])
			path[temp.y][temp.x] += path[temp.y][temp.x - 1];
	}
	if (temp.x + 1 < N) {
		if (map[temp.y][temp.x] > map[temp.y][temp.x + 1]) {
			input.x = temp.x + 1;
			input.y = temp.y;
			input.val = map[temp.y][temp.x + 1];
			Insert(H, input);
		}
		else if (map[temp.y][temp.x] < map[temp.y][temp.x + 1])
			path[temp.y][temp.x] += path[temp.y][temp.x + 1];
	}
	if (temp.y - 1 >= 0) {
		if (map[temp.y][temp.x] > map[temp.y - 1][temp.x]) {
			input.x = temp.x;
			input.y = temp.y - 1;
			input.val = map[temp.y - 1][temp.x];
			Insert(H, input);
		}
		else if (map[temp.y][temp.x] < map[temp.y - 1][temp.x])
			path[temp.y][temp.x] += path[temp.y - 1][temp.x];
	}
	if (temp.y + 1 < M) {
		if (map[temp.y][temp.x] > map[temp.y + 1][temp.x]) {
			input.x = temp.x;
			input.y = temp.y + 1;
			input.val = map[temp.y + 1][temp.x];
			Insert(H, input);
		}
		else if (map[temp.y][temp.x] < map[temp.y + 1][temp.x])
			path[temp.y][temp.x] += path[temp.y + 1][temp.x];
	}
}

int main(void) {
	int M, N, i, j;
	int** map;
	Heap* H = createHeap(1);
	data input;
	scanf("%d %d", &M, &N);
	map = (int**)malloc(sizeof(int*) * M);
	if (!map)
		return 1;
	for (i = 0; i < M; i++) {
		map[i] = (int*)malloc(sizeof(int) * N);
		if (!map[i])
			return 1;
		for (j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	path[0][0] = 1;
	if (map[0][1] < map[0][0]) {
		input.x = 1;
		input.y = 0;
		input.val = map[0][1];
		Insert(H, input);
	}
	if (map[1][0] < map[0][0]) {
		input.x = 0;
		input.y = 1;
		input.val = map[1][0];
		Insert(H, input);
	}	
	while (H->count != 0)
		BFS(H, map, M, N);
	printf("%d", path[M - 1][N - 1]);
	return 0;
}