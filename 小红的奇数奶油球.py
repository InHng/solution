# 克服 py 栈太浅的问题
from types import GeneratorType
# 装饰器 手写栈
# 函数头加上@bootstrap, 函数内部 return 改成 yield
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:  # 递归一层返回
            return f(*args, **kwargs)
        else:
            # 遍历生成器函数
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:  # 新的生成器函数
                    stack.append(to)  # 入栈
                    to = next(to)  # 递归
                else:  # 没有新的生成器函数
                    stack.pop()  # 弹出递归入口
                    if not stack:  # 全部遍历完了
                        break
                    to = stack[-1].send(to)
            return to  # 返回答案
    return wrappedfunc

import sys
input = lambda: sys.stdin.readline().strip()

for _ in range(int(input())):
    n = int(input())
    g = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        g[u].append(v)
        g[v].append(u)
    if n == 1:
        print(1)
        continue
    size = [1 for _ in range(n + 1)]

    @bootstrap
    def dfs(u, fa):
        for v in g[u]:
            if v != fa:
                yield dfs(v, u)
                size[u] += size[v]
        yield size[u]

    dfs(1, -1)
    ans = 0
    st = [(1, -1)]
    while st:
        u, fa = st.pop()
        flag = (n - size[u]) % 2 == 1 or n == size[u]
        for v in g[u]:
            if v == fa:
                continue
            if size[v] & 1 == 0:
                flag = False
            st.append((v, u))
        if flag:
            ans += 1
    print(ans)
