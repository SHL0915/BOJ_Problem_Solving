#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int ans = -500000000;
vector <pair<int, int>> acrobat;
int psum[50000];

bool cmp(pair<int, int> A, pair<int, int> B) {
	if (A.first + A.second == B.first + B.second) return A.first > B.first;
	return A.first + A.second > B.first + B.second;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int weight, strength;
		cin >> weight >> strength;
		acrobat.push_back({ weight, strength });
	}
	sort(acrobat.begin(), acrobat.end(), cmp);
	for (int i = 0; i < N; i++) {
		if (i == 0) psum[i] = acrobat[i].first;
		else psum[i] = psum[i - 1] + acrobat[i].first;
	}
	for (int i = 0; i < N; i++) ans = max(ans, psum[N - 1] - (acrobat[i].second + psum[i]));
	cout << ans;
	return 0;
}