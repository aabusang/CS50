from cs50 import get_float

while True:
    change_owed = get_float("Change owed: ")
    if change_owed >= 0:
        break
coins_count = 0
change_owed = change_owed * 100
while change_owed >= 25:
    change_owed -= 25
    coins_count += 1
while change_owed >= 10:
    change_owed -= 10
    coins_count += 1
while change_owed >= 5:
    change_owed -= 5
    coins_count += 1
while round(change_owed) >= 1:
    change_owed -= 1
    coins_count += 1

print(coins_count)