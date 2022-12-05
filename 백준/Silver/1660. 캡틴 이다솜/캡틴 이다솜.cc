#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

long long N;
vector <long long> arr;
vector <long long> temp;
long long table[300001];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	arr.push_back(0);
	temp.push_back(0);
	for (int i = 1; ; i++) {
		temp.push_back(temp.back() + i);
		arr.push_back(arr.back() + temp.back());
		if (arr.back() > N) break;
	}
	memset(table, INF, sizeof(table));
	table[0] = 0;
	for (int i = 1; i < arr.size(); i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i] > j) continue;
			table[j] = min(table[j], table[j - arr[i]] + 1);
		}
	}
	cout << table[N];
	return 0;
}