#pragma once
#ifndef SUCCESS
#define SUCCESS 1//标志位成功
#endif 
#ifndef FAILURE 
#define FAILUER 0//标志位失败
#endif
#ifndef INF
#define INF 0x3f3fffff//标志位无穷
#endif
#ifndef MAXNUM
#define MAXNUM 20
#endif

#include<stdio.h>
#include<iostream>
using namespace std;
typedef bool Status;//定义函数状态数据类型
//Status Vertex[MAXNUM];
typedef char Vertextype[MAXNUM][MAXNUM];//定义顶点向量数据类型
typedef int AdjMatrix[MAXNUM][MAXNUM];//定义邻接矩阵数据类型

typedef struct Graph {//定义图数据类型
	Vertextype Vexs;//图的顶点向量
	AdjMatrix Arcs;//图的邻接矩阵
	int VexNum;//图的当前顶点
	int ArcNum;//图的当前弧
}*pGraph;//定义图的指针数据类型

typedef struct CloseEdge {//定义辅助数组数据类型
	Vertextype Vexs;//图的顶点向量
	int Lowcost[MAXNUM];//最短路径
}*pCloseEdge;//定义辅助数组指针数据
