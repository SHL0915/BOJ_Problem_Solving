#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

pii arr[3];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
		sum += arr[i].first;
	}
	sort(arr, arr + 3);
	if (sum >= 100) cout << "OK";
	else {
		if (arr[0].second == 0) cout << "Soongsil";
		else if (arr[0].second == 1) cout << "Korea";
		else cout << "Hanyang";
	}
	return 0;
}