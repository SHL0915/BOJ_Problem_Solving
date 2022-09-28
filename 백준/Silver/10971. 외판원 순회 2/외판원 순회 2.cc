#include <iostream>
#include <algorithm>
using namespace std;

int N, minCost = -1;
int citys[10][10];
int mark[10];

void Traverse(int start, int now, int k, int cost);

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> citys[i][j];
		}
		mark[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		mark[i] = 1;
		Traverse(i, i, 0 , 0);
		mark[i] = 0;
	}
	cout << minCost;
	return 0;
}

void Traverse(int start, int now, int k, int cost) {
	if (k == N - 1) {
		if (citys[now][start] == 0)
			return;
		else {
			cost += citys[now][start];
			if (minCost == -1)
				minCost = cost;
			else
				minCost = min(minCost, cost);
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			if (mark[i] != 0 || citys[now][i] == 0)
				continue;
			else {
				mark[i] = 1;
				Traverse(start, i, k + 1, cost + citys[now][i]);
				mark[i] = 0;
			}
		}
	}
}