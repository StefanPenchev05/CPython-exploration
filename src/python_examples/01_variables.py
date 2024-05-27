#Integer variable
my_int = 10
print(f"Integer: {my_int}")

# Float variable
my_float = 3.14
print(f"Float: {my_float}")

# String variable
my_string = "Hello, World!"
print(f"String: {my_string}")

# Boolean variable
my_bool = True
print(f"Boolean: {my_bool}")

#List variable
my_list = [1,2,3,7,9]
print(f"List: {my_list}")

# concatenation of lists
my_conc_list = [4,5,9,10]
my_list + my_conc_list
print(f"The concated list: {my_list}")

# copying(shalow copy) the id of the list
rgb = ["Red", "Green", "Blue"]
rgba = rgb
print(id(rgb) == id(rgba))