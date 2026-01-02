class Node:
    def __init__(self):
        self.left = 0
        self.right = 0

n = int(input())
node = [Node() for _ in range(n + 1)]
IN = [0] * (n + 1) # 入度数组，用于寻找根节点

# 读取 n-1 条边并建树
for _ in range(n - 1):
    a, b = map(int, input().split())
    IN[b] += 1
    if node[a].left == 0 and node[a].right == 0:
        if a < b:
            node[a].left = b
        else:
            node[a].right = b
    elif node[a].left != 0:
        if node[a].left > b:
            # 原左孩子移到右边，新节点 b 成为左孩子
            node[a].right = node[a].left
            node[a].left = b
        else:
            node[a].right = b
    else: 
        if node[a].right < b:
            # 原右孩子移到左边，新节点 b 成为右孩子
            node[a].left = node[a].right
            node[a].right = b
        else:
            node[a].left = b

start = 0
for i in range(1, n + 1):
    if IN[i] == 0:
        start = i
        break

def pre_search(now):
    print(now, end = " ")
    if node[now].left != 0:
        pre_search(node[now].left)
    if node[now].right != 0:
        pre_search(node[now].right)

# 中序遍历 (Left -> Root -> Right)
def mid_search(now):
    if node[now].left != 0:
        mid_search(node[now].left)
    print(now, end = " ")
    if node[now].right != 0:
        mid_search(node[now].right)

# 后序遍历 (Left -> Right -> Root)
def rear_search(now):
    if node[now].left != 0:
        rear_search(node[now].left)
    if node[now].right != 0:
        rear_search(node[now].right)
    print(now, end = " ")

pre_search(start)
print()
mid_search(start)
print()
rear_search(start)
print()
