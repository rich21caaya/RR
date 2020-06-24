#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <sstream>

namespace Algorithms
{
	/**
	 * The Node ADT
	 *
	 * @author Michael Melachridis
	 */
	template <typename T>
	class Node 
	{
			
	public:
		Node() : value(NULL) {}
		Node(T value) : value(value) {}
		
		inline bool operator ==(const Node<T>& other){ return (other.value == this->value); }
		inline bool operator !=(const Node<T>& other){ return !(other.value == this->value); }
		inline bool operator >(const Node<T>& other){ return (other.value > this->value); }
		inline bool operator <(const Node<T>& other){ return (other.value < this->value); }

		/**
		 * Sets the value of this node
		 */
		inline void setValue(T value) {
			this->value = value;
		}
		
		/**
		 *	Gets the value of this node
		 */
		inline T getValue() const {
			return this->value;
		}

		/**
		 * Prints the value of this node instance
		 */
		friend std::ostream& operator<< (std::ostream& os, const Node<T>& node) {
			std::stringstream ss;
			ss << node.value;
			return (os << ss.str());
		}
		
	private:
		T value;
	};
} // namepsace Algorithms

#endif
