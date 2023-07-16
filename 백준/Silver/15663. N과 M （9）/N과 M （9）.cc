#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int input[9];
int output[9];
int cnt[10005];

void Permutation(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++)
            cout << output[i] << ' ';
        cout << '\n';
        return;
    } else {
        for (int i = 0; i < N; i++) {
            if (i && input[i] == input[i - 1]) continue;
            if (cnt[input[i]] == 0) continue;
            output[k] = input[i];
            cnt[input[i]]--;
            Permutation(k + 1);
            cnt[input[i]]++;
        }
        return;
    }
}

int main(void) {
    ios::sync_with_stdio();

    int i;
    cin >> N >> M;

    for (i = 0; i < N; i++)
        cin >> input[i];
    sort(input, input + N);

    for (int i = 0; i < N; i++) cnt[input[i]]++;

    Permutation(0);

    return 0;
}