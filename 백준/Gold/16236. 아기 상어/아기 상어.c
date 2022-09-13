#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y, depth;
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

void EnQueue(Queue* Q, listdata data) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
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
	listdata data = temp->data;
	if (Q->size == 1)
		Q->rear = NULL;
	Q->front = temp->next;
	Q->size--;
	free(temp);
	return data;
}

void Transfer(int** map, int x, int y, int N) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (map[i][j] == 9) {
				map[i][j] = 0;
			}
		}
	}
	map[y][x] = 9;
	return;
}

int size = 2;
int fish = 0;
int time = 0;
int flag;
int base;
int k;


void BFS(Queue* Q, int** map, int ** mark, int N, listdata * candidate) {
	listdata temp = DeQueue(Q);
	listdata input;
	if (flag == 1) {
		if (temp.depth > base)
			return;
	}
	if (mark[temp.y][temp.x] != -1)
		return;
	mark[temp.y][temp.x] = temp.depth;

	if ((temp.y - 1 >= 0) && (map[temp.y - 1][temp.x] <= size)) {
		input = temp;
		input.depth += 1;
		input.y -= 1;
		if (((map[input.y][input.x] == size) || (map[input.y][input.x] == 0)) || map[input.y][input.x] == 9) {
			if(flag == 0)
				EnQueue(Q, input);
		}
		else {
			candidate[k] = input;
			k++;
			base = temp.depth;
			flag = 1;
		}
	}
	if ((temp.x - 1 >= 0) && (map[temp.y][temp.x - 1] <= size)) {
		input = temp;
		input.depth += 1;
		input.x -= 1;
		if (((map[input.y][input.x] == size) || (map[input.y][input.x] == 0)) || map[input.y][input.x] == 9) {
			if (flag == 0)
				EnQueue(Q, input);
		}
		else {
			candidate[k] = input;
			k++;
			base = temp.depth;
			flag = 1;
		}
	}
	if ((temp.x + 1 < N) && (map[temp.y][temp.x + 1] <= size)) {
		input = temp;
		input.depth += 1;
		input.x += 1;
		if (((map[input.y][input.x] == size) || (map[input.y][input.x] == 0)) || map[input.y][input.x] == 9) {
			if (flag == 0)
				EnQueue(Q, input);
		}
		else {
			candidate[k] = input;
			k++;
			base = temp.depth;
			flag = 1;
		}
	}
	if ((temp.y + 1 < N) && (map[temp.y + 1][temp.x] <= size)) {
		input = temp;
		input.depth += 1;
		input.y += 1;
		if (((map[input.y][input.x] == size) || (map[input.y][input.x] == 0)) || map[input.y][input.x] == 9) {
			if (flag == 0)
				EnQueue(Q, input);
		}
		else {
			candidate[k] = input;
			k++;
			base = temp.depth;
			flag = 1;
		}
	}
}

void Merge(listdata Arr[], listdata temp[], int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while ((i < right) && (j <= right_end)) {
		if (Arr[i].depth <= Arr[j].depth) {
			if (Arr[i].depth == Arr[j].depth) {
				if (Arr[i].y <= Arr[j].y) {
					if (Arr[i].y == Arr[j].y) {
						if (Arr[i].x <= Arr[j].x) {
							temp[pos].x = Arr[i].x;
							temp[pos].y = Arr[i].y;
							temp[pos].depth = Arr[i].depth;
							i++;
							pos++;
						}
						else {
							temp[pos].x = Arr[j].x;
							temp[pos].y = Arr[j].y;
							temp[pos].depth = Arr[j].depth;
							j++;
							pos++;
						}
					}
					else {
						temp[pos].x = Arr[i].x;
						temp[pos].y = Arr[i].y;
						temp[pos].depth = Arr[i].depth;
						i++;
						pos++;
					}					
				}
				else {
					temp[pos].x = Arr[j].x;
					temp[pos].y = Arr[j].y;
					temp[pos].depth = Arr[j].depth;
					j++;
					pos++;
				}
			}
			else {
				temp[pos].x = Arr[i].x;
				temp[pos].y = Arr[i].y;
				temp[pos].depth = Arr[i].depth;
				i++;
				pos++;
			}
		}
		else {
			temp[pos].x = Arr[j].x;
			temp[pos].y = Arr[j].y;
			temp[pos].depth = Arr[j].depth;
			j++;
			pos++;
		}
	}
	while (i < right) {
		temp[pos].x = Arr[i].x;
		temp[pos].y = Arr[i].y;
		temp[pos].depth = Arr[i].depth;
		i++;
		pos++;
	}
	while (j <= right_end) {
		temp[pos].x = Arr[j].x;
		temp[pos].y = Arr[j].y;
		temp[pos].depth = Arr[j].depth;
		j++;
		pos++;
	}
	for (i = left; i <= right_end; i++) {
		Arr[i].x = temp[i].x;
		Arr[i].y = temp[i].y;
		Arr[i].depth = temp[i].depth;
	}
}

void MergeSort(listdata Arr[], listdata temp[], int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(Arr, temp, left, mid);
		MergeSort(Arr, temp, mid + 1, right_end);
		Merge(Arr, temp, left, mid + 1, right_end);
	}
}

int main(void) {
	int N, i, j;
	int** map, ** mark;
	listdata input;
	listdata* candidate, * temp;
	Queue* Q = createQueue();



	scanf("%d", &N);

	map = (int**)malloc(sizeof(int*) * N);
	mark = (int**)malloc(sizeof(int*) * N);
	candidate = (listdata*)malloc(sizeof(listdata) * N * N);
	temp = (listdata*)malloc(sizeof(listdata) * N * N);

	for (i = 0; i < N; i++) {
		map[i] = (int*)malloc(sizeof(int) * N);
		mark[i] = (int*)malloc(sizeof(int) * N);
		for (j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	}

	while (1) {
		flag = 0;
		k = 0;
		base = 0;
		for (i = 0; i < N; i++) {			
			for (j = 0; j < N; j++) {
				mark[i][j] = -1;
				if (map[i][j] == 9) {
					input.x = j;
					input.y = i;
					input.depth = 0;
				}
			}
		}

		EnQueue(Q, input);

		while (Q->size != 0)
			BFS(Q, map, mark, N, candidate);

		if (flag == 0) {
			printf("%d", time);
			break;
		}

		MergeSort(candidate, temp, 0, k-1);
					
		Transfer(map, candidate[0].x, candidate[0].y, N);
		fish++;
		if (fish == size) {
			size++;
			fish = 0;
		}
		time += candidate[0].depth;		
		
	}

	return 0;
}