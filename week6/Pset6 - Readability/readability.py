# Declare starting variables
letters = 0
words = 1
sentences = 0

# Get input from user
text = input("Text: ")

# Loop through the input
for char in text:
    # Check and update letters
    if char.isalpha():
        letters += 1
    # Check and update words
    elif char == " ":
        words += 1
    # Check and update sentences
    elif char == "." or char == "!" or char == "?":
        sentences += 1

# Apply Coleman-Liau formula
L = letters / words * 100
S = sentences / words * 100
index = round(0.0588 * L - 0.296 * S - 15.8)

if index > 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")