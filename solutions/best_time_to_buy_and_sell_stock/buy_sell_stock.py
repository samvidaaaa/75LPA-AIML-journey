def maxProfit(prices):
    min_price = float('inf')
    max_profit = 0

    for price in prices:
        if price < min_price:
            min_price = price
        elif price - min_price > max_profit:
            max_profit = price - min_price

    return max_profit


# Test
print(maxProfit([7,1,5,3,6,4]))  # Expected 5
print(maxProfit([7,6,4,3,1]))    # Expected 0
