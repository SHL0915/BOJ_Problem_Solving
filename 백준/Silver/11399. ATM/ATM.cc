#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int people[1001];

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> people[i];
	sort(people, people + N + 1);
	for (int i = 1; i <= N; i++) {
		people[i] += people[i - 1];
		ans += people[i];
	}
	cout << ans;
	return 0;
}