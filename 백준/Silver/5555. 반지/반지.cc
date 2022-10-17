#include <iostream>
using namespace std;

int N, ans;
string wantToFind;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> wantToFind;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int flag = 1;
		string ring;
		cin >> ring;
		for (int j = 0; j < 10; j++) {
			if (ring[j] == wantToFind[0]) {
				flag = 0;
				for (int k = 0; k < wantToFind.length(); k++) {
					if (ring[((j + k) % 10)] != wantToFind[k]) {
						flag = 1;
						break;
					}
				}
				if (flag == 0) break;			
			}			
		}
		if (flag == 0) ans++;
	}
	cout << ans;
	return 0;
}