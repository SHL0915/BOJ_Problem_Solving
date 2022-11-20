#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1234567890;

int N;
string S;
int cnt[26];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> S;
	for (int i = 0; i < S.length(); i++) cnt[S[i] - 'A']++;
	int ans = INF;
	ans = min(ans, cnt['H' - 'A']);
	ans = min(ans, cnt['I' - 'A']);
	ans = min(ans, cnt['A' - 'A']);
	ans = min(ans, cnt['R' - 'A']);
	ans = min(ans, cnt['C' - 'A']);
	cout << ans;
	return 0;
}