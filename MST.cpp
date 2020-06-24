/**
 * MST.cpp
 *
 *  Created on: Jan 6, 2017
 *      Author: Michael Melachridis
 *       Email: michael.melachridis@gmail.com
 */

#include "MST.h"
#include <cassert>
#include <limits>

namespace Algorithms
{
	MST::MST(Graph& graph) :
		edgeTo(std::vector<Edge<int>* >(graph.getV())),
		distTo(std::vector<double>(graph.getV(), std::numeric_limits<double>::max())),
		marked(std::vector<bool>(graph.getV())),
		pq(graph.getV())
	{
		for (int v = 0; v < graph.getV(); v++)     	// run from each vertex to find
			if (!marked[v])
				prim(graph, v);    					// minimum spanning forest
	}

	void MST::prim(Graph& g, int s) {
		distTo[s] = 0.0;
		pq.push(s, distTo[s]);

		while (!pq.isEmpty()) {
			int v = pq.top(); //pq.delMin();
			pq.pop();
			scan(g, v);
		}
	}

	void MST::scan(Graph& g, int v) {
		marked[v] = true;
		std::vector<std::list<Edge<int>*> > adj = g.getAdjacencyList();

		for (Edge<int>* e : adj[v]) {
			int w = e->other(v);
			if (marked[w])
				continue;         // v-w is obsolete edge
			if (e->getWeight() < distTo[w]) {
				distTo[w] = e->getWeight();
				edgeTo[w] = e;
				if (pq.contains(w))
					pq.changePriority(w, distTo[w]);
				else
					pq.push(w, distTo[w]);
			}
		}
	}

	const std::vector<Edge<int>* > MST::edges() {
		std::vector<Edge<int>*> mst;
		for (unsigned int v = 0; v < edgeTo.size(); v++) {
			Edge<int>* e = edgeTo[v];
			if (e != NULL) {
				mst.push_back(e);
			}
		}
		return mst;
	}

	double MST::cost() {
		double weight = 0.0;
		for (Edge<int>* e : edges())
			weight += e->getWeight();
		return weight;
	}
}
