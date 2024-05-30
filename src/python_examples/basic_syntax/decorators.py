# Decorators are a significant part of Python. 
# They allow programmers to modify the behavior of function or class. 
# Decorators allow us to wrap another function in order to extend the behavior of the wrapped function, 
# without permanently modifying it.

def f1(func):
    def wrapper():
        print("Start")
        func()
        print("End")
    
    return wrapper

@f1        
def f():
    print("Hello, world!")
    
f()
# Prints "Calling function f" and assigns "Hello, world!" to x
# x = f1(f)()


# Logging: Decorators can be used to add logging to functions to track when they are called and what they return. 
# This can be very useful for debugging and monitoring.
def log_decorator(func):
    def wrapper(*args, **kwargs):
        print(f"Calling function {func.__name__}")
        result = func(*args, **kwargs )
        print(f"{func.__name__} returned {result}")
        return result
    
    return wrapper

@log_decorator
def add(a,b):
    return a + b

add(1,2)

# Access control: Decorators can be used to restrict access to certain functions based on some condition, 
# like user roles in a web application.

class User:
    def __init__(self, * , username:str, is_admin:bool) -> None:
        self.username = username
        self.is_admin = is_admin

def admin_required(func):
    def wrapper(user, *args, **kwargs):
        if user.is_admin:
            return func(user, *args, **kwargs)
        else:
            raise PermissionError("Admin privileges required")
        
    return wrapper

@admin_required
def restricted_function(user: User):
    print(f"Access Grated, welcome back {user.username}!")
    
admin_user = User(username="Stefan", is_admin=True)
no_admin_user = User(username="Viktor", is_admin=False)
restricted_function(admin_user)