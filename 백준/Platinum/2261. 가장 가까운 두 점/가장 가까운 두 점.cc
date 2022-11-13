#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1234567890;

int N;
vector <pair<int, int>> arr;

bool cmp(pair<int, int> A, pair<int, int> B) {
	return A.first < B.first;
}

int DNC(int left, int right);
int sqrDis(int A, int B) {
	return (arr[A].first - arr[B].first) * (arr[A].first - arr[B].first) + (arr[A].second - arr[B].second) * (arr[A].second - arr[B].second);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		arr[i] = { x,y };
	}
	sort(arr.begin(), arr.end(), cmp);
	cout << DNC(0, N - 1);
	return 0;
}

int DNC(int left, int right) {
	int mid = (left + right) / 2;
	if (right - left == 2) {
		int A = min(sqrDis(left, left + 1), sqrDis(left + 1, right));
		A = min(A, sqrDis(left, right));
		return A;	
	}
	if (right - left == 1) return sqrDis(left, right);
	if (right == left) return INF;
	else {
		int A = min(DNC(left, mid), DNC(mid + 1, right));
		vector <pair<int, int>> temp;
		int line = (arr[mid].first + arr[mid + 1].first) / 2;
		for (int i = left; i <= right; i++) {
			if ((line - arr[i].first) * (line - arr[i].first) < A) temp.push_back({ arr[i].second, arr[i].first });
		}
		sort(temp.begin(), temp.end(), cmp);
		for (int i = 0; i < temp.size(); i++) {
			for (int j = i + 1; j < temp.size(); j++) {
				int diffX = temp[i].second - temp[j].second;
				int diffY = temp[i].first - temp[j].first;
				if (diffY * diffY >= A) break;
				A = min(A, diffX * diffX + diffY * diffY);
			}
		}
		return A;
	}
}