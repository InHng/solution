from queue import Queue
n, m = map(int, input().split())
cnt, dist = [0 for _ in range(n + 1)], [0 for _ in range(n + 1)]
g, final = [[] for _ in range(n + 1)], []
for _ in range(m):
    u, v = map(int, input().split())
    g[v].append(u)
    cnt[u] += 1

def topsort():
    q = Queue()
    for i in range(1, n + 1):
        if not cnt[i]:
            q.put(i)
    while q.qsize():
        u = q.get()
        final.append(u)
        for v in g[u]:
            dist[v] = max(dist[v], dist[u] + 1)
            cnt[v] -= 1
            if not cnt[v]:
                q.put(v)
    return len(final) == n

if topsort():
    print(sum(dist[1:]) + len(dist) * 100 - 100)
else:
    print("Poor Xed")
