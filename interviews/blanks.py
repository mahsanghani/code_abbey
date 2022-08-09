array1 = [1,None,2,3,None,None,5,None]

def solution(nums):
    valid = 0
    results = []
    for i in nums:
        if i is not None:
            results.append(i)
            valid = i
        else:
            results.append(valid)
    return results

print(solution(array1))