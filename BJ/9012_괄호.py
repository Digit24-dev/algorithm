T = int(input())


def check(strings):
    stack = []

    for i in strings:
        if i == '(':
            stack.append(i)
        else:
            if not stack:
                print("NO")
                return
            else:
                stack.pop()

    if not stack:
        print("YES")
        return
    else:
        print("NO")
        return
첫째 줄에 (A+B)%C, 둘째 줄에 ((A%C) + (B%C))%C, 셋째 줄에 (A×B)%C, 넷째 줄에 ((A%C) × (B%C))%C를 출력한다.

for _ in range(T):
    n = input()
    check(n)


