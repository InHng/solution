from queue import Queue

for _ in range(int(input())):
    n, k = map(int, input().split())
    g, IN = [[] for __ in range(n + 1)], [0 for _ in range(n + 1)]
    all = 0
    for __ in range(k):
        a = list(map(int, input().split()))
        for i in range(n):
            if i > 1:
                g[a[i - 1]].append(a[i])
                IN[a[i]] += 1
    
    q = Queue()
    for i in range(1, n + 1):
        if IN[i] == 0:
            q.put(i)
    
    while q.qsize():
        u = q.get()
        all += 1
        for v in g[u]:
            IN[v] -= 1
            if IN[v] == 0:
                q.put(v)
    
    print("YES" if all == n else "NO")
