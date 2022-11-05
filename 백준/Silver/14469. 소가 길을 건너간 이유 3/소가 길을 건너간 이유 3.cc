#include <iostream>
#include <algorithm>
using namespace std;

int N, now;
pair <int, int> cow[100];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int arrive, time;
		cin >> arrive >> time;
		cow[i] = { arrive, time };
	}
	sort(cow, cow + N);
	for (int i = 0; i < N; i++) {
		if (cow[i].first > now) now = cow[i].first + cow[i].second;
		else now += cow[i].second;
	}
	cout << now;
	return 0;
}