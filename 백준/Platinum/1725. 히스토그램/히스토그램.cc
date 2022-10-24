#include <iostream>
#include <vector>
using namespace std;

int N;
long long input, ans;
vector <pair<long long, long long>> s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;	
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (s.size() == 0) s.push_back({ input, i });
		else if (input > s.back().first) s.push_back({ input, i });
		else if (input == s.back().first) continue;
		else {
			while (1) {
				pair <long long, long long> temp = s.back();
				ans = max(ans, temp.first * (i - temp.second));
				s.pop_back();
				if (s.size() == 0) {
					s.push_back({ input,0 });
					break;
				}
				if (input > s.back().first) {
					s.push_back({ input, temp.second });
					break;
				}
				else if (input == s.back().first) break;				
			}
		}
	}
	while (s.size()) {
		pair <long long, long long> temp = s.back();
		s.pop_back();
		ans = max(ans, temp.first * (N - temp.second));
	}
	cout << ans << '\n';
	return 0;
}