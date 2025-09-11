/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}

 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

 

Example 1:

Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

Example 2:

Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.

Example 3:

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.

 

Constraints:

    The number of nodes in the graph is in the range [0, 100].
    1 <= Node.val <= 100
    Node.val is unique for each node.
    There are no repeated edges and no self-loops in the graph.
    The Graph is connected and all nodes can be visited starting from the given node.
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class IndexedPtrSet {
    std::vector<Node*> data;
    std::unordered_map<Node*, std::size_t> index_map;

public:
    void insert(Node* ptr) {
        data.push_back(ptr);
        index_map[ptr] = data.size() - 1;
    }

    bool contains(Node* ptr) const {
        return index_map.contains(ptr);
    }

    Node* operator[](std::size_t i) const {
        return data[i];
    }

    std::size_t index_of(Node* ptr) const {
        return index_map.find(ptr)->second;
    }
};
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        std::queue<Node*> q;
        q.push(node);

        IndexedPtrSet visited;
        std::vector<Node*> copied;

        while (!q.empty()) {
            Node* n = q.front();
            q.pop();
            if (visited.contains(n)) 
                continue; 
            visited.insert(n);

            copied.push_back(new Node(n->val));
            
            for (int j = 0; j < n->neighbors.size(); ++j){
                if (visited.contains(n->neighbors[j])) continue;
                q.push(n->neighbors[j]);
            }
        }

        for(int i = 0; i < copied.size(); ++i)
        {
            for(int j = 0; j < visited[i]->neighbors.size(); ++j){
                copied[i]->neighbors.push_back(copied[visited.index_of(visited[i]->neighbors[j])]);
            }
        }

        return copied[0];
    }
};

