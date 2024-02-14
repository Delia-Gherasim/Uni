
"""
Write an application for a book library. The application will store:

Book: book_id, title, author
Client: client_id, name
Rental: rental_id, book_id, client_id, rented_date, returned_date
Create an application to:

Manage clients and books. The user can add, remove, update, and list both clients and books.
Rent or return a book. A client can rent an available book. A client can return a rented book at any time. Only available books (those which are not currently rented) can be rented.
Search for clients or books using any one of their fields (e.g. books can be searched for using id, title or author). The search must work using case-insensitive, partial string matching, and must return all matching items.
Create statistics:
Most rented books. This will provide the list of books, sorted in descending order of the number of times they were rented.
Most active clients. This will provide the list of clients, sorted in descending order of the number of book rental days they have (e.g. having 2 rented books for 3 days each counts as 2 x 3 = 6 days).
Most rented author. This provides the list of book authors, sorted in descending order of the number of rentals their books have.
"""

from rep_books import rep_books
from rep_clients import rep_clients
from rep_rent import rep_rent
from ui import UI


ui=UI( rep_books(), rep_clients(), rep_rent())
ui.start()

