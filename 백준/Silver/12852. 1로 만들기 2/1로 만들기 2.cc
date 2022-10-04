#include <iostream>
#include <vector>
using namespace std;

int N;
pair <int, int> memo[1000001];

int main(void) {
	cin >> N;
	memo[2] = { 1,1 };
	memo[3] = { 1,1 };
	for (int i = 4; i <= N; i++) {
		if (i % 3 == 0 && i % 2 == 0) {
			int branch, temp;
			if (memo[i / 3].first <= memo[i / 2].first) {
				temp = memo[i / 3].first;
				branch = 0;
			}
			else {
				temp = memo[i / 2].first;
				branch = 1;
			}
			if (memo[i - 1].first <= temp) {
				temp = memo[i - 1].first;
				branch = 2;
			}
			switch (branch) {
			case 0: memo[i] = { temp + 1, i / 3 };
				  break;
			case 1: memo[i] = { temp + 1, i / 2 };
				  break;
			case 2: memo[i] = { temp + 1, i - 1 };
				  break;
			}
		}
		else if (i % 3 == 0) {
			if (memo[i / 3].first <= memo[i - 1].first)
				memo[i] = { memo[i / 3].first + 1, i / 3 };
			else
				memo[i] = { memo[i - 1].first + 1, i - 1 };
		}
		else if (i % 2 == 0) {
			if (memo[i / 2].first <= memo[i - 1].first) 
				memo[i] = { memo[i / 2].first + 1, i / 2 };
			else
				memo[i] = { memo[i - 1].first + 1, i - 1 };
		}
		else 
			memo[i] = { memo[i - 1].first + 1, i - 1 };		
	}
	cout << memo[N].first << "\n";
	int temp = N;
	while (temp != 0) {
		cout << temp << " ";
		temp = memo[temp].second;
	}
	return 0;
}