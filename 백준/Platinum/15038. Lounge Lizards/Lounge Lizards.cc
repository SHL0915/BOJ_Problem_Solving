#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> piii;

int X, Y, N, cnt;
piii arr[1000000];
map <pair<int, int>, vector <pair<int, int>>> m;

void put(int x, int y, int h);
int GCD(int A, int B);
int absol(int A);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> X >> Y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, h;
		cin >> x >> y >> h;
		put(x - X, y - Y, h);
	}
	for (auto i = m.begin(); i != m.end(); i++) {
		vector <pair<int, int>>& v = (*i).second;
		sort(v.begin(), v.end());
		vector <int> ans;
		for (int j = 0; j < v.size(); j++) {
			if (ans.size() == 0 || v[j].second > ans.back()) ans.push_back(v[j].second);
			else {
				int idx = lower_bound(ans.begin(), ans.end(), v[j].second) - ans.begin();
				ans[idx] = v[j].second;
			}
		}
		cnt += ans.size();
	}
	cout << cnt;
	return 0;
}

void put(int x, int y, int h) {
	if (x == 0) {
		int nx = 0, ny = 1;
		if (y < 0) ny = -1;
		m[{nx, ny}].push_back({ y / ny, h });
	}
	else if (y == 0) {
		int nx = 1, ny = 0;
		if (x < 0) nx = -1;
		m[{nx, ny}].push_back({ x / nx, h });
	}
	else {
		int gcd = GCD(absol(x), absol(y));
		int nx = x / gcd;
		int ny = y / gcd;		
		m[{nx, ny}].push_back({ gcd, h });
	}
	return;
}

int GCD(int A, int B) {
	if (A > B) {
		if (A % B == 0) return B;
		else return GCD(A % B, B);
	}
	else {
		if (B % A == 0) return A;
		else return GCD(B % A, A);
	}
}

int absol(int A) {
	if (A < 0) return -A;
	else return A;
}