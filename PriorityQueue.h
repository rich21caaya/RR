/**
 * PriorityQueue.h
 *
 *  Created on: Dec 25, 2016
 *      Author: Michael Melachridis
 *       Email: michael.melachridis@gmail.com
 */

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include <vector>
#include <algorithm>
#include <sstream>
#include <cassert>

namespace Algorithms
{
	/**
	 *	This class models a structure called a priority queue.
	 *	Lower priority numbers correspond to higher effective properties
	 *
	 *	@see https://en.wikipedia.org/wiki/Priority_queue
	 *
	 *	@author Michael Melachridis
	 */
	template <typename T>
	class PriorityQueue
	{
	public:

		/**
		 * Initializes a new empty priority queue
		 */
		PriorityQueue(int maxCapacity) : heap(std::vector<HeapEntry>(maxCapacity)), currentSize(0) {}

		~PriorityQueue() {
			this->clear();
		}

		/**
		 * Adds element to the queue with the specified priority in O(log N) time
		 * @param element the element to be added
		 * @param priority its priority
		 */
		void push(T element, double priority) {
			// double size of array if necessary
			int length = heap.size();
			if (currentSize == length - 1)
				heap.resize(2 * length);

			// add element, and percolate it up to maintain heap invariant
			int hole = ++currentSize;

			heap[hole].value = element;
			heap[hole].priority = priority;
			percolateUp(hole);
		}

		/**
		 * Removes the item with the highest priority value
		 * @note time complexity is O(log N) time
		 */
		void pop() {
			assert (currentSize > 0);
			heap[1] = heap[currentSize--];
			percolateDown(1);
		}

		/**
		 * Changes the priority of queue element.
		 *
		 * @param element 	The node element
		 * @param priority	the new priority
		 */
		void changePriority(T element, double priority) {
			heap[currentSize].value = element;
			heap[currentSize].priority = priority;
			percolateUp(currentSize);
		}

		/**
		 * removes the top element of the queue.
		 * @see <code>pop</code>
		 */
		int delMin() {
			int u = top();
			pop();
			return u;
		}

		/**
		 * Checks if queue contains element
		 *
		 * @param element the element to be checked upon
		 * @return <code>true</code> if it does and <code>false</code> otherwise
		 */
		bool contains(T element) {
			for (int i = 0; i < currentSize; i++) {
				if (heap[i].value == element) {
					return true;
				}
			}
			return false;
		}

		/**
		 * Returns the top element of the queue.
		 * @return the top element of the queue
		 */
		T& top() {
			return heap[1].value;
		}

		/**
		 * Return the number of queue elements.
		 * @return the number of queue elements
		 */
		int size() {
			return currentSize;
		}

		/**
		 * Removes all elements from the priority queue.
		 */
		void clear() {
			heap.clear();
		}

		/**
		 * Checks if the priority queue contains no elements.
		 * @return Returns <code>true</code> if the priority queue contains no elements,
		 *         and <code>false</code> otherwise
		 */
		bool isEmpty() const {
			return (currentSize == 0);
		}

		/**
		 *	Prints out the priority queue
		 */
		friend std::ostream& operator<<(std::ostream& os, const PriorityQueue<T>& pq) {
			std::stringstream ss;

			for (int i = 0; i < pq.currentSize+1; i++) {
				ss << pq.heap[i].value << "(" << pq.heap[i].priority << ")" << std::endl;
			}
			return (os << ss.str());
		}

	private:

		void swap(int i, int j) {
			HeapEntry temp = heap[i];
			heap[i] = heap[j];
			heap[j] = temp;
		}

		bool greater(int i, int j) {
            return (heap[i].priority > heap[j].priority);
		}

		void percolateUp(int k) {
			while (k > 1 && greater(k / 2, k)) {
				swap(k, k / 2);
				k = k / 2;
			}
		}

		void percolateDown(int k) {
			while (2 * k <= currentSize) {
				int j = 2 * k;
				if (j < currentSize && greater(j, j + 1))
					j++;
				if (!greater(k, j))
					break;
				swap(k, j);
				k = j;
			}
		}

		struct HeapEntry {
			T value;
			double priority;
		};

		std::vector<HeapEntry> heap;
		int currentSize;
	};
}

#endif /* PRIORITYQUEUE_H_ */
