import collections

def solution(s):
    count = collections.Counter(s)

    for i, j in enumerate(s):
        if count[j] == 1:
            return i
    return -1

print(solution('alphabet'))
print(solution('barbados'))
print(solution('crunchy'))