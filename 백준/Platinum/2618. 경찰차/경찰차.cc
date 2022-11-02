#include <iostream>
#include <algorithm>
using namespace std;

int N, W;
pair<int, int> arr[1001];
int table[1001][1001];
int route[1001][1001];

int DP(int car1, int car2);
int dist(int x1, int y1, int x2, int y2);
int absol(int A);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> W;
	for (int i = 1; i <= W; i++) {
		int x, y;
		cin >> x >> y;
		arr[i] = { x,y };
	}	
	cout << DP(0, 0) << '\n';
	int x_ptr = 0, y_ptr = 0;
	for (int i = 0; i < W; i++) {
		cout << route[x_ptr][y_ptr] << '\n';
		if (route[x_ptr][y_ptr] == 1) x_ptr = i + 1;
		else y_ptr = i + 1;
	}
	return 0;
}

int DP(int car1, int car2) {
	if (car1 == W || car2 == W) return 0;
	else if (table[car1][car2] == 0) {
		int next = max(car1, car2) + 1;
		int A, B;
		if (car1 == 0) A = DP(next, car2) + dist(arr[next].first, arr[next].second, 1, 1);
		else A = DP(next, car2) + dist(arr[next].first, arr[next].second, arr[car1].first, arr[car1].second);
		if (car2 == 0) B = DP(car1, next) + dist(arr[next].first, arr[next].second, N, N);
		else B = DP(car1, next) + dist(arr[next].first, arr[next].second, arr[car2].first, arr[car2].second);
		table[car1][car2] = min(A, B);
		if (A <= B) route[car1][car2] = 1;
		else route[car1][car2] = 2;
	}
	return table[car1][car2];
}

int dist(int x1, int y1, int x2, int y2) {
	return absol(x1 - x2) + absol(y1 - y2);
}

int absol(int A) {
	if (A >= 0) return A;
	else return -1 * A;
}