import heapq
import sys
input = sys.stdin.read

def dijkstra(graph, start):
    n = len(graph)
    distances = [float('inf')] * n
    distances[start] = 0
    queue = [(0, start)]
    
    while queue:
        current_distance, current_node = heapq.heappop(queue)
        
        if current_distance > distances[current_node]:
            continue
        
        for neighbor, weight in graph[current_node]:
            distance = current_distance + weight
            
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(queue, (distance, neighbor))
    
    return distances

def main():
    data = input().split()
    N, E = int(data[0]), int(data[1])
    
    graph = [[] for _ in range(N + 1)]
    index = 2
    for _ in range(E):
        a, b, c = int(data[index]), int(data[index + 1]), int(data[index + 2])
        graph[a].append((b, c))
        graph[b].append((a, c))
        index += 3
    
    v1, v2 = int(data[index]), int(data[index + 1])
    
    dist_from_1 = dijkstra(graph, 1)
    dist_from_v1 = dijkstra(graph, v1)
    dist_from_v2 = dijkstra(graph, v2)
    
    path1 = dist_from_1[v1] + dist_from_v1[v2] + dist_from_v2[N]
    path2 = dist_from_1[v2] + dist_from_v2[v1] + dist_from_v1[N]
    
    result = min(path1, path2)
    
    if result >= float('inf'):
        print(-1)
    else:
        print(result)

if __name__ == "__main__":
    main()
