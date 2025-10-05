#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSumBruteforce(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    if (find(result.begin(), result.end(), triplet) == result.end()) {
                        result.push_back(triplet); // Avoid duplicates
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSumBruteforce(nums);

    for (auto &triplet : res) {
        for (int num : triplet) cout << num << " ";
        cout << endl;
    }
}
