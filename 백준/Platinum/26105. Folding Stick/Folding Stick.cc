#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

int N, cand;
ll arr[100001];
ll psum[100001];
ll table[100001];
priority_queue <pli, vector<pli>, greater<pli>> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}
	memset(table, 0x3f, sizeof(table));
	table[0] = 0;
	for (int i = 1; i <= N; i++) {
		if (table[i - 1] >= psum[N] - psum[i - 1]) table[i] = min(table[i], table[i - 1]);
		table[i] = min(table[i], table[i - 1] + arr[i]);		
		while (pq.size()) {			
			if (pq.top().first <= psum[i]) {				
				cand = max(cand, pq.top().second);
				pq.pop();
			}
			else break;
		}
		table[i] = min(table[i], psum[i] - psum[cand]);
		pq.push({ psum[i] + table[i], i });
		//cout << table[i] << " ";
	}
	cout << table[N];
	return 0;
}