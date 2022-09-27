#include <iostream>
using namespace std;

int N, K, ans = -1;
string words[50];
int chosen[26];

void FindWordNum(int k, int start);

int main(void) {
	cin >> N >> K;
	chosen['z' - 'a'] = 1; // a
	chosen['z' - 'c'] = 1; // c
	chosen['z' - 'i'] = 1; // i
	chosen['z' - 'n'] = 1; // n
	chosen['z' - 't'] = 1; // t
	for (int i = 0; i < N; i++) 
		cin >> words[i];
	if (K < 5) {
		cout << 0;
		return 0;
	}
	FindWordNum(0, 0);
	cout << ans;
	return 0;
}

void FindWordNum(int k, int start) {
	int i, j;
	if (k == K - 5) {
		int cnt = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < words[i].length(); j++) {
				if (chosen['z' - words[i][j]] == 0)
					break;
			}
			if (j == words[i].length())
				cnt++;
		}
		ans = max(ans, cnt);
	}
	else {
		for (i = start; i < 26; i++) {
			if (chosen[i] == 1)
				continue;
			else {
				chosen[i] = 1;
				FindWordNum(k + 1, i + 1);
				chosen[i] = 0;
			}
		}
	}
}