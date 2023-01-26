#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int coins[100];
int memo[10001];

int main(void) {
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
		cin >> coins[i];
	sort(coins, coins + n);	
	memo[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (coins[i] > j)
				continue;			
			else
				memo[j] += memo[j - coins[i]];							
		}
	}	
	cout << memo[k];
	return 0;
}