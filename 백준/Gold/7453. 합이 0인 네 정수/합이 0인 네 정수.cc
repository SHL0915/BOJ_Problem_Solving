#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <cmath>

#define INF 100000

using namespace std;
int n;
vector<long long> sum[2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //------input-------
    long long read;
    long long ans = 0;

    cin >> n;

    vector<long long> arr[4];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> read;
            arr[j].push_back(read);
        }
    }
    //------logic-------
    // 4개의 배열 -> 2개의 배열로 합치기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum[0].push_back(arr[0][i] + arr[1][j]);
        }
    }

    sort(sum[0].begin(), sum[0].end());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum[1].push_back(arr[2][i] + arr[3][j]);
        }
    }
    sort(sum[1].begin(), sum[1].end());

    // 투포인터로 SUM을 0 으로 만드는 모든 조합 탐색
    int j = n * n - 1;

    for(int i = 0; i < n * n;) {
        if(j < 0) break;
        long long add = sum[0][i] + sum[1][j];

        if (add == 0) {
            long long upper_cnt = 0;
            long long downer_cnt = 0;
            long long a = sum[0][i];
            long long b = sum[1][j];
            for (; i < n * n; i++) {
                if (a == sum[0][i]) upper_cnt++;
                else break;
            }
            for (; j >= 0; j--) {
                if (b == sum[1][j]) downer_cnt++;
                else break;
            }
            ans += upper_cnt * downer_cnt;
        } else if (add > 0) j--;
        else i++;

    }

    cout << ans;
    return 0;
}