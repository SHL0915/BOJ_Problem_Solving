#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1234567890;

int N, ans = INF;
vector <pair<int, int>> arr;

int DNC(int left, int right);
int sqrDis(pair<int, int> A, pair<int, int> B) {
	return (A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		arr.push_back({ x,y });
	}
	sort(arr.begin(), arr.end());
	ans = min(ans, DNC(0, N - 1));
	cout << ans;
	return 0;
}

int DNC(int left, int right) {
	int mid = (left + right) / 2;
	if (left == right) return INF;
	if (right - left == 1) return sqrDis(arr[left], arr[right]);
	else {
		int A = min(DNC(left, mid), DNC(mid + 1, right));
		vector <pair<int, int>> temp;
		for (int i = left; i <= right; i++) {
			if ((arr[mid].first - arr[i].first) * (arr[mid].first - arr[i].first) < A) temp.push_back({arr[i].second, arr[i].first});
		}
		if (temp.size() == 0) return A;
		sort(temp.begin(), temp.end());
		for (int i = 0; i < temp.size(); i++) {
			for (int j = i + 1; j < temp.size(); j++) {
				int d = (temp[i].first - temp[j].first) * (temp[i].first - temp[j].first);
				if (d > A) break;
				int d2 = (temp[i].second - temp[j].second) * (temp[i].second - temp[j].second);
				if (d2 > A) continue;
				else {
					int dist = sqrDis(temp[i], temp[j]);
					A = min(A, dist);
				}
			}
		}
		return A;
	}
}