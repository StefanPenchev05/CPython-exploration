# This file demonstrates different ways of creating dictionaries in Python

a = dict(one=1, two=2, three=3)
b = {"one": 1, "two": 2, "three": 3}

print(a == b) # True

c = dict(zip(["one", "two", "three"], [1,2,3]))
print(a == b == c) # True

d = dict([('two', 2), ('one', 1), ('three', 3)])
print(a == b == c == d) # True
 