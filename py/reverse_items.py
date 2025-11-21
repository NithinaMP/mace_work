def reverse_items(lst):
    new_list = []
    for item in lst:
        new_list.append(item[::-1])
    return new_list

# Example
items = ["apple", "cat", "hello"]
print(reverse_items(items))
