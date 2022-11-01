#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, idx, ans;
int arr[1000000];
pair<int, int> table[1000000];
pair<int, int> temp[1000000];
vector <int> result;

int UpperBound(int left, int right, int data);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++) {
		table[i] = { 1,i };
		if (idx == 0) temp[idx++] = { arr[i],i };
		else if (arr[i] > temp[idx - 1].first) {
			temp[idx++] = { arr[i],i };
			table[i] = { idx, temp[idx - 2].second };
		}
		else {
			int iter = UpperBound(0, idx, arr[i]);
			if (iter == 0) temp[iter] = { arr[i],i };
			else if (temp[iter - 1].first != arr[i]) {
				table[i] = { iter, temp[iter - 1].second };
				temp[iter] = { arr[i],i };
			}
		}		
	}
	for (int i = 0; i < N; i++) ans = max(ans, table[i].first);
	for (int i = 0; i < N; i++) {
		if (table[i].first == ans) {
			int pos = i;
			result.push_back(pos);
			while (1) {
				if (pos == table[pos].second) break;
				result.push_back(table[pos].second);
				pos = table[pos].second;
			}
			break;
		}
	}
	cout << ans << '\n';
	for (int i = result.size() - 1; i >= 0; i--) cout << arr[result[i]] << " ";
	return 0;
}

int UpperBound(int left, int right, int data) {
	int mid = (left + right) / 2;
	if (left < right) {
		if (data < temp[mid].first) return UpperBound(left, mid, data);
		else return UpperBound(mid + 1, right, data);
	}
	else return mid;
}