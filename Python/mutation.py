nA = int(input())
A = set(map(int, input().split()))
N = int(input())

for x in range(N):
    command = input()
    sets = set(map(int, input().split()))
    arrComm = command.split()
    if arrComm[0] == "intersection_update":
        A.intersection_update(sets)
    elif arrComm[0] == "update":
        A.update(sets)
    elif arrComm[0] == "difference_update":
        A.difference_update(sets)
    elif arrComm[0] == "symmetric_difference_update":
        A.symmetric_difference_update(sets)


print(sum(A))
