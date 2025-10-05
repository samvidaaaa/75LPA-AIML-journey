#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;

    // Step 1: Count frequencies
    for (int num : nums) {
        freq[num]++;
    }

    // Step 2: Copy keys into a vector
    vector<int> keys;
    for (auto &p : freq) {
        keys.push_back(p.first);
    }

    // Step 3: Sort keys based on frequency (descending)
    sort(keys.begin(), keys.end(), [&](int a, int b) {
        return freq[a] > freq[b];
    });

    // Step 4: Take first k elements
    keys.resize(k);
    return keys;
}

int main() {
    vector<int> nums1 = {1,1,1,2,2,3};
    int k1 = 2;
    vector<int> res1 = topKFrequent(nums1, k1);
    for(int num : res1) cout << num << " ";  // Expected: 1 2
    cout << endl;

    vector<int> nums2 = {1};
    int k2 = 1;
    vector<int> res2 = topKFrequent(nums2, k2);
    for(int num : res2) cout << num << " ";  // Expected: 1
    cout << endl;

    return 0;
}
