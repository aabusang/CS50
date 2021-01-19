from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break
for i in range(height):
    for j in range(1, height - i):
        print(" ", end = "")
    for k in range(i + 1):
        print("#", end = "")
    for l in range(2):
        print(" ", end = "")
    for m in range(i + 1):
        print("#", end = "")

    print("")