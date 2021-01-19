import csv
from cs50 import get_string

with open("phonebook.csv", "a") as file:

    name = get_string("Name: ")
    number = get_string("Number: ")

    writer = csv.writer(file)
    writer.writerow([name, number])

# people = {
#     "Brian": "+1 505-506-007",
#     "David": "+1 505-506-008"
# }

# name = get_string("Name: ")
# if name in people:
#     number = people[name]
#     print(f"Number: {number}")

# for name in people:
#     print(f"Name: {name}")