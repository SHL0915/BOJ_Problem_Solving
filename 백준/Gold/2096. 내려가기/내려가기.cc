#include <iostream>
#include <algorithm>
using namespace std;

int N;
char arr[100000][3];
int table[100000][3];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		arr[i][0] -= '0';
		arr[i][1] -= '0';
		arr[i][2] -= '0';
	}
	table[0][0] = arr[0][0];
	table[0][1] = arr[0][1];
	table[0][2] = arr[0][2];	
	for (int i = 1; i < N; i++) {
		int temp = max(table[i - 1][0], table[i - 1][1]);
		temp = max(temp, table[i - 1][2]);
		table[i][0] = arr[i][0] + max(table[i - 1][0], table[i - 1][1]);
		table[i][1] = arr[i][1] + temp;
		table[i][2] = arr[i][2] + max(table[i - 1][1], table[i - 1][2]);
	}
	int max_num = max(table[N - 1][0], table[N - 1][1]);
	max_num = max(max_num, table[N - 1][2]);
	table[0][0] = arr[0][0];
	table[0][1] = arr[0][1];
	table[0][2] = arr[0][2];
	for (int i = 1; i < N; i++) {
		int temp = min(table[i - 1][0], table[i - 1][1]);
		temp = min(temp, table[i - 1][2]);
		table[i][0] = arr[i][0] + min(table[i - 1][0], table[i - 1][1]);
		table[i][1] = arr[i][1] + temp;
		table[i][2] = arr[i][2] + min(table[i - 1][1], table[i - 1][2]);
	}
	int min_num = min(table[N - 1][0], table[N - 1][1]);
	min_num = min(min_num, table[N - 1][2]);
	cout << max_num << " " << min_num;
	return 0;
}