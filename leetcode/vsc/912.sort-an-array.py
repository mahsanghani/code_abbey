#
# @lc app=leetcode id=912 lang=python3
#
# [912] Sort an Array
#

# @lc code=start
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        # return sorted(nums) ## Accepted, Runtime: 689 ms, faster than 92.97%
        return self.mergeSort(nums) ## Accepted, Runtime: 1761 ms, faster than 56.47%, recursive, always O(nlog(n))
        # return self.quickSort2(nums) ## Time Limit Exceeded
        # return self.quickSort(nums) ## Time Limit Exceeded; recursive, avg O(nlog(n)), worst O(n^2)
        # return self.binarySort(nums) ## Time Limit Exceeded
        # return self.bubbleSort(nums) ## Time Limit Exceeded
        
    def mergeSort(self, nums):
        def recur(left, right):
            nonlocal tmp
            if left>=right: return ## base case
            
            mid = (left+right)//2
            recur(left, mid); recur(mid+1, right) ## recursive calls
            
            pl, pr, pt = left, mid+1, left ## left, right, tmp pointer
            while pl<=mid and pr<=right: ## merge
                if nums[pl]<=nums[pr]:
                    tmp[pt]=nums[pl]; pl+=1
                else:
                    tmp[pt]=nums[pr]; pr+=1
                pt += 1
            if pl<mid+1: ## merge rest
                tmp[pt:right+1] = nums[pl:mid+1] 
            elif pr<right+1:
                tmp[pt:right+1] = nums[pr:right+1]
            nums[left:right+1] = tmp[left:right+1] ## copy back
            
        l=len(nums); tmp=[None]*l
        recur(0, l-1)
        return nums
    
    def quickSort2(self, nums):
        def recur(head, tail):
            if head>=tail: return ## base case
            l, r = head, tail
            pivot = nums[(r-l)//2+l] ## choose middle point as pivot
            while r>=l:
                while r>=l and nums[l]<pivot: l+=1
                while r>=l and nums[r]>pivot: r-=1
                if r>=l:
                    nums[l], nums[r] = nums[r], nums[l]
                    l += 1; r -= 1
            recur(head, r); recur(l, tail)
        recur(0, len(nums)-1)
        return nums
    
    def quickSort(self, nums): 
        l = len(nums)
        if l<2: return nums ## base case
        curr = 0 
        for i in range(1,l):
            if nums[0]>nums[i]:
                curr += 1
                nums[curr], nums[i] = nums[i], nums[curr]
        nums[curr], nums[0] = nums[0], nums[curr]
        return self.quickSort(nums[:curr]) + [nums[curr]] + self.quickSort(nums[curr+1:])
    
    def binarySort(self, nums): 
        def insert(n):
            nonlocal ns
            if not ns: ns=[n]; return
            if n>ns[-1]: ns=ns+[n]; return
            if n<ns[0]: ns=[n]+ns; return
            low, high = 0, len(ns)-1
            while low<high:
                mid = (low + high) // 2
                if ns[mid]==n:
                    ns = ns[:mid]+[n]+ns[mid:]
                    return 
                if ns[mid]<n:
                    low = mid + 1
                else:
                    high = mid
            ns = ns[:low]+[n]+ns[low:] 
        ns = []
        for n in nums:
            insert(n) #;print(ns)
        return ns
    
    def bubbleSort(self, nums): 
        l = len(nums)
        for i in range(l-1):
            for j in range(l-1-i):
                if nums[j]>nums[j+1]:
                    nums[j], nums[j+1] = nums[j+1], nums[j]
        return nums
# @lc code=end

