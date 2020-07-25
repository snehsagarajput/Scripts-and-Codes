#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
#include <iomanip>
 
class Graph {
private:
    unsigned V;
    std::list<std::pair<int, int>> *adj_list;
    void print_path(std::vector<int> &, int);
public:
    Graph(unsigned);
    ~Graph();
    void add_edge(int, int, int);
    void shortest_path(int);
};
 
Graph::~Graph()
{
    delete [] adj_list;
}
 
Graph::Graph(unsigned V)
{
    this->V = V;
    adj_list = new std::list<std::pair<int, int>>[V];
}
 
void Graph::add_edge(int u, int v, int w)
{
    /* a undirected graph */
    adj_list[u].push_back(std::make_pair(v, w));
    adj_list[v].push_back(std::make_pair(u, w));
}
 
typedef std::pair<int, int> int_pair;
using std::priority_queue;
using std::vector;
using std::greater;
using std::list;
using std::cout;
using std::setw;
 
void Graph::print_path(std::vector<int> &parent, int v)
{
    if (parent[v] == -1) {
        cout << v << ' ';
        return ;
    }
    print_path(parent, parent[v]);
    cout << v << ' ';
}
 
void Graph::shortest_path(int src)
{
    /* create a priority queue to store vertices that being processed
     * full reference of priority_queue: 
     *  en.cppreference.com/w/cpp/container/priority_queue
     * */
    priority_queue<int_pair, vector<int_pair>, greater<int_pair>> pq;
 
    vector<int> dist(V, INT_MAX);
 
    /* create a parent to store path info. */
    vector<int> parent(V);
    parent[src] = -1;
 
    /* still  pair stored in a form of <weight(distance), source> */
    pq.push(std::make_pair(0, src));
    dist[src] = 0;
 
    /* looping till priority queue becomes empty
     *  which means all distance finalized
     * */
     int visited[V]={0};
     while (pq.size()) {
        /* the first field stores vertex distance
         * the second field stores vertex label
         * extract minimum distance vertex from pq
         * */
        int u = pq.top().second;
        pq.pop();
        visited[u]=true;
 
        /* iterate through all vertices adjacent to `u' */
        list<int_pair>::iterator it;
        for (it = adj_list[u].begin(); it != adj_list[u].end(); it++) {
            int v = it->first;
            int w = it->second;
 
            /* if there is a shorter path to v through u */
            if (!visited[v] && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(std::make_pair(dist[v], v));
                parent[v] = u;
            }
        }
    }
 
    /* print the final result */
    cout << "Vertex  SPD      Path\n";
    for (unsigned i = 0; i < V; i++) {
        cout << "  " << setw(2) << i << "     "
             << setw(2) << dist[i] << "      ";
        print_path(parent, i);
        cout << '\n';
    }
}
 
int main(void)
{
    int V = 9;
    Graph g(V);
    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);
    g.shortest_path(0);
    return 0;
}
