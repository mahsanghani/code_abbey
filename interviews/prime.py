n = 35
def solution(n):
    prime = []
    for num in range(n):
        if num > 1:
            for i in range(2,num):
                if (num % 1) == 0:
                    break
            else:
                prime.append(num)
    return prime

print(solution(n))