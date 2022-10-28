#include <iostream>
using namespace std;

int N, Q;
int tempo[1000];
int delta[1000];
int psum[1000];

int absolute(int A) {
	if (A >= 0) return A;
	else return A * (-1);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 0; i < N; i++) cin >> tempo[i];
	for (int i = 1; i < N; i++) {
		delta[i] = absolute(tempo[i] - tempo[i - 1]);
		psum[i] = psum[i - 1] + delta[i];
	}
	while (Q--) {
		int s_pos, e_pos;
		cin >> s_pos >> e_pos;
		cout << psum[e_pos - 1] - psum[s_pos - 1] << '\n';
	}
	return 0;
}