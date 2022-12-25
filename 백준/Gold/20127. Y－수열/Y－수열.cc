#include <bits/stdc++.h>
using namespace std;

int N, now, cnt1, cnt2;
int arr[1000000];
bool check1, check2, cant1, cant2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	now = arr[0];
	for (int i = 0; i < N; i++) {
		if (now > arr[i]) {
			if (!check1) {
				check1 = true;
			}
			else cant1 = true;
		}
		else if (now < arr[i]) {
			if (!check2) {
				check2 = true;
			}
			else cant2 = true;
		}
		if (now <= arr[i] && !check1) cnt1++;		
		if (now >= arr[i] && !check2) cnt2++;		
		now = arr[i];
	}
	if (arr[0] > arr[N - 1])cant2 = true;
	if (arr[0] < arr[N - 1])cant1 = true;
	if (cnt1 == N || cnt2 == N) cout << 0;	
	else {
		if (cant1 && cant2) cout << -1;		
		else if (!cant1 && !cant2) cout << min(cnt1, cnt2);
		else if (cant1) cout << cnt2;		
		else if (cant2) cout << cnt1;		
	}

}