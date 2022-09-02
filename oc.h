#include <unordered_map>
#include <vector>

using std::tuple;
using std::unordered_map;
using std::vector;

typedef uint16_t nodeType;

class AbstractOCPath {};

class OCUnitPath : AbstractOCPath {
public:
	nodeType u;

	OCUnitPath(nodeType u) {
		this->u = u;
	}
};

class OCPath : AbstractOCPath {
private:
	/*Unordered set of nodes. Order is provided by setting the right value.
	 * Should be efficient as the access to the content of the map is
	 * performed only a couple of times. */
	unordered_map<nodeType, nodeType> u;

public:
	OCPath() : u() {
	}

	OCPath(unordered_map<nodeType, nodeType> u) {
		this->u = u;
	}

	vector<nodeType> getPath() {
		unordered_map<nodeType, nodeType>::iterator it;
		vector<nodeType> path(u.size());

		for (it = u.begin(); it != u.end(); ++it) {
			path[it->second] = it->first;
		}

		return path;
	}

	int hops() {
		return this->u.size() - 1;
	}

	int nodes() {
		return this->u.size();
	}

	void insert(nodeType node) {
		u[node] = u.size();
	}

	bool hasNode(nodeType node) {
		return u.count(node);
	}

	OCPath operator*(OCUnitPath &right) {
		OCPath left(this->u);

		left.insert(right.u);
		return left;
	}
};

template <typename T, typename... Args> class OCWeight {
protected:
	tuple<T, Args...> args;

public:
	OCWeight(T first, Args... others)
		: args(std::make_tuple(first, others...)) {
	}

	virtual void update(T w1, Args... args) = 0;
  void operator*=(OCWeight& right) {
    std::apply(this->update, right.args);
  }
};


template <typename T, typename... Args> class OCWeightedPath {


};