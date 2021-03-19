n, m = map(int, input().split())
rst = 0
for i in range(n):
    num = list(map(int, input().split()))
    answer = min(num)
    answer = max(answer, rst)

print(answer)