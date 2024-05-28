#Suppose you have a list of students and their scores in a test. 
# You want to find out the rank of each student based on their score.

students = [("John", 85), ("Emma", 92), ("Kelly", 90), ("Jason", 88), ("Liam", 92)]

# Sort the list in descending order based on the scores
students.sort(key= lambda x: x[1], reverse=True)

# Use the enumerate() function to loop over the sorted list and print the rank of each student
for i, (name, grade) in enumerate(students):
    print("Rank {0}: Name {1} with a score of {2}".format(i, name, grade))
    
#You have a list of products and their prices. 
# Your task is to print each product with its corresponding index and price, 
# and also calculate and print the total price of all products.

products = [("Apples", 1.5), ("Bananas", 0.5), ("Oranges", 0.75), ("Pears", 1.25), ("Grapes", 2.0)]

total_price = [0]
for i, (product, price) in enumerate(products, start=1):
    print("Index of product {0}\tProduct: {1}\tPrice: {2}".format(i, product, price))
    total_price[0] += price
    
print("Total price: {0}".format(total_price[0]))