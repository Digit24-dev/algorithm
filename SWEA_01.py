a = int(input())

for _ in range(a):
    n = int(input())
    maps = [['']*n for _ in range(n)]

    for i in range(n):
        maps[i] = input()

print(maps)
