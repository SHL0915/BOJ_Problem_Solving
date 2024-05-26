#include <iostream>
#include <string>

long long N;
std::string S;

int main(void) {
    std::cin >> N >> S;

    long long cnt = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '2') cnt++;
        else {
            for (long long j = 1; j <= cnt; j++) ans += j * (cnt - j + 1);
            cnt = 0;
        }
    }

    for (long long i = 1; i <= cnt; i++) ans += i * (cnt - i + 1);

    std::cout << ans;

    return 0;
}