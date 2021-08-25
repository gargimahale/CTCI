#include <vector>
#include <iostream>
using namespace std;


class SepearateHash{
private:
	int n;
	vector<vector<int>> V;
public:
	SepearateHash(int n){
		this->n = n;
		V = vector<vector<int>> (n);
	}

	int getHashIndex(int x){
		return x % n;
	}

	void addElement(int x){
		V[getHashIndex(x)].push_back(x);
	}

	void deleteElement(int x){
		int idx = getHashIndex(x);

		for (int i = 0; i<V[idx].size(); ++i){
			if (V[idx][i] == x){
				V[idx].erase(V[idx].begin() + i);
				cout << x << " deleted\n";
				return;
			}
		}
		cout << "No Element Found!\n";
	}

	void displayHash(){
		for (int i = 0; i<V.size(); ++i){
			cout << i;
			for (int j = 0; j < V[i].size(); ++j){
				cout << " ->" << V[i][j];
			}
			cout << '\n';
		}
	}

};

int32_t main(){
	int arr[] = {12, 3, 23, 4, 11, 32, 26, 33, 17, 19};
	SepearateHash obj(10);

	for (int i = 0; i < 10; ++i){
		obj.addElement(arr[i]);
	}

	// Display the initial hash
    cout << "Initial Hash:\n";
    obj.displayHash();

    cout << "\nRemoving 23 from Hash: ";
    obj.deleteElement(23);
    cout << endl;
  
    cout << "Final Hash:\n";
    obj.displayHash();
    return 0;
}