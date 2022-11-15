#include <iostream>
#include <vector>
using namespace std;

long long N, K, Q;

long long parent(long long node);
long long absol(long long A) {
	if (A >= 0) return A;
	else return -1 * A;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K >> Q;	
	while (Q--) {
		long long x, y;
		cin >> x >> y;
		long long cnt = 0;
		if (K == 1) {
			cout << absol(x - y) << '\n';
			continue;
		}
		while (x != y) {
			if (x < y) {
				long long temp = x;
				x = y;
				y = temp;
			}
			x = parent(x);
			cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}

long long parent(long long node) {
	if (node == 1) return 1;	
	return (node - 2) / K + 1;
}