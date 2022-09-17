height = 0
while height not in range(1, 9):
    try:
        height = int(input("Height (1 to 8): "))
    except ValueError:
        print("That's not an integer!")
for row in range(1, height + 1, 1):
    for space in range(height - row):
        print(" ", end="")
    for hash in range(row):
        print("#", end="")
    print("  ", end="")
    for hash in range(row):
        print("#", end="")
    print("")
