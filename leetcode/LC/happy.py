class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        results = ''
        maxHeap = []
        for count, char in [(-a, 'a'), (-b, 'b'), (-c, 'c')]:
            if count != 0:
                heapq.heappush(maxHeap, (count, char))

        while maxHeap:
            count, char = heapq.heappop(maxHeap)
            if len(results) > 1 and results[-1] == results[-2] == char:
                if not maxHeap:
                    break

                count2, char2 = heapq.heappop(maxHeap)
                results += char2
                count2 += 1
                if count2:
                    heapq.heappush(maxHeap, (count2, char2))
            else:
                results += char
                count += 1
            if count:
                heapq.heappush(maxHeap, (count, char))

        return results
