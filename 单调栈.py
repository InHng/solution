n = int(input())
a = list(map(int, input().split()))
st, ans = [], []
for i in range(n):
    while st and st[-1] >= a[i]:
        st.pop()
    ans.append(str(st[-1]) if st else "-1")
    st.append(a[i])
print(" ".join(ans))
