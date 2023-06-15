#include "routers.h"
using namespace std;

vector<int> find_routers(int l, int n, int q) {
	vector<int> ans;
	ans.push_back(0);
	for (int i = 1; i < n; i++) {
		int left = ans[i - 1], right = l;
		int find = 0;
		while (left <= right) {
			int mid = (left + right) / 2;
			int res = use_detector(mid);
			if (res != i - 1) {
				right = mid - 1;
				find = mid;
			}
			else left = mid + 1;
		}
		ans.push_back(ans[i - 1] + (find - ans[i - 1] - 1) * 2);
	}
	return ans;
}