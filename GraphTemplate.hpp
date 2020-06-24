#include <vector>
#include <string>
#include <map>

// YOU CAN USE ONLY THE VECTORS, STRINGS AND MAPS FOR THIS ASSIGNMENT!


class NodeTemplate {
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

    void manipulate_parent(NodeTemplate *target) {
        parent = target;
    }

    void manipulate_distance(int dis) {
        distance = dis;
    }

    int weight(NodeTemplate const& a) {
        return adjacentNodes.find(a)->second; //returns weight
    }

    std::map<NodeTemplate, int> connections() {
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
    GraphTemplate(NodeTemplate start) {
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
    void add(NodeTemplate node) {
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

    // TODO: implement Prim
    // TODO: implement Bellman-Ford
    /*
    void relax(NodeTemplate start, std::pair<NodeTemplate, int> connection) {
        if(connection.first.weight() > )
    }
    
    void bellman_fort(GraphTemplate G, NodeTemplate s) {
        for(auto node : G.nodes) {
            node.manipulate_distance(INT_MAX);
            node.manipulate_parent(nullptr);
        }
        s.manipulate_distance(0);
        for(int i = 1; i < nodes.size(); i++) {
            for(auto node : G.nodes) {
                for(auto edge : node.connections()) {
                    relax(node, edge);
                }
            }
        }
    }
    */
    

    // TODO: implement printGraph function that generates a file written using the dot format
};