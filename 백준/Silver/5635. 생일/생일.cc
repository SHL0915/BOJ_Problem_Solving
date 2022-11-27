#include <bits/stdc++.h>
using namespace std;

int N;
string name[100];
int day[100];
int month[100];
int year[100];
pair<int, int> num[100];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name[i] >> day[i] >> month[i] >> year[i];
		num[i] = { year[i] * 100 + month[i] * 10 + day[i],i };
	}
	sort(num, num + N);
	cout << name[num[N - 1].second] << '\n' << name[num[0].second];
	return 0;
}