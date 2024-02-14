in_bound_dict=[]
out_bound_dict=[]
cost_dict=[]
number_of_vertices=0
number_of_edges=0

import random

class Graph_predecessor_getters:
    def __init__(self, vertice, predecessor):
        self.__vertice = vertice
        self.__predecessor = predecessor

    def set_predecessor(self, predecessor):
        self.__predecessor = predecessor

    def get_predecessor(self):
        return self.__predecessor

    def set_vertice(self, vertice):
        self.__vertice = vertice

    def get_vertice(self):
        return self.__vertice

    def __str__(self):
        return f'vertice = {self.__vertice}, predecessor = {self.__predecessor} '

class Graph_successor_getters:
    def __init__(self, vertice, successor):
        self.__vertice = vertice
        self.__successor = successor

    def set_successor(self, successor):
        self.__successor = successor

    def get_successor(self):
        return self.__successor

    def set_vertice(self, vertice):
        self.__vertice = vertice

    def get_vertice(self):
        return self.__vertice

    def __str__(self):
        return f' vertice ={self.__vertice}, successor = {self.__successor} '

class Graph_cost_getters:
    def __init__(self, edge, cost):
        self.__edge=edge
        self.__cost=cost
    
    def set_edge(self, edge):
        self.__edge=edge
    
    def get_edge(self):
        return self.__edge

    def set_cost(self, cost):
        self.__cost=cost

    def get_cost(self):
        return self.__cost
    
    def __str__(self):
        return f'edge={self.__edge}, cost={self.__cost}'

def write_text(info, nr_of_edges, nr_of_vertices):
    info=str(info)
    with open('input_file.txt', "w") as f:
        f.writelines(info)

def read_text_file():
    #f = open('input_file.txt', 'r')
    with open('input.txt', 'r') as f:
        number_of_vertices, number_of_edges = [int(x) for x in next(f).split()] # read first line
        graph.create_dictionarys(number_of_vertices)

    for line in f:
        array=[]
        array.append([int(x) for x in line.split()])
        graph.add_vertice(array[0])
        graph.add_edge(array[0], array[1], array[2])

def create_dictionarys(nr_of_vertices):
    for i in range(0, nr_of_vertices):
        predecessor={"vertice": i, "predecessor":[]}
        successor={"vertice":i, "successor":[]}
        in_bound_dict.append(predecessor)
        out_bound_dict.append(successor)

def is_vertice(x):
    for i in range(0, number_of_vertices):
        if x==Graph_predecessor_getters.get_vertice(in_bound_dict[i]):
            if x==Graph_successor_getters.get_vertice(in_bound_dict[i]):
                return True
    return False

def is_edge(u, v):
    if Graph_predecessor_getters.get_vertice(in_bound_dict[u])==v:
        if Graph_successor_getters.get_successor(out_bound_dict[v])==u:
            return True
    return False

def add_vertice(vertice):
    if is_vertice(vertice)==False:
        #nu.i bun asa vertice as a key osca
        predecessor=[]
        successor={"vertice":vertice, "successor":[]}
        in_bound_dict.append(predecessor)
        out_bound_dict.append(successor)
        number_of_vertices=number_of_vertices+1
    else:
        return

def remove_vertice(vertice):
    if is_vertice(vertice)==True:
        pass
        number_of_vertices=number_of_vertices-1
    else:
        return

def add_edge(vertice1, vertice2, cost):
    if is_edge(vertice1, vertice2)==False:
        array_of_vertices=Graph_predecessor_getters.get_predecessor(in_bound_dict[vertice1])
        array_of_vertices.append(vertice2)
        Graph_predecessor_getters.set_predecessor(in_bound_dict[vertice1], array_of_vertices)

        array_of_vertices=Graph_successor_getters.get_successor(out_bound_dict[vertice2])
        array_of_vertices.append(vertice1)
        Graph_successor_getters.set_successor(out_bound_dict, array_of_vertices)

        cost_and_edge={"edge":(vertice1, vertice2), "cost": cost}
        cost_dict.append(cost_and_edge)
        number_of_edges=number_of_edges+1
    else:
        pass

