def maxProfit(prices):
    # Edge case: empty list
    if not prices:
        return 0

    min_prices = prices[0]   # Track minimum buying price
    max_profit = 0            # Track maximum profit

    for current_price in prices:
        # Update minimum price if current price is lower
        if current_price < min_prices:
            min_prices = current_price
        # Calculate potential profit if selling today
        profit = current_price - min_prices
        # Update max_profit if this profit is higher
        max_profit = max(max_profit, profit)

    return max_profit

# Test cases
print(maxProfit([7,1,5,3,6,4]))  # Expected 5
print(maxProfit([7,6,4,3,1]))    # Expected 0
