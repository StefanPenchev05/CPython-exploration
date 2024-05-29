import math

#To loop over a sequence in sorted order, 
# use the sorted() function which returns a new sorted list while leaving the source unaltered.
basket = ['apple', 'orange', 'apple', 'pear', 'orange', 'banana']

for i in sorted(basket):
    print(i, end=' ')
    
print()
#Using set() on a sequence eliminates duplicate elements. 
# The use of sorted() in combination with set() over a sequence is an idiomatic 
# way to loop over unique elements of the sequence in sorted order.

for f in sorted(set(basket)):
    print(f, end=' ')
    
# It is sometimes tempting to change a list while you are looping over it; 
# however, it is often simpler and safer to create a new list instead.

print()

raw_data = [56.2, float('NaN'), 51.7, 55.3, 52.5, float('NaN'), 47.8]
filtered_data = []
for value in raw_data:
    if not math.isnan(value):
        filtered_data.append(value)
    
print(filtered_data)