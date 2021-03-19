board = [[0, 0, 0, 0, 0], [0, 0, 1, 0, 3], [0, 2, 5, 0, 1], [4, 2, 4, 4, 2], [3, 5, 1, 3, 1]]
moves = [1, 5, 3, 5, 1, 2, 1, 4]


def solution(board, moves):
    stack = []
    answer = 0
    for k in moves:
        for i in range(len(board[0])):
            if board[i][k - 1] != 0:
                stack.append(board[i][k - 1])
                board[i][k - 1] = 0

                if len(stack) > 1 and stack[len(stack)-1] == stack[len(stack)-2]:
                    stack.pop()
                    stack.pop()
                    answer += 2
                break

    return answer


print(solution(board, moves))
