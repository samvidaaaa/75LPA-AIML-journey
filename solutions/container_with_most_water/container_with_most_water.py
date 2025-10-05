def maxArea(height: List[int]) -> int:
    left, right = 0, len(height) - 1
    max_area = 0

    while left < right:
        # width between lines
        width = right - left
        # height is the smaller line
        current_height = min(height[left], height[right])
        # area = width * height
        max_area = max(max_area, width * current_height)

        # move the pointer of the smaller line
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1

    return max_area

# Test
print(maxArea([1,8,6,2,5,4,8,3,7]))  # Expected output: 49
print(maxArea([1,1]))                # Expected output: 1
