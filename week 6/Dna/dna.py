import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    database = []
    with open(sys.argv[1], newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            database.append(row)

            # Get the list of STRs from the first row
    strs = list(database[0].keys())[1:]

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as file:
        dna_sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    str_counts = {}
    for s in strs:
        str_counts[s] = longest_match(dna_sequence, s)

    # TODO: Check database for matching profiles
    for person in database:
        match = True
        for s in strs:
            if int(person[s]) != str_counts[s]:
                match = False
                break
        if match:
