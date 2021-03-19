n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
sum_A = 0
sum_l = []
temp = 268435455

for i in range(n):
    for j in range(n):
        sum_A = sum_A + (a[i] & b[j])
        sum_l.append(a[i] + b[j])

    for j in range(len(sum_l) - 1):
        ans_B = temp & sum_l[j] & sum_l[j+1]
        temp = ans_B

    sum_l = []

print(sum_A % 1999, ans_B)
