#include"SATMS.h"

void putBackgroundimgsky() {
	//输出菜单背景图片
	PIMAGE imgsky = newimage(100, 50);//初始化
	getimage(imgsky, "D:\\Picture\\view.jpg", 0, 0);//获取图片地址
	putimage(0, 0, imgsky);//放置图片
	delimage(imgsky);//释放图片指针
	/*setbkcolor(WHITE);*/
}
void putBgMap() {
	//输出地图背景
	PIMAGE imgsky = newimage(100, 50);//初始化
	getimage(imgsky, "D:\\Picture\\sky.jpg", 0, 0);//获取图片地址
	putimage(0, 0, imgsky);//放置图片
	delimage(imgsky);//释放图片指针
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
	outtextxy(280, 200, "输出景区景点分布图");//x:280-415,y:200-235
	outtextxy(280, 240, "输出导游路线图");//x:280-385,y:240-275
	outtextxy(280, 280, "判断导游线路图有无回路");//x:280-445,y:280-315
	outtextxy(280, 320, "求两个景点之间的最短距离");//x:280-460,y:320-355
	outtextxy(280, 360, "输出道路修建规划图");//x:280-415,y:360-395
	outtextxy(280, 400, "退出程序");//x:280-340,y:400-435
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
		"请输入该景点的X坐标：",
		str,
		sizeof(str) / sizeof(*str));
	return atoi(str);
}
int inputInfoY() {
	char str[100];
	inputbox_getline("创建景点",
		"请输入该景点的Y坐标：",
		str,
		sizeof(str) / sizeof(*str));
	return atoi(str);
}
int Mouse() {//点击功能模块，返回其对应序号
	mouse_msg msg = { 0 };
	for (; is_run(); delay_fps(60))
	{
		//获取鼠标消息，这个函数会等待，等待到有消息为止
		//类似地，有和kbhit功能相近的函数MouseHit，用于检测有没有鼠标消息
		int X, Y;
		while (mousemsg())
		{
			msg = getmouse();
		}
		//格式化输出为字符串，用于后面输出
		//msg和flag常数请参考文档或者mouse_msg_e, mouse_flag_e的声明
		/*xyprintf(0, 0, "x = %10d  y = %10d",
		msg.x, msg.y, msg.wheel);
		xyprintf(0, 20, "move  = %d down  = %d up    = %d",
		(int)msg.is_move(),
		(int)msg.is_down(),
		(int)msg.is_up());
		xyprintf(0, 40, "left  = %d mid   = %d right = %d",
		(int)msg.is_left(),
		(int)msg.is_mid(),
		(int)msg.is_right());
		xyprintf(0, 60, "wheel = %d  wheel rotate = %d",
		(int)msg.is_wheel(),
		msg.wheel);*/
		mousepos(&X, &Y);
		if (X >= 280 && X <= 415 && Y >= 160 && Y <= 195 && msg.is_left()) {
			return 1;
		}
		else if (X >= 280 && X <= 415 && Y >= 200 && Y <= 235 && msg.is_left()) {
			return 2;
		}
		else if (X >= 280 && X <= 385 && Y >= 240 && Y <= 275 && msg.is_left()) {
			return 3;
		}
		else if (X >= 280 && X <= 445 && Y >= 280 && Y <= 315 && msg.is_left()) {
			return 4;
		}
		else if (X >= 280 && X <= 460 && Y >= 320 && Y <= 355 && msg.is_left()) {
			return 5;
		}
		else if (X >= 280 && X <= 415 && Y >= 360 && Y <= 395 && msg.is_left()) {
			return 6;
		}
		else if (X >= 280 && X <= 340 && Y >= 400 && Y <= 435 && msg.is_left()) {
			return 0;
		}
	}
	return 0;
}
