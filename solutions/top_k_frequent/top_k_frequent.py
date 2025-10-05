def kFrequentElements(nums, k):
    freq = {}  # dictionary to store counts
    for num in nums:
        freq[num] = freq.get(num, 0) + 1

    sorted_items = sorted(freq.items(), key=lambda x: x[1], reverse=True)
    result = [num for num, count in sorted_items[:k]]
    return result

# Test
print(kFrequentElements([1,1,1,2,2,3], 2))  # Expected: [1,2]
print(kFrequentElements([1], 1))            # Expected: [1]
