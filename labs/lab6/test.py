import sys
import csv

if len(sys.argv) != 2:
    print("Usage: python filename command-line argument")
    sys.exit(1)

with open(sys.argv[1], "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        print({row["team"], row["rating"]})