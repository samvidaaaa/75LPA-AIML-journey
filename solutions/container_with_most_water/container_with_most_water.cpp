#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int max_area = 0;

    while (left < right) {
        int width = right - left;
        int current_height = min(height[left], height[right]);
        max_area = max(max_area, width * current_height);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return max_area;
}

int main() {
    vector<int> heights1 = {1,8,6,2,5,4,8,3,7};
    cout << "Max Area: " << maxArea(heights1) << endl;  // Expected: 49

    vector<int> heights2 = {1,1};
    cout << "Max Area: " << maxArea(heights2) << endl;  // Expected: 1

    return 0;
}
