#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int dairy[100000];

bool cmp(int A, int B) {
	return A > B;
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> dairy[i];
	sort(dairy, dairy + N, cmp);
	for (int i = 0; i < N; i++) if (i % 3 == 0 || i % 3 == 1) ans += dairy[i];
	cout << ans;
	return 0;
}