class Book:
    def __init__(self, title, author, publisher=None):
        self.title = title
        self.author = author
        self.publisher = publisher

    def display(self):
        if self.publisher:
            print(f"{self.title} written by {self.author} is published by {self.publisher}")
        else:
            print("Unknown Publisher")

b1 = Book("Python Basics", "James", "ABC Publishers")
b2 = Book("Math Guide", "Ravi")

b1.display()
b2.display()
