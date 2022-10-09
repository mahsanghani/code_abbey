import heapq


class Heap:
    def __init__(self, indices: List[int], nums: List[int], max=False) -> None:
        self.max = max
        self.heap = [[-nums[i], i] if self.max else [nums[i], i] for i in indices]
        self.indices = set(indices)
        heapq.heapify(self.heap)

    def __len__(self) -> int:
        return len(self.indices)

    def remove(self, index: int) -> None:
        if index in self.indices:
            self.indices.remove(index)

    def pop(self) -> List[int]:
        while self.heap and self.heap[0][1] not in self.indices:
            heapq.heappop(self.heap)
        item = heapq.heappop(self.heap)
        self.indices.remove(item[1])
        return [-item[0], item[1]] if self.max else item

    def push(self, item: List[int]) -> None:
        self.indices.add(item[1])
        heapq.heappush(self.heap, [-item[0], item[1]] if self.max else item)

    def peek(self) -> int:
        while self.heap and self.heap[0][1] not in self.indices:
            heapq.heappop(self.heap)
        v, _ = self.heap[0]
        return -v if self.max else v


class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        indices = sorted(range(k), key=lambda x: nums[x])
        minheap = Heap(indices[(k + 1) // 2:], nums)
        maxheap = Heap(indices[:(k + 1) // 2], nums, max=True)
        median = ((lambda: maxheap.peek()) if k % 2 else
                  (lambda: (minheap.peek() + maxheap.peek()) / 2))
        ans = []
        ans.append(median())
        for i in range(k, len(nums)):
            v = nums[i]
            minheap.remove(i - k)
            maxheap.remove(i - k)
            maxheap.push([v, i])
            minheap.push(maxheap.pop())
            if len(minheap) > len(maxheap):
                maxheap.push(minheap.pop())
            ans.append(median())
        return ans
