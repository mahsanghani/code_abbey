# Implement a string compression algorithm, where consecutive identical characters are replaced with a single character and an integer representing the number of occurrences of that character.

# “abbccc” > “ab2c3”
# “aabddda” > “a2bd3a”
# “bbccaa” > “b2c2a2”

class stringcompression:
    def __init__(self) -> None:
        return

    def encode(self, s: str) -> str:
        output = []
        i = 0
        try:
            for j in range(1,len(s)):
                if s[i]!=s[j]:
                    print(s[i])
                    print("if new element, left pointer:"+s[i])               
                    output.append(str(s[i])+str(j-i)+'#')
                    i=j
                if j==len(s)-1:
                    print("if last element, right pointer:"+s[j])
                    output.append(str(s[j])+str(j-i+1)+'#')
        except:
            print("j out of range")
        print("".join(output))    
        return "".join(output)
    
s = stringcompression()
s.encode("bbccaa")