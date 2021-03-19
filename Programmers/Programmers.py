num = list(map(int, input().split()))


def solution(numbers):
    answer = []
    temp = []
    for i in range(0, len(numbers)):
        for j in range(i+1, len(numbers)):
            temp.append(numbers[i] + numbers[j])
    temp = list(set(temp))
    temp.sort()
    answer = temp
    return answer

print(solution(num))
