class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        i=0
        j=k
        my_set = set()

        while j<=len(s):
            if s[i:j] not in my_set:
                my_set.add(s[i:j])
            i+=1
            j+=1

        return len(my_set)>=2**k
