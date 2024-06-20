#include <stdio.h>

int N, M, D, ans, aans;
int arr[15][15];
int grid[15][15];
int pos[3][2];
int cand[305][3], temp[305][3];

void merge(int l, int r) {
    int m = (l + r) / 2;
    int lptr = l, rptr = m + 1, now = l;
    while (lptr <= m && rptr <= r) {
        if (cand[lptr][0] < cand[rptr][0]) {
            temp[now][0] = cand[lptr][0];
            temp[now][1] = cand[lptr][1];
            temp[now][2] = cand[lptr][2];
            now++;
            lptr++;
        } else {
            if (cand[lptr][0] == cand[rptr][0]) {
                if (cand[lptr][1] < cand[rptr][1]) {
                    temp[now][0] = cand[lptr][0];
                    temp[now][1] = cand[lptr][1];
                    temp[now][2] = cand[lptr][2];
                    now++;
                    lptr++;
                } else {
                    temp[now][0] = cand[rptr][0];
                    temp[now][1] = cand[rptr][1];
                    temp[now][2] = cand[rptr][2];
                    now++;
                    rptr++;
                }
            } else {
                temp[now][0] = cand[rptr][0];
                temp[now][1] = cand[rptr][1];
                temp[now][2] = cand[rptr][2];
                now++;
                rptr++;
            }
        }
    }
    while (lptr <= m) {
        temp[now][0] = cand[lptr][0];
        temp[now][1] = cand[lptr][1];
        temp[now][2] = cand[lptr][2];
        now++;
        lptr++;
    }
    while (rptr <= r) {
        temp[now][0] = cand[rptr][0];
        temp[now][1] = cand[rptr][1];
        temp[now][2] = cand[rptr][2];
        now++;
        rptr++;
    }
    for (int i = l; i <= r; i++) {
        cand[i][0] = temp[i][0];
        cand[i][1] = temp[i][1];
        cand[i][2] = temp[i][2];
    }
    return;
}

void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    merge(l, r);
    return;
}

void update() {
    int temp[20][20] = {0};

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            temp[i][j] = grid[i - 1][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) grid[i][j] = temp[i][j];
    }

    return;
}

void attack(int aa) {

    int choose[3][2];
    int ccnt = 0;
    for (int k = 0; k < 3; k++) {
        int cnt = 0;
        int x = pos[k][0], y = pos[k][1];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!grid[i][j]) continue;
                int dx = x - j, dy = y - i;
                if (dx < 0) dx *= -1;
                if (dy < 0) dy *= -1;
                if (dx + dy > D) continue;
                cand[cnt][0] = dx + dy;
                cand[cnt][1] = j;
                cand[cnt][2] = i;
                cnt++;
            }
        }

        if (cnt == 0) continue;
        merge_sort(0, cnt - 1);
        choose[ccnt][0] = cand[0][1];
        choose[ccnt][1] = cand[0][2];
        ccnt++;
    }

    for (int i = 0; i < ccnt; i++) {
        int x = choose[i][0], y = choose[i][1];
        if (grid[y][x]) {
            ans++;
            grid[y][x] = 0;
        }
    }

    update();

    return;
}

int main(void) {
    scanf("%d %d %d", &N, &M, &D);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) scanf("%d", &arr[i][j]);
    }

    for (int i = 0; i < (1 << M); i++) {
        int cnt = 0;
        for (int j = 0; j < M; j++) {
            if (i & (1 << j)) cnt++;
        }

        if (cnt != 3) continue;

        cnt = 0;
        for (int j = 0; j < M; j++) {
            if (i & (1 << j)) {
                pos[cnt][0] = j;
                pos[cnt][1] = N;
                cnt++;
            }
        }

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) grid[j][k] = arr[j][k];
        }

        ans = 0;
        for (int j = 0; j < N + 1; j++) {
            attack(i);
        }

        if (ans > aans) aans = ans;
    }

    printf("%d", aans);
    return 0;
}