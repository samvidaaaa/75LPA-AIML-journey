#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices)
{
    int maxProfit = 0;
    int minPrice = INT_MAX;
    
    for(int price : prices)
    {
        if(price < minPrice)
        {
            minPrice = price;
        }
        int profit = price - minPrice;
        maxProfit = max(maxProfit, profit);
    }
    return maxProfit;
}

int main()
{
    vector<int> prices = {1, 2, 3, 4, 5};
    int result  = maxProfit(prices);
    cout << "Max profit is " << result;

    return 0;
}
