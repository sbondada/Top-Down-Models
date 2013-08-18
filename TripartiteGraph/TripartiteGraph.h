/*******************************************************************
 * Video2Text
 * Copyright (c) 2013, Jason Corso
 * All rights reserved.
 *
 *
 *******************************************************************
 * \file   TDMTripartiteGraph.h
 * \author Kaushal Bondada (sbondada@buffalo.edu)
 *              
 * DESCRIPTION: 
 *   
 * This defines the functions required to construct the tripatite graph
 * and also the structures and enum used in the construction of the 
 * graphs.
 *
 ********************************************************************
 */
/*! \file TDMTripartiteGraph.h
 * \brief This defines the functions required to construct the tripatite graph
 * and also the structures and enum used in the construction of the 
 * graphs.
 **/
 
#ifndef TRIPARTITEGRAPH_H
#define TRIPARTITEGRAPH_H

#include <boost/config.hpp> // kept it to suppress some VC++ warnings

#include <iostream>
#include <iterator>
#include <algorithm>
#include <time.h>

#include <boost/utility.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/algorithm/string.hpp>

namespace tptg
{

enum type{first,second,third};

struct TripartiteGraphVertexParam
{
	std::vector<std::string> firstvlist;
	std::vector<std::string> secondvlist;
	std::vector<std::string> thirdvlist;
};

struct TripartiteGraphEdgeParam
{

	std::vector<std::pair<std::string,int> > firstsecondelist;
	std::vector<std::pair<std::string,int> > secondthirdelist;
};

struct edgeprop
{
	std::string edgename;
	float weight;
};

typedef boost::property < boost::vertex_name_t,std::string >name;
typedef boost::adjacency_list < boost::vecS, boost::vecS, boost::undirectedS,name,edgeprop,boost::vecS> UndirectedGraph;

struct Collection
{
	std::vector<boost::graph_traits<UndirectedGraph>::vertex_descriptor> nodelist; 
};

class TripartiteGraph
{
	
private:

UndirectedGraph udgraph;
TripartiteGraphVertexParam vparam;
TripartiteGraphEdgeParam eparam;
Collection frstlist;
Collection scndlist;
Collection thrdlist;

public:

TripartiteGraph(UndirectedGraph& tptgraph,TripartiteGraphVertexParam& vparameters,TripartiteGraphEdgeParam& eparameters):udgraph(tptgraph),vparam(vparameters),eparam(eparameters){}

void constructTPTGraph();

int getIndex(std::vector<std::string>& collist,std::string matchstr);

edgeprop getEdgeDescription(std::string source,std::string target,type sourcetype);

std::string getVertexDescription(std::string nodename,type wordtype);

};
}
#endif
