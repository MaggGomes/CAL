#include "SchoolBus.h"
#include "Graphviewer.h"
#include "GraphCreator.h"

using namespace std;

// TODO - APAGAR - grafo de testes
Graph<int> CreateTestGraph(){
	Graph<int> myGraph;

	for(int i = 0; i < 20; i++)
		myGraph.addVertex(i);

	myGraph.addEdge(0, 1, 2);
	myGraph.addEdge(0, 3, 7);
	myGraph.addEdge(1, 3, 3);
	myGraph.addEdge(1, 4, 5);
	myGraph.addEdge(2, 0, 2);
	myGraph.addEdge(0, 2, 2);
	myGraph.addEdge(2, 5, 5);
	myGraph.addEdge(3, 2, 1);
	myGraph.addEdge(3, 4, 1);
	myGraph.addEdge(3, 5, 6);
	myGraph.addEdge(3, 6, 4);
	myGraph.addEdge(4, 6, 2);
	myGraph.addEdge(5, 4, 2);
	myGraph.addEdge(5, 3, 3);
	myGraph.addEdge(6, 5, 4);
	myGraph.addEdge(6, 7, 1);
	myGraph.addEdge(7, 6, 1);
	myGraph.addEdge(7, 8, 2);
	myGraph.addEdge(8, 9, 5);
	myGraph.addEdge(9, 12, 5);
	myGraph.addEdge(10, 11, 1);
	myGraph.addEdge(6, 14, 3);
	myGraph.addEdge(13, 4, 1);
	myGraph.addEdge(10, 17, 6);
	myGraph.addEdge(15, 18, 4);
	myGraph.addEdge(5, 16, 8);
	myGraph.addEdge(16, 18, 2);
	myGraph.addEdge(17, 19, 2);
	myGraph.addEdge(6, 10, 3);
	myGraph.addEdge(12, 15, 4);
	myGraph.addEdge(18, 3, 4);

	return myGraph;
}

int main(){

	// TODO - APAGAR -  c�digo de teste


	/////////////////////////////////////////////
	Graph<int> test = CreateTestGraph();

	int ints[] = {3,5,7,8,12,14,15,17};
	vector<int> vec (ints, ints + sizeof(ints) / sizeof(int) );

	test.dijkstraShortestPath(0);
	Graph<int> multPointsGraph = test.multiplePoints(test,0,19,vec);

	GraphViewer * gv = new GraphViewer(800, 600, true);
	gv->createWindow(800, 600);
	gv->defineVertexColor("blue");
	gv->defineEdgeCurved(false);

	vector<Vertex<int>*> routes = multPointsGraph.getVertexSet();
	vector<vector<Vertex<int>*> > testeRotas = multPointsGraph.getShortestPathAllPoints(routes[0], routes[routes.size()-1]);



	cout << "num rotas: " << testeRotas.size() << endl;
	for (unsigned int i = 0; i < testeRotas.size(); i++)
		for (unsigned int j = 0; j < testeRotas[i].size(); j++)
			cout << "| ponto: " << testeRotas[i][j]->getInfo();


	cout << "custo:" << multPointsGraph.edgeCost(3, 5);


	for (unsigned int i = 0; i < routes.size(); i++){
		gv->addNode(routes[i]->getInfo());
		gv->setVertexSize(routes[i]->getInfo(), 5);
		routes[i]->gvNodeID = routes[i]->getInfo();
	}

	unsigned int counter = 0;
	for (unsigned int i = 0; i < routes.size(); i++){
		for (int unsigned j = 0; j < routes[i]->adj.size(); j++){
			gv->addEdge(counter++, routes[i]->gvNodeID,
					routes[i]->adj[j].getDest()->gvNodeID,
					EdgeType::DIRECTED);

			routes[i]->adj[j].setGvEdgeID(counter);
			gv->setEdgeWeight(counter-1, routes[i]->adj[j].getWeigth());
		}
	}

	//////////////////////////////////////////////////////////////

	SchoolBus schoolBus(CreateTestGraph());
	schoolBus.loadData();
	schoolBus.menuStarting();

	/*int tempID = 1;
	GraphViewer *gv = graphCreator(txtAReader(),txtBReader() ,txtCReader(tempID));
	gv->rearrange();
	getchar();*/



	return 0;
}
