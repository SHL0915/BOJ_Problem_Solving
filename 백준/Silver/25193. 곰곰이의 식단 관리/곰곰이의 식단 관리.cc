#include <iostream>
using namespace std;

int N, cnt;
string input;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> input;
	for (int i = 0; i < N; i++) if (input[i] != 'C') cnt++;
	if ((N - cnt) % (cnt + 1) == 0) cout << (N - cnt) / (cnt + 1);
	else cout << (N - cnt) / (cnt + 1) + 1;
	return 0;
}