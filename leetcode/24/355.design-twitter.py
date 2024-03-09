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
        self.time = 0
        self.tweetMap = defaultdict(list)
        self.followMap = defaultdict(list)

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.follow(userId,userId)
        self.tweetMap[userId].insert(0,[self.time,tweetId])
        self.time+=1

    def getNewsFeed(self, userId: int) -> List[int]:
        self.results = []
        for i in self.followMap[userId]:
            for j in self.tweetMap[i][:max(10,len(self.tweetMap[i]))]:
                heapq.heappush(self.results, j)
            while len(self.results)>10:
                heapq.heappop(self.results)
        self.results.sort(key=lambda x:-x[0])
        return [r[1] for r in self.results]

    def follow(self, followerId: int, followeeId: int) -> None:
        if followeeId not in self.followMap[followerId]:
            self.followMap[followerId].append(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.followMap[followerId]:
            self.followMap[followerId].remove(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)