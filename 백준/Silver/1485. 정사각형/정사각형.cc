#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
pair <long long, long long> dots[4];
vector <long long> v;

long long cal(pair <long long, long long> A, pair <long long, long long> B) {
	return (A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second);
}

bool cmp(pair <long long, long long> A, pair <long long, long long> B) {
	return A.first < B.first;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		v.clear();
		for (int j = 0; j < 4; j++) {
			int x, y;
			cin >> x >> y;
			dots[j] = { x,y };
		}	
		sort(dots, dots + 4, cmp);
		v.push_back(cal(dots[0], dots[1]));
		v.push_back(cal(dots[0], dots[2]));
		v.push_back(cal(dots[0], dots[3]));
		v.push_back(cal(dots[1], dots[2]));
		v.push_back(cal(dots[1], dots[3]));
		v.push_back(cal(dots[2], dots[3]));
		sort(v.begin(), v.end());
		int flag = 0;
		for (int j = 0; j < 4; j++) if (v[j] != v[0]) flag = 1;
		if (v[4] != v[5]) flag = 1;
		if (flag == 0) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}