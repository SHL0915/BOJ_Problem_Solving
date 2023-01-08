#include <bits/stdc++.h>
using namespace std;

string S, cmp;
int idx;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	getline(cin, S);
	cmp = "UCPC";
	for (int i = 0; i < S.length(); i++) {
		if (idx == 4) break;
		if (S[i] == cmp[idx]) idx++;
	}
	if (idx == 4) cout << "I love UCPC";
	else cout << "I hate UCPC";
	return 0;
}