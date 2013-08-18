#include <iostream>
#include "TripartiteGraph.h"

using namespace std;
using namespace tptg;

int main()
{	
	tptg::TripartiteGraphVertexParam vparam;
	tptg::TripartiteGraphEdgeParam eparam;
	
	vparam.firstvlist.push_back("aeroplane");
	vparam.firstvlist.push_back("bicycle");
	vparam.firstvlist.push_back("bird");
	vparam.firstvlist.push_back("boat");
	vparam.firstvlist.push_back("person");
	vparam.firstvlist.push_back("bus");
	
	
	vparam.secondvlist.push_back("smile");
	vparam.secondvlist.push_back("laugh");
	vparam.secondvlist.push_back("chew");
	vparam.secondvlist.push_back("jump");
	vparam.secondvlist.push_back("clap");
	vparam.secondvlist.push_back("climb");
	
    vparam.thirdvlist.push_back("aeroplane");
	vparam.thirdvlist.push_back("bicycle");
	vparam.thirdvlist.push_back("bird");
	vparam.thirdvlist.push_back("boat");
	vparam.thirdvlist.push_back("person");
	vparam.thirdvlist.push_back("bus");
	
	eparam.firstsecondelist.push_back(std::make_pair(std::string("aeroplane-smile"),13));
	eparam.firstsecondelist.push_back(std::make_pair(std::string("aeroplane-jump"),43));
	eparam.firstsecondelist.push_back(std::make_pair(std::string("person-smile"),123));
	eparam.firstsecondelist.push_back(std::make_pair(std::string("bicycle-climb"),11));
	eparam.firstsecondelist.push_back(std::make_pair(std::string("person-clap"),15));
	
	eparam.secondthirdelist.push_back(std::make_pair(std::string("smile-bus"),3));
	eparam.secondthirdelist.push_back(std::make_pair(std::string("jump-person"),38));
	eparam.secondthirdelist.push_back(std::make_pair(std::string("laugh-bird"),19));
	eparam.secondthirdelist.push_back(std::make_pair(std::string("laugh-person"),73));
	eparam.secondthirdelist.push_back(std::make_pair(std::string("chew-boat"),51));

    tptg::UndirectedGraph graph;
    TripartiteGraph t(graph,vparam,eparam);
    t.constructTPTGraph();
    tptg::edgeprop e=t.getEdgeDescription("aeroplane","jump",first);
    cout<<e.weight<<endl;
}
