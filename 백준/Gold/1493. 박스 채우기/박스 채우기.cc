#include <iostream>
using namespace std;

int L, W, H, cnt, flag;
int N;
int cube[20];
int power[20];

void DNC(int l, int w, int h);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> L >> W >> H;
	int temp = 1;
	for (int i = 0; i < 20; i++) {
		power[i] = temp;
		temp *= 2;
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		cube[A] = B;
	}
	DNC(L, W, H);
	if (flag == 1) cout << -1;
	else cout << cnt;
	return 0;
}

void DNC(int l, int w, int h) {
	if (l == 0 && w == 0 && h == 0) return;
	int temp = min(l, w);
	temp = min(temp, h);
	for (int i = 19; i >= 0; i--) {
		if (power[i] > temp) continue;
		if (cube[i] == 0) {
			if (i == 0) flag = 1;
			continue;
		}
		else {
			cube[i]--;
			cnt++;
			DNC(l - power[i], w, h);
			DNC(power[i], power[i], h - power[i]);
			DNC(power[i], w - power[i], h);
			return;
		}
	}
}