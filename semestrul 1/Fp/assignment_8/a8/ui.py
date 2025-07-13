from services import service

class UI:
    def __init__(self, all_books, all_clients, all_rent):
        self.all_books = all_books
        self.all_clients=all_clients
        self.all_rent=all_rent
        #self.history = [service]

    def ui_add(self):
        print("What do you want to add?")
        print("1. client")
        print("2. book")
        print("3. actually, go back")
        opt=int(input(">"))
        if opt==1:
            id = input("Input the id ")
            try:
                id = int(id)
            except ValueError:
                print("Invalid ID ")
                return
            name = input("Input the name ")
            client={"id": id, "name":name}
            Service=service(self.all_clients)
            Service.add_client(client)
        elif opt==2:
            id = input("Input the id ")
            try:
                id = int(id)
            except ValueError:
                print("Invalid ID ")
                return
            title = input("Input the title ")
            author = input("Input the author ")
            book={"id": id, "title":title, "author":author}
            Service=service(self.all_books)
            Service.add_book(book)
        elif opt==3:
            return
        else:
            print("invalid input")
            return

    def ui_update(self):
        print("What do you want to update?")
        print("1. client")
        print("2. book")
        print("3. actually, go back")
        opt=int(input(">"))
        if opt==1:
            old=service.search()
            id = input("Input the id ")
            try:
                id = int(id)
            except ValueError:
                print("Invalid ID ")
                return
            name = input("Input the name ")
            client={"id": id, "name":name}
            self.all_clients.service.update_client(old, new)
            self.all_rent.service.update_rent(old, new)
        elif opt==2:
            old=service.search()
            id = input("Input the id ")
            try:
                id = int(id)
            except ValueError:
                print("Invalid ID ")
                return
            title = input("Input the title ")
            author = input("Input the author ")
            book={"id": id, "title":title, "author":author}
            self.all_books.service.update_book(old, new)
            self.all_rent.service.update_rent(old, new)
        elif opt==3:
            return
        else:
            print("invalid input")
            return

    def ui_remove(self):
        print("What do you want to update?")
        print("1. client")
        print("2. book")
        print("3. actually, go back")
        opt=int(input(">"))
        if opt==1:
            id = input("Input the id ")
            try:
                id = int(id)
            except ValueError:
                print("Invalid ID ")
                return
            self.all_clients.service.remove_client(id)
            self.all_rent.service.remove_rent_client(id)
        elif opt==2:
            id = input("Input the id ")
            try:
                id = int(id)
            except ValueError:
                print("Invalid ID ")
                return
            self.all_books.service.remove_book(id)
            self.all_rent.service.remove_rent_book(id)
        elif opt==3:
            return
        else:
            print("invalid input")
            return

    def ui_list(self):
        print("What do you want to list?")
        print("1. client")
        print("2. book")
        print("3. rentals")
        print("4. actually, go back")
        opt=int(input(">"))
        if opt==1:
            for i in range (len(self.all_clients)):
                print(i)
                print("\n")
        elif opt==2:
            for i in range (len(self.all_books)):
                print(i)
                print("\n")
        elif opt==3:
            for i in range (len(self.all_rent)):
                print(i)
                print("\n")
        elif opt==4:
            return
        else:
            print("invalid input")
            return

    def ui_most_book(self):
        print(self.all_rent.service.max())
    
    def ui_most_active(self):
        print(self.all_rent.service.max())
    
    def ui_most_author(self):
        print(self.all_rent.service.max())

    def run_console(self):
        while True:
            print("Manage clients and books")
            print("Option 1: Add ")
            print("Option 2: Update")
            print("Option 3: Remove")
            print("Option 4: List")
            print("Option 5: Most rented books")
            print("Option 6: Most active clients")
            print("Option 7: Most rented author")
            print("Option 8: Exit")
            option = int(input("Please enter your choice: "))
            #self.service = deepcopy(self.history[-1])
            if option == 1:
                self.ui_add()
            elif option == 2:
                self.ui_update()
            elif option == 3:
                self.ui_remove()
            elif option == 4:
                self.ui_list()
            elif option == 5:
                self.ui_most_book()
            elif option == 6:
                self.ui_most_active()
            elif option == 7:
                self.ui_most_author()
            elif option == 8:
                exit()
            else:
                print("Invalid choice ")



    def start(self):
        self.run_console()