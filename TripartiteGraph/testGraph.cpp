#include <iostream>
#include "TripartiteGraph.h"

using namespace std;
using namespace tptg;

int main()
{	
	tptg::TripartiteGraphVertexParam vparam;
	tptg::TripartiteGraphEdgeParam eparam;
	
	const char* first_inp[]={"aeroplane","bicycle","bird","boat","bottle","person","car","bus","dog","cat","chair","table","cow","table","horse","bike","plant","sheep","sofa","monitor"};
	const char* second_inp[]={"smile","laugh","chew","talk","smoke","eat","drink","cartwheel","clap","climb","climb stairs","dive","fall","backhand flip","handstand","jump","pull up","push up","run","sit down","sit up","somersault","stand up","turn","walk","wave","brush","catch","draw sword","dribble","golf","hit","kick","pick","pour","push","ride","shoot ball","shoot bow","shoot gun","swing bat","exercise","throw","fence","hug","kiss","punch","shake hands","sword fight"};
	const char* third_inp[]={"aeroplane","bicycle","bird","boat","bottle","person","car","bus","dog","cat","chair","table","cow","table","horse","bike","plant","sheep","sofa","monitor"};

	/*vparam.firstvlist.push_back("table");
	vparam.firstvlist.push_back("bottle");
	vparam.firstvlist.push_back("bird");
	vparam.firstvlist.push_back("plant");
	vparam.firstvlist.push_back("person");
	vparam.firstvlist.push_back("car");
	
	
	vparam.secondvlist.push_back("drink");
	vparam.secondvlist.push_back("fall");
	vparam.secondvlist.push_back("talk");
	vparam.secondvlist.push_back("brush");
	vparam.secondvlist.push_back("turn");
	vparam.secondvlist.push_back("climb");
	vparam.secondvlist.push_back("fence");
	vparam.secondvlist.push_back("walk");
	vparam.secondvlist.push_back("hit");
	vparam.secondvlist.push_back("eat");
	vparam.secondvlist.push_back("clap");
	vparam.secondvlist.push_back("laugh");
	vparam.secondvlist.push_back("cartwheel");
	vparam.secondvlist.push_back("pick");
	vparam.secondvlist.push_back("jump");
	
    vparam.thirdvlist.push_back("aeroplane");
	vparam.thirdvlist.push_back("bicycle");
	vparam.thirdvlist.push_back("bird");
	vparam.thirdvlist.push_back("boat");
	vparam.thirdvlist.push_back("person");
	vparam.thirdvlist.push_back("bus");*/
	

    tptg::UndirectedGraph graph;
    TripartiteGraph t(graph,vparam,eparam);
    t.loadVertexParameters(first_inp,first);
    t.loadVertexParameters(second_inp,second);
    t.loadVertexParameters(third_inp,third);
    t.loadEdgeParameters(std::string("firstsecondedgwtoutput.txt"),first);
    t.loadEdgeParameters(std::string("secondthirdedgwtoutput.txt"),second);
    t.constructTPTGraph();
    tptg::edgeprop e=t.getEdgeDescription("talk","person",second);
    cout<<e.weight<<endl;
}
