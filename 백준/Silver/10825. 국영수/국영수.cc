#include <bits/stdc++.h>
using namespace std;

int N;
int A[100001], B[100001], C[100001], key[100001];
string name[100001];

bool cmp(int a, int b) {
	if (A[a] == A[b]) {
		if (B[a] == B[b]) {
			if (C[a] == C[b]) return name[a] < name[b];
			return C[a] > C[b];
		}
		return B[a] < B[b];
	}
	return A[a] > A[b];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name[i] >> A[i] >> B[i] >> C[i];
		key[i] = i;
	}
	sort(key, key + N, cmp);
	for (int i = 0; i < N; i++) cout << name[key[i]] << '\n';
	return 0;
}