def ifClause():
    # user input - input
    # convert str into int 
    x = int(input("Please enter some random number from 0 to 3: "))

    #if clause
    if x < 0:
        print(f"Negative {x} changed to 0")
        x = 0
    elif x == 1:
        print(f"Number {x}")
    elif x == 2:
        print(f"Number {x}")
    elif x == 3:
        print(f"Number {x}")
    else:
        print("Undefined")
    
def rangeCommand():
    # Create a list of numbers from 0 to 9 using the range() function
    my_list = list(range(0,10))
    # Print the list
    print(my_list)
    # Check if the number 4 is in the list and print the result
    print(4 in my_list)
    
    # Create a list of numbers from 5 to 15, stepping by 3, using the range() function
    my_list = list(range(5,15,3))
    # Print the new list
    print(my_list)

def forClause():
    # for clause
    words = ["Cat", "apple", "watermalen"]
    for word in words:
        print(f"{word} {len(word)}") 
    
    # Initialize a dictionary with user names as keys and their status as values
    users = {'Hans': 'active', 'Éléonore': 'inactive', '景太郎': 'active'}

    # Iterate over a copy of the dictionary. This is necessary because we can't modify a dictionary while iterating over it.
    for user, status in users.copy().items():
        # If the user's status is 'inactive', remove them from the original dictionary
        if status == "inactive":
            del users[user]
            
    print(users)
    
    # Initialize a dictionary with product names as keys and their quantities as values
    products = {
        'Apples': 5,
        'Bananas': 0,
        'Oranges': 3,
        'Pears': 0,
        'Grapes': 2
    }

    # Iterate over a copy of the dictionary. This is necessary because we can't modify a dictionary while iterating over it.
    for product, quantity in products.copy().items():
        # If the product's quantity is 0 or less, remove it from the original dictionary
        if quantity <= 0:
            del products[product]
    print(products)
    
    # Iterate over a range of numbers from 0 to 10 (inclusive)
    for i in range(0,11):
        print(i)
        
    # Initialize a list of words
    a = ['Mary', 'had', 'a', 'little', 'lamb']

    # Iterate over the length of the list
    for i in range(len(a)):
        print(f"{i} : {a[i]}")

    # Initialize a list of seasons
    seasons = ['Spring', 'Summer', 'Fall', 'Winter']

    # Print the list of seasons with their corresponding indices using the enumerate() function
    print(list(enumerate(seasons)))
    

#ifClause()
#rangeCommand()
forClause()