#include <iostream>
#include <vector>
using namespace std;

int k, sum, ans;
int valid[4000000];
int weight[13];
int mark[13];
vector <int> mnum;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> weight[i];
		sum += weight[i];
	}
	for (int i = 0; i < (1 << k); i++) {
		mnum.clear();
		int sum = 0;
		int bit = 1;
		for (int j = 0; j < k; j++) {
			if (i & bit) {
				mark[j] = 1;
				sum += weight[j];
			}
			else {
				mark[j] = 0;
				mnum.push_back(j);
			}
			bit <<= 1;
		}
		valid[sum] = 1;	
		for (int j = 0; j < (1 << mnum.size()); j++) {
			int msum = 0;
			bit = 1;
			for (int l = 0; l < mnum.size(); l++) {
				if (j & bit) msum += weight[mnum[l]];				
				bit <<= 1;
			}
			if (sum > msum) valid[sum - msum] = 1;
		}

	}
	for (int i = 1; i <= sum; i++) if (valid[i] == 0) ans++;
	cout << ans;
	return 0;
}