#include <deque>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Graph {
	int m_V;
	vector<vector<int>> m_adj;

public:
	Graph(int v): m_V(v), m_adj(v) {}

	void addEdge(int u, int v) {
		m_adj[u].push_back(v);
	}

	bool bfs(int start, int end) {
		if (start == end) return true;

		deque<int> Q;
		vector<bool> visited(m_V, false);

		Q.push_back(start);
		visited[start] = true;

		while (!Q.empty()) {
			int x = Q.front(); Q.pop_front();
			if (x == end){
				return true;
			}
			for (int t : m_adj[x]) {
				if (!visited[t]) {
					Q.push_back(t);
					visited[t] = true;
				}
			}
		}
		return false;
	}
};

int main() {
	int nodes;
	cin >> nodes;
	Graph G(nodes);
	for (int i = 0; i<nodes; ++i){
		int x, y;
		cin >> x >> y;
		G.addEdge(x, y);
	}
	cout << G.bfs(3, 1) << "\n"; 
	return 0;
}


