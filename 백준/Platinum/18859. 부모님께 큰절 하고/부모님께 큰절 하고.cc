#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[402005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);

    set<int> A, B;
    A.insert(arr[0]);
    B.insert(arr[0]);

    int a = -1, b = -1;
    for (int i = 1; i < N; i++) {
        if (a == -1) {
            a = arr[i] - *A.rbegin();
            if (a == 0) {
                cout << "No";
                return;
            }
            A.insert(arr[i]);
        } else {
            if (arr[i] - *A.rbegin() == a) A.insert(arr[i]);
            else {
                if (b == -1) {
                    b = arr[i] - *B.rbegin();
                    if (b == 0) {
                        cout << "No";
                        return;
                    }
                    B.insert(arr[i]);
                } else {
                    if (arr[i] - *B.rbegin() == b) B.insert(arr[i]);
                    else {
                        int flag = 0;
                        while (A.size() >= 2) {
                            int temp = *A.rbegin();
                            B.insert(temp);
                            A.erase(temp);

                            b = -1;
                            for (auto i = next(B.begin()); i != B.end(); i++) {
                                if (b == -1) b = *i - *prev(i);
                                else {
                                    if (*i - *prev(i) != b) {
                                        cout << "No";
                                        return;
                                    }
                                }
                            }

                            if (arr[i] - *B.rbegin() == b) {
                                B.insert(arr[i]);
                                flag = 1;
                                break;
                            } else continue;
                        }

                        if (flag) continue;
                        else {
                            cout << "No";
                            return;
                        }
                    }
                }
            }
        }
    }

    if (a == 0 || b == 0) cout << "No";
    else cout << "Yes";
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}