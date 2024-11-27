#include<bits/stdc++.h>
using namespace std;

int maxWater(vector<int>& arr) {
    int res = 0;

    int n = arr.size();
    vector <int> prefix_max(n + 1, 0), suffix_max(n + 1, 0);
    prefix_max[0] = arr[0];
    suffix_max[n - 1] = arr[n - 1];
    for(int i = 1; i < n; i++) prefix_max[i] = max(prefix_max[i - 1], arr[i]);
    for(int i = n - 2; i >= 0; i--) suffix_max[i] = max(suffix_max[i + 1], arr[i]);

    for(int i = 0; i < n; i++) {
        res += min(suffix_max[i], prefix_max[i]) - arr[i];
    }

    return res;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int t = 0; t < 1; ++t) {
        int B, H;
        cin >> H >> B;

        vector<int> arr(B);
        for (int i = 0; i < B; ++i) {
            cin >> arr[i];
        }

        cout << maxWater(arr) << endl;
    }

    return 0;
}