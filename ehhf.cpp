#include <iostream>
using namespace std;

// Struct Node untuk linked list
struct Node {
    int data;
    Node* next;
};

// Kelas Graph
class Graph {
    int V; // Jumlah vertex
    Node** adj; // Array of pointers to linked list

public:
    Graph(int V); // Konstruktor
    void addEdge(int v, int w); // Tambahkan edge ke graph
    void printGraph(); // Cetak graph
};

// Konstruktor Graph
Graph::Graph(int V) {
    this->V = V;
    adj = new Node*[V];
    for (int i = 0; i < V; ++i)
        adj[i] = NULL;
}

// Tambahkan edge ke graph
void Graph::addEdge(int v, int w) {
    Node* newNode = new Node;
    newNode->data = w;
    newNode->next = adj[v];
    adj[v] = newNode;

    newNode = new Node;
    newNode->data = v;
    newNode->next = adj[w];
    adj[w] = newNode;
}

// Cetak graph
void Graph::printGraph() {
    for (int i = 0; i < V; ++i) {
        cout << "\n Adjacency list dari vertex " << i << "\n head ";
        Node* temp = adj[i];
        while (temp != NULL) {
            cout << "-> " << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }
}

// Fungsi utama
int main() {
    // Buat graph sesuai contoh di atas
    Graph g(5); // 5 vertex dari 0 ke 4
    
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    
    // Cetak adjacency list
    g.printGraph();
    
    return 0;
}