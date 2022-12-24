#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll A, B, ans;
pair<ll, int> arr[50000];
vector <pair<ll, int>> v;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> A >> B;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s >> arr[i].first;
		if (s[0] == 'S') arr[i].second = 1;
		else arr[i].second = 0;
	}
	sort(arr, arr + N);
	v.push_back(arr[0]);
	for (int i = 1; i < N; i++) {
		if (arr[i].second == arr[i - 1].second) continue;
		else {
			if ((arr[i].first + arr[i - 1].first) % 2) {
				v.push_back({ (arr[i].first + arr[i - 1].first) / 2, arr[i - 1].second });
				v.push_back({ (arr[i].first + arr[i - 1].first) / 2 + 1, arr[i].second });
			}
			else {
				if (arr[i].second == 1) {
					v.push_back({ (arr[i].first + arr[i - 1].first) / 2 - 1, 0 });
					v.push_back({ (arr[i].first + arr[i - 1].first) / 2, 1 });
				}
				else {
					v.push_back({ (arr[i].first + arr[i - 1].first) / 2 , 1 });
					v.push_back({ (arr[i].first + arr[i - 1].first) / 2 + 1, 0 });
				}
			}
		}
	}
	v.push_back(arr[N - 1]);
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first < A) continue;
		if (v[i].first > B) {
			if (v[i].second == 1) {
				if (i == 0) ans += (B - A + 1);
				else if (v[i - 1].second == 1) ans += (B - max(A, v[i - 1].first) + 1);
			}
			break;
		}
		if (v[i].second == 0) continue;
		if (i == 0) ans += (v[i].first - A);
		else if (v[i - 1].second == 1) ans += (v[i].first - max(v[i - 1].first, A) + 1);			
	}
	if (v.back().first < B && v.back().second == 1) ans += (B - v.back().first);
	cout << ans;
	return 0;
}