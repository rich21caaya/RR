#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <vector>
#include <list>
#include <string> 
#include <sstream>
#include <utility>
#include <string>

#include "Node.h"
#include "Edge.h"

namespace Algorithms
{
	const int MAX_GRAPH_SIZE = 50;

	/**
	 *	This class implements a parameterized <code>Graph</code> class used
	 *	to represent <b><i>graphs,</i></b> which consist of a set of
	 *	<b><i>nodes</i></b> (vertices) and a set of <b><i>arcs</i></b> (edges).
	 *
	 *  It supports the following operations: 
	 *		1) V (G): returns the number of vertices in the graph
	 *		2) E (G): returns the number of edges in the graph
	 *		3) adjacent (G, x, y): tests whether there is an edge from node x to node y
	 *		4) neighbors (G, x): lists all nodes y such that there is an edge from x to y
	 *		5) add (G, x, y): adds to G the edge from x to y, if it is not there
	 *		6) delete (G, x, y): removes the edge from x to y, if it is there
	 *		7) get_node_value (G, x): returns the value associated with the node x
	 *		8) set_node_value( G, x, a): sets the value associated with the node x to a
	 *		9) get_edge_value( G, x, y): returns the value associated to the edge (x,y)
	 *	   10) set_edge_value (G, x, y, v): sets the value associated to the edge (x,y) to v
	 *
	 *  This implementation uses an adjacency-lists representation, which 
	 *  is a vectror of lists of <code>Edge</code> objects.
	 *
	 *  @author Michael Melachridis (michael.melachirdis@gmail.com)
	 */
	class Graph
	{
	public:

		typedef std::list<Edge<int>*> listOfEdges; 					// a list of edges
		typedef listOfEdges::iterator listOfEdgesItr;				// the associated iterator of list of edges
		typedef listOfEdges::const_iterator listOfEdgesConstItr;

		/**
		 * Initializes an empty graph with V vertices (50 by default) and 0 edges.
		 * 
		 * @param V the number of vertices
		 */
		Graph(int V = MAX_GRAPH_SIZE);


        /**
         * Initializes a graph with data read from file.
         *
         * @param filename The file name of the input data of integer triples: (i, j, cost).
         */
        Graph(const std::string& filename);

		/**
		 * Destructor
		 */
		~Graph();

		/**
		 * Initializes a new graph that is a deep copy of other.
		 *
		 * @param other the graph to copy
		 */
		Graph(const Graph& other);

		/**
		 * Creates a cloned object of this
		 * @return A pointer to the new Graph object
		 */
		Graph* clone() const;

		/**
		 * Copy data from other's storage to this storage (deep copy)
		 *
		 * @param other the graph to copy
		 */
		Graph& operator=(const Graph& other);

		/**
		 * Compare if two graphs are equal
		 *
		 * @param other the graph to compare
		 * @return	TRUE if equal and false otherwise
		 */
		bool operator==(const Graph& other) const;

		/**
		 * Compare if two graphs are not equal
		 *
		 * @param other the graph to compare
		 * @return	TRUE if not equal and false otherwise
		 */
		bool operator!=(const Graph& other) const;

		/**
		 * Returns the number of vertices in this graph.
		 *
		 * @return the number of vertices in this graph
		 */
		inline int getV() const { return this->V; }

		/**
		 * Returns the number of edges in this graph.
		 *
		 * @return the number of edges in this graph
		 */
		inline int getE() const { return this->E; }

		/**
		 * Tests whether there is an edge from node x to node y
		 *
		 * @param x the node x
		 * @param y the node y
		 * @return TRUE if there is an edge from node x to node y,
		 * 		   and FALSE otherwise
		 */
		bool isAdjacent(int x, int y) const;

		/**
		 * Lists all nodes y such that there is an edge from x to y
		 *
		 * @param x the node to search for edges
		 * @return A list of all nodes where x has an edge to y
		 */
		const listOfEdges getNeighbors(int x) const;

		/**
		 * Adds the undirected edge x-y to this graph.
		 *
		 * @param x one vertex in the edge
		 * @param y the other vertex in the edge
		 * @param w the weight
		 * @note  w = 0 for undirected graphs by default
		 * @return TRUE if it is not there and FALSE otherwise
		 */
		bool addEdge(int x, int y, double w = 0.0);

		/**
		 * Removes an undirected edge x-y from this graph.
		 * @param x one vertex in the edge
		 * @param y the other vertex in the edge
		 * @return TRUE if it is there and FALSE otherwise
		 */
		bool removeEdge(int x, int y);

		/**
		 * Returns the pointer of the <code>Node</code> associated with the x value.
		 * @param x node value to search for
		 * @return a pointer to the <code>Node</code> associated with the x value
		 */
		const Node<int>* getNodeValue(int x) const;

		/**
		 * Sets the value associated with the node x to a
		 * @param x node to be set to a
		 */
		void setNodeValue(int x, int a);

		/**
		 * Sets the value associated to the edge (x,y) to v.
		 * @param x node
		 * @param y node
		 * @param v the new value to associate (weight)
		 */
		void setEdgeValue(int x, int y, double v);

		/**
		 * Returns the pointer of <code>Edge</code> associated to the edge (x,y).
		 * @param x node
		 * @param y node
		 * @return pointer of <code>Edge</code> associated to the edge (x,y)
		 */
		const Edge<int>* getEdgeValue(int x, int y) const;

		/**
		 * Returns the degree of vertex
		 * @param v v the vertex
		 * @return the degree of vertex
		 */
		int getDegree(int v) const;

		/**
		 * Produces a randomly generated set of edges with positive distances
		 * @see https://en.wikipedia.org/wiki/Monte_Carlo_method
		 *
		 * @param density the graph density (how many edges are in
		 * 		  set E compared to the maximum possible number of edges
		 * 		  between vertices in set V)
		 * @param minDistance the lower range of the edge weight (cost)
		 * @param maxDistance the lower range of the edge weight (cost)
		 */
		void generateRandomGraph(double density, double minDistance, double maxDistance);

		/**
		 * Returns a reference to the internal adjacency list
		 * @return a reference to the internal adjacency list
		 */
		std::vector< std::list<Edge<int>* > >& getAdjacencyList() { return this->adjacencyList; }

		/**
		 *	Prints out the graph structure
		 */
		friend std::ostream& operator<<(std::ostream& os, const Graph& gragh);

	private:
		int V;
		int E;
		std::vector< std::list<Edge<int>* > > adjacencyList;

		/// Conversion from string to template type.
		//  Types that you would like to convert to
		//  need to implement instream operator >>().
		template <class Type>
		Type convert(const std::string& str) {
		        Type result;
		        std::istringstream sin(str);
		        sin >> result;
		        return result;
		}
	};

} // namepsace Algorithms
#endif
