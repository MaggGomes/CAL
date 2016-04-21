#include "SchoolBus.h"
#include "Graphviewer.h"
#include "GraphCreator.h"

using namespace std;

Graph<int> CreateTestGraph()
		{
	Graph<int> myGraph;

	for(int i = 1; i < 8; i++)
		myGraph.addVertex(i);

	myGraph.addEdge(1, 2, 2);
	myGraph.addEdge(1, 4, 7);
	myGraph.addEdge(2, 4, 3);
	myGraph.addEdge(2, 5, 5);
	myGraph.addEdge(3, 1, 2);
	myGraph.addEdge(3, 6, 5);
	myGraph.addEdge(4, 3, 1);
	myGraph.addEdge(4, 5, 1);
	myGraph.addEdge(4, 6, 6);
	myGraph.addEdge(4, 7, 4);
	myGraph.addEdge(5, 7, 2);
	myGraph.addEdge(6, 4, 3);
	myGraph.addEdge(7, 6, 4);

	return myGraph;
		}

int main(){
	/*GraphViewer *gv = new GraphViewer(600, 600, false);
	gv->createWindow(600, 600);
	gv->addNode(0, 200, 200);
	gv->addNode(1, 20, 20);
	gv->rearrange();*/


	/*int tempID = 1;

	GraphViewer *gv = graphCreator(txtAReader(),txtBReader() ,txtCReader(tempID));
	gv->rearrange();
	getchar();

	SchoolBus schoolBus;
	schoolBus.menuStarting();*/




	return 0;
}
