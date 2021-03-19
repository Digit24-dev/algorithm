n, m = map(int, input().split())
card = [[]*m for _ in range(n)]

for i in range(n):
    card[i] = list(map(int, input().split()))
    a = min(card[i])
    ans = 0
    ans = max(a, ans)

print(ans)