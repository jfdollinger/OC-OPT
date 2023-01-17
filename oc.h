#include <unordered_map>
#include <vector>
#include <iostream>

using std::tuple;
using std::unordered_map;
using std::vector;

typedef uint16_t nodeType;

class OCPath {
private:
  /*
  * Keeping the source node appart to improve computation of the star operator.
  */
	nodeType source;

	/*Unordered set of nodes. Order is provided by setting the right value.
	 * Should be efficient as the access to the content of the map is
	 * performed only a couple of times. */
	unordered_map<nodeType, nodeType> nodes;

public:
  const static OCPath EMPTY_PATH;
  
public:
	OCPath() : nodes() {  //empty path  
	}
	OCPath(nodeType n) : nodes() {
		insert(n);
	}
  OCPath(OCPath &p) {
		source = p.source;
		nodes = p.nodes;
	}
	vector<nodeType> getPath() {
		vector<nodeType> path(nodes.size());

    unordered_map<nodeType, nodeType>::iterator it;
    for (it = nodes.begin(); it != nodes.end(); ++it) {
      path[it->second] = it->first;
    }
		return path;
	}
	int hopCount() {
		int n = nodes.size();

		if (n != 0) {
			n = n - 1;
		}
		return n;
	}
	int size() {
		return nodes.size();
	}
	inline bool isEmpty() {
		return size() == 0;
	}
	bool hasNode(nodeType node) {
		return nodes.count(node);
	}
	nodeType getHead() {
		return source;
	}
  void insert(nodeType node) {
    int n = nodes.size();
    
    if(n == 0) { 
      this->source = node; 
    }
    nodes[node] = n;
  }
	OCPath operator*(OCPath &right) {
		OCPath left = *this;

		left.insert(right.getHead());

		return left;
	}
};

template <typename T, typename... Args> class OCWeight {
protected:
	tuple<T, Args...> weight;
public: 
  typedef std::tuple<T, Args...> Constraints;
protected:
  static Constraints *constraints;

public:
	OCWeight(T first, Args... others)
		: weight(std::make_tuple(first, others...)) {
	}

	virtual void update(T w1, Args... args) = 0;
	virtual bool check() = 0;

	void operator*=(OCWeight &right) {
		std::apply(this->update, right.weight);
	}
	void operator<=(OCWeight &right) {
		std::apply(this->check, right.weight);
	}
  static void setConstraints(Constraints *constraints) {
    OCWeight<T, Args...>::constraints = constraints;
  }
};

template <typename T, typename... Args> 
tuple<T, Args...> *OCWeight<T, Args...>::constraints = 0;

template <typename T> class OCWeightedPath {

public:
  OCPath path;
	T weight;

public:
  static OCWeightedPath EMPTY_WEIGHTED_PATH;

public:
	OCWeightedPath(T weight) : weight(weight) {
    
	}
  OCWeightedPath(OCWeightedPath &wp) {
    
  }

  OCWeightedPath operator*(OCWeightedPath &right) {
    OCWeightedPath left;
    
    if(this->path.isEmpty() || right.path.isEmpty()) {
      left = OCWeightedPath::EMPTY_WEIGHTED_PATH;
    }
    else {
      OCWeightedPath left = *this;
      left.weight = left.weight * right.weight;
      /*if(!(left.weight <= )) {
        
      }
      else {
              
      }*/
    }
    return left;
  }
};

template <typename T, typename... Args> class OCWeightedPathUnion {};