"""
Valid Anagram Problem
---------------------
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Approach 1: HashMap (Optimal) -> O(n) time, O(1) space
Approach 2: Sorting (Simple) -> O(n log n) time, O(n) space
"""

# Approach 1: HashMap (Optimal)
def isAnagram_hashmap(s: str, t: str) -> bool:
    if len(s) != len(t):
        return False

    sdict = {}
    for ch in s:
        sdict[ch] = sdict.get(ch, 0) + 1

    for ch in t:
        if ch not in sdict:
            return False
        sdict[ch] -= 1
        if sdict[ch] == 0:
            del sdict[ch]

    return len(sdict) == 0


# Approach 2: Sorting (Simple)
def isAnagram_sorting(s: str, t: str) -> bool:
    return sorted(s) == sorted(t)


# Tests
print("HashMap approach:")
print(isAnagram_hashmap("anagram", "nagaram"))  # Expected True
print(isAnagram_hashmap("rat", "car"))          # Expected False

print("\nSorting approach:")
print(isAnagram_sorting("anagram", "nagaram"))  # Expected True
print(isAnagram_sorting("rat", "car"))          # Expected False
