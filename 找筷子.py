import sys
input = lambda: sys.stdin.readline().strip()
from functools import reduce

input()
print(reduce(lambda x, y: x ^ y, list(map(int, input().split()))))
