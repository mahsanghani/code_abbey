class Solution:
    def reorganizeString(self, s: str) -> str:
        counts = Counter(s)
        maxHeap = [[-cnt, char] for char, cnt in counts.items()]
        heapq.heapify(maxHeap)

        prev = None
        results = ''
        while maxHeap or prev:
            if prev and not maxHeap:
                return ""

            cnt, char = heapq.heappop(maxHeap)
            results += char
            cnt += 1

            if prev:
                heapq.heappush(maxHeap, prev)
                prev = None
            if cnt != 0:
                prev = [cnt, char]
        return results
