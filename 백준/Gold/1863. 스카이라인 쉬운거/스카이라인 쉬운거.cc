#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	stack <int> S;
	int n, cnt = 0;
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {		
		cin >> x >> y;
		if (y == 0) {
			while (S.size() != 0) {
				S.pop();
				cnt++;
			}
		}
		else if (S.size() == 0)
			S.push(y);
		else if (S.top() < y)
			S.push(y);
		else if (S.top() == y)
			continue;
		else {			
			while (1) {
				if (S.size() == 0) {
					S.push(y);
					break;
				}
				if (S.top() > y) {
					S.pop();
					cnt++;
				}
				else if (S.top() == y)
					break;
				else {
					S.push(y);
					break;
				}
			}
		}
	}
	while (S.size() != 0) {
		S.pop();
		cnt++;
	}
	cout << cnt;
	return 0;
}