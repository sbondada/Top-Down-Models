/*******************************************************************
 * Video2Text
 * Copyright (c) 2013, Jason Corso
 * All rights reserved.
 *
 *
 *******************************************************************
 * \file   TDMTripartiteGraph.cpp
 * \author Kaushal Bondada (sbondada@buffalo.edu)
 *              
 * DESCRIPTION: 
 *   this is the implemetation of Tripartite Graph using Boost Library
 *   it has the functions to create the graph based on the parameter sets
 *   and to view the contents of the edges and the vertex nodes
 *
 ********************************************************************
 */
 /*! \file TDMTripartiteGraph.cpp
 * \brief this is the implemetation of Tripartite Graph using Boost Library
 *   it has the functions to create the graph based on the parameter sets
 *   and to view the contents of the edges and the vertex nodes
 **/
 
#include "TripartiteGraph.h"

using namespace std;
using namespace boost;
using namespace tptg;


void TripartiteGraph::constructTPTGraph()
{
	 typedef typename tptg::UndirectedGraph::vertex_property_type Name;
	 for(int i=0;i<vparam.firstvlist.size();i++)
	 {
		 frstlist.nodelist.push_back(add_vertex(Name(vparam.firstvlist[i]),udgraph));
	 }
	 for(int i=0;i<vparam.secondvlist.size();i++)
	 {
		 scndlist.nodelist.push_back(add_vertex(Name(vparam.secondvlist[i]),udgraph));
	 }
	 for(int i=0;i<vparam.thirdvlist.size();i++)
	 {
		 thrdlist.nodelist.push_back(add_vertex(Name(vparam.thirdvlist[i]),udgraph));
	 } 
	 
	std::vector<std::string> splitstr;
	typename graph_traits<tptg::UndirectedGraph>::vertex_descriptor src,tgt;
	int matchsrc,matchtgt;
	for(int i=0;i<eparam.firstsecondelist.size();i++)
	{
	boost::split(splitstr,eparam.firstsecondelist[i].first,boost::is_any_of("-"));
	if(splitstr.size()==2)
	{
		matchsrc=getIndex(vparam.firstvlist,splitstr[0]);
		matchtgt=getIndex(vparam.secondvlist,splitstr[1]);
		if(matchsrc!=-1 && matchtgt!=-1)
		{
		src=frstlist.nodelist[matchsrc];
		tgt=scndlist.nodelist[matchtgt];
		typename graph_traits<tptg::UndirectedGraph>::edge_descriptor e1;
		bool found;
		boost::tie(e1,found)=add_edge(src,tgt,udgraph); 
		udgraph[e1].edgename=eparam.firstsecondelist[i].first;
		udgraph[e1].weight=eparam.firstsecondelist[i].second;
		}	
	}
	}
	for(int i=0;i<eparam.secondthirdelist.size();i++)
	{
	boost::split(splitstr,eparam.secondthirdelist[i].first,boost::is_any_of("-"));
	if(splitstr.size()==2)
	{
		matchsrc=getIndex(vparam.secondvlist,splitstr[0]);
		matchtgt=getIndex(vparam.thirdvlist,splitstr[1]);
		if(matchsrc!=-1 && matchtgt!=-1)
		{
		src=scndlist.nodelist[matchsrc];
		tgt=thrdlist.nodelist[matchtgt];
		typename graph_traits<tptg::UndirectedGraph>::edge_descriptor e1;
		bool found;
		boost::tie(e1,found)=add_edge(src,tgt,udgraph); 
		udgraph[e1].edgename=eparam.secondthirdelist[i].first;
		udgraph[e1].weight=eparam.secondthirdelist[i].second;
		}	
	}
	}
	return ;
}

int TripartiteGraph::getIndex(std::vector<std::string>& collist,std::string matchstr)
{
	int index=0;
	for(std::vector<std::string>::iterator it = collist.begin(); it != collist.end(); ++it) 
	{
		if(matchstr.compare(*it)==0)
		{
			return index;
		}
		else
		{
			index++;
	    }
    }
    return -1;
}

edgeprop TripartiteGraph::getEdgeDescription(std::string source,std::string target,type sourcetype)
{
	typename property_map < tptg::UndirectedGraph,std::string edgeprop::*>::type
    edgname = get(&edgeprop::edgename, udgraph);
    typename property_map < tptg::UndirectedGraph,float edgeprop::*>::type
    edgweight = get(&edgeprop::weight, udgraph);
	typename graph_traits< tptg::UndirectedGraph>::vertex_descriptor src,tgt;
	typename graph_traits<tptg::UndirectedGraph>::edge_descriptor e1;
	bool found;
    tptg::edgeprop edgedescription;
	int matchsrc,matchtgt;
	if(sourcetype==first)
	{
	matchsrc=getIndex(vparam.firstvlist,source);
	matchtgt=getIndex(vparam.secondvlist,target);
		if(matchsrc!=-1 && matchtgt!=-1)
		{
		src=frstlist.nodelist[matchsrc];
		tgt=scndlist.nodelist[matchtgt];
	    boost::tie(e1,found)=edge(src,tgt,udgraph);
	    edgedescription.edgename=get(edgname,e1);
	    edgedescription.weight=get(edgweight,e1);
	    return edgedescription;
		}
	}	
	else if(sourcetype==second)
	{
	matchsrc=getIndex(vparam.secondvlist,source);
	matchtgt=getIndex(vparam.thirdvlist,target);
		if(matchsrc!=-1 && matchtgt!=-1)
		{
		src=scndlist.nodelist[matchsrc];
		tgt=thrdlist.nodelist[matchtgt];
		boost::tie(e1,found)=edge(src,tgt,udgraph);
	    edgedescription.edgename=get(edgname,e1);
	    edgedescription.weight=get(edgweight,e1);
	    return edgedescription;
		}
	}	
	cout<<"edge not found"<<endl;
}

std::string TripartiteGraph::getVertexDescription(std::string nodename,type wordtype)
{
	typename property_map < tptg::UndirectedGraph, vertex_name_t >::type
    vname = get(vertex_name, udgraph);
	typename graph_traits<tptg::UndirectedGraph>::vertex_descriptor vertexnode;
	int matchnode;
	if(wordtype==first)
	{
		matchnode=getIndex(vparam.firstvlist,nodename);
		vertexnode=frstlist.nodelist[matchnode];
	}
	else if(wordtype==second)
	{
		matchnode=getIndex(vparam.secondvlist,nodename);
		vertexnode=scndlist.nodelist[matchnode];
	}
	else 
	{
		matchnode=getIndex(vparam.thirdvlist,nodename);
		vertexnode=thrdlist.nodelist[matchnode];
	}
	return get(vname,vertexnode);
}


