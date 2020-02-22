import networkx as nx

"""
The solution does not take into account the cleaning lady of the canteen, as it would
need changing the shortest path finding algorithm, which is not implemented by me
"""

def build_graph(qlen, mlen, queues):
    """
    The function parses received queue descriptions into a networkx Graph object
    """
    graph = nx.DiGraph()
    graph.add_nodes_from(((0, 0), 'end'))
    for q1 in range(2):
        q2 = (q1 + 1) % 2   # 1 if q1 == 0 else 0
        for i in range(qlen):
            if queues[q1][i] == '.':
                # A jump beyond the end is always possible
                if qlen - i <= mlen:
                    graph.add_edge((q1, i), 'end')  
                else:       
                    # We can move back and forth 1 step in our queue
                    for j in i - 1, i + 1:
                        if queues[q1][j] == '.':
                            graph.add_edge((q1, i), (q1, j))               
                    # We can jump mlen positions ahead into the opposite queue
                    if queues[q2][i + mlen] == '.':
                        graph.add_edge((q1, i), (q2, i + mlen))
    return graph

qLen, moveLen = (int(x) for x in input().split())
graph = build_graph(qLen, moveLen, (input(), input()))
try:
    print(nx.shortest_path_length(graph, (0, 0), 'end'))
except nx.NetworkXNoPath:
    print(-1)
