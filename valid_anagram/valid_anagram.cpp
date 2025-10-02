#include <iostream>
#include <unordered_map>
using namespace std;

// Function to check if two strings are anagrams
bool isAnagram(string s, string t) {
    // Step 1: Check size first
    if (s.size() != t.size()) return false;

    unordered_map<char, int> count;

    // Step 2: Count characters in s
    for (char ch : s) {
        count[ch]++;
    }

    // Step 3: Subtract counts using t
    for (char ch : t) {
        if (count.find(ch) == count.end() || count[ch] == 0)
            return false;  // Extra char in t or more occurrences than in s
        count[ch]--;
    }

    // Step 4: If all counts matched, return true
    return true;
}

// Test the function
int main() {
    cout << boolalpha; // Print true/false instead of 1/0
    cout << "Test 1: " << isAnagram("anagram", "nagaram") << endl; // true
    cout << "Test 2: " << isAnagram("rat", "car") << endl;         // false
    cout << "Test 3: " << isAnagram("aabbc", "abcab") << endl;     // true
    cout << "Test 4: " << isAnagram("hello", "bello") << endl;     // false
    return 0;
}
