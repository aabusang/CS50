from cs50 import get_string

name = get_string("What is your name? ")
print(">>>Using get_string<<<")
print("Hello, " + name)
print(f"Hello, {name}")
print(">>>Using input<<<")
name = input("What is your full name? ")
print("You full name is " + name)