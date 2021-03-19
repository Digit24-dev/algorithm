n, m = map(int, input().split())

num_list = [i+1 for i in range(n)]
check_list = [False] * n

arr = []

def dfs(cnt):
    if cnt==m:
        print(*arr,end=' ')
        print("<<<<<")
        return

    for i in range(0, n):
        if(check_list[i]):
            continue
        check_list[i] = True
        arr.append(num_list[i])
        dfs(cnt + 1)
        arr.pop()
        print(arr)
        print(check_list)
        check_list[i] = False

dfs(0)