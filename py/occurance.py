def search_item(lst,item):
    count=lst.count(item)
    return count

element=input("Enter a list of elements seperated by space:").split()
search_el=input("Enter the element to search for:")
occurance=search_item(element,search_el)
print(f"The item {search_el} occures {occurance} times in the list")
