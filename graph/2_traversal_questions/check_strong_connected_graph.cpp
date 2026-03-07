https://www.geeksforgeeks.org/dsa/connectivity-in-a-directed-graph/


Doing one DFS/BFS to verify if graph is strongly connected would work in undirected graph. 
But that is not sufficient in directed graph: such as  1-->2-->3-->4 starting DFS from 4 would fail to traverse other nodes. 

Solution: 
1. We can do DFS v times from all nodes and if one of these visits all nodes -> strong connected components. 
2. A better idea can be Strongly Connected Components (SCC) algorithm. Kosaraju’s Algorithm is a classic algorithm used for finding strongly connected components (SCCs) in a directed graph.

Euclerian path and cycle for undirected graph: https://www.geeksforgeeks.org/dsa/eulerian-path-and-circuit/
Euclerian path and cycle for directed graph: https://www.geeksforgeeks.org/dsa/euler-circuit-directed-graph/
Kosarajus algorithm: https://www.geeksforgeeks.org/cpp/kosarajus-algorithm-in-cpp/
