#include <bits/stdc++.h>
using namespace std;

int N, M, cnt;
string s[100];
string p[100];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> s[i];
	for (int i = 0; i < N; i++) cin >> p[i];
	for (int i = 0; i < M; i++) {
		int A = 0, G = 0, C = 0, T = 0, a = 0, g = 0, c = 0, t = 0;
		for (int j = 0; j < N; j++) {
			switch (s[j][i]) {
			case 'A': A = 1; break;
			case 'G': G = 1; break;
			case 'C': C = 1; break;
			case 'T': T = 1; break;
			}
			switch (p[j][i]) {
			case 'A': a = 1; break;
			case 'G': g = 1; break;
			case 'C': c = 1; break;
			case 'T': t = 1; break;
			}
		}
		A += a;
		G += g;
		C += c;
		T += t;
		if (max({ A,G,C,T }) <= 1) cnt++;
	}
	cout << cnt;
	return 0;
}