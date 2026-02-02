import sys
input = lambda: sys.stdin.readline().strip()
mod = 2000120420010122

while True:
    try:
        s = list(input())
        if s == []:
            break
    except EOFError:
        break
    dpc, dpcw, dpcwb, ans = 0, 0, 0, 0
    for c in s:
        if c in ['c', 'C']:
            dpc += 1
            ans += dpcwb
        elif c in ['w', 'W']:
            dpcw += dpc
        elif c in ['b', 'B']:
            dpcwb += dpcw
    print(ans % mod)
