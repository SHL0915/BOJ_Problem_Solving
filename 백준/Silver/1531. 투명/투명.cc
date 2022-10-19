#include <iostream>
#include <vector>
using namespace std;

int N, M, ans;
int drawing[100][100];

void Hide(pair <int, int> rd, pair <int, int> lu);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int xd, yd, xu, yu;
		cin >> xd >> yd >> xu >> yu;
		Hide({ xd - 1,yd - 1 }, { xu - 1,yu - 1 });
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (drawing[i][j] > M) ans++;
		}
	}
	cout << ans;
	return 0;
}

void Hide(pair <int, int> rd, pair <int, int> lu) {
	for (int i = rd.second; i <= lu.second; i++) {
		for (int j = rd.first; j <= lu.first; j++) drawing[i][j]++;
	}
	return;
}