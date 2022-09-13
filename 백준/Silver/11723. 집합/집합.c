#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void all(int* Arr) {
	int i;
	for (i = 0; i < 20; i++)
		Arr[i] = 1;
}

void empty(int* Arr) {
	int i;
	for (i = 0; i < 20; i++)
		Arr[i] = 0;
}

void add(int* Arr, int x) {
	Arr[x] = 1;
}

void Remove(int* Arr, int x) {
	Arr[x] = 0;
}

void check(int* Arr, int x) {
	printf("%d\n", Arr[x]);
}

void toggle(int* Arr, int x) {
	Arr[x] += 1;
	Arr[x] %= 2;
}



int main(void) {
	int* S = (int*)malloc(sizeof(int) * 20);
	int M, i, x;
	char operation[7];

	scanf("%d", &M);


	empty(S);

	for (i = 0; i < M; i++) {
		scanf("%s", operation);
		if (operation[0] == 'r') {
			scanf("%d", &x);
			Remove(S, x - 1);
		}
		else if (operation[0] == 't') {
			scanf("%d", &x);
			toggle(S, x - 1);
		}
		else if (operation[0] == 'c') {
			scanf("%d", &x);
			check(S, x - 1);
		}
		else if (operation[0] == 'e') {
			empty(S);
		}
		else if (operation[1] == 'd') {
			scanf("%d", &x);
			add(S, x - 1);
		}
		else {
			all(S);
		}
	}
	return 0;

}