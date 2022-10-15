n, m = map(int, input().split())
memo = list(list(-1 for i in range(j+1)) for j in range(n+1))
memo[0][0] = 1
memo[1][0] = 1
memo[1][1] = 1
for i in range(2, n+1):
    for j in range(0, i+1):
        if j == 0 or j == i:
            memo[i][j] = 1
        else:
            memo[i][j] = memo[i-1][j] + memo[i-1][j-1]
print("%d" % (memo[n][m]))