#include <iostream>
using namespace std;

int N, L, t, pos;
int TL[100][3];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> L;
	for (int i = 0; i < N; i++) cin >> TL[i][0] >> TL[i][1] >> TL[i][2];
	for (int i = 0; i < N; i++) {
		t += (TL[i][0] - pos);
		pos = TL[i][0];
		int temp = t % (TL[i][1] + TL[i][2]);
		if (temp > TL[i][1]) continue;
		else (t += (TL[i][1] - temp));
	}
	t += (L - pos);
	cout << t;
	return 0;
}