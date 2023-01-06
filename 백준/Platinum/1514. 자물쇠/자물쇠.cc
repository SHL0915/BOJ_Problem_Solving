#include <bits/stdc++.h>

using namespace std;

// 실험용 코드, 출처 https://nicotina04.tistory.com/84

int n;
int dp[105][10][10][10];
int start[105], goal[105];

inline int rot(int x)
{
    while (x < 0)
        x += 10;
    return x % 10;
}

inline int turn(int x)
{
    return x / 3 + (x % 3 != 0);
}

int memo(int curr, int a, int b, int c);

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    memset(dp, -1, sizeof dp);
    cin >> n;
    cin.get();

    for (int i = 0; i < n; ++i)
        start[i] = cin.get() - '0';
    cin.get();
    for (int j = 0; j < n; ++j)
        goal[j] = cin.get() - '0';

    cout << memo(0, start[0], start[1], start[2]);
}

int memo(int curr, int a, int b, int c)
{
    if (curr == n)
        return 0;

    int& ret = dp[curr][a][b][c];

    if (ret != -1)
        return ret;

    ret = 1e9;

    for (int i = -1; i <= 1; i += 2)
    {
        int mov = rot(rot(goal[curr] - a) * i);

        for (int j = 0; j <= mov; ++j)
        {
            for (int k = 0; k <= j; ++k)
            {
                int nb = rot(b + j * i), nc = rot(c + k * i);
                int tmp = memo(curr + 1, nb, nc, start[curr + 3]) + (turn(mov - j) + turn(j - k) + turn(k));
                ret = min(tmp, ret);
            }
        }
    }

    return ret;
}
