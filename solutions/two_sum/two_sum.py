# Two Sum - My First Python Code

def two_sum(nums, target):
    # This will store numbers we've seen
    seen = {}
    for i, num in enumerate(nums):
        diff = target - num
        if diff in seen:
            return [seen[diff], i]
        seen[num] = i
    return []

# Test the function
nums = [2, 7, 11, 15]
target = 9
print(two_sum(nums, target))  # Should print [0, 1]
