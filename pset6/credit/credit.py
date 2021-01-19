from cs50 import get_string



def main():
    while True:
        card_number = get_string("Number: ")
        length = len(card_number)
        # if (length >= 13 and length <= 16) and
        if card_number.isdigit():
            break

    if checksum(card_number) != 0:
        print("INVALID")
    # amex = 15 starts with 34 or 37
    if length == 15 and (card_number[0] == "3" and (card_number[1] == "4" or card_number[1] == "7")):
        print("AMEX")

    # masta = 16 starts with 51 to 55
    elif length == 16 and (card_number[0] == "5"):
        print("MASTERCARD")

    # visa = 13 or 16 starts with 4
    elif length == 13 or length == 16 and (card_number[0] == "4"):
        print("VISA")

#taking number as a string
def checksum(number):
    results = 0
    digit = 0
    #reverse the number or string
    number = number[::-1]
    for i in range(len(number)):
        if i % 2 != 0:
            digit = int(number[i]) * 2
        else:
            digit = int(number[i])
        for num in str(digit):
            results += int(num)
    return results % 2

# taking number as an in
# def checksum1(number):
#     results = 0
#     digit = 0
#     while number > 0:
#         digit = number % 10




# if __name__ == "__name__":
main()

