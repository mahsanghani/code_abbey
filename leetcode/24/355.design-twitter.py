#
# @lc app=leetcode id=355 lang=python3
#
# [355] Design Twitter
#
# @lc code=start
from heapq import heappush, heappop
from collections import defaultdict
class Twitter:
    def __init__(self):
        self.count = 0
        self.tweetMap = defaultdict(list)
        self.followMap = defaultdict(set)

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweetMap[userId].append([self.count, tweetId])
        self.count -= 1

    def getNewsFeed(self, userId: int) -> List[int]:
        results = []
        minHeap = []

        self.followMap[userId].add(userId)

        for followeeId in self.followMap[userId]:
            if followeeId in self.tweetMap:
                index = len(self.tweetMap[followeeId]) - 1
                count, tweetId = self.tweetMap[followeeId][index]
                heappush(minHeap, [count, tweetId, followeeId, index-1])

        while minHeap and len(results)<10:
            count, tweetId, followeeId, index = heappop(minHeap)
            results.append(tweetId)
            if index>=0:
                count, tweetId = self.tweetMap[followeeId][index]
                heappush(minHeap, [count, tweetId, followeeId, index-1])

        return results

    def follow(self, followerId: int, followeeId: int) -> None:
        self.followMap[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.followMap[followerId]:
            self.followMap[followerId].remove(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
# @lc code=end

