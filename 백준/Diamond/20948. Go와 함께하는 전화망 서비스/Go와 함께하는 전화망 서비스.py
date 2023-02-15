import sys; input = sys.stdin.readline
MIS = lambda: map(int, input().split())
from collections import deque
MFS = lambda: map((lambda s:int(s)if s.isdigit()else int(float(s)*10)),input().split())
INF = 10**5

def mcmf(start, end):
    
    def BFS(start, end, vst):
        que = deque([start])
        while que:
            cur = que.popleft()
            for nxt in range(N):
                if graph[cur][nxt] and graph[cur][nxt] > flow[cur][nxt] and vst[nxt] == -1:
                    vst[nxt] = cur
                    que.append(nxt)
                    if nxt == end: break
        if vst[end] == -1: return False
        else: return True

    def max_flow(start, end):
        ret = 0
        while True:
            vst = [-1]*N
            if not BFS(start, end, vst): break
            min_flow = INF
            idx = end
            while idx != start:
                min_flow = min(min_flow, graph[vst[idx]][idx] - flow[vst[idx]][idx])
                idx = vst[idx]
            idx = end
            while idx != start:
                flow[vst[idx]][idx] += min_flow
                flow[idx][vst[idx]] -= min_flow
                idx = vst[idx]
            ret += min_flow
        return ret

    flow = [[0]*N for _ in range(N)]
    mf = max_flow(start, end)
    if mf < 10: return False
    else: return True

N = int(input())
data = list(MIS())
graph = [list(MFS()) for _ in range(N)]
flag = True
sg = 0
for i in range(N):
    if data[i]*10 < sum(graph[i]):
       flag = False
    sg += sum(graph[i])

if sg// 2 != (N-1)*10: flag = False

for i in range(1, N):
    if not mcmf(0, i):
        flag = False
        break

print("YES" if flag else "NO")