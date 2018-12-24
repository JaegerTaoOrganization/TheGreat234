#include "SATMS.h"
#include "classPutImg.h"

int main() {
	/*setinitmode(INIT_NOBORDER);//设置控制台无边框*/
	initgraph(1000, 600);
	/*Mouse();*/
	putBackgroundimgsky();//背景图片
	putMenu();//菜单
	switch (Mouse()){
		case 1: {cleardevice();
				putBgMap();
				putImg a(100, 100);
				putImg b(200, 200); 

				int x = inputInfoX();
				int y = inputInfoY();
				char Xlocate[10];
				char Ylocate[10];
				outtext(_itoa(x, Xlocate, 10));
				outtext(_itoa(y, Ylocate, 10));
				/*char str[100];
				inputbox_getline("创建景点",
					"请输入该景点的名称：",
					str,
					sizeof(str) / sizeof(*str));*/
				
				break; }
				
		case 0: {exit(0); }
		 
	default:
		break;
	}
	getch();
	closegraph();
	return 0;
}
