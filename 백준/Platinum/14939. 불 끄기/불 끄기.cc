#include <iostream>
#include <algorithm>
using namespace std;

int lightBulb[10][10];
int temp[10][10];
int minNum = -1;

void BruteForce(int bit);
void Switch(int x, int y);

int main(void) {
	string s;
	for (int i = 0; i < 10; i++) { // 전구 입력
		cin >> s;
		for (int j = 0; j < 10; j++) {
			if (s[j] == '#') lightBulb[i][j] = 0;
			else lightBulb[i][j] = 1;
		}
	}
	for (int i = 0; i < 1 << 10; i++)
		BruteForce(i); // 첫 번째 줄에 대하여 완전 탐색 2^10
	cout << minNum;
	return 0;
}

void BruteForce(int bit) {
	int cnt = 0, x = 0, sum = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			temp[i][j] = lightBulb[i][j];
		}
	}
	while (bit) {
		if (bit & 1) {
			Switch(x, 0);
			cnt++; // 스위치 누른 횟수 저장
		}
		x++;
		bit = bit >> 1;
	}
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (temp[i - 1][j] == 1) {
				Switch(j, i);
				cnt++;
			}
		}
	}
	for (int i = 0; i < 10; i++)
		sum += temp[9][i];
	if (sum == 0) {
		if (minNum == -1)
			minNum = cnt;
		else
			minNum = min(minNum, cnt);
	}
	return;
}

void Switch(int x, int y) {
	temp[y][x] ++;
	temp[y][x] %= 2;
	if (x - 1 >= 0) {
		temp[y][x - 1] ++;
		temp[y][x - 1] %= 2;
	}
	if (x + 1 < 10) {
		temp[y][x + 1] ++;
		temp[y][x + 1] %= 2;
	}
	if (y - 1 >= 0) {
		temp[y - 1][x] ++;
		temp[y - 1][x] %= 2;
	}
	if (y + 1 < 10) {
		temp[y + 1][x] ++;
		temp[y + 1][x] %= 2;
	}
	return;
}