def solution(progresses, speeds):
    answer = []
    cnt = 1

    sol = lambda k: (100 - progresses[k]) / speeds[k]

    for i in range(len(progresses) - 1):
        temp = i
        if sol(temp) >= sol(i + 1):
            for j in range(i+1, len(progresses) - 1):
                if sol(temp) > sol(j):
                    cnt += 1
                    progresses.remove(progresses[0])
                    speeds.remove(speeds[0])
                else:
                    break
            i += cnt
        answer.append(cnt)
        cnt = 1
    answer.append(cnt)

    return answer


a = [95,90,99,99,80,99]
b = [1,1,1,1,1,1]

print(solution(a, b))
