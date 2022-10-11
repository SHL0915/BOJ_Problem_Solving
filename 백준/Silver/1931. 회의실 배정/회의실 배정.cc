#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans, ptr;
vector <pair <int, int>> meeting;

bool cmp(pair <int, int> A, pair <int, int> B) {
	if (A.second == B.second) return A.first < B.first;
	else return A.second < B.second;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		meeting.push_back({ start, end });
	}
	sort(meeting.begin(), meeting.end(), cmp);
	for (int i = 0; i < N; i++) {
		if (meeting[i].first >= ptr) {
			ptr = meeting[i].second;
			ans++;
		}
	}
	cout << ans;
	return 0;
}