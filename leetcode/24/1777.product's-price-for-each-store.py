#
# @lc app=leetcode id=1777 lang=MySQL
#
# [1777] Product's Price for Each Store
#
# @lc code=start
# Write your MySQL query statement below
select product_id,
sum(case when store ='store1' THEN  price ELSE NULL END) AS "store1",
sum(case when store ='store2' THEN price  ELSE NULL END) AS "store2",
sum(case when store ='store3' THEN price  ELSE NULL END) AS "store3"
FROM Products
group by product_id
# @lc code=end

