#include "SATMS.h"
#include "graph.h"

int main() {
	/*setinitmode(INIT_NOBORDER);//设置控制台无边框*/
	initgraph(1000, 600);
	setcaption("The Great 234");
	putBackgroundimgsky();
	putMenu();
	MGraph G;
	Mouse1(&G);
	MUSIC music;
	
	getch();
	closegraph();
	return 0;
}
