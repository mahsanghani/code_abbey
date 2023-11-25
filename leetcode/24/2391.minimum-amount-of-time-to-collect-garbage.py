#
# @lc app=leetcode id=2391 lang=python3
#
# [2391] Minimum Amount of Time to Collect Garbage
#

# @lc code=start
class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        time = 0
        prefix = travel[:1]
        lastpos = {'M':0, 'P':0, 'G':0}
        count = {'M':0, 'P':0, 'G':0}
        
        # for g in garbage:
        #     while 'M' in g:
        #         count['M']+=1
        #         g = g.replace('M', '')
        #     while 'P' in g:
        #         count['P']+=1
        #         g = g.replace('P', '')
        #     while 'G' in g:
        #         count['G']+=1
        #         g = g.replace('G', '')

        count['M'] = sum(s.count('M') for s in garbage)
        count['P'] = sum(s.count('P') for s in garbage)
        count['G'] = sum(s.count('G') for s in garbage)
                    
        for i in range(1,len(travel)):
            prefix.append(travel[i]+prefix[-1])

        for i in range(len(garbage)-1,-1,-1):
            if lastpos['M']==0 and 'M' in garbage[i]:
                lastpos['M']=i
            if lastpos['P']==0 and 'P' in garbage[i]:
                lastpos['P']=i
            if lastpos['G']==0 and 'G' in garbage[i]:
                lastpos['G']=i

        # print(count['M'])
        # print(prefix[lastpos['M']])
        # print(count['P'])
        # print(prefix[lastpos['P']])
        # print(count['G'])
        # print(prefix[lastpos['G']])

        time+=count['M']
        time+=prefix[lastpos['M']-1] if lastpos['M']!=0 else 0
        time+=count['P']
        time+=prefix[lastpos['P']-1] if lastpos['P']!=0 else 0
        time+=count['G']
        time+=prefix[lastpos['G']-1] if lastpos['G']!=0 else 0

        return time
# @lc code=end

