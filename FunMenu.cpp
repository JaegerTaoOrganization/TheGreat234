#include"SATMS.h"
void putBackgroundimgsky(int i) {
	//输出菜单背景图片
	PIMAGE imgsky = newimage(100, 50);//初始化
	switch (i)
	{
	case 1:getimage(imgsky, "D:\\Picture\\Menu.png", 0, 0);//获取图片地址
		break;
	case 2:getimage(imgsky, "D:\\Picture\\Menu2.png", 0, 0);//获取图片地址
		break;
	case 3:getimage(imgsky, "D:\\Picture\\Menu3.png", 0, 0);//获取图片地址
		break;
	case 4:getimage(imgsky, "D:\\Picture\\Menu4.png", 0, 0);//获取图片地址
		break;
	case 5:getimage(imgsky, "D:\\Picture\\Menu5.png", 0, 0);//获取图片地址
		break;
	case 6:getimage(imgsky, "D:\\Picture\\Menu6.png", 0, 0);//获取图片地址
		break;
	case 7:getimage(imgsky, "D:\\Picture\\Menu7.png", 0, 0);//获取图片地址
		break;
	case 8:getimage(imgsky, "D:\\Picture\\Menu8.png", 0, 0);//获取图片地址
		break;
	case 9:getimage(imgsky, "D:\\Picture\\Menu9.png", 0, 0);//获取图片地址
		break;
	default:
		break;
	}
	putimage(0, 0, 1000,600,imgsky,0,160,1890,1061);//放置图片
	delimage(imgsky);//释放图片指针
	/*setbkcolor(WHITE);*/
}
void putBgMap(int i) {
	//输出地图背景
	setbkcolor(WHITE);
	PIMAGE imgBg = newimage(100, 50);//初始化
	switch (i)
	{
	case 1: getimage(imgBg, "D:\\Picture\\岛屿.png", 0, 0);//获取图片地址
		putimage(0, 0, 800, 605, imgBg, 0, 0, 852, 746);//放置图片
		break;
	case 2: getimage(imgBg, "D:\\Picture\\map.png", 0, 0);//获取图片地址
		putimage(0, 0, 800, 605, imgBg, 0, 0, 479, 426);//放置图片
		break;
	case 3: getimage(imgBg, "D:\\Picture\\map2.jpg", 0, 0);//获取图片地址
		putimage(0, 0, 800, 605, imgBg, 0, 0, 858, 504);//放置图片
		break;
	default:
		break;
	}
	delimage(imgBg);//释放图片指针
	PIMAGE walk = newimage(100, 50);//初始化
	getimage(walk, "D:\\Picture\\walk.gif", 0, 0);//获取图片地址
	putimage(800, 300, 200, 300, walk, 50, 0, 250, 350);//放置图片
	delimage(walk);//释放图片指针
}
void putMenu() {
	//菜单的输出
	setcolor(BLACK);
	setfont(70, 30,"华文琥珀");
	LOGFONTA f;
	getfont(&f);
	f.lfQuality = ANTIALIASED_QUALITY;//抗锯齿
	f.lfWeight = 500;
	setfont(&f);
	setbkmode(TRANSPARENT);//设置文字背景透明
	outtextxy(250, 70, "景区旅游管理系统");
	f.lfHeight = 35;
	f.lfWidth = 15;
	char a[] = "宋体";
	strcpy(f.lfFaceName, a);
	setfont(&f);
	outtextxy(280, 160, "创建景区景点分布图");//x:280-415,y:160-195
	outtextxy(280, 200, "关于我们");//x:280-415,y:200-235
	//outtextxy(280, 240, "输出导游路线图");//x:280-385,y:240-275
	//outtextxy(280, 280, "判断导游线路图有无回路");//x:280-445,y:280-315
	//outtextxy(280, 320, "求两个景点之间的最短距离");//x:280-460,y:320-355
	//outtextxy(280, 360, "输出道路修建规划图");//x:280-415,y:360-395
	outtextxy(280, 240, "退出程序");//x:280-340,y:400-435
}
void putFunMenu(int i) {
	setcolor(BLACK);
	setfont(25, 12, "华文琥珀");
	outtextxy(820, 10, "景区管理界面");
	setfont(15, 7, "黑体");
	outtextxy(815, 40, "可点击的功能选项：");
	switch (i)
	{
	case 0:{
		outtextxy(820, 70, "创建景区景点");
		outtextxy(820, 100, "创建道路");
		outtextxy(820, 130, "鼠标移到这输出导游路线图");
		outtextxy(820, 160, "鼠标移到这输出道路规划");
		outtextxy(820, 190, "两点最短路线");
		outtextxy(820, 230, "返回"); 
		break; }
	case 1: {
		setcolor(RED);
		setfont(15, 7, "华文琥珀");
		outtextxy(820, 70, "创建景区景点");
		setcolor(BLACK);
		setfont(15, 7, "黑体");
		outtextxy(820, 100, "创建道路");
		outtextxy(820, 130, "鼠标移到这输出导游路线图");
		outtextxy(820, 160, "鼠标移到这输出道路规划");
		outtextxy(820, 230, "返回");
		break; }
	case 2:{
		outtextxy(820, 70, "创建景区景点");
		setcolor(RED);
		setfont(15, 7, "华文琥珀");
		outtextxy(820, 100, "创建道路");
		setcolor(BLACK);
		setfont(15, 7, "黑体");
		outtextxy(820, 130, "鼠标移到这输出导游路线图");
		outtextxy(820, 160, "鼠标移到这输出道路规划");
		outtextxy(820, 230, "返回"); break; }
	case 3: {
		outtextxy(820, 70, "创建景区景点");
		outtextxy(820, 100, "创建道路");
		setcolor(RED);
		setfont(15, 7, "华文琥珀");
		outtextxy(820, 130, "鼠标移到这输出导游路线图");
		setcolor(BLACK);
		setfont(15, 7, "黑体");
		outtextxy(820, 160, "鼠标移到这输出道路规划");
		outtextxy(820, 230, "返回"); break; }
	case 4: {
		outtextxy(820, 70, "创建景区景点");
		outtextxy(820, 100, "创建道路");
		outtextxy(820, 130, "鼠标移到这输出导游路线图");
		setcolor(RED);
		setfont(15, 7, "华文琥珀");
		outtextxy(820, 160, "鼠标移到这输出道路规划");
		setcolor(BLACK);
		setfont(15, 7, "黑体");
		outtextxy(820, 230, "返回"); break; }
	case 5: {
		outtextxy(820, 70, "创建景区景点");
		outtextxy(820, 100, "创建道路");
		outtextxy(820, 130, "鼠标移到这输出导游路线图");
		outtextxy(820, 160, "鼠标移到这输出道路规划");
		setcolor(RED);
		setfont(15, 7, "华文琥珀");
		outtextxy(820, 230, "返回"); break; }
	default:
		break;
	}
	
}
int input() {
	//从键盘读入数字字符，返回该数字int型
	setcolor(BLACK);
	outtextxy(400, 500, "请选择功能，输入选项序号");
	int k = 0;
	for (; k != key_esc; ) // key_esc是ege定义的按键常数
	{
		char str[32];
		//等待用户按键，并把得到的按键给k
		//如果你不想等待，可以在调用getch之前，使用kbhit检测是否有按键按下
		//如 if ( kbhit() ) k = getch();
		k = getch();
		//格式化输出为字符串，用于后面输出
		sprintf(str, "%c %3d", k, k);
		outtext(str);
		return atoi(str);
	}
	return 0;
}
int inputInfoX() {
	char str[100];
	inputbox_getline("创建景点",
		"请输入该景点的X坐标(0-800)：",
		str,
		sizeof(str) / sizeof(*str));
	return atoi(str);
}
int inputInfoY() {
	char str[100];
	inputbox_getline("创建景点",
		"请输入该景点的Y坐标(0-550)：",
		str,
		sizeof(str) / sizeof(*str));
	return atoi(str);
}

void putline(int a, int b, int c, int d) {
	setlinestyle(DASHED_LINE, NULL, 6);
	line(a, b, c, d);
}
