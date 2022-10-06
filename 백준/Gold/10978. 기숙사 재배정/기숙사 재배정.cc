#include <iostream>
using namespace std;

long long memo[21];
int T, N;

long long DP(int N);

int main(void) {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << DP(N) << "\n";
    }
    return 0;
}

long long DP(int N) {
    if (N == 1) return 0;
    else if (memo[N] != 0) return memo[N];
    else if (N == 2) memo[N] = 1;
    else memo[N] = (N - 1) * (DP(N - 2) + DP(N - 1));
    return memo[N];
}