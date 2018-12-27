#pragma once
#include<stdio.h>
#include"classPutImg.h"

typedef char Vertextype; //顶点类型,用string 数组存每个顶点名字
typedef int Edgetype;//每条边权值类型，表示距离
typedef int Boolean;//布尔类型，其值是TURE或者FALSE
#define maxvex 30//最大顶点数
#define Wuqiong 10000//带权图，表示没有路时的权值
#define OK 1;

//typedef int Pathmatirx[maxvex][maxvex];
//typedef int ShortPathTable[maxvex][maxvex];
typedef struct {
	Edgetype arc[maxvex][maxvex];//邻接矩阵，边表
	int numvertextype, numedgetype;//图中当前的顶点数和边数
}MGraph;
struct Ver {
	Vertextype Vex[10];//顶点名字
	int x;
	int y;
};
struct Ver vex[maxvex];
Boolean visit[maxvex];//深度优先遍历算法时，给顶点打标志
int DFS_count;//连通分量数，判断有无回路

void CreateMGraph(MGraph *G);//创建邻接矩阵,也就是整幅图
void DFS(MGraph G, int i);//深度优先遍历算法实现过程
extern void DFSTraverse(MGraph G);//深度优先遍历的操作
extern void circle(MGraph G);//判断是否有回路
extern void MiniTree_Prim(MGraph);//判断最小生成树,普里姆算法
extern void ShortPath_Floyd(MGraph G, int P[][30], int D[][30]);//弗洛伊德算法，求最短距离
void Mouse1(MGraph *G);//点击功能模块，返回其对应序号
void Mouse2(MGraph *G,int i);
void Mouse0(MGraph *G);
//页面切换函数
//创建页面
void pageCreate(int i) {
	cleardevice();
	putBgMap(i);
}//创建页面