def remove_edge(predecessor_vertice, successor_vertice):
    if is_edge(predecessor_vertice, successor_vertice)==False:
        pass
        number_of_edges=number_of_edges-1
    else:
        pass

def in_degree(v):
    array_of_vertices=Graph_predecessor_getters.get_predecessor(in_bound_dict[v])
    print("In degree of vertice  ", v, " is", len(array_of_vertices))

def out_degree(v):
    array_of_vertices=Graph_predecessor_getters.get_predecessor(in_bound_dict[v])
    print("In degree of vertice  ", v, " is", len(array_of_vertices))

def parse_vertices_and_get_number():
    print("Set of vertices is:")
    for i in range (number_of_vertices):
        print(Graph_predecessor_getters.get_vertice(in_bound_dict))
        print("\n")
    print("number of vertices is:", number_of_vertices)

def parse_outbound_edges(v):
    print("Set of outbound edges is: ")
    for i in range(number_of_edges):
        print(out_bound_dict[i])
        print("\n")
    
def parse_inbound_edges(v):
    print("Set of inbound edges is: ")
    for i in range(number_of_edges):
        print(in_bound_dict[i])
        print("\n")

def endpoints_of_edge(edge):
    pass

def retrieve_cost_of_edge(vertice1, vertice2):
    for i in range(number_of_edges):
        if (vertice1, vertice2)==Graph_cost_getters.get_edge(cost_dict[i]):
            print(Graph_cost_getters.get_cost(cost_dict[i]))

def modify_cost_of_edge(vertice1, vertice2, new_cost):
    for i in range(number_of_edges):
        if (vertice1, vertice2)==Graph_cost_getters.get_edge(cost_dict[i]):
            Graph_cost_getters.set_cost(cost_dict[i], new_cost)

def copy_graph():
    pass

def create_random_graph():
    pass
        
class ui:    
    def print_options():
        print("Here are your options:")
        print("1. Read a graph from text file")
        print("2. Write a graph from text file")
        print("3. Add an edge")
        print("4. Remove an edge")
        print("5. Add a vertex")
        print("6. Remove a vertex")
        print("7. Parse the set of vertices and get the number of vertices")
        print("8. Find out whether there is an edge from a vertice to another")
        print("9. Get the in degree and the out degree of a vertex")
        print("10. Parse the set of outbound edges of a vertex")
        print("11. Parse the set of inbound edges of a vertex")
        print("12. Get the endpoints of an edge")
        print("13. Retrieve the cost of an edge")
        print("14. Modify the cost of an edge")
        print("15. Copy the graph")
        print("16. Create a random graph")
        print("17. Exit")

    def menu():
        while True:
            ui.print_options()
            print("Your option is:")
            option=int(input(">"))
            if option==1:
                read_text_file()
            elif option==2:
                write_text(info)
            elif option==3:
                #baga user input
                add_edge(predecessor_vertice, successor_vertice, cost)
            elif option==4:
                remove_edge(predecessor_vertice, successor_vertice)
            elif option==5:
                add_vertice(vertice)
            elif option==6:
                remove_vertice(vertice)
            elif option==7:
                parse_vertices_and_get_number()
            elif option==8:
                is_edge(u, v)
            elif option==9:
                in_degree(v)
                out_degree(v)
            elif option==10:
                parse_outbound_edges(v)
            elif option==11:
                parse_inbound_edges(v)
            elif option==12:
                endpoints_of_edge(edge)
            elif option==13:
                retrieve_cost_of_edge(edge)
            elif option==14:
                modify_cost_of_edge(edge)
            elif option==15:
                copy_graph()
            elif option==16:
                create_random_graph()
            elif option==17:
                break
            else:
                print("Invalid choice")


ui.menu()