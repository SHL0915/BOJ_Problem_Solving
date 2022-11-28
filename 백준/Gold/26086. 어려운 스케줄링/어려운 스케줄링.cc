#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> piii;

int N, Q, k, state;
deque <int> arr;
piii sorted_area;

bool cmp(int A, int B) {
	return A > B;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> Q >> k;
	for (int i = 0; i < Q; i++) {
		int A, B;
		cin >> A;
		if (A == 0) {
			cin >> B;
			if (state == 0) arr.push_back(B);
			else {
				arr.push_front(B);
				sorted_area.first.first++;
				sorted_area.first.second++;
			}
		}
		else if (A == 1) sorted_area = { {0, arr.size() - 1}, state };
		else state ^= 1;
	}
	if (sorted_area.second == 0) sort(arr.begin() + sorted_area.first.first, arr.begin() + sorted_area.first.second + 1, cmp);
	else sort(arr.begin() + sorted_area.first.first, arr.begin() + sorted_area.first.second + 1);
	if (state == 0) cout << arr[arr.size() - k];
	else cout << arr[k - 1];
	return 0;
}