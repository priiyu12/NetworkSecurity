#include "bits/stdc++.h"

using namespace std;

const int inf = 1e7;

int main(){
	
	int nodes, links;
	cout << "Enter number of routers: ";
	cin >> nodes;
	cout << "Enter number of links: ";
	cin >> links;
	
	vector<int> dist(nodes,inf);
	vector<vector<pair<int, int>>> graph(nodes);

	cout << "Enter the edges (node1, node2, weight):";
	for (int i = 0; i < links; i++) {
	    int n1, n2, w;
	    cout << endl << "Enter the node 1 (u): ";
	    cin >> n1;
	    cout << "Enter the node 2 (v): ";
	    cin >> n2;
	    cout << "Enter the weight (w): ";
	    cin >> w;

	    graph[n1].push_back({n1, w});        
	    graph[n2].push_back({n2, w});     
	    
	    cout<<"___________";
	}

	int source;
	cout << endl << "Enter the source node: ";
	cin >> source;

	dist[source] = 0;
	set<pair<int, int>> s;
	s.insert({0, source});

	dist[source] = 0;
	set<pair<int, int>> s;
	s.insert({0, source});

	cout << "Shortest distances from source " << source << ":" << endl;
	for (int i = 0; i < n; i++) {
	    if (dist[i] < inf) {
	        cout << "Node " << i << ": " << dist[i] << endl;
	    } else {
	        cout << "Node " << i << ": " << -1 << " (unreachable)" << endl;
	    }
	}

	return 0;
}