#include <iostream>
#include <set>
using namespace std;

int N, ans;
string chat;
set <string> names;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> chat;
		if (chat == "ENTER") names.clear();
		else if (names.find(chat) == names.end()) {
			names.insert(chat);
			ans++;
		}
	}
	cout << ans;
	return 0;
}