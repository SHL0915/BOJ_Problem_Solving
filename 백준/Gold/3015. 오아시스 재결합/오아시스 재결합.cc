#include <iostream>
#include <stack>
using namespace std;

long long N, height, cnt = 0, temp;
stack <pair<long long, long long>> s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> height;
		if (s.size() == 0) {
			s.push({ height,1 });
			continue;
		}
		if (height < s.top().first) {
			cnt ++;
			s.push({ height,1 });
		}
		else if (height == s.top().first) {
			cnt += s.top().second;
			temp = s.top().second + 1;
			s.pop();
			if (s.size())
				cnt ++;
			s.push({ height, temp });
		}
		else {
			while (s.size() && height > s.top().first) {
				cnt += s.top().second;
				s.pop();
			}
			if (s.size() == 0) {
				s.push({ height,1 });
				continue;
			}
			if (height == s.top().first) {
				cnt += s.top().second;
				temp = s.top().second + 1;
				s.pop();
				if (s.size())
					cnt ++;
				s.push({ height, temp });
			}
			else {
				cnt ++;
				s.push({ height,1 });
			}
		}
	}
	cout << cnt;
	return 0;
}