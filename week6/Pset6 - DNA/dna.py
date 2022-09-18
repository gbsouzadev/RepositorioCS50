import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py filename.csv filename.txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    csvfile = open(sys.argv[1], "r")
    reader = csv.DictReader(csvfile)
    subsequences = reader.fieldnames[1:]

    # TODO: Read DNA sequence file into a variable
    sequence = open(sys.argv[2], "r").read()

    # TODO: Find longest match of each STR in DNA sequence
    strs_count = dict()
    for str in subsequences:
        strs_count[str] = longest_match(sequence, str)

    # TODO: Check database for matching profiles
    for row in reader:
        name = row["name"]
        count = 0
        for str in subsequences:
            if strs_count[str] != int(row[str]):
                break
            elif strs_count[str] == int(row[str]):
                count += 1
        if count == len(subsequences):
            print(f"{name}")
            csvfile.close()
            sys.exit(0)
    csvfile.close()
    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


if __name__ == '__main__':
    main()
