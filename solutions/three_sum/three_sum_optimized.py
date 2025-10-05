def threesum_optimized(nums):
    result = []
    nums.sort()  # Sort array first for two-pointer technique

    for i in range(len(nums)-2):  # Fix first element
        if i > 0 and nums[i] == nums[i-1]:
            continue  # Skip duplicates for i

        left, right = i+1, len(nums)-1  # Two pointers

        while left < right:
            tripleSum = nums[i] + nums[left] + nums[right]

            if tripleSum == 0:
                result.append([nums[i], nums[left], nums[right]])
                left += 1
                right -= 1

                # Skip duplicates for left pointer
                while left < right and nums[left] == nums[left-1]:
                    left += 1
                # Skip duplicates for right pointer
                while left < right and nums[right] == nums[right+1]:
                    right -= 1

            elif tripleSum < 0:
                left += 1  # Need larger sum
            else:
                right -= 1  # Need smaller sum

    return result

print(threesum_optimized([-1,0,1,2,-1,-4]))
