#include <iostream>
#include <queue>
using namespace std;

int N;
queue <int> buffer;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (1) {
		int input;
		cin >> input;
		if (input == -1) break;
		if (input == 0) buffer.pop();
		else if (buffer.size() < N) buffer.push(input);
	}
	if (buffer.size() == 0) cout << "empty";
	while (buffer.size()) {
		cout << buffer.front() << ' ';
		buffer.pop();
	}
	return 0;
}