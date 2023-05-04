from collections import defaultdict

# function for DFS traversal
def DFS(graph, start, goal, visited=None, path=None):
    if visited is None:
        visited = set()
    if path is None:
        path = []
    visited.add(start)
    path.append(start)
    if start == goal:
        print("Path found:", path)
        return
    for neighbor in graph[start]:
        if neighbor not in visited:
            DFS(graph, neighbor, goal, visited, path.copy())

# function for BFS traversal
def BFS(graph, start, goal):
    visited = set()
    queue = [[start]]
    while queue:
        path = queue.pop(0)
        node = path[-1]
        if node == goal:
            print("Path found:", path)
            return
        if node not in visited:
            visited.add(node)
            for neighbor in graph[node]:
                new_path = list(path)
                new_path.append(neighbor)
                queue.append(new_path)

# main function
if __name__ == '__main__':
    # sample graph represented as adjacency list
    graph = defaultdict(list)
    graph[0] = [1, 2]
    graph[1] = [0, 2, 3]
    graph[2] = [0, 1, 4]
    graph[3] = [1, 4]
    graph[4] = [2, 3]
    
    # get source and goal node from user
    source = int(input("Enter source node: "))
    goal = int(input("Enter goal node: "))
    
    # perform DFS and BFS traversal
    print("Performing DFS traversal...")
    DFS(graph, source, goal)
    print("Performing BFS traversal...")
    BFS(graph, source, goal)
