#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Node {
public:
    T value;

    Node(T value) : value(value) {}
};


template<class T>
class Path {
public:
    Node<T> *first;
    Node<T> *second;
    int weight;

    Path(Node<T>* first, Node<T>* second, int weight)
    {
        this->first = first;
        this->second = second;
        this->weight = weight;
    }
};


template<class T>
class Graph {
public:
    void add_node(Node<T> &node)
    {
        for(auto n : nodes) {
            if(n == &node) {
                throw "This node is already in the graph!";
            }
        }

        nodes.push_back(&node);
    }

    void connect(Node<T> &n1, Node<T> &n2, int weight)
    {
        routes.push_back(Path<T>(&n1, &n2, weight));
        routes.push_back(Path<T>(&n2, &n1, weight));
    }

    void print_all()
    {
        for(auto n : nodes) {
            cout << n->value << endl;
        }
    }

    void print_all_paths()
    {
        for(auto route : routes) {
            //TODO
        }
    }

private:
    vector<Node<T>*> nodes;
    vector<Path<T>> routes;
};


int main()
{
    Graph<int> graph;
    Node<int> n1(1);
    Node<int> n2(2);
    Node<int> n3(3);
    Node<int> n4(4);
    Node<int> n5(5);
    Node<int> n6(6);

    graph.add_node(n1);
    graph.add_node(n2);
    graph.add_node(n3);
    graph.add_node(n4);
    graph.add_node(n5);
    graph.add_node(n6);

    graph.connect(n1, n2, 7);
    graph.connect(n1, n3, 9);
    graph.connect(n1, n6, 14);

    graph.connect(n2, n3, 10);
    graph.connect(n2, n4, 15);

    graph.connect(n3, n4, 11);
    graph.connect(n3, n6, 2);

    graph.connect(n4, n5, 6);

    graph.connect(n5, n6, 9);

    graph.print_all();

    return 0;
}