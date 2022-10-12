#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans;
int input[300000];
pair <int, int> books[300000];
int mark[300001];

bool cmp(pair <int, int> A, pair <int, int> B) {
	return A.first < B.first;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
		books[i] = { input[i], i };
	}
	sort(books, books + N, cmp);
	for (int i = N; i >= 1; i--) {
		if (mark[i] != 0) {
			for (int j = 0; j < books[i + 1].second; j++) {
				if (mark[input[j]] == 0) {
					mark[input[j]] = 1;
					ans++;
				}
			}
			break;
		}
		if (i == N) {
			mark[input[books[i - 1].second]] = 1;
			for (int j = books[i - 1].second; j < N; j++) {
				if (mark[input[j]] == 0) {
					mark[input[j]] = 1;
					ans++;
				}
			}
		}
		else {
			mark[input[books[i - 1].second]] = 1;
			for (int j = books[i - 1].second; j < books[i].second; j++) {
				if (mark[input[j]] == 0) {
					mark[input[j]] = 1;
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}