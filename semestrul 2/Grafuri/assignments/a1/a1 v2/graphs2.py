

from collections import deque


class Graph:

    def __init__(self, n, m):
        self.__number_of_vertices = n
        self.__vertices = []
        self.__list_of_predecessors = {}
        self.__list_of_successors = {}
        self.__cost = {}

        self.dependencies = {}
        self.duration = {}
        self.activities={}


        for i in range(n):
            self.add_vertex(i)

    def is_vertex(self, vertex):
        return vertex in self.__vertices

    def is_edge(self, vertex_1, vertex_2):
        return vertex_2 in self.__list_of_successors.get(vertex_1, [])

    def add_vertex(self, vertex):
        if self.is_vertex(vertex):
            return -1
        self.__vertices.append(vertex)
        self.__list_of_predecessors[vertex] = []
        self.__list_of_successors[vertex] = []
        self.__number_of_vertices += 1
        return 1

    def add_edge(self, vertex_1, vertex_2, edge_cost):
        if self.is_edge(vertex_1, vertex_2):
            return -1
        if not self.is_vertex(vertex_1) or not self.is_vertex(vertex_2):
            return -2
        self.__list_of_predecessors[vertex_2].append(vertex_1)
        self.__list_of_successors[vertex_1].append(vertex_2)
        self.__cost[(vertex_1, vertex_2)] = edge_cost
        return 1

    def remove_edge(self, vertex_1, vertex_2):
        if not self.is_edge(vertex_1, vertex_2):
            return -1
        if vertex_2 in self.__list_of_successors[vertex_1]:
            self.__list_of_successors[vertex_1].remove(vertex_2)
        if vertex_1 in self.__list_of_predecessors[vertex_2]:
            self.__list_of_predecessors[vertex_2].remove(vertex_1)
        del self.__cost[(vertex_1, vertex_2)]

    def remove_vertex(self, vertex_to_remove):        
        if not self.is_vertex(vertex_to_remove):
            return -1
        for vertex in self.__list_of_successors[vertex_to_remove][:]:
            self.remove_edge(vertex_to_remove, vertex)
        for vertex in self.__list_of_predecessors[vertex_to_remove][:]:
            self.remove_edge(vertex, vertex_to_remove)
        del self.__list_of_successors[vertex_to_remove]
        del self.__list_of_predecessors[vertex_to_remove]
        self.__vertices.remove(vertex_to_remove)
        self.__number_of_vertices -= 1
        return 1

    def get_edge_cost(self, vertex1, vertex2):
        return self.__cost.get((vertex1, vertex2), -1)

    def set_edge_cost(self, vertex1, vertex2, new_cost):
        if (vertex1, vertex2) not in self.__cost:
            return -1
        self.__cost[(vertex1, vertex2)] = new_cost

    def get_number_of_vertices(self):
        return self.__number_of_vertices

    def get_vertices(self):
        return self.__vertices

    def get_predecessors(self):
        return self.__list_of_predecessors

    def get_successors(self):
        return self.__list_of_successors

    def get_cost(self):
        return self.__cost

    def service_in_degree(self, vertex):
        return len(self.get_predecessors().get(vertex, [])), self.get_predecessors().get(vertex, [])

    def service_out_degree(self, vertex):
        return len(self.get_successors().get(vertex, [])), self.get_successors().get(vertex, [])

    def service_outbound_edges(self, vertex):
        if self.is_vertex(vertex):
            return self.get_successors()[vertex]
        else:
            return None

    def service_inbound_edges(self, vertex):
        if self.is_vertex(vertex):
            return self.get_predecessors()[vertex]
        else:
            return None

    def service_change_cost_of_edge(self, vertex_1, vertex_2, new_cost):
        self.set_edge_cost(vertex_1, vertex_2, new_cost)

    def get_list_of_costs(self):
        return self.get_cost()

    def get_vertices_without_predecessors(self):
        vertices_without_predecessors = []
        for vertex in self.__vertices:
            has_predecessor = False
            for edge in self.__edges:
                if edge[1] == vertex:
                    has_predecessor = True
                    break
            if not has_predecessor:
                vertices_without_predecessors.append(vertex)
        return vertices_without_predecessors

    def get_vertices_without_successors(self):
        vertices_without_successors = []
        for vertex in self.__vertices:
            has_successor = False
            for edge in self.__edges:
                if edge[0] == vertex:
                    has_successor = True
                    break
            if not has_successor:
                vertices_without_successors.append(vertex)
        return vertices_without_successors

 ##############################################################################

    def lowest_length_path(self, start, end):
        visited = []
        queue = [end]
        dist = {end: 0}     
        predecessors = {}

        while queue:
            x = queue.pop(0)
            visited.append(x)
            if x == start:
                path = [x]
                while path[-1] != end:
                    path.append(predecessors[path[-1]])
                return list(path)
            for i in self.__list_of_predecessors[x]:
                if i not in visited:
                    queue.append(i)
                    visited.append(i)
                    dist[i] = dist[x] + 1
                    predecessors[i] = x

        return None


 ##############################################################################

    def fords_algorithm(self, start, end):
        dist = {}
        prev = {}
        maximum_value = float("inf")
        for i in self.__vertices:
            dist[i] = maximum_value
        dist[start] = 0
        for i in range(len(self.__vertices)):
            changed = False
            for (x, y) in self.__cost:
                if dist[y] > dist[x] + self.get_edge_cost(x, y):
                    dist[y] = dist[x] + self.get_edge_cost(x, y)
                    prev[y] = x
                    changed = True
            if not changed:
                break
        else:
            return None, None

        if end not in prev:
            return None, None

        path = [end]
        while path[-1] != start:
            path.append(prev[path[-1]])
        path.reverse()

        return path, dist[end]

 ##############################################################################

    def topological_sort(self):
        
        in_degree = [0] * self.__number_of_vertices
        sorted_order = []
        queue = deque()

        for vertex in self.__vertices:
            for successor in self.get_successors()[vertex]:
                in_degree[successor] += 1

        for vertex in self.__vertices:
            if in_degree[vertex] == 0:
                queue.append(vertex)

        while queue:
            vertex = queue.popleft()
            sorted_order.append(vertex)

            for successor in self.__list_of_successors[vertex]:
                in_degree[successor] -= 1
                if in_degree[successor] == 0:
                    queue.append(successor)
      
        if len(sorted_order) != self.__number_of_vertices:
            return None

        return sorted_order


    def scheduling_problem(self):
        order = self.topological_sort()
        if len(order) != self.get_number_of_vertices():
            print("Not a DAG!")
            return

        total_time = sum(self.duration.values())
        earliest = [0] * self.get_number_of_vertices()
        latest = [total_time] * self.get_number_of_vertices()
        duration = [self.duration[i] for i in range(self.get_number_of_vertices())]


        for x in order:
            for in_vertex in self.service_inbound_edges(x):
                earliest[x] = max(earliest[x], earliest[in_vertex] + duration[in_vertex])

        for x in order[::-1]:
            if earliest[x]==0:
                latest[x]=0
            else:
                latest[x]=total_time-earliest[x];
            for out_vertex in self.service_outbound_edges(x):
                latest[x] = min(latest[x], latest[out_vertex] - duration[x])

        for i in range(self.get_number_of_vertices()):
            print(f"For activity {i}, the earliest starting time is {earliest[i]} and the latest is {latest[i]}.")

        print(f"The total time to finish the project is {total_time}.")

        critical_activities = [i for i in range(self.get_number_of_vertices()) if earliest[i] == latest[i]]
        print("The critical activities are:", critical_activities)


    def add_activity(self, activity, duration, dependencies):
        vertex = self.activities.get(activity)
        if vertex is None:
            vertex = len(self.__vertices)
            self.add_vertex(vertex)
            self.activities[activity] = vertex
            self.duration[vertex] = duration
            self.dependencies[vertex] = []

        dep_vertices = []
        for dep in dependencies:
            dep_vertex = self.activities.get(dep)
            if dep_vertex is None:
                dep_vertex = len(self.__vertices)
                self.add_vertex(dep_vertex)
                self.activities[dep] = dep_vertex
                self.duration[dep_vertex] = 0
                self.dependencies[dep_vertex] = []

            dep_vertices.append(dep_vertex)

        self.dependencies[vertex].extend(dep_vertices)
        for dep_vertex in dep_vertices:
            self.__list_of_successors[vertex].append(dep_vertex)
            self.__list_of_predecessors[dep_vertex].append(vertex)


    def read_activities(self, file_path):
        self.__number_of_vertices=0
        self.__vertices.clear()
        self.__list_of_predecessors.clear()
        self.__list_of_successors.clear()
        self.duration.clear()
        self.activities.clear()

        with open(file_path, 'r') as file:
            line_number = 0
            for line in file:
                line_number += 1
                line = line.strip()
                if line:
                    parts = line.split(":")
                    activity = parts[0]
                    duration = float(parts[1])
                    dependencies = parts[2:]
                    self.add_activity(activity, duration, dependencies)

        
