#include <iostream>
using namespace std;

int N, ans = -1;
double Building[50];

void findBuilding(int n);

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Building[i];
	for (int i = 0; i < N; i++) 
		findBuilding(i);
	cout << ans;
	return 0;
}

void findBuilding(int n) {
	int i, j;
	int cnt = 0;
	for (i = 0; i < N; i++) {
		if (i < n) {
			for (j = i + 1; j < n; j++) {
				if (((Building[n] - Building[i]) / (n - i)) * (j - i) + Building[i] <= Building[j])
					break;
			}
			if (j == n)
				cnt++;
		}
		else if (i == n)
			continue;
		else {
			for (j = n + 1; j < i; j++) {
				if ((Building[i] - Building[n]) / (i - n) * (j - n) + Building[n] <= Building[j])
					break;
			}
			if (j == i)
				cnt++;
		}
	}	
	ans = max(ans, cnt);
	return;
}
