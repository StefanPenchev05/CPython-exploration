import math

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
    
def matchState():
    http_error = int(input("Give error code for https: "))

    # The match statement is used to match the value of http_error against different patterns (in this case, different integers)
    match http_error:
        # If http_error is 400, this block of code is executed
        case 400:
            print("Bad Request")
        # If http_error is 401, 403, or 404, this block of code is executed
        case 401 | 403 | 404:
            print("Not allowed")
        # If http_error is 500, this block of code is executed
        case 500:
            print("Server Error")
        # The underscore (_) is a wildcard pattern that matches anything
        # If none of the above patterns match, this block of code is executed
        case _:
            print("Something's wrong with the internet")
            
    shapes = [
        {"type": "circle", "radius": 5},
        {"type": "rectangle", "width": 10, "height": 5},
        {"type": "square", "side": 7},
        {"type": "circle", "radius": 2},
        {"type": "square", "side": 4},
        {"type": "rectangle", "width": 2, "height": 3},
    ]

    for shape in shapes:
        match shape:
            case {"type": "circle", "radius": radius}:
                area = math.pi * radius ** 2
                print("The area of the circle is {0}".format(area))
            case {"type": "rectangle", "width": width, "height": height}:
                area = width * height
                print("The area of rectangle is {0}".format(area))
            case {"type": "square", "side": side}:
                area = side ** 2
                print("The area of square is {0}".format(area))
            case _:
                print("Unknown shape")
                    
def docString():
    """
        This is olny a test.
        Wow this is really cool.
        I have never seen something like this before
    """       
    pass

def greet(question_to_ask, name="Stefan", lastName="Penchev") -> str:
    """ This function greet some person with its name

    Args:
        question_to_ask (str, required): Question to ask the person after greeting
        name (str, optional): First name. Defaults to "Stefan".
        lastName (str, optional): Last Name. Defaults to "Penchev".
    Returns:
        str: "Hello {name} {lastName}\n{question_to_ask}" 
    """
    print("Hello {0} {1}!".format(name, lastName))
    match question_to_ask.lower():
        case "how are you":
            return "Good, thanks for asking!"
        case "what's up":
            return "Not much, just working!"
        case "what are you doing":
            return "I'm helping people learn Python!"
        case _:
            return "I'm not sure how to respond to that."
    
def cheeseshop(kind, *arguments, **keywords):
    print("-- Do you have any", kind, "?")
    print("-- I'm sorry, we're all out of", kind)
    for argument in arguments:
        print(f"Argument: {argument}")
    for keyword in keywords:
        print(f"{keyword} : {keywords[keyword]}")

#ifClause()
#rangeCommand()
#forClause()
#matchState()
#print(docString.__doc__)

# Showing the memory address of the function
print(docString)

# Return type is None
print(docString())

# Return type is Str
print(greet("what are you doing"))

cheeseshop("Random", "It's really very, VERY runny, sir.",
           shopkeeper="Michael Palin",
           client="John Cleese",
           sketch="Cheese Shop Sketch")