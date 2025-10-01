def isAnagram(s: str, t: str) -> bool:
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


# Test
print(isAnagram("anagram", "nagaram"))  # Expected True
print(isAnagram("rat", "car"))          # Expected False
