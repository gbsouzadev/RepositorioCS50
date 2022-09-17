from cs50 import get_int
from cs50 import get_string

# Get cc number as string
strCc = get_string("Card number: ")

# Check if it's a valid number of digits
if len(strCc) not in range(13, 17):
    print("INVALID")
    exit()

# Convert cc number to integer
cc = int(strCc)

# Declare variables
res = 0

# 1st Luhn's step
tmp = cc // 10
while tmp > 0:
    digit = tmp % 10
    product = digit * 2
    res += (product % 10) + (product // 10)
    tmp //= 100

# 2nd Luhn's step
tmp = cc
while tmp > 0:
    digit = tmp % 10
    res += digit
    tmp //= 100

# 3th Luhn's step - Chack if last number == 0
lastDigit = res % 10
if lastDigit != 0:
    print("INVALID")

# Identify cc flag
elif strCc[0] == "3" and (strCc[1] == "4" or strCc[1] == "7"):
    print("AMEX")
elif strCc[0] == "5" and (strCc[1] >= "1" and strCc[1] <= "5"):
    print("MASTERCARD")
elif strCc[0] == "4":
    print("VISA")
else:
    print("INVALID")
