#include <iostream>

int N, Q;
int chk[1000005];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cout.tie(0);
    std::cin.tie(0);

    std::cin >> N >> Q;

    int ans = N;
    while (Q--) {
        int a;
        std::cin >> a;
        if (a == 1) {
            int b;
            std::cin >> b;
            if (chk[b]) continue;
            else {
                ans--;
                chk[b] = 1;
            }
        } else if (a == 2) {
            int b;
            std::cin >> b;
            if (!chk[b]) continue;
            else {
                ans++;
                chk[b] = 0;
            }
        } else if (a == 3) std::cout << ans << '\n';
    }

    return 0;
}
