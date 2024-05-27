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

## List variable
my_list = [1,2,3,7,9]
print(f"List: {my_list}")

# Concatenation of lists
my_conc_list = [4,5,9,10]
my_list + my_conc_list
print(f"The concated list: {my_list}")

# Copying (shallow copy) the id of the list
rgb = ["Red", "Green", "Blue"]
rgba = rgb

# The id() function returns the identity of an object. This identity is unique and constant for this object during its lifetime.
# Here we're checking if the id of rgb is the same as the id of rgba. Since rgba is a shallow copy of rgb, they point to the same object, hence have the same id.
print(id(rgb) == id(rgba))

# Dictionary variable
my_dic = {"name" : "Stefan", "lastName" : "Penchev", "age": 30}

# Print the name from the dictionary
print(f"Name: {my_dic['name']}")

# Print the last name from the dictionary
print(f"Last Name: {my_dic['lastName']}")

# Print the age from the dictionary
print(f"Age: {my_dic['age']}")

# Add a new key-value pair to the dictionary
my_dic['profession'] = 'Software Engineer'
print(f"Profession: {my_dic['profession']}")

# Remove a key-value pair from the dictionary
del my_dic['age']
print(f"Dictionary after removing age: {my_dic}")

# Check if a key exists in the dictionary
if 'name' in my_dic:
    print(f"Name exists in the dictionary: {my_dic['name']}")

# Get the length of the dictionary
print(f"Number of key-value pairs in the dictionary: {len(my_dic)}")

# Print all keys in the dictionary
print(f"Keys in the dictionary: {my_dic.keys()}")

# Print all values in the dictionary
print(f"Values in the dictionary: {my_dic.values()}")

# Tuples are immutable, so they cannot be changed
my_tuple = (1,"stefan", 3.7)
print(my_tuple)

#Change the tuple variables
y = list(my_tuple)
y[0] = y[len(my_tuple) - 1]
my_tuple = tuple(y)
print(my_tuple)


