# Get valid input
while True:
    try:
        change = float(input("Owed change: ")) * 100
        if change >= 0:
            break
    except ValueError:
        print("That's not a float!")

# Declare coins counter and available coin in till
coins = 0
till = [25, 10, 5, 1]

# For each coin in till
for coin in till:

    # If actual coin is able to subtract from change, do it and itarate coins counter
    while coin <= change:
        change -= coin
        coins += 1
print(coins)