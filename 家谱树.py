from queue import Queue

n = int(input())
g, cnt = [[] for _ in range(n + 1)], [0 for _ in range(n + 1)]
for i in range(1, n + 1):
    a = list(map(int, input().split()))
    for x in a[:-1]:
        g[i].append(x)
        cnt[x] += 1

q = Queue()
for i in range(1, n + 1):
    if not cnt[i]:
        q.put(i)
while q.qsize():
    u = q.get()
    print(u, end = " ")
    for v in g[u]:
        cnt[v] -= 1
        if not cnt[v]:
            q.put(v)
