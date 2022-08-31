#include <map>
#include <vector>

using std::map;
using std::vector;

typedef uint16_t nodeType;

class AbstractPath {};

class UnitPath : AbstractPath {
public:
	nodeType u;
  
  UnitPath(nodeType u) {
    this->u = u;
  }
};

class Path : AbstractPath {
private:
	/*Unordered set of nodes for. Order is provided by setting the right value
	 * to the key. Should be efficient as the access to the content of the map
	 * should be performed only a couple of times. */
	map<nodeType, nodeType> u;

public:
	Path() : u() {
	}

	Path(map<nodeType, nodeType> u) {
		this->u = u;
	}

	vector<nodeType> getPath() {
		map<nodeType, nodeType>::iterator it;
		vector<nodeType> path(u.size());

		for (it = u.begin(); it != u.end(); ++it) {
			path[it->second] = it->first;
		}

		return path;
	}

	int getHops() {
		return this->u.size() - 1;
	}

  int getNodes() {
    return this->u.size();
  }

	void insert(nodeType node) {
		u[node] = u.size();
	}

	bool hasNode(nodeType node) {
		return u.count(node);
	}

	Path operator*(UnitPath &right) {
		Path left(this->u);
    
		left.insert(right.u);
		return left;
	}
};




class Weight {
private:
public:
	Weight() {
	}
};