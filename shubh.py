import heapq

graph = {
    'a': {'b': 4, 'c': 3},
    'b': {'a': 4, 'f': 5},
    'c': {'a': 3, 'd': 7, 'e': 10},
    'd': {'c': 7, 'e': 2},
    'e': {'c': 10, 'd': 2, 'z': 5},
    'f': {'b': 5, 'z': 16},
    'z': {'e': 5, 'f': 16}
}

heuristic = {
    'a': 14,
    'b': 12,
    'c': 11,
    'd': 6,
    'e': 4,
    'f': 11,
    'z': 0
}

def astar(start, end, graph, heuristic):
    to_visit = [(0, start)]
    visited = set()

    path = {}
    cost = {}
    path[start] = [start]
    cost[start] = 0

    while len(to_visit) > 0:
        f_score, current = heapq.heappop(to_visit)

        if current == end:
            return path[current]

        visited.add(current)

        for neighbor, weight in graph[current].items():
            if neighbor in visited:
                continue

            tentative_cost = cost[current] + weight

            if neighbor not in [node for (_, node) in to_visit]:
                heapq.heappush(to_visit, (tentative_cost + heuristic[neighbor], neighbor))

            if neighbor not in cost or tentative_cost < cost[neighbor]:
                cost[neighbor] = tentative_cost
                path[neighbor] = path[current] + [neighbor]

    return None

path = astar('a', 'z', graph, heuristic)
print(path)
