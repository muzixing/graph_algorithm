def kruskal(graph):
    assert type(graph)==dict

    nodes = graph.keys()   
    visited = set()
    path = []
    next = None

    while len(visited) < len(nodes):
        distance = float('inf') 
        for s in nodes:
            for d in nodes:
                if s in visited and d in visited or s == d:
                    continue
                if graph[s][d] < distance:
                    distance = graph[s][d]
                    pre = s
                    next = d

        path.append((pre, next))
        visited.add(pre)
        visited.add(next)

    return path


if __name__ == '__main__':
    graph_dict = {  "s1":{"s1": 0, "s2": 6, "s10": 3, "s12": 4, "s5":3},
                    "s2":{"s1": 1, "s2": 0, "s10": 4, "s12": 3, "s5":4},
                    "s10":{"s1": 2, "s2": 6, "s10": 0, "s12":3, "s5":4},
                    "s12":{"s1": 1, "s2": 5, "s10": 2, "s12":0,"s5":2},
                    "s5":{"s1": 3, "s2": 5, "s10": 7, "s12":4,"s5":0},
    }

    path = kruskal(graph_dict)
    print path

