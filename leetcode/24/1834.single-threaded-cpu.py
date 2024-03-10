#
# @lc app=leetcode id=1834 lang=python3
#
# [1834] Single-Threaded CPU
#
# @lc code=start
class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        for i,j in enumerate(tasks):
            j.append(i)
        tasks.sort(key=lambda x:x[0])

        heap = []
        results = []
        i = 0
        time = tasks[0][0]

        while heap or i<len(tasks):
            while i<len(tasks) and time>=tasks[i][0]:
                heapq.heappush(heap, [tasks[i][1], tasks[i][2]])
                i+=1

            if not heap:
                time = tasks[i][0]
            else:
                process, index = heapq.heappop(heap)
                time += process
                results.append(index)
        
        return results
# @lc code=end
