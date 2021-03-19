from collections import deque
a = deque()

a = deque([1,2,3,4,5])
a.pop()
a.popleft()
for i in a:
    print(i)

a=list(a)


print(a)