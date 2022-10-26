#include <iostream>
#include <vector>
using namespace std;

int T;
int N;
vector <int> N_B;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		int ans = 0;
		for (int i = 2; i <= 64; i++) {
			N_B.clear();
			int temp = N;
			int divider = i;
			while (temp) {
				N_B.push_back(temp % divider);
				temp -= (temp % divider);
				temp /= divider;
			}
			int lptr = 0;
			int rptr = N_B.size() - 1;
			while (lptr <= rptr) {
				if (N_B[lptr] != N_B[rptr]) break;
				lptr++;
				rptr--;
			}
			if (lptr > rptr) {
				ans = 1;
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}