sentence1 = 'We are really pleased to meet you in our city'
sentence2 = 'The city was hit by a really heavy storm'

def solution(sentence1, sentence2):
    set1 = set(sentence1.split())
    set2 = set(sentence2.split())
    return sorted(list(set1^set2)), sorted(list(set1&set2))

print(solution(sentence1, sentence2))