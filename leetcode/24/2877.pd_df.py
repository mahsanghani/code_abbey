#
# @lc app=leetcode id=2877 lang=pandas
#
# [2877] Create a DataFrame from List
#

# @lc code=start
import pandas as pd

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    return pd.DataFrame(student_data, columns=["student_id", "age"])
# @lc code=end

