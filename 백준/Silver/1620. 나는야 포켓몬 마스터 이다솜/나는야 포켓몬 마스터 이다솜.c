#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char* name;
	int index;
}Pokemon;

Pokemon* CreatePokemon() {
	Pokemon* P = (Pokemon*)malloc(sizeof(Pokemon));
	if (!P)
		return NULL;
	P->name = (char*)malloc(sizeof(char) * 21);
	if (!P->name)
		return NULL;
	P->index = 0;
	return P;
}

void Merge(Pokemon** P, Pokemon** temp, int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while ((i <= right - 1) && (j <= right_end)) {
		if (strcmp(P[i]->name, P[j]->name) <= 0) {
			temp[pos] = P[i];
			i++;
			pos++;
		}
		else {
			temp[pos] = P[j];
			j++;
			pos++;
		}
	}
	while (i <= right - 1) {
		temp[pos] = P[i];
		i++;
		pos++;
	}
	while (j <= right_end) {
		temp[pos] = P[j];
		j++;
		pos++;
	}
	for (i = left; i <= right_end; i++)
		P[i] = temp[i];
	return;
}

void MergeSort(Pokemon** P, Pokemon** temp, int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(P, temp, left, mid);
		MergeSort(P, temp, mid + 1, right_end);
		Merge(P, temp, left, mid + 1, right_end);
	}
	else
		return;
}

int Search(Pokemon** P, int left, int right_end, char* str) {
	int mid = (left + right_end) / 2;
	int a;
	if (left < right_end) {
		if (strcmp(P[mid]->name, str) == 0)
			return P[mid]->index;
		else if (strcmp(P[mid]->name, str) < 0)
			a = Search(P, mid + 1, right_end, str);
		else
			a = Search(P, left, mid, str);

	}
	else
		return P[mid]->index;
}

int main(void) {
	int N, M;
	int i;
	Pokemon** P, ** temp;
	char** Arr;
	char str[21];
	int num;

	scanf("%d %d", &N, &M);
	
	P = (Pokemon**)malloc(sizeof(Pokemon*) * N);
	temp = (Pokemon**)malloc(sizeof(Pokemon*) * N);
	Arr = (char**)malloc(sizeof(char*) * N);
	

	for (i = 0; i < N; i++) {
		Arr[i] = (char*)malloc(sizeof(char) * 21);
		P[i] = CreatePokemon();
		temp[i] = CreatePokemon();
		scanf("%s", P[i]->name);
		strcpy(Arr[i], P[i]->name);
		P[i]->index = i + 1;
	}

	MergeSort(P, temp, 0, N - 1);

	for (i = 0; i < M; i++) {
		scanf("%s", str);
		num = atoi(str);
		if (num == 0) {
			printf("%d\n", Search(P, 0, N - 1, str));
		}
		else {
			printf("%s\n", Arr[num - 1]);
		}
	}

	return 0;
}