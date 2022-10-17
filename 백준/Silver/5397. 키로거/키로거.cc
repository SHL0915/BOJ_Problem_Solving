#include <iostream>
#include <queue>
using namespace std;

int T;
deque <char> leftWord;
deque <char> rightWord;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		leftWord.clear();
		rightWord.clear();
		string TC;
		cin >> TC;
		for (int j = 0; j < TC.length(); j++) {
			if (TC[j] == '<') {
				if (leftWord.size()) {
					rightWord.push_front(leftWord.back());
					leftWord.pop_back();
				}
			}
			else if (TC[j] == '>') {
				if (rightWord.size()) {
					leftWord.push_back(rightWord.front());
					rightWord.pop_front();
				}
			}
			else if (TC[j] == '-') {
				if (leftWord.size()) leftWord.pop_back();				
			}
			else leftWord.push_back(TC[j]);			
		}
		for (int j = 0; j < leftWord.size(); j++) cout << leftWord[j];
		for (int j = 0; j < rightWord.size(); j++) cout << rightWord[j];
		cout << "\n";
	}
	return 0;
}