answer = []
arr = [1,1,3,3,0]

for i in arr:
    if answer[-1:] == [i]: continue
    answer.append(i)
print(answer)
print(answer[-1:])