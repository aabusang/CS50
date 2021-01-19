import csv

# schools = set()
schools = dict()

with open ("G-Accra-Schools - Sheet1.csv","r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        school = row["School"].strip().upper()
        if school not in schools:
            schools[school] = 0
        schools[school] += 1


for school in sorted(schools, key=lambda school: schools[school], reverse = True):
    print(school, schools[school])




        # if title in titles:
        #     titles[title] += 1
        # else:
        #     titles[title] = 1
# def f(title):
#     return titles[title]

# for title in sorted(titles, key=lambda title: titles[title], reverse = True):
#     print(title, title[title])