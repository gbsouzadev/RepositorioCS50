# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file

    # Declare a variable to store sys.argv[1]
    filename = sys.argv[1]

    # Open CSV file
    with open(filename, "r") as file:

        # Convert each row of the file into a dict()
        reader = csv.DictReader(file)

        # Loop through each row in file
        for team in reader:

            # Convert the rating string into an int
            team["rating"] = int(team["rating"])

            # Stick the actual dict(team = "x", rating = n) into [teams]
            teams.append(team)

    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    for i in range(N):
        team_name = simulate_tournament(teams)
        if team_name in counts:
            counts[team_name] += 1
        else:
            counts[team_name] = 1

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO

    # Loop ultil only 1 team left
    while len(teams) > 1:

        # teams gets the winner of the round
        teams = simulate_round(teams)

    # After all rounds, return the last team, which happens to be the winner
    return teams[0]["team"]


if __name__ == "__main__":
    main()
