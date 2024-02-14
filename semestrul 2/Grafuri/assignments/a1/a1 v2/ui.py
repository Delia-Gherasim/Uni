from asyncio.windows_events import NULL
from xml.dom.expatbuilder import ElementInfo
from graphs2 import *
import random

"""

"""
class UI:
    def __init__(self, n, m):
        service = Graph(n, m)
        self.__graph = service
        self.__n=n  #n-number of vertices
        self.__m=m  #m-number of edges

    def printMenu(self):
        print("Here are your options:")
        print(" 0. EXIT")
        print(" 1. Add an vertex")
        print(" 2. Remove a vertex")
        print(" 3. Add an edge")
        print(" 4. Remove an edge")
        print(" 5. Get the number of vertices  ")
        print(" 6. Display the set of vertices")
        print(" 7. Verify if there is an edge between two vertices")
        print(" 8. Get the in degree of a specified vertex")
        print(" 9. Get the out degree of a specified vertex")
        print("10. Parse the set of outbound edges of a specified vertex")
        print("11. Parse the set of inbound edges of a specified vertex")
        print("12. Get the cost of an edge")
        print("13. Modify the cost of an edge")
        print("14. Read the graph from a text file ")
        print("15. Write the graph to a text file")
        print("16. Create a random graph with specified number of vertices and of edges")
        print("17. ASSIGNMENT 2: given a directed graph and two vertices, find a lowest length path between them, by using a backward breadth-first search from the ending vertex")
        print("18. ASSIGNMENT 3: Find a lowest cost walk between the given vertices, using Ford's algorithm( or prints a message if there are negative cost cycles accessible from the starting vertex)")
        print("19. ASSIGNMENT 4: Write a program that, given a list of activities with duration and list of prerequisites for each activity, does the following:")
        print("a. verify if the corresponding graph is a DAG and performs a topological sorting of the activities using the algorithm based on predecessor counters;")
        print("b. prints the earliest and the latest starting time for each activity and the total time of the project.")
        print("c. prints the critical activities.")
        print("\n")

    def addVertex(self):
        vertex = input("Enter the vertex:  ")
        try:
            vertex=int(vertex)
        except ValueError as ve:
            print("Invalid input ")
        while vertex<0:
            print("This is not a valid vertex")
            vertex = input("Enter the vertex: ")
            try:
                vertex=int(vertex)
            except ValueError as ve:
                print("Invalid input ")

        if self.__graph.add_vertex(vertex)==1:
            print("Vertex was added")
            self.__n=self.__n+1
        else:
            print("Vertex already exists")
        print("\n")

    def removeVertex(self):
        vertex = input("What vertex do you want to remove? ")
        try:
            vertex=int(vertex)
        except ValueError as ve:
            print("Invalid input ")
        while vertex<0:
            print("This is not a valid vertex")
            vertex = input("What vertex do you want to remove? ")
            try:
                vertex=int(vertex)
            except ValueError as ve:
                print("Invalid input ")

        if self.__graph.remove_vertex(vertex):
            print("Vertex was removed")
            self.__n=self.__n-1
        else:
            print("Vertex does not exist ")
        print("\n")

    def addEdge(self):
        vertex_1 = input("first vertex: ")
        try:
            vertex_1=int(vertex_1)
        except ValueError as ve:
            print("Invalid input ")
        while vertex_1<0:
            print("This is not a valid vertex")
            vertex_1 = input("first vertex: ")
            try:
                vertex_1=int(vertex_1)
            except ValueError as ve:
                print("Invalid input ")

        vertex_2 = input("second vertex: ")
        try:
            vertex_2=int(vertex_2)
        except ValueError as ve:
            print("Invalid input ")
        while vertex_2<0:
            print("This is not a valid vertex")
            vertex_2 = input("second vertex: ")
            try:
                vertex_2=int(vertex_2)
            except ValueError as ve:
                print("Invalid input ")
        cost = int(input("Enter the cost of this edge  "))


        if self.__graph.add_edge(vertex_1, vertex_2, cost)==1:
            print("Edge was added")
            self.__m=self.__m+1
        elif self.__graph.add_edge(vertex_1, vertex_2, cost)==-1:
            print("This edge already exists")
        elif self.__graph.add_edge(vertex_1, vertex_2, cost)== -2:
            print("One or both of of the vertices you entered do not exist")
        print("\n")

    def removeEdge(self):
        vertex_1 = input("first vertex: ")
        try:
            vertex_1=int(vertex_1)
        except ValueError as ve:
            print("Invalid input ")
        while vertex_1<0:
            print("This is not a valid vertex")
            vertex_1 = input("first vertex: ")
            try:
                vertex_1=int(vertex_1)
            except ValueError as ve:
                print("Invalid input ")

        vertex_2 = input("second vertex: ")
        try:
            vertex_2=int(vertex_2)
        except ValueError as ve:
            print("Invalid input ")
        while vertex_2<0:
            print("This is not a valid vertex")
            vertex_2 = input("second vertex: ")
            try:
                vertex_2=int(vertex_2)
            except ValueError as ve:
                print("Invalid input ")
        
        if self.__graph.remove_edge(vertex_1, vertex_2):
            print("Edge was removed ")
            self.__m=self.__m-1
        else:
            print("Edge doesn't exist ")
        print("\n")

    def getNumberOfVertices(self):
        print("The number of vertices is: ", self.__graph.get_number_of_vertices())
        print("\n")

    def printVertices(self):
        print("The vertices are ", self.__graph.get_vertices())
        print("\n")

    def isedge(self):
        vertex_1 = input("first vertex: ")
        try:
            vertex_1=int(vertex_1)
        except ValueError as ve:
            print("Invalid input ")
        while vertex_1<0:
            print("This is not a valid vertex")
            vertex_1 = input("first vertex: ")
            try:
                vertex_1=int(vertex_1)
            except ValueError as ve:
                print("Invalid input ")

        vertex_2 = input("second vertex: ")
        try:
            vertex_2=int(vertex_2)
        except ValueError as ve:
            print("Invalid input ")
        while vertex_2<0:
            print("This is not a valid vertex")
            vertex_2 = input("second vertex: ")
            try:
                vertex_2=int(vertex_2)
            except ValueError as ve:
                print("Invalid input ")


        if self.__graph.is_edge(vertex_1, vertex_2):
            print("These two vertices construct an edge with the cost of ", self.__graph.get_edge_cost(vertex_1, vertex_2))
        else:
            print("These two vertices do not construct an edge")
        print("\n")

    def getInDegreeOfVertex(self):
        vertex = input("Enter the vertex you want to see the in degree for: ")
        try:
            vertex=int(vertex)
        except ValueError as ve:
            print("Invalid input ")
        while vertex<0:
            print("This is not a valid vertex")
            vertex = input("Enter the vertex you want to see the in degree for:  ")
            try:
                vertex=int(vertex)
            except ValueError as ve:
                print("Invalid input ")

        in_degree, predecessor_vertices = self.__graph.service_in_degree(vertex)
        print("The in degree is : ", in_degree)
        print("The predecessor vertices that construct these edges are : ", predecessor_vertices)
        print("\n")

    def getOutDegreeOfVertex(self):
        vertex = input("Enter the vertex you want to see the out degree for: ")
        try:
            vertex=int(vertex)
        except ValueError as ve:
            print("Invalid input ")
        while vertex<0:
            print("This is not a valid vertex")
            vertex = input("Enter the vertex you want to see the out degree for:  ")
            try:
                vertex=int(vertex)
            except ValueError as ve:
                print("Invalid input ")

        out_degree, successor_vertices = self.__graph.service_out_degree(vertex)
        print("the out degree is : ", out_degree)
        print("the successor vertices that construct these edges are : ", successor_vertices)
        print("\n")

    def getOutboundEdgesOfAVertex(self):
        vertex = input("Enter the vertex you want to see the outbound edges for: ")
        try:
            vertex=int(vertex)
        except ValueError as ve:
            print("Invalid input ")
        while vertex<0:
            print("This is not a valid vertex")
            vertex = input("Enter the vertex you want to see the outbound edges for:  ")
            try:
                vertex=int(vertex)
            except ValueError as ve:
                print("Invalid input ")

        successors = self.__graph.service_outbound_edges(vertex)
        if successors:
            print("the outbound edges of this vertex are: ")
            for successor_vertex in successors:
                print("edge ", vertex, "->", successor_vertex)
        else:
            print("this vertex does not have any edges associated with it.")
        print("\n")

    def getINboundEdgesOfAVertex(self):
        vertex = input("Enter the vertex you want to see the inbound edges for: ")
        try:
            vertex=int(vertex)
        except ValueError as ve:
            print("Invalid input ")
        while vertex<0:
            print("This is not a valid vertex")
            vertex = input("Enter the vertex you want to see the inbound edges for:  ")
            try:
                vertex=int(vertex)
            except ValueError as ve:
                print("Invalid input ")
       
        predecessors = self.__graph.service_inbound_edges(vertex)
        if predecessors:
            print("the inbound edges of this vertex are: ")
            for predecessor_vertex in predecessors:
                print("edge ", vertex, "<-", predecessor_vertex)
        else:
            print("this vertex does not have any edges associated with it.")
        print("\n")

    def costOfEdge(self):
        print("Enter the vertices of your edge ")
        vertex_1 = input("first vertex: ")
        try:
            vertex_1=int(vertex_1)
        except ValueError as ve:
            print("Invalid input ")
        while vertex_1<0:
            print("This is not a valid vertex")
            vertex_1 = input("first vertex: ")
            try:
                vertex_1=int(vertex_1)
            except ValueError as ve:
                print("Invalid input ")

        vertex_2 = input("second vertex: ")
        try:
            vertex_2=int(vertex_2)
        except ValueError as ve:
            print("Invalid input ")
        while vertex_2<0:
            print("This is not a valid vertex")
            vertex_2 = input("second vertex: ")
            try:
                vertex_2=int(vertex_2)
            except ValueError as ve:
                print("Invalid input ")
        
        if self.__graph.get_edge_cost(vertex_1, vertex_2) != -1:
            print("the cost of this edge is", self.__graph.get_edge_cost(vertex_1, vertex_2))
        else:
            print("this edge does not have a cost")
        print("\n")

    def changeCostOfEdge(self):
        print("Enter the vertices of your edge")
        vertex_1 = input("first vertex: ")
        try:
            vertex_1=int(vertex_1)
        except ValueError as ve:
            print("Invalid input ")
        while vertex_1<0:
            print("This is not a valid vertex")
            vertex_1 = input("first vertex: ")
            try:
                vertex_1=int(vertex_1)
            except ValueError as ve:
                print("Invalid input ")

        vertex_2 = input("second vertex: ")
        try:
            vertex_2=int(vertex_2)
        except ValueError as ve:
            print("Invalid input ")
        while vertex_2<0:
            print("This is not a valid vertex")
            vertex_2 = input("second vertex: ")
            try:
                vertex_2=int(vertex_2)
            except ValueError as ve:
                print("Invalid input ")
       
        new_cost=NULL
        while new_cost==NULL:
            new_cost = input("enter the new cost of this edge: ")
            try: 
                new_cost=int(new_cost)
            except ValueError:
                print("Invalid input")

        if self.__graph.service_change_cost_of_edge(vertex_1, vertex_2, new_cost) != -1:
            print("The cost was updated")
        print("\n")

    def readFromFile(self):
        file=input("Name of the input file: ")
        file = open(file, "r")
        self.__n, self.__m = map(int, file.readline().split())
        grapf = Graph(self.__n, self.__m)
        self.__graph = grapf
        for _ in range(self.__m):
            vertex1, vertex2, edge_cost = map(int, file.readline().split())
            self.__graph.add_edge(vertex1, vertex2, edge_cost)
        file.close()
        print("The new graph has ", self.__n, " vertices and " , self.__m, " edges ")
        print("\n")

    def writeToFile(self):
        file=input("Name of the file where you want the graphs saved: ")
        with open(file, "w") as f:
            f.write(str(self.__n))
            f.writelines(" ")
            f.writelines(str(self.__m))
       
        with open(file, "a") as f:
            for i in self.__graph.get_list_of_costs():
                f.writelines("\n")
                vertex1, vertex2=int(i[0]), int(i[1])
                f.writelines(str(vertex1))
                f.writelines(" ")
                f.writelines(str(vertex2))
                f.writelines(" ")
                f.writelines(str(self.__graph.get_edge_cost(vertex1, vertex2)))

        print("File updated")


    def generateRandomGraph(self):
        
        self.__n=input("How many vertices does the graph have? ")
        try:
            self.__n=int(self.__n)
        except ValueError as ve:
            print("Invalid input ")
        while self.__n<=0:
            print("number must be > 0")
            self.__n=input("How many vertices does the graph have? ")
            try:
                self.__n=int(self.__n)
            except ValueError as ve:
                print("Invalid input ")
           
      
        self.__m=input("How many edges does the graph have? ")
        try:
            self.__m=int(self.__m)
        except ValueError:
            print("Invalid input")
        while self.__m<0 or self.__m>(self.__n*(self.__n-1)):
            print ("number must be >0  and smaller than the number of vertices*(number of vertices-1)")
            self.__m=input("How many edges does the graph have? ")
            try:
                self.__m=int(self.__m)
            except ValueError:
                print("Invalid input")

        service = Graph(self.__n, self.__m)
        self.__graph = service
        i=0
        while i<self.__m:
            costOfEdge=random.randint(0, 100)
            vertex1=random.randint(0, self.__n)
            vertex2=random.randint(0, self.__n)
            if self.__graph.add_edge(vertex1, vertex2, costOfEdge)==1:
                i=i+1
      
        print("The new graph has ", self.__n, "vertices, and " , self.__m, "edges and it looks like: ")
        for i in self.__graph.get_list_of_costs():
            vertex1, vertex2=int(i[0]), int(i[1])
            print(vertex1, " ", vertex2, " ", self.__graph.get_edge_cost(vertex1, vertex2))


    def assignment2(self):
        vertex_1 = input("starting vertex: ")
        try:
            vertex_1=int(vertex_1)
        except ValueError as ve:
            print("Invalid input ")
        while vertex_1<0:
            print("This is not a valid vertex")
            vertex_1 = input("first vertex: ")
            try:
                vertex_1=int(vertex_1)
            except ValueError as ve:
                print("Invalid input ")

        vertex_2 = input("end vertex: ")
        try:
            vertex_2=int(vertex_2)
        except ValueError as ve:
            print("Invalid input ")
        while vertex_2<0:
            print("This is not a valid vertex")
            vertex_2 = input("second vertex: ")
            try:
                vertex_2=int(vertex_2)
            except ValueError as ve:
                print("Invalid input ")
        
        l=self.__graph.lowest_length_path(vertex_1, vertex_2)
        if l is not None:
            print("The lowest lenght path is ", len(l)-1)
            print(l)
        else:
            print ("There is no path between these 2 vertices")
        

    def assignment3(self):
        vertex_1 = input("starting vertex: ")
        try:
            vertex_1=int(vertex_1)
        except ValueError as ve:
            print("Invalid input ")
        while vertex_1<0:
            print("This is not a valid vertex")
            vertex_1 = input("first vertex: ")
            try:
                vertex_1=int(vertex_1)
            except ValueError as ve:
                print("Invalid input ")

        vertex_2 = input("end vertex: ")
        try:
            vertex_2=int(vertex_2)
        except ValueError as ve:
            print("Invalid input ")
        while vertex_2<0:
            print("This is not a valid vertex")
            vertex_2 = input("second vertex: ")
            try:
                vertex_2=int(vertex_2)
            except ValueError as ve:
                print("Invalid input ")

        l, cost=self.__graph.fords_algorithm(vertex_1, vertex_2)
        if cost is not None:
            print("The walk has cost: ", cost)
            print("The path is: ", l)
        else:
            print("The ending vertex is not reacheable from the start vertex, or there is a negative cycle")

        print("\n \n")

    def assignment4(self):
        file_path=input("From what file do i read the activities? ")
            
        self.__graph.read_activities(file_path)

        sorted_order = self.__graph.topological_sort()
        
        print("Here are the results for the activities: ")
        if sorted_order is not None:
            print("topological sort:", sorted_order)
            self.__graph.scheduling_problem()
        else:
            print("There is a cycle in the graph \n")
             
         

    def start_ui(self):
        while True:
            self.printMenu()
            option = int(input("Enter your option : "))
            
            if option ==1:
                self.addVertex()
            elif option ==2:
                self.removeVertex()
            elif option ==3:
                self.addEdge()
            elif option ==4 :
                self.removeEdge()
            elif option==5:
                self.getNumberOfVertices()
            elif option==6:
                self.printVertices()
            elif option==7:
                self.isedge()
            elif option==8:
                self.getInDegreeOfVertex()
            elif option==9:
                self.getOutDegreeOfVertex()
            elif option==10:
                self.getOutboundEdgesOfAVertex()
            elif option==11:
                self.getINboundEdgesOfAVertex()
            elif option==12:
                self.costOfEdge()
            elif option==13:
                self.changeCostOfEdge()
            elif option==14:
                 self.readFromFile()
            elif option==15:
                 self.writeToFile()
            elif option==16:
                 self.generateRandomGraph()
            elif option==17:
                self.assignment2()
            elif option==18:
                self.assignment3()
            elif option==19:
                self.assignment4()
            elif option == 0:
                break
            else:
                print("Invalid option.")

print("Let's create a graph to start with ")
number_of_vertices = input("Enter the number of vertices you want the graph to have:  ")
try:
    number_of_vertices=int(number_of_vertices)
except ValueError as ve:
    print("Invalid input ")
while number_of_vertices<0:
    print("This is not a valid number of vertices")
    number_of_vertices = input("Enter the number of vertices: ")
    try:
        number_of_vertices=int(number_of_vertices)
    except ValueError as ve:
        print("Invalid input ")


ui = UI(number_of_vertices, 0)
ui.start_ui()