#include <iostream>
#include <algorithm>
using namespace std;

int N, M, houseNum = 0, chickenNum = 0, minSum = -1;
int city[50][50];
pair <int, int> house[2500];
pair <int, int> chicken[2500];
pair <int, int> chosenChicken[13];

void ChooseChicken(int start, int k);
void FindDistance();

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1) house[houseNum++] = { j , i };
			else if (city[i][j] == 2) chicken[chickenNum++] = { j, i };
		}
	}
	ChooseChicken(0, 0);
	cout << minSum;
	return 0;
}

void ChooseChicken(int start, int k) {
	if (k == M) {
		FindDistance();
		return;
	}
	else {
		for (int i = start; i < chickenNum; i++) {
			chosenChicken[k] = chicken[i];
			ChooseChicken(i + 1, k + 1);
		}
	}
}

void FindDistance() {
	int sum = 0;
	for(int i = 0; i < houseNum; i ++){
		int x_dis, y_dis, dis, min_dis = -1;
		for (int j = 0; j < M; j++) {
			x_dis = house[i].first - chosenChicken[j].first;
			if (x_dis < 0) x_dis *= -1;
			y_dis = house[i].second - chosenChicken[j].second;
			if (y_dis < 0) y_dis *= -1;
			dis = x_dis + y_dis;
			if (min_dis == -1)
				min_dis = dis;
			else
				min_dis = min(min_dis, dis);
		}
		sum += min_dis;
	}
	if (minSum == -1)
		minSum = sum;
	else 
		minSum = min(minSum, sum);
	return;
}