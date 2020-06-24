#ifndef EDGE_H_
#define EDGE_H_

#include "Node.h"
#include <stdexcept>

namespace Algorithms
{
	/**
	 * The Edge ADT
	 *
	 * @author Michael Melachridis
	 */
	template <typename T>
	class Edge 
	{
	public:
		Edge() : x(NULL), y(NULL), weight(0.0) {}

		Edge(Node<T>* x, Node<T>* y, double weight = 0.0) : x(x), y(y), weight(weight) {}

		~Edge() {
			delete x;
			delete y;
		}

		inline bool operator==(const Edge<T>& other) { 
			return (other.getX() == this->getX() && other.getY() == this->getY()); 
		}
	
		inline Node<T>* getX() const {
			return x;
		}

		inline Node<T>* getY() const {
			return y;
		}

		inline double getWeight() const {
			return weight;
		}

		/**
		 * Returns either end-point of this edge.
		 *
		 * @return either end-point of this edge
		 */
		inline int either() {
			return getX()->getValue();
		}

		/**
		 * Returns the end-point of this edge that is different from the given vertex.
		 *
		 * @param  vertex one end-point of this edge
		 * @return the other end-point of this edge
		 *
		 * @throws <code>std::invalid_argument</code> if the vertex is not one of the
		 *         end-points of this edge
		 */
		int other(int vertex) {
			if (vertex == getX()->getValue())
				return getY()->getValue();
			else if (vertex == getY()->getValue())
				return getX()->getValue();
			else
				throw std::invalid_argument("Illegal end-point");
		}

		/**
		 * Prints the value of this node instance
		 */
		friend std::ostream& operator<< (std::ostream& os, const Edge<T>& edge) {
			std::stringstream ss;
			ss << "(" << edge.x << " " << "-" << " " << edge.y << ")";
			return (os << ss.str());
		}

	private:
		Node<T>* x;	// vertex X
		Node<T>* y; // vertex Y
		double	weight;
	};
} // namespace Algorithms
#endif
