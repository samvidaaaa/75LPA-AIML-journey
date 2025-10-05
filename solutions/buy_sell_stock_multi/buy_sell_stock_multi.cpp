#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) 
        return 0;

    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        int diff = prices[i] - prices[i - 1];
        if (diff > 0)
            profit += diff;
    }
    return profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit is: " << maxProfit(prices) << endl; // Expected: 7
    return 0;
}
