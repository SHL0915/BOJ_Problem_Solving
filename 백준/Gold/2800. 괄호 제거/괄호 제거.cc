#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
using namespace std;

string org;
deque <int> front_pos;
vector <pair<int, int>> complete;
vector <string> candidate;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> org;
	for (int i = 0; i < org.length(); i++) {
		if (org[i] == '(') front_pos.push_back(i);
		else if (org[i] == ')') {
			complete.push_back({ front_pos.back(), i });
			front_pos.pop_back();
		}
	}
	for (int i = 1; i < (1 << (long long)complete.size()); i++) {
		int bit = 1;
		int pos = 0;
		string temp = "";
		set <int> s;
		while (bit <= i) {
			if (bit & i) {
				s.insert(complete[pos].first);
				s.insert(complete[pos].second);
			}
			bit <<= 1;
			pos++;
		}
		for (int j = 0; j < org.size(); j++) {
			if (s.count(j) != 0) continue;
			else temp += org[j];
		}
		candidate.push_back(temp);
	}
	sort(candidate.begin(), candidate.end());
	candidate.erase(unique(candidate.begin(), candidate.end()), candidate.end());
	for (int i = 0; i < candidate.size(); i++) cout << candidate[i] << '\n';
	return 0;
}