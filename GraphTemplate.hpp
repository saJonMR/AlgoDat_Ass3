#include <vector>
#include <string>
#include <map>

// YOU CAN USE ONLY THE VECTORS, STRINGS AND MAPS FOR THIS ASSIGNMENT!


struct NodeTemplate {
private:
    /* data */
    std::string label;
    std::map<NodeTemplate, int> adjacentNodes; // the int is for the weight od the egde
    NodeTemplate *parent;
    int distance; // aka key

public:
    NodeTemplate(std::string name) {
        label = name;
        parent = nullptr;
        distance = 0;
    }

    //~NodeTemplate();
    
    std::string name() {
        return label;
    }

    // TODO: implement method for adding a connection
    void add_connection(NodeTemplate const& target, int weight) {
        adjacentNodes.insert(std::pair<NodeTemplate, int>(target, weight));
    }

    // TODO: implement method for removing a connection
    void remove_connection(NodeTemplate target) { // const& ?
        adjacentNodes.erase(target);
    }

    void init_parent() {
        parent = nullptr;
    }

    void init_distance() {
        distance = INT_MAX;
    }

    void manipulate_parent(NodeTemplate target) {
        parent = &target;
    }

    void manipulate_distance(int dis) {
        distance = dis;
    }

    int dist() {
        return distance;
    }

    int weight(NodeTemplate const& a) {
        return adjacentNodes.find(a)->second; //returns weight
    }

    std::map<NodeTemplate, int> const connections() {
        return adjacentNodes;
    }

    bool operator <(NodeTemplate const& rhs) const {
        return label < rhs.label;
    }
    
};

class MinHeapNodeTemplate{
private:
    /* data */
    NodeTemplate *node;
    MinHeapNodeTemplate *parent;
    MinHeapNodeTemplate *left;
    MinHeapNodeTemplate *right;

public:
    MinHeapNodeTemplate(/* args */);
    ~MinHeapNodeTemplate();

    // TODO: implement additional constructors
};

class MinHeapTemplate {
private:
    MinHeapNodeTemplate *root;

public:
    MinHeapTemplate(/* args */);
    ~MinHeapTemplate();
    // TODO: implement method for restructuring the min-priority Queue
    // TODO: implement method for extracting the smaller element from the min-priority Queue
};


class GraphTemplate {
private:
    std::vector<NodeTemplate> nodes;
    MinHeapTemplate *minPriorityQueue;
    bool isDirected;

public:
    GraphTemplate(NodeTemplate const& start) {
        nodes.push_back(start);
    }

    ~GraphTemplate() {
        clear();
        minPriorityQueue = nullptr;
    }

    void clear() {
        while(nodes.size() > 0) {
            nodes.pop_back();
        }
    }

    // TODO: implement method for adding a node
    void add(NodeTemplate const& node) {
        nodes.push_back(node);
    }

    // TODO: implement method for removing a node
    void remove(std::string label) {
        int pos = find(label);
        if(pos > 0) {
            nodes.erase(nodes.begin() + pos);
        }
    }

    int find(std::string label) {
        int pos = 0;
        while(pos < nodes.size()) {
            if(nodes[pos].name() == label) {
                return pos;
            }
            ++pos;
        }
        return -1;
    }
    
    std::string listNodes() {
        for(auto it = nodes.begin(); it != nodes.end(); ++it) {
            return it->name();
        }
    }
    

    std::string listNode(int x) {
        return nodes[x].name();
    }

    // TODO: implement Prim
    // TODO: implement Bellman-Ford
    
    void relax(NodeTemplate u, NodeTemplate v, int w) {
        int uDist = u.dist();
        int vDist = v.dist();
        int weight = w;
        if(vDist > uDist + w) {
            v.manipulate_parent(u);
            v.manipulate_distance(w + uDist);
        }
    }

    bool hasNegative(NodeTemplate u, NodeTemplate v, int w) {
        int uDist = u.dist();
        int vDist = v.dist();
        int weight = w;
        if(vDist > uDist + w) {
            return false;
        }
    }
    
    bool bellman_fort(NodeTemplate & s) {
        int pos = 0;
        for(auto &node : nodes) {
            node.init_distance();
            node.init_parent();
        }
        s.manipulate_distance(20);
        for(int i = 1; i < nodes.size(); i++) {
            for(auto& node : nodes) {
                for(std::pair<NodeTemplate, int> edge : node.connections()) {
                    //relax(node, edge.first, edge.second);
                }
            }
        }
        for(auto node : nodes) {
            for(auto edge : node.connections()) {
                //hasNegative(node, edge.first, edge.second);
            }
        }
        return true;
    }
    
    /*
    std::string bellman_fort_fake(NodeTemplate s) {
        for(auto node : nodes) {
            node.manipulate_distance(INT_MAX);
            node.init_parent();
        }
        s.manipulate_distance(0);
        for(int i = 1; i < nodes.size(); i++) {
            for(auto it = std::begin(nodes); it != std::end(nodes); ++it) {
                return *it->name();
            }
        }
        /*
        for(auto node : nodes) {
            return node.name();
        }
        
        //return true;
    }
    */
    
    

    // TODO: implement printGraph function that generates a file written using the dot format
};