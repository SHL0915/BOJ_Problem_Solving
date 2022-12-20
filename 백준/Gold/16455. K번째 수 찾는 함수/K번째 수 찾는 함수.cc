#include <bits/stdc++.h>
using namespace std;

int kth(vector<int> &a, int k) {
	nth_element(a.begin(), a.begin() + k - 1, a.end());
	return a[k - 1];
}