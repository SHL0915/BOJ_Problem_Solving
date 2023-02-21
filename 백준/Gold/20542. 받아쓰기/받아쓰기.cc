#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int N, M;
string s1, s2, S1, S2;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	cin >> S1 >> S2;

	vector<vector<int>>lcs(N + 1, vector<int>(M + 1, 0));

	s1 = "1" + S1; s2 = "2" + S2;
	int l1 = s1.length(); int l2 = s2.length();
	for (int i = 0; i < l1; i++) {
		lcs[i][0] = i;
	}
	for (int i = 0; i < l2; i++) {
		lcs[0][i] = i;
	}
	for (int i = 1; i < l1; i++) {
		for (int j = 1; j < l2; j++) {
			char a = s1[i]; char b = s2[j];
			if (a == 'i' && b == 'j' || a == 'i' && b == 'l' || a == 'v' && b == 'w') {
				lcs[i][j] = lcs[i - 1][j - 1];
			}
			else if (a == b) {
				lcs[i][j] = lcs[i - 1][j - 1];
			}
			else {
				lcs[i][j] = min(lcs[i][j - 1], lcs[i - 1][j]) + 1;
				lcs[i][j] = min(lcs[i][j], lcs[i - 1][j - 1] + 1);
			}
		}
	}
	cout << lcs[l1 - 1][l2 - 1] << '\n';
	return 0;
}