#include <iostream>
#include <algorithm>
using namespace std;

int B, C, D, sum, discount;
int burger[1000];
int side[1000];
int soda[1000];

bool cmp(int A, int B) {
	return A > B;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> B >> C >> D;
	for (int i = 0; i < B; i++) {
		cin >> burger[i];
		sum += burger[i];
	}
	for (int i = 0; i < C; i++) {
		cin >> side[i];
		sum += side[i];
	}
	for (int i = 0; i < D; i++) {
		cin >> soda[i];
		sum += soda[i];
	}
	cout << sum << "\n";
	sort(burger, burger + B, cmp);
	sort(side, side + C, cmp);
	sort(soda, soda + D, cmp);
	int temp = min(B, C);
	temp = min(temp, D);
	for (int i = 0; i < temp; i++) discount += (burger[i] + side[i] + soda[i]);
	discount *= 0.1;
	sum -= discount;
	cout << sum;
	return 0;
}