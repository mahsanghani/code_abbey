class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        trips.sort(key=lambda t: t[1])

        minHeap = []  # [end, pass]
        current = 0
        for t in trips:
            passengers, start, end = t

            while minHeap and minHeap[0][0] <= start:
                current -= minHeap[0][1]
                heapq.heappop(minHeap)

            current += passengers
            if current > capacity:
                return False

            heapq.heappush(minHeap, [end, passengers])

        return True
