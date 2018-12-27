
#include "graph.h"

int main() {
	/*setinitmode(INIT_NOBORDER);//设置控制台无边框*/
	initgraph(1000, 600);
	setcaption("The Great 234");
	setbkmode(TRANSPARENT);
	MGraph G;
	Mouse0(&G);
	
	getch();
	closegraph();
	return 0;
}
