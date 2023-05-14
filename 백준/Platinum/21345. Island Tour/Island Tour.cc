#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
int AB[405][405], BC[405][405], CA[405][405];
ll dist[405], A[405], B[405], C[405];
pii temp1[405], temp2[405];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> dist[i];
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	for (int i = 0; i < N; i++) cin >> C[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
			ll timeA = 0, timeB = 0;
			for (int k = 0; k < N; k++) {
				temp1[(i + k) % N].first = timeA;
				temp2[(j + k) % N].first = timeB;

				timeA += A[(i + k) % N];
				timeB += B[(j + k) % N];

				temp1[(i + k) % N].second = timeA;
				temp2[(j + k) % N].second = timeB;

				timeA += dist[(i + k) % N];
				timeB += dist[(j + k) % N];
			}

			int flag = 0;
			for (int k = 0; k < N; k++) {
				ll aa, bb, cc, dd;
				aa = temp1[k].first;
				bb = temp1[k].second;
				cc = temp2[k].first;
				dd = temp2[k].second;

				if (aa > cc) {
					swap(aa, cc);
					swap(bb, dd);
				}

				if (bb > cc) flag = 1;
			}

			if (flag == 0) AB[i][j] = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			ll timeA = 0, timeB = 0;
			for (int k = 0; k < N; k++) {
				temp1[(i + k) % N].first = timeA;
				temp2[(j + k) % N].first = timeB;

				timeA += B[(i + k) % N];
				timeB += C[(j + k) % N];

				temp1[(i + k) % N].second = timeA;
				temp2[(j + k) % N].second = timeB;

				timeA += dist[(i + k) % N];
				timeB += dist[(j + k) % N];
			}

			int flag = 0;
			for (int k = 0; k < N; k++) {
				ll aa, bb, cc, dd;
				aa = temp1[k].first;
				bb = temp1[k].second;
				cc = temp2[k].first;
				dd = temp2[k].second;

				if (aa > cc) {
					swap(aa, cc);
					swap(bb, dd);
				}

				if (bb > cc) flag = 1;
			}

			if (flag == 0) BC[i][j] = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			ll timeA = 0, timeB = 0;
			for (int k = 0; k < N; k++) {
				temp1[(i + k) % N].first = timeA;
				temp2[(j + k) % N].first = timeB;

				timeA += C[(i + k) % N];
				timeB += A[(j + k) % N];

				temp1[(i + k) % N].second = timeA;
				temp2[(j + k) % N].second = timeB;

				timeA += dist[(i + k) % N];
				timeB += dist[(j + k) % N];
			}

			int flag = 0;
			for (int k = 0; k < N; k++) {
				ll aa, bb, cc, dd;
				aa = temp1[k].first;
				bb = temp1[k].second;
				cc = temp2[k].first;
				dd = temp2[k].second;

				if (aa > cc) {
					swap(aa, cc);
					swap(bb, dd);
				}

				if (bb > cc) flag = 1;
			}

			if (flag == 0) CA[i][j] = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (AB[i][j] == 0) continue;

			for (int k = 0; k < N; k++) {
				if (k == i || k == j) continue;
				if (CA[k][i] == 1 && BC[j][k] == 1) {
					cout << i + 1 << " " << j + 1 << " " << k + 1;
					return;
				}
			}
		}
	}

	cout << "impossible";

	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}