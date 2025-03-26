import sys
from heapq import *
input = lambda:sys.stdin.readline().strip()
from math import sqrt

def f(i, j):
    return sqrt(pow(idx[i][0] - idx[j][0], 2) + pow(idx[i][1] - idx[j][1], 2))

n = int(input())
idx = [()] + [list(map(int, input().split())) for _ in range(n)]
g = [[] for _ in range(n + 1)]
dist = [0x3f3f3f3f for _ in range(n + 1)]
for _ in range(int(input())):
    i, j = map(int, input().split())
    g[i].append((f(i, j), j))
    g[j].append((f(i, j), i))
s, t = map(int, input().split())
q = [(0, s)]
while q:
    dis, u = heappop(q)
    if u == t:
        exit(print(f"{dis:.2f}"))
    for l, v in g[u]:
        if dist[v] > dis + l:
            dist[v] = dis + l
            heappush(q, (dist[v], v))
