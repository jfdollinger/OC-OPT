#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>

using std::tuple;
using std::unordered_map;
using std::vector;

typedef uint16_t nodeType;

class OCPath {
private:
	/*
	 * Keeping the source node appart to improve computation of the star
	 * operator.
	 */
	nodeType source;

	/*Unordered set of nodes. Order is provided by setting the right value.
	 * Should be efficient as the access to the content of the map is
	 * performed only a couple of times. */
	unordered_map<nodeType, nodeType> nodes;

public:
	const static OCPath EMPTY_PATH;

public:
	OCPath() : nodes() { // empty path
	}
	OCPath(nodeType n) : nodes() {
		insert(n);
	}
	OCPath(const OCPath &p) {
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

		if (n == 0) {
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

template <class ConcreteWeight, typename T, typename... Args>
class AbstractOCWeight {
public:
  typedef std::tuple<T, Args...> MetricsType;
public:
	std::tuple<T, Args...> weight;

	AbstractOCWeight() {
	}
	AbstractOCWeight(T first, Args... others)
		: weight(std::make_tuple(first, others...)) {
	}

	AbstractOCWeight(ConcreteWeight &w) {
		this->weight = w.weight;
	}

	virtual ConcreteWeight operator*(ConcreteWeight &right) = 0;
	virtual bool operator<=(tuple<T, Args...> &right) = 0;
};
