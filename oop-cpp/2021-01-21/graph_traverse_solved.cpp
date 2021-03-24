#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

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

    void print_all_paths(Node<T>* current, Node<T>* destination, vector<Node<T>*> path = {}, int distance = 0)
    {
        if (current == destination) {
            cout << "Found solution with distance: " << distance << endl << "\t";

            for (Node<T>* stop : path) {
                cout << stop->value << " --> ";
            }

            cout << destination->value << endl << endl;
        } else {
            for (pair<Node<T>*, int> route : get_neighbours(current)) {
                if (std::count(path.begin(), path.end(), route.first) == 0) {
                    vector<Node<T>*> copy = path;
                    copy.push_back(current);

                    print_all_paths(route.first, destination, copy, distance + route.second);
                }
            }
        }

    }

    map<Node<T>*, int> get_neighbours(Node<T>* n)
    {
        map<Node<T>*, int> neighbours;

        for (Path<T>& route : routes) {
            if (route.first == n) {
                neighbours.insert(pair<Node<T>*, int>(route.second, route.weight));
            }
        }

        return neighbours;
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

    Node<int>* check = &n3;
    map<Node<int>*, int> neighbours = graph.get_neighbours(check);
    cout << "Neighbours of " << check->value  << " are: " << endl;
    for (auto pair : neighbours) {
        cout << pair.first->value << ", distance is " << pair.second << endl;
    }

    graph.print_all_paths(&n1, &n5);

    return 0;
}