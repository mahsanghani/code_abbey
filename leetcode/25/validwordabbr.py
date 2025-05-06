class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        i=j=k=0
        length=''
        while i<len(word) and j<len(abbr):
            if word[i]==abbr[j]:
                i+=1
                j+=1
                continue

            if abbr[j]=='0' or not abbr[j].isdigit():
                return False

            length = 0
            while j<len(abbr) and abbr[j].isdigit():
                length = length*10+int(abbr[j])
                j+=1

            i+=length

            # if length:
            #     i+=int(length)
            #     k=j+int(length)

        return i==len(word) and j==len(abbr)
