#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int N, K, P;
vector <int> graph[300005], rev[300005];
int A_degree[300005], B_degree[300005];
int A[300005], B[300005];
ll pow_N[300005];

void ATopology();
void BTopology();

void solve() {
	cin >> N >> K >> P;

	for (int i = 0; i < P; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		rev[b].push_back(a);
		A_degree[a]++; B_degree[b]++;
	}

	ATopology();
	BTopology();

	//for (int i = 0; i < K; i++) cout << A[i] << " ";
	//cout << endl;
	//for (int i = 0; i < K; i++) cout << B[i] << " ";
	//cout << endl;

	pow_N[0] = 1;
	for (int i = 1; i < K; i++) pow_N[i] = (pow_N[i - 1] * N) % mod;

	ll sumA = 0;
	for (int i = 0; i < K; i++) sumA = (sumA + (pow_N[i] * A[i]) % mod) % mod;
	ll sumB = 0;
	for (int i = 0; i < K; i++) sumB = (sumB + (pow_N[i] * B[i]) % mod) % mod;

	sumA -= sumB;
	if (sumA < 0) sumA += mod;


	cout << sumA;
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

void ATopology() {
	priority_queue <int, vector<int>, greater<>> pq;
	for (int i = 0; i < K; i++) if (A_degree[i] == 0) pq.push(i);

	int cnt = N - K;

	for (int i = 0; i < K; i++) {
		int now = pq.top(); pq.pop();
		A[now] = cnt++;

		for (int next : rev[now]) {
			if (--A_degree[next] == 0) pq.push(next);
		}
	}

	return;
}

void BTopology() {
	priority_queue <int, vector<int>, greater<>> pq;
	for (int i = 0; i < K; i++) if (B_degree[i] == 0) pq.push(i);

	int cnt = K - 1;

	for (int i = 0; i < K; i++) {
		int now = pq.top(); pq.pop();
		B[now] = cnt--;

		for (int next : graph[now]) {
			if (--B_degree[next] == 0) pq.push(next);
		}
	}

	return;
}