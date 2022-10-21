#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, newScore, P;
vector <int> score;
vector <int> board;

bool cmp(int A, int B) {
	return A > B;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> newScore >> P;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		score.push_back(input);
		board.push_back(input);
	}
	score.push_back(newScore);
	if (N == 0) {
		cout << 1;
		return 0;
	}
	if (N == P && board.back() >= newScore) {
		cout << -1;
		return 0;
	}
	sort(score.begin(), score.end(), cmp);
	for (int i = 0; i < P; i++) {
		if (score[i] == newScore) {
			
			cout << i + 1;
			exit(0);
		}
	}
	return 0;
}