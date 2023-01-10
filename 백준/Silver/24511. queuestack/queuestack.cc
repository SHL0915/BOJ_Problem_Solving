#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[100001], B[100001], C[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];	
	for (int i = 0; i < N; i++) cin >> B[i];
	cin >> M;
	for (int i = 0; i < M; i++) cin >> C[i];
	int pos = N - 1, cnt = 0;
	while (M--) {
		int flag = 0;
		if (pos >= 0) {
			for (pos; pos >= 0; pos--) {
				if (A[pos] == 0) {
					cout << B[pos--] << ' ';
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0) cout << C[cnt++] << ' ';
	}
	return 0;
}