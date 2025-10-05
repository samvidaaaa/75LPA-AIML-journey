#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSumOptimized(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end()); // Sort for two-pointer technique

    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // Skip duplicates

        int left = i + 1, right = nums.size() - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                // Skip duplicates for left pointer
                while (left < right && nums[left] == nums[left-1]) left++;
                // Skip duplicates for right pointer
                while (left < right && nums[right] == nums[right+1]) right--;
            }
            else if (sum < 0) left++;
            else right--;
        }
    }
    return result;
}

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSumOptimized(nums);

    for (auto &triplet : res) {
        for (int num : triplet) cout << num << " ";
        cout << endl;
    }
}
