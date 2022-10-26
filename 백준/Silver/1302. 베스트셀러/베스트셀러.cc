#include <iostream>
#include <set>
using namespace std;

int N, max_num;
multiset <string> books;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		books.insert(input);
	}
	for (auto i = books.begin(); i != books.end(); i++) max_num = max(max_num, (int)books.count(*i));
	for (auto i = books.begin(); i != books.end(); i++) {
		if (books.count(*i) == max_num) {
			cout << *i;
			return 0;
		}
	}
	return 0;
}