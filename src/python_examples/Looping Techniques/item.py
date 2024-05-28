import random
import string

# Function to generate a random string of a given length
def random_string(length):
    # Define the characters that can be used in the string
    letters = string.ascii_letters
    # Use a list comprehension to generate a list of random letters, then join them into a string
    return ''.join(random.choice(letters) for i in range(length))

# Function to generate a dictionary with random string keys and random integer values
def random_dict(size):
    # Use a dictionary comprehension to generate a dictionary with random keys and values
    return {random_string(6) : random.randint(1,100) for i in range(size)}

# Generate a random dictionary with 8 items
my_dict = random_dict(8)

# Use the items() method to iterate over the dictionary
# The items() method returns a view object that displays a list of a dictionary's key-value tuple pairs
for k, v in my_dict.items():
    print("Key: {0}, Value: {1}".format(k,v))