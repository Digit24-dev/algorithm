n, m, k = map(int, input().split())
num = list(map(int, input().split()))
num.sort()
cnt = 0
sum = 0

for i in range(m):
    cnt += 1
    if cnt == k:
        sum += num[len(num)-2]
        cnt = 0
    else:
        sum += num[len(num)-1]
print(sum)