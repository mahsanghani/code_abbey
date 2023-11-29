#
# @lc app=leetcode id=804 lang=python3
#
# [804] Unique Morse Code Words
#

# @lc code=start
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        morse = []
        mapping = {'a':".-",
                   'b':"-...",
                   'c':"-.-.",
                   'd':"-..",
                   'e':".",
                   'f':"..-.",
                   'g':"--.",
                   'h':"....",
                   'i':"..",
                   'j':".---",
                   'k':"-.-",
                   'l':".-..",
                   'm':"--",
                   'n':"-.",
                   'o':"---",
                   'p':".--.",
                   'q':"--.-",
                   'r':".-.",
                   's':"...",
                   't':"-",
                   'u':"..-",
                   'v':"...-",
                   'w':".--",
                   'x':"-..-",
                   'y':"-.--",
                   'z':"--.."}
        for word in words:
            code = ""
            for char in word:
                code+=mapping[char]
            morse.append(code)
        return len(set(morse))
# @lc code=end

