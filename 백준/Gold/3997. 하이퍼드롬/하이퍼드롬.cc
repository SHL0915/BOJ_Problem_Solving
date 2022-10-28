#include <iostream>
#include <map>
using namespace std;

int N;
long long ans;
long long bit;
string S;
map <long long, long long> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> S;
	m[0] = 1;
	for (int i = 0; i < N; i++) {
		if (S[i] >= 'a' && S[i] <= 'z') bit ^= ((long long)1 << (S[i] - 'a'));
		else bit ^= ((long long)1 << (S[i] - 'A' + 26));
		ans += m[bit];
		for (int j = 0; j < 52; j++) {
			if(m.find((bit ^ (long long)1 << j)) != m.end()) ans += m[(bit ^ (long long)1 << j)];
		}
		m[bit]++;
	}
	cout << ans;
	return 0;
}