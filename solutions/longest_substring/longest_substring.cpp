#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndex;  // store last seen index of each character
    int maxLength = 0;
    int start = 0;  // left pointer of the window

    for (int end = 0; end < s.size(); end++) {
        char currentChar = s[end];

        // If we have seen this char before and it’s inside the current window
        if (charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= start) {
            start = charIndex[currentChar] + 1; // move start to right of the duplicate
        }

        charIndex[currentChar] = end; // update last seen index
        maxLength = max(maxLength, end - start + 1); // update window size
    }

    return maxLength;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "Length of longest substring without repeating characters: "
         << lengthOfLongestSubstring(s) << endl;

    return 0;
}
