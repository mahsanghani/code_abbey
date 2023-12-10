#
# @lc app=leetcode id=1783 lang=MySQL
#
# [1783] Grand Slam Titles
#

# @lc code=start
# Write your MySQL query statement below
# with cte as (
#     select year, 'Wimbledon' tournament, Wimbledon 'player_id' from Championships
# UNION
# select year, 'Fr_open' tournament, FR_open 'player_id' from Championships
# UNION
# select year, 'US_open' tournament, US_open 'player_id' from Championships
# UNION
# select year, 'AU_open' tournament, AU_open 'player_id' from Championships
# ),

# cte2 as
#  ( select  player_id , count(tournament) as "grand_slams_count" 
#  from cte group by player_id)

# select c.player_id, p.player_name, grand_slams_count
# from cte2 c right join players p
# on c.player_id = p.player_id
# where grand_slams_count is not null

select  player_id, player_name,
    (sum(player_id = Wimbledon) + 
    sum(player_id = Fr_open) + 
    sum(player_id = US_open) + 
    sum(player_id = Au_open)) as grand_slams_count
from championships 
left join players
on player_id in (Wimbledon, Fr_open, US_open, Au_open)
group by player_id;
# @lc code=end

