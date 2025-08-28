#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

vector<string> parsePath(const string& path) {
	vector<string> result;
	stringstream ss(path);
	string segment;

	while (getline(ss, segment, '\\')) {
		result.push_back(segment);
	}
	return result;
}

struct Trie {
	struct Node {
		map<string, int> children;
	};

	vector<Node> nodes;

	Trie() : nodes(1) {}

	void insert(const vector<string>& path_segments) {
		int current_node_idx = 0; 
		for (const string& segment : path_segments) {

			if (nodes[current_node_idx].children.find(segment) == nodes[current_node_idx].children.end()) {

				int next_node_idx = nodes.size();
				nodes[current_node_idx].children[segment] = next_node_idx;
				nodes.emplace_back();
			}

			current_node_idx = nodes[current_node_idx].children[segment];
		}
	}

	void printAll(int current_node_idx, int depth) {
		for (auto& p : nodes[current_node_idx].children) {

			auto& name = p.first;
			int child_idx = p.second;
			for (int i = 0; i < depth; ++i) {
				cout << " ";
			}
			cout << name << "\n";

			printAll(child_idx, depth + 1);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int N;
	cin >> N;

	Trie disk_trie;
	for (int i = 0; i < N; ++i) {
		string path;
		cin >> path;
		vector<string> segments = parsePath(path);
		disk_trie.insert(segments);
	}
	disk_trie.printAll(0, 0);

	return 0;
}