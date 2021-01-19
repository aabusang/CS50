from cs50 import get_int

print(">>>Using get_int<<<")
x = get_int("x: ")
y = get_int("y: ")
print(x + y)
print(">>>Using input<<<")
a = input("a: ")
b = input("a: ")
print(a + b)
print(">>>Using input and casting to int<<<")
c = int(input("c: "))
d = int(input("d: "))
print(c + d)