#include <iostream>
#include <vector>
using namespace std;

int N, M, leaf = 1;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N - 1; i++) {
		if (i < M) 	cout << 0 << " " << leaf++ << '\n';
		else cout << leaf - 1 << " " << leaf++ << '\n';		
	}
	return 0;
}