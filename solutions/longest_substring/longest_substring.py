def longestSubstring(s):
    mapping = {}  # stores last index of each character
    start = 0     # start of the current window
    max_length = 0

    for end in range(len(s)):
        char = s[end]

        # if the character is already seen and inside the current window
        if char in mapping and mapping[char] >= start:
            start = mapping[char] + 1  # move start after the repeated char

        # update last seen index of current character
        mapping[char] = end

        # update max_length for current window
        max_length = max(max_length, end - start + 1)

    return max_length


# test cases
print(longestSubstring("abcabcbb"))  # Expected output: 3 ("abc")
print(longestSubstring("bbbbb"))     # Expected output: 1 ("b")
print(longestSubstring("pwwkew"))    # Expected output: 3 ("wke")
