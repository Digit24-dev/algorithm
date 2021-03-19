
s = "1234"
answer = True

for i in s:
    if i.isalpha():
        answer = False
        break

print(answer)