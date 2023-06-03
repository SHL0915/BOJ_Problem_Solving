import sys; input = lambda: sys.stdin.readline().strip('\n')
MIS = lambda: map(int, input().split())
II = lambda: int(input())

def ask(x):
    print(x, flush=True)
    pack = input().split()
    if len(pack) <= 2: exit(0)
    ret = int(pack[2][1:])
    return ret

chs = []
for i in range(10):
    chs.append(str(i))
for i in range(26):
    chs.append(chr(i+65))
    chs.append(chr(i+97))

for i in range(1, 21):
    ret = ask('1'*i)
    if ret != 5: 
        L = i
        prv = 14
        break

for ch in chs:
    if ask(ch*L) == 14: 
        ans = [ch]*L
        break

for i in range(L):
    if prv != 14 + 9*i: continue
    for ch in chs:
        ans[i] = ch
        ret = ask(''.join(ans))
        if ret != prv:
            prv = ret
            break