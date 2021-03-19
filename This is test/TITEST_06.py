alpha = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
cnt = 0
loc = input()

for i, val in enumerate(alpha):
    if val == loc[0]:
        x = i

y = int(loc[1]) - 1

dir_list = [[-1, 2], [-1, -2], [1, 2], [1, -2], [-2, 1], [-2, -1], [2, 1], [2, -1]]

for i, j in dir_list:
    if 8 > x + i >= 0 and 8 > y + j >= 0:
        cnt += 1

print(cnt)