"""
LC 3413 - Maximum Coins From K Consecutive Bags

Run:    python3 coins3413.py
Debug:  set a breakpoint (click left of a line number) and press F5 in VS Code

Approach: coordinate-compressed sliding window.
- Segments are given as [l, r, c] meaning positions l..r each hold c coins.
- Gaps between segments are worth 0 coins.
- The optimal k-length window can only START at a point aligned with a
  segment boundary (either a segment's left edge, or positioned so the
  window's right edge lands exactly on a segment's right edge) -- because
  between two boundaries the coin-density is flat, so sliding strictly
  inside a flat region never changes the sum.
- For each candidate start, compute the window's total via binary search
  + prefix sums over segments: O(log n) per candidate, O(n) candidates,
  O(n log n) total (dominated by the initial sort).
"""

import bisect
from typing import List

class Solution:
    def maximumCoins(self, coins: List[List[int]], k: int) -> int:
        coins.sort(key=lambda x: x[0])
        n = len(coins)
        lefts = [c[0] for c in coins]
        rights = [c[1] for c in coins]

        prefix = [0]*(n+1)
        for i,(l,r,c) in enumerate(coins):
            prefix[i+1] = prefix[i] + c*(r-l+1)

        def window_value(start):
            end = start+k-1
            hi_idx = bisect.bisect_right(lefts, end)-1
            lo_idx = bisect.bisect_left(rights, start)

            if hi_idx<0:
                return 0
            if lo_idx>hi_idx:
                return 0
            
            total = prefix[hi_idx+1] - prefix[lo_idx]
            l0,r0,c0 = coins[lo_idx]
            l1,r1,c1 = coins[hi_idx]

            if l0<start:
                total-=c0*(start-l0)
            if r1>end:
                total-=c1*(r1-end)

            return total

        res=0
        for l,r,c in coins:
            res = max(res, window_value(l))
            res = max(res, window_value(r-k+1))
        return res

# ----------------------------------------------------------------------
# Test harness -- the exact cases you validated on LeetCode
# ----------------------------------------------------------------------
if __name__ == "__main__":
    sol = Solution()

    tests = [
        # (coins, k, expected)
        ([[8, 10, 1], [1, 3, 2], [5, 6, 4]], 4, 10),
        ([[1, 10, 3]], 2, 6),
    ]

    for i, (coins, k, expected) in enumerate(tests, 1):
        got = sol.maximumCoins([row[:] for row in coins], k)  # copy: sort() mutates input
        status = "PASS" if got == expected else "FAIL"
        print(f"Case {i}: coins={coins}  k={k}")
        print(f"  got={got}  expected={expected}   [{status}]")
        print()
