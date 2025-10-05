def maxProfit(prices):
    if len(prices) < 2:
        return 0

    profit = 0
    for i in range(1, len(prices)):
        diff = prices[i] - prices[i-1]
        if diff > 0:
            profit += diff
    return profit

# Test
print(maxProfit([7,1,5,3,6,4]))  # Expected output: 7
