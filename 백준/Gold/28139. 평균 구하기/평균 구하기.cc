#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[5005];

double dist(pii a, pii b);

void solve() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;

	double sum = 0;
	for(int i = 0; i < N; i++){
		for(int j = i + 1; j < N; j++) sum += dist(arr[i], arr[j]);
	}	
	
	cout << sum * (double)2 / N;

	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(12);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

double dist(pii a, pii b){
	ll dx = a.first - b.first;
	ll dy = a.second - b.second;
	return sqrt(dx * dx + dy * dy);
}