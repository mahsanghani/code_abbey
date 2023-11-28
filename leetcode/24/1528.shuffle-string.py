#
# @lc app=leetcode id=1683 lang=MySQL
#
# [1683] Invalid Tweets
#

# @lc code=start
# Write your MySQL query statement below
select tweet_id from tweets where char_length(content)>15
# @lc code=end

