N = int(input())

students = list(map(int, input().split()))
stack = []
cnt = 1

while students:
    if cnt == students[0]:
        cnt += 1
        students.pop(0)
    else :
        stack.append(students.pop(0))

    while len(stack) != 0:
        if stack[-1] == cnt:
            stack.pop()
            cnt += 1
        else:
            break

if len(stack) == 0:
    print("Nice")
else:
    print("Sad")
