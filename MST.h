#ifndef MST_H_
#define MST_H_

#include "Graph.h"
#include "PriorityQueue.h"

namespace Algorithms
{
	/**
	 * The {@code MST} class represents a data type for computing a
	 * <em>minimum spanning tree</em> in an edge-weighted graph
	 * using Prim's greedy algorithm.
	 *
	 * @author Michael Melachridis (michael.melachirdis@gmail.com)
	 */
	class MST
	{
	public:

		/**
		 * Compute a minimum spanning tree of an edge-weighted graph.
		 *
		 * @param graph the edge-weighted graph
		 */
		MST(Graph& graph);

		/**
		 * Runs Prim's algorithm
		 *
		 * @param Graph g The graph
		 * @param s The source vertex
		 */
		void prim(Graph& g, int s);

		/**
		 * Scan vertex v
		 *
		 * @param g The graph
		 * @param v The vertex to scan
		 */
		void scan(Graph& g, int v);

		/**
		 * Returns the edges in a minimum spanning tree
		 * @return the edges in a minimum spanning tree as a vector of edges
		 */
		const std::vector<Edge<int>*> edges();

		/**
		 * Returns the sum of the edge weights in a minimum spanning tree.
		 * @return the total cost
		 */
		double cost();

	private:
		std::vector<Edge<int>* > edgeTo;   	// edgeTo[v] = shortest edge from tree vertex to non-tree vertex
		std::vector<double> distTo;    		// distTo[v] = weight of shortest such edge
		std::vector<bool> marked;			// marked[v] = true if v on tree, false otherwise
		PriorityQueue<double> pq;			// A min heap of priorities
	};
}

#endif /* MST_H_ */
