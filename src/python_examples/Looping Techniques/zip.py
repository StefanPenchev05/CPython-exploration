# Initialize a list of names
names = ["John", "Emma", "Kelly", "Jason"]

# Initialize a list of scores corresponding to each name
scores = [85, 92, 90, 88]

# Use the zip() function to combine the names and scores lists into a single iterable
# The zip() function returns a zip object, which is an iterator of tuples where the first item in each passed iterator is paired together, 
# and then the second item in each passed iterator are paired together etc.
# If the passed iterators have different lengths, the iterator with the least items decides the length of the new iterator.
for name, score in zip(names, scores):
    # Print each name with its corresponding score
    print("Person {0} with score {1}".format(name, score))
    
#Suppose you are working with data related to a group of students. 
# You have their names, the subjects they are studying, and their respective grades. 
# All of this data is in separate lists and you want to combine them for better data handling.


students = ["John", "Emma", "Kelly", "Jason"]

subjects = ["Math", "Science", "English", "History"]

grades = [85, 92, 90, 88]

# Use the zip() function to combine the students, subjects, and grades lists into a single iterable
for student, subject, grade in zip(students, subjects, grades):
    print("Studnet {0} is studying {1} and the grade is {2}".format(student, subject, grade))
    
# You have three lists: products representing the names of products, prices representing the price of each product, 
# and quantities representing the quantity of each product in stock. 
# Your task is to print each product with its corresponding price and quantity,
# and also calculate and print the total value of all products in stock.

products = ["Apples", "Bananas", "Oranges", "Pears", "Grapes"]
prices = [1.5, 0.5, 0.75, 1.25, 2.0]
quantities = [100, 200, 150, 120, 80]

total_price = [0]
for product, price, quntity in zip(products, prices, quantities):
    print("Product {0} its price {1} and quality {2}".format(product, price, quntity))
    total_price[0] += price
    
print("Total price is {0}".format(total_price[0]))