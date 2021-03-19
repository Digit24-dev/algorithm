answer = []
commands = [[2, 5, 3], [4, 4, 1], [1, 7, 3]]
array = [1, 5, 2, 6, 3, 7, 4]

for l in range(len(commands)):
    i, j, k = commands[l]
    temp = []
    for f in range(i - 1, j):
        temp.append(array[f])
    temp.sort()
    answer.append(temp[k - 1])

print(answer)



'''
def solution(array, commands):
    answer = []
    for command in commands:
        i,j,k = command
        answer.append(list(sorted(array[i-1:j]))[k-1])
    return answer
'''