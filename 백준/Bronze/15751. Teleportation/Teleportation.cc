#include <bits/stdc++.h>
using namespace std;

int absol(int A);
int cal(int A, int B, int C, int D);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, x, y;
	cin >> a >> b >> x >> y;
	int ans = absol(a - b);
	ans = min({ ans, cal(a,x,y,b), cal(a,y,x,b) });
	cout << ans;
	return 0;
}

int absol(int A) {
	if (A < 0) return -A;
	else return A;
}

int cal(int A, int B, int C, int D) {
	return absol(A - B) + absol(C - D);
}