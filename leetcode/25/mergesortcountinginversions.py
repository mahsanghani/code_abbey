def countInversions(arr):
    # Helper function to merge two sorted halves and count split inversions
    def mergeAndCount(arr, temp, left, mid, right):
        inv_count = 0
        
        i = left     # index for left subarray
        j = mid      # index for right subarray
        k = left     # index for merged array
        
        while i < mid and j <= right:
            if arr[i] <= arr[j]:
                temp[k] = arr[i]
                i += 1
            else:
                # This is the key insight: if arr[i] > arr[j], then all elements
                # from arr[i] to arr[mid-1] are also greater than arr[j]
                temp[k] = arr[j]
                inv_count += (mid - i)
                j += 1
            k += 1
        
        # Copy remaining elements from left subarray
        while i < mid:
            temp[k] = arr[i]
            i += 1
            k += 1
        
        # Copy remaining elements from right subarray
        while j <= right:
            temp[k] = arr[j]
            j += 1
            k += 1
        
        # Copy back the merged elements to original array
        for i in range(left, right + 1):
            arr[i] = temp[i]
            
        return inv_count
    
    # Main recursive function to sort array and count inversions
    def mergeSortAndCount(arr, temp, left, right):
        inv_count = 0
        
        if left < right:
            # Divide the array into two parts and call recursively
            mid = (left + right) // 2
            
            # Count inversions in left subarray
            inv_count += mergeSortAndCount(arr, temp, left, mid)
            
            # Count inversions in right subarray
            inv_count += mergeSortAndCount(arr, temp, mid + 1, right)
            
            # Count split inversions
            inv_count += mergeAndCount(arr, temp, left, mid + 1, right)
            
        return inv_count
    
    # Create a temporary array to store sorted subarrays during merge
    n = len(arr)
    temp = [0] * n
    return mergeSortAndCount(arr, temp, 0, n - 1)

# Example usage:
test_arr = [5, 2, 6, 1]
print(countInversions(test_arr))  
# # Should output 5

