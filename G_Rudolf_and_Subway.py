from collections import defaultdict
from queue import deque
from heapq import *

def solve():
    n, m = map(int, input().split())
    color = defaultdict(set)
    have = defaultdict(set)
    for _ in range(m):
        u, v, c = map(int, input().split())
        color[c].add(u)
        color[c].add(v)
        have[u].add(c)
        have[v].add(c)
    b, e = map(int, input().split())
    q = deque()
    q.append((b, 0))
    visit = [0 for _ in range(n + 1)]
    vis = set()
    while q:
        u, dis = q.popleft()
        if u == e:
            print(dis)
            return
        if visit[u]:
            continue
        visit[u] = 1
        for c in have[u]:
            if c in vis:
                continue
            vis.add(c)
            for v in color[c]:
                if visit[v]:
                    continue
                q.append((v, dis + 1))


if __name__ == "__main__":
    for _ in range(int(input())):
        solve()
