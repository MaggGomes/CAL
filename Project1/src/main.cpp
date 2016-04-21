#include "SchoolBus.h"
#include "Graphviewer.h"
#include "GraphCreator.h"

using namespace std;

int main(){
	/*GraphViewer *gv = new GraphViewer(600, 600, false);
	gv->createWindow(600, 600);
	gv->addNode(0, 200, 200);
	gv->addNode(1, 20, 20);
	gv->rearrange();*/


	int tempID = 1;
	//txtCReader(tempID);
	//cout << deg_to_cartLat(41.1800) << " - " << deg_to_cartLong(-8.600) << endl ;

	GraphViewer *gv = graphCreator(txtAReader(),txtBReader() ,txtCReader(tempID));
	gv->rearrange();
	getchar();

	SchoolBus schoolBus;
	schoolBus.menuStarting();




	return 0;
}
