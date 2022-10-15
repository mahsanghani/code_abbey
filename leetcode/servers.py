class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        results = [0] * len(tasks)

        available = [(servers[i], i) for i in range(len(servers))]
        heapq.heapify(available)
        unavailable = []

        t = 0
        for i in range(len(tasks)):
            t = max(t, i)
            if len(available) == 0:
                t = unavailable[0][0]
            while unavailable and t >= unavailable[0][0]:
                time, weight, index = heapq.heappop(unavailable)
                heapq.heappush(available, (weight, index))

            weight, index = heapq.heappop(available)
            results[i] = index
            heapq.heappush(unavailable, (t + tasks[i], weight, index))
        return results
