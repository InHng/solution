from heapq import *

def solve():
    n, m = map(int, input().split())
    s = int(input(), 2)
    medicines = [[] for _ in range(m)]
    dist = [0x3f3f3f3f for _ in range(1 << n)]
    dist[s] = 0
    for i in range(m):
        f = int(input())
        sf = int(input(), 2) ^ ((1 << n) - 1)
        ss = int(input(), 2)
        medicines[i] = [f, sf, ss]
    q = [(0, s)]
    while q:
        day, lai = heappop(q)
        for a, b, c in medicines:
            qu = lai & b
            qu |= c
            if dist[qu] > day + a:
                dist[qu] = day + a
                heappush(q, (dist[qu], qu))
    print(-1 if dist[0] == 0x3f3f3f3f else dist[0])

if __name__ == "__main__":
    for _ in range(int(input())):
        solve()
