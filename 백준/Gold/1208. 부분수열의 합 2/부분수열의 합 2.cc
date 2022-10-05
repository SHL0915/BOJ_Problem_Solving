#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
long long ans;
int arr[40];
vector <long> leftSet, rightSet;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) 
		cin >> arr[i];	
	for (int i = 0; i < (1 << (N / 2)); i++) {
		int sum = 0;
		int bit = 1;
		for (int j = 0; j < N / 2; j++) {			
			if (i & bit) sum += arr[j];				
			bit <<= 1;
		}
		leftSet.push_back(sum);
	}
	for (int i = 0; i < (1 << (N - (N / 2))); i++) {
		int sum = 0;
		int bit = 1;
		for (int j = N / 2; j < N; j++) {
			if (i & bit) sum += arr[j];
			bit = bit << 1;			
		}
		rightSet.push_back(sum);
	}
	sort(rightSet.begin(), rightSet.end());
	for (int i = 0; i < leftSet.size(); i++) 	
		ans += (upper_bound(rightSet.begin(), rightSet.end(), S - leftSet[i]) - lower_bound(rightSet.begin(), rightSet.end(), S - leftSet[i]));
	if (S == 0) ans--;
	cout << ans;
	return 0;
}