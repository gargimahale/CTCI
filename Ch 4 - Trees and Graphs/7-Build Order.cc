#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph{
public:
	bool sortDependencies(int numProjects, vector<vector<int>>& dependencies){
		vector<vector<int>> V(numProjects, vector<int>());

		vector<int> degree(numProjects);

		for (auto& edge: dependencies){
			V[edge[1]].push_back(edge[0]);
			degree[edge[0]]++;
		}

		deque<int> todo;
		for (int i = 0; i<numProjects; ++i){
			if (degree[i] == 0)
				todo.push_back(i);
		}

		while(!todo.empty()){
			auto curr = todo.front();
			todo.pop_front();

			--numProjects;
			cout << curr << " ";
			for (int i = 0; i < V[curr].size(); ++i){
				if (--degree[V[curr][i]] == 0){
					todo.push_back(V[curr][i]);
				}
			}

		}
		return numProjects == 0;

	}
};

int main(void){
	Graph G;
	int n;
	cin >> n;
	vector<vector<int>> D;
	for (int i = 0; i<n; ++i){
		int s, t;
		cin >> s >> t;
		D.push_back({s, t});
	}
	cout << G.sortDependencies(n, D) << "\n";
}