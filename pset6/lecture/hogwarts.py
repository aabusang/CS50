from csv

houses = {
    "Gryffindor": 0,
    "Hufflepuff": 0,
    "Ravenclaw": 0,
    "Slytherin": 0
}

with open("csv file here", "r") as file:
    reader = reader.csv(file)
    next(reader)
    for row in reader:
        house = row[1]
        houses[house] += 1

for house in house:
    print(f"House: {house}: {houses[house]})
