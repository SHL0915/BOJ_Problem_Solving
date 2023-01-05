#include <bits/stdc++.h>
using namespace std;

int N, ans;
int arr[101];
int in_degree[101];
int mark[101];

int absol(int A);
bool check(int A, int type);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		if (i == 0) mark[i] = 1;
		else if (i == N - 1) continue;
		else if (absol(arr[i] - arr[i - 1]) > absol(arr[i] - arr[i + 1])) mark[i] = 1;
	}
	for (int i = 0; i < N; i++) {
		if (i == 0) in_degree[i + 1] = 1;
		else if (i == N - 1) in_degree[i - 1] = 1;
		else if (absol(arr[i] - arr[i - 1]) > absol(arr[i] - arr[i + 1])) in_degree[i + 1] = 1;
		else in_degree[i - 1] = 1;
	}
	for (int i = 0; i < N; i++) {
		if (in_degree[i] == 0) ans++;
	}
	for (int i = 0; i < N - 1; i++) {
		if (mark[i] == 1 && mark[i + 1] == 0) {
			if (!(check(i - 1, 1) || check(i + 2, 0))) ans++;
		}
	}
	cout << ans;
	return 0;
}

int absol(int A) {
	if (A < 0) return -A;
	else return A;
}

bool check(int A, int type) {
	if (A < 0 || A > N - 1) return false;
	if (type ^ mark[A]) return false;
	else return true;
}