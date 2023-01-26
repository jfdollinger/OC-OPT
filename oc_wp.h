#pragma once

#include "oc_basic.h"
#include <iostream>

class AbstractOCWeightedPath {
public:
	AbstractOCWeightedPath() {
	}
	virtual std::string toString() = 0;
};

template <class ConcreteOCWeight> class OCWeightedPathUnion;

template <class ConcreteOCWeight>
class OCWeightedPath : public AbstractOCWeightedPath {
protected:
	OCPath path;
	ConcreteOCWeight weight;

public:
	static typename ConcreteOCWeight::MetricsType constraints;
	static const OCWeightedPath<ConcreteOCWeight> EMPTY_WEIGHTED_PATH;

private:
	OCWeightedPath();

public:
	OCWeightedPath(const ConcreteOCWeight &weight, const OCPath &path);
	OCWeightedPath<ConcreteOCWeight>
	operator*(OCWeightedPath<ConcreteOCWeight> &right);
	OCWeightedPathUnion<ConcreteOCWeight>
	operator+(OCWeightedPath<ConcreteOCWeight> &right);
	std::string toString();

public:
	static void
	setConstraints(const typename ConcreteOCWeight::MetricsType &constraints);
};

template <class ConcreteOCWeight>
class OCWeightedPathUnion : public AbstractOCWeightedPath {
protected:
  std::vector<OCWeightedPath<ConcreteOCWeight>> weightedPaths;
public:
	OCWeightedPathUnion(const OCWeightedPath<ConcreteOCWeight> &wp);
  OCWeightedPathUnion(const OCWeightedPath<ConcreteOCWeight> &left, const OCWeightedPath<ConcreteOCWeight> &right);
	OCWeightedPathUnion<ConcreteOCWeight>
	operator*(OCWeightedPath<ConcreteOCWeight> &right);
	OCWeightedPathUnion<ConcreteOCWeight>
	operator+(OCWeightedPath<ConcreteOCWeight> &right);
	std::string toString();
};

template <class ConcreteOCWeight>
const OCWeightedPath<ConcreteOCWeight>
	OCWeightedPath<ConcreteOCWeight>::EMPTY_WEIGHTED_PATH =
		OCWeightedPath<ConcreteOCWeight>();

template <class ConcreteWeight>
typename ConcreteWeight::MetricsType
	OCWeightedPath<ConcreteWeight>::constraints = 0;

template <class ConcreteOCWeight>
OCWeightedPath<ConcreteOCWeight>::OCWeightedPath()
	: AbstractOCWeightedPath(), weight(), path() {
}

template <class ConcreteOCWeight>
OCWeightedPath<ConcreteOCWeight>::OCWeightedPath(
	const ConcreteOCWeight &weight,
	const OCPath &path)
	: AbstractOCWeightedPath(), weight(weight), path(path) {
}

template <class ConcreteOCWeight>
OCWeightedPath<ConcreteOCWeight> OCWeightedPath<ConcreteOCWeight>::
operator*(OCWeightedPath<ConcreteOCWeight> &right) {
	OCWeightedPath<ConcreteOCWeight> left = *this;
	if (left.path.isEmpty() || right.path.isEmpty()) {
		return OCWeightedPath::EMPTY_WEIGHTED_PATH;
	} else {
		left.weight = left.weight * right.weight;
		if (left.weight <= constraints) {
			left.path = left.path * right.path;
		} else {
			return OCWeightedPath::EMPTY_WEIGHTED_PATH;
		}
	}
	return left;
}

template <class ConcreteOCWeight>
OCWeightedPathUnion<ConcreteOCWeight> OCWeightedPath<ConcreteOCWeight>::
operator+(OCWeightedPath<ConcreteOCWeight> &right) {
	return OCWeightedPathUnion<ConcreteOCWeight>();
}

template <class ConcreteOCWeight>
std::string OCWeightedPath<ConcreteOCWeight>::toString() {
	return path.toString() + weight.toString();
}

template <class ConcreteOCWeight>
void OCWeightedPath<ConcreteOCWeight>::setConstraints(const typename ConcreteOCWeight::MetricsType &constraints) {
	OCWeightedPath::constraints = constraints;
}

template <class ConcreteOCWeight>
OCWeightedPathUnion<ConcreteOCWeight>::OCWeightedPathUnion(
	const OCWeightedPath<ConcreteOCWeight> &wp)
	: AbstractOCWeightedPath() {
}

template <class ConcreteOCWeight>
OCWeightedPathUnion<ConcreteOCWeight>::OCWeightedPathUnion(
	const OCWeightedPath<ConcreteOCWeight> &left, const OCWeightedPath<ConcreteOCWeight> &right)
	: AbstractOCWeightedPath() {
    
}

template <class ConcreteOCWeight>
OCWeightedPathUnion<ConcreteOCWeight> OCWeightedPathUnion<ConcreteOCWeight>::
operator*(OCWeightedPath<ConcreteOCWeight> &right) {
	return OCWeightedPathUnion<ConcreteOCWeight>();
}

template <class ConcreteOCWeight>
OCWeightedPathUnion<ConcreteOCWeight> OCWeightedPathUnion<ConcreteOCWeight>::
operator+(OCWeightedPath<ConcreteOCWeight> &right) {
	return OCWeightedPathUnion<ConcreteOCWeight>();
}

template <class ConcreteOCWeight>
std::string OCWeightedPathUnion<ConcreteOCWeight>::toString() {
	return "";
}

/*template <typename T, typename... Args>
class OCWeightedPath : AbstractOCWeightedPath<T, Args...> {
public:
	typedef OCWeight<T, Args...> OCWeightType;

public:
	OCPath *path;
	OCWeightType *weight;

public:
	static OCWeightedPath<T, Args...> EMPTY_WEIGHTED_PATH;
	static typename OCWeightType::ConstraintsType *constraints;

public:
	OCWeightedPath(OCPath *path, OCWeightType *weight) {
		this->path = path;
		this->weight = weight;
	}
	OCWeightedPath(OCWeightedPath &wp) {
	}

	OCWeightedPath<T, Args...> operator*(OCWeightedPath<T, Args...> &right) {
		OCWeightedPath<T, Args...> left = *this;
		if (left.path->isEmpty() || right.path->isEmpty()) {
			return OCWeightedPath::EMPTY_WEIGHTED_PATH;
		} else {
			(*left.weight) = (*left.weight) * (*right.weight);
			// OCWeightType *t = ;
			if (*left.weight <= *constraints) {
				*left.path = (*left.path) * (*right.path);
			} else {
				return OCWeightedPath::EMPTY_WEIGHTED_PATH;
			}
		}
		return left;
	}

	OCWeightedPath operator+(OCWeightedPath &right) {
		return OCWeightedPath::EMPTY_WEIGHTED_PATH;
	}

	void print() {
		std::cout << "" << std::endl;
	}


	static OCWeight<T, Args...> *
	setOCWeightFabric(OCWeight<T, Args...> *(OCWeightFabric)(T, Args...)) {
	}
};

template <typename T, typename... Args>
typename OCWeightedPath<T, Args...>::OCWeightType::ConstraintsType
	*OCWeightedPath<T, Args...>::constraints = 0;

template <typename T, typename... Args> class OCWeightedPathUnion {};
*/