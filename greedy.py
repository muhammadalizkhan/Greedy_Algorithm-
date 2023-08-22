def coin_change_greedy(coins, target_amount):
    coins.sort(reverse=True)  # Sort the coin denominations in descending order
    num_coins = 0
    remaining_amount = target_amount

    for coin in coins:
        num_coins += remaining_amount // coin  # Add the maximum number of this coin
        remaining_amount %= coin  # Update the remaining amount

    return num_coins

# Example usage
coin_denominations = [25, 10, 5, 1]
amount = 63
min_coins = coin_change_greedy(coin_denominations, amount)
print(f"Minimum number of coins needed for {amount} cents: {min_coins}")
