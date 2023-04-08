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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        
        queue<Node*> q;
        unordered_map<int, vector<int>> adjList;
        
        q.push(node);
        adjList[node->val] = {};
        
        while(!q.empty()){
            Node* cur = q.front(); q.pop();
            
            for(Node* nei : cur->neighbors){
                adjList[cur->val].push_back(nei->val);
                if(adjList.find(nei->val) != adjList.end()) continue;
                
                adjList[nei->val] = {};
                q.push(nei);
            }
        }
        
        int count = adjList.size();
        
        //dummy node
        vector<Node*> newnodes = {new Node(0)};
        
        for(int i = 1; i <= count; ++i){
            newnodes.push_back(new Node(i));
        }
        
        for(int i = 1; i <= count; i++){
            for(const int& nei : adjList[i]){
              
                newnodes[i]->neighbors.push_back(newnodes[nei]);
            }
        }
        
        return newnodes[1];
    }
};
