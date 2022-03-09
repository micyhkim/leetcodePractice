# Solution
## Topic
Union find, DFS  
## Explanation
To make all computer to be connected, we first need to find distinct connected chunks, and add connection to each of the connection.
How can we do this? We first create the node and edge graph and perform search algorithm. As we are searching, we need to mark the
id of each nodes belong to. I chose it to become the very first node that initiates search algorithm. As we are searching nodes,
we mark another nodes being inserted into the queue to have id of the previous id, connecting all of them.

## Algorithm
* Create graph using 2-D vector or hashmap
* Create id_vector (union id vector) to mark up the chunk id for each node
* Loop through each node, check if the node is visited or not.
* If the node is not visited, we perform dfs starting from the node. Insert the node to the queue and perform search algorithm, marking
chunk_id for all connected nodes to have the same id.
* Find the number of unique ids after search algorithm and subtract 1 because we want to find the edges between them.

## Analysis
* Runtime : We are iterating through whole connections and the number of n **O(n)**
* Space : We create data structure of size n **O(n)**