//基础功能函数
void CreateMGraph(MGraph *G)
{
	int i, j;
	//printf("输入顶点数和边数:\n");
	//scanf_s("%d %d", &G->numvertextype, &G->numedgetype);
	char str[10]="0";
	do{
		inputbox_getline("创建景点",
			"请输入景区的景点数量(1-8)：",
			str,
			sizeof(str) / sizeof(*str));
		G->numvertextype = atoi(str);
	} while (atoi(str)<=0||atoi(str)>8);
	inputbox_getline("创建景点",
		"请输入景区通路数量：",
		str,
		sizeof(str) / sizeof(*str));
	G->numedgetype = atoi(str);
	//printf("输入每个顶点的名字和坐标\n");
	for (i = 0; i < G->numvertextype; i++) {
		//scanf_s("%s %d %d", &vex[i].Vex, 10, &vex[i].x, &vex[i].y);//给每个顶点取名字
		inputbox_getline("创建景点",
			"请输入景点的名称：",
			vex[i].Vex,
			sizeof(vex[i].Vex) / sizeof(*vex[i].Vex));
		vex[i].x = inputInfoX();
		vex[i].y = inputInfoY();
	}
	for (i = 0; i < G->numvertextype; i++) {
		for (j = 0; j < G->numvertextype; j++) {
			if (i == j) {
				G->arc[i][j] = 0;
			}
			else {
				G->arc[i][j] = Wuqiong;
			}
		}
	}
}
void CreateRoad(MGraph *G) {
	int i,j,w,k;
	for (k = 0; k < G->numedgetype; k++) {
		//printf("输入边的下标i，j，和要赋的权值\n");
		//scanf_s("%d %d %d", &i, &j, &w);
		char str[10];
		inputbox_getline("创建道路",
			"请输入起点的序号：",
			str,
			sizeof(str) / sizeof(*str));
		i = atoi(str);
		inputbox_getline("创建道路",
			"请输入终点的序号：",
			str,
			sizeof(str) / sizeof(*str));
		j = atoi(str);
		w = (int)pow(pow(vex[i].x-vex[j].x,2)+pow(vex[i].y-vex[j].y,2),0.5);//求距离
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];
		/*putline(vex[i].x + 25, vex[i].y + 50, vex[j].x + 25, vex[j].y + 50);
		char outw[10];
		_itoa_s(w,outw,4,10);
		setcolor(WHITE);
		outtextxy((vex[i].x + vex[j].x) / 2, (vex[i].y + vex[j].y) / 2, outw);*/
	}	
}
void DFS(MGraph G, int i) {
	int j;
	visit[i] = 1;
	//printf("%s %d %d", vex[i].Vex, vex[i].x, vex[i].y);//打印顶点
	putImg(vex[i].x, vex[i].y);
	setfont(25, 10, "华文琥珀");
	outtextxy(vex[i].x-5, vex[i].y+45, vex[i].Vex);
	for (j = 0; j < G.numvertextype; j++) {
		if (G.arc[i][j] != 0 && G.arc[i][j] != Wuqiong && !visit[j]) {
			DFS(G, j);//递归加for循环，等于多个函数同时进行，这也是如果只有一个连通分量就不会出这个函数的基础
		}
	}
}
void DFSTraverse(MGraph G) {
	int i;
	for (i = 0; i < G.numvertextype; i++) {
		visit[i] = 0;//给每个顶点标记未走过
	}
	for (i = 0; i < G.numvertextype; i++) {
		if (!visit[i]) {
			DFS_count++;//判断几个连通分量
			DFS(G, i);//未访问过的点进入递归循环，如果只有一个连通分量，只会执行一次
		}
	}
	for (i = 0; i < G.numvertextype; i++) {
		for (int j = 0; j < G.numvertextype; j++) {
			if (G.arc[i][j] != Wuqiong) {
				setcolor(RED);
				putline(vex[i].x + 25, vex[i].y + 50, vex[j].x + 25, vex[j].y + 50);
				char outw[10];
				_itoa_s(G.arc[i][j], outw, 4, 10);
				setcolor(WHITE);
				outtextxy((vex[i].x + vex[j].x) / 2, (vex[i].y + vex[j].y) / 2, outw);
			}
		}
	}
}
void circle(MGraph G) {
	if (DFS_count + G.numedgetype > G.numvertextype) {
		printf("存在回路\n");
	}
	else {
		printf("不存在回路\n");
	}
}
void MiniTree_Prim(MGraph G) {
	int min, i, j, k;
	int adjvex[maxvex];//把每个顶点下标存入
	int lowcost[maxvex];//用来存每个顶点的权值好进行比较
	lowcost[0] = 0;//第一个顶点的权值为0
	adjvex[0] = 0;//初始化第一个顶点下标为0
	for (i = 1; i < G.numvertextype; i++) {
		lowcost[i] = G.arc[0][i];//把跟第一个顶点有关的边的权值加进去，没有关的就把无穷加进去
		adjvex[i] = 0;//先全部给0，这个数组主要是为了打印哪条边而存在，对于算法进程关系不大
	}
	for (i = 1; i < G.numvertextype; i++) {
		min = Wuqiong;//先把最小的设为无穷
		j = 1; k = 0;//从一开始，如果和v0有边的就会进入判断
		while (j < G.numvertextype) {
			if (lowcost[j] != 0 && lowcost[j] < min) {
				min = lowcost[j];//把最小值设为第一条边的权值与后面几条边的权值比较
				k = j;//j要变，所以要赋给另一个变量
			}
			j++;
		}
		/*printf("(%s %d %d)", vex[adjvex[k]].Vex,  vex[adjvex[k]].x, vex[adjvex[k]].y);
		printf("(%s %d %d)", vex[k].Vex, vex[k].x, vex[k].y);*/
		setcolor(BLUE);
		putline(vex[adjvex[k]].x+2,vex[adjvex[k]].y+2,vex[k].x+2,vex[k].y+2);
		lowcost[k] = 0;//当前权值为0，表示已经录入这条边
		for (j = 1; j < G.numvertextype; j++) {
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) {//因为与第一个顶点无关的都设为了无穷，这里就把与选中的第二个顶点有关的边的权值录入，原本是无穷。不等于0的原因是不录入已经录入的边
				lowcost[j] = G.arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}
void ShortPath_Floyd(MGraph G, int P[][30], int D[][30]) {
	int v, w, k;
	for (v = 0; v < G.numvertextype; v++) {
		for (w = 0; w < G.numvertextype; w++) {
			D[v][w] = G.arc[v][w];//给D数组赋上每条边的权值
			P[v][w] = w;
		}
	}
	for (k = 0; k < G.numvertextype; k++) {
		for (v = 0; v < G.numvertextype; v++) {
			for (w = 0; w < G.numvertextype; w++) {
				if (D[v][w] > D[v][k] + D[k][w]) {
					D[v][w] = D[v][k] + D[k][w];//暴力求解，k值为此次循环路径必经过的点，所以它会求出所有点到所有点的最短距离，无穷必被替代
					P[v][w] = P[v][k];//经过哪些路径的下标显示
				}
			}
		}
	}
	/*printf("输入你要查找哪个点到哪个点的最短距离\n");
	scanf_s("%d %d", &v, &w);
	printf("%d\n", D[v][w]);*/
	char str[10] = "0";
	inputbox_getline("查找两个景点最短路径",
		"请输入起点序号：",
		str,
		sizeof(str) / sizeof(*str));
	v = atoi(str);
	inputbox_getline("查找两个景点最短路径",
		"请输入终点序号：",
		str,
		sizeof(str) / sizeof(*str));
	w = atoi(str);
	//printf("%s %d %d\n", vex[v].Vex, vex[v].x, vex[v].y);//源点名字，x坐标，y坐标
	putImg(vex[v].x, vex[v].y);
	setfont(25, 10, "华文琥珀");
	outtextxy(vex[v].x - 5, vex[v].y + 45, vex[v].Vex);
	k = P[v][w];
	int xx = vex[v].x; 
	int yy = vex[v].y;
	putImg(xx, yy);
	while (k != w) {
		//printf("%s %d %d\n", vex[k].Vex, vex[k].x, vex[k].y);//经过的中途各个顶点的名字，x坐标，y坐标
		putImg(vex[v].x, vex[v].y);
		setfont(25, 10, "华文琥珀");
		for(;is_run()&&xx+60<vex[v].x&&yy<vex[v].y;delay_fps(60)){
			xx = xx + 50;
			yy = yy + 50;
			putImg(xx, yy);
		}
		putImg((vex[v].x+xx)/6, (vex[v].y+yy)/6);
		
		putImg((vex[v].x + xx)* 2 / 3, (vex[v].y + yy)* 2 / 3);
		
		putImg(vex[v].x, vex[v].y);
		outtextxy(vex[k].x - 5, vex[k].y + 45, vex[k].Vex);
		xx = vex[k].x;
		yy = vex[k].y;
		k = P[k][w];
	}
	//printf("%s %d %d\n", vex[w].Vex, vex[w].x, vex[w].y);//终点名字，x坐标，y坐标
	putImg((vex[w].x), (vex[w].y));
}


void Mouse1(MGraph *G) {//二级菜单，点击功能模块
	mouse_msg msg = { 0 };
	for (; is_run(); delay_fps(60))
	{
		cleardevice();
		putBackgroundimgsky(3);
		//putMenu();
		setfont(15, 7, "华文琥珀");
		xyprintf(0, 0, "%d %d",
			msg.x, msg.y, msg.wheel);
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
		if (X >= 655 && X <= 805 && Y >= 190 && Y <= 225 ) {
			putBackgroundimgsky(6);
			if (msg.is_left()) {
				pageCreate(1);
				Mouse2(G,1);
			}
		}
		else if (X >= 655 && X <= 805 && Y >= 240 && Y <= 275 ) {
			putBackgroundimgsky(7);
			if (msg.is_left()) {
				pageCreate(2);
				Mouse2(G,2);
			}
		}
		else if (X >= 655 && X <= 805 && Y >= 295 && Y <= 325 ) {
			putBackgroundimgsky(8);
			if (msg.is_left()) {
				pageCreate(3);
				Mouse2(G,3);
			}
		}
		/*else if (X >= 280 && X <= 445 && Y >= 280 && Y <= 315 && msg.is_left()) {
		return 4;
		}
		else if (X >= 280 && X <= 460 && Y >= 320 && Y <= 355 && msg.is_left()) {
		return 5;
		}
		else if (X >= 280 && X <= 415 && Y >= 360 && Y <= 395 && msg.is_left()) {
		return 6;
		}*/
		else if (X >= 655 && X <= 805 && Y >= 344 && Y <= 375 ) {
			putBackgroundimgsky(9);
			if (msg.is_left()) {
				Mouse0(G);
			}
		}
	}
}
void Mouse2(MGraph *G,int i) {//三级菜单，点击功能模块
	mouse_msg msg = { 0 };
	for (; is_run(); delay_fps(60))
	{
		//获取鼠标消息，这个函数会等待，等待到有消息为止
		//类似地，有和kbhit功能相近的函数MouseHit，用于检测有没有鼠标消息
		cleardevice();
		putBgMap(i);
		putFunMenu(0);
		setfont(15, 7, "华文琥珀");
		xyprintf(0, 0, "%d %d",
			msg.x, msg.y, msg.wheel);
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
		if (X >= 815 && X <= 1000 && Y >= 70 && Y <= 85) {
			cleardevice();
			putBgMap(i);
			putFunMenu(1);
			if(msg.is_left()) 
				CreateMGraph(G);
		}
		else if (X >= 815 && X <= 1000 && Y >= 100 && Y <= 115) {
			cleardevice();
			putBgMap(i);
			putFunMenu(2);
			if (msg.is_left())
				CreateRoad(G);
		}
		else if (X >= 815 && X <= 1000 && Y >= 130 && Y <= 145) {
			cleardevice();
			putBgMap(i);
			putFunMenu(3);
			DFSTraverse(*G);
		}
		else if (X >= 815 && X <= 1000 && Y >= 160 && Y <= 175) {
			cleardevice();
			putBgMap(i);
			putFunMenu(4);
			DFSTraverse(*G);
			MiniTree_Prim(*G);
		}
		else if (X >= 815 && X <= 1000 && Y >= 190 && Y <= 205 && msg.is_left()) {
			cleardevice();
			putBgMap(i);
			int P[30][30]; int D[30][30];
			ShortPath_Floyd(*G,P,D);
		}
		/*else if (X >= 280 && X <= 415 && Y >= 360 && Y <= 395 && msg.is_left()) {
		return 6;
		}*/
		else if (X >= 815 && X <= 1000 && Y >= 230 && Y <= 245) {
			cleardevice();
			putBgMap(i);
			putFunMenu(5);
			if (msg.is_left()) {
				putBackgroundimgsky(1);
				putMenu();
				Mouse1(G);
			}
		}
	}
}
void Mouse0(MGraph *G) {//一级菜单
	mouse_msg msg = { 0 };
	for (; is_run(); delay_fps(60))
	{
		cleardevice();
		putBackgroundimgsky(1);
		//putMenu();
		setfont(15, 7, "华文琥珀");
		xyprintf(0, 0, "%d %d",
			msg.x, msg.y, msg.wheel);
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
		if (X >= 390 && X <= 540 && Y >= 190 && Y <= 230 ) {
			putBackgroundimgsky(2);
			if (msg.is_left()) 
				Mouse1(G);
		}
		else if (X >= 390 && X <= 540 && Y >= 276 && Y <= 314 ) {
			putBackgroundimgsky(4);
		}
		/*else if (X >= 280 && X <= 385 && Y >= 240 && Y <= 275 && msg.is_left()) {
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
		}*/
		else if (X >= 390 && X <= 540 && Y >= 370 && Y <= 405) {
			putBackgroundimgsky(5);
			if(msg.is_left())
			exit(0);
		}
	}
}
