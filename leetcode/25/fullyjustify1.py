class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        i=0
        res=[]
        line=[]
        length=0

        while i<len(words):
            if length + len(words[i]) + len(line) <= maxWidth:
                line.append(words[i])
                length += len(words[i])
                i += 1
            else:
                extra = maxWidth - length
                remainder = extra % max(1, len(line)-1)
                space = extra // max(1, len(line)-1)

                for j in range(max(1, len(line)-1)):
                    line[j] += ' ' * space
                    if remainder:
                        line[j] += ' '
                        remainder -= 1
                res.append(''.join(line))
                line = []
                length = 0

        last = ' '.join(line)
        trail = maxWidth - len(last)
        res.append(last + ' ' * trail)

        return res
