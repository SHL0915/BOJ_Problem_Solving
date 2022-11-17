#include <iostream>
using namespace std;

int N;
long long table[30];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	table[0] = 0;
	table[1] = 3;
	for (int i = 2; ; i++) {
		table[i] = table[i - 1] * 2 + (i + 2);
		if (table[i] >= N) 	break;		
	}
	while (1) {
		int pos;
		for (pos = 0; ; pos++) {
			if (table[pos] > N) {
				pos--;
				break;
			}
		}
		N -= table[pos];
		if (N <= pos + 3) {
			if (N == 1) cout << 'm';
			else cout << 'o';
			break;
		}
		else N -= (pos + 3);
	}
	return 0;
}