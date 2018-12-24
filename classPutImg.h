#pragma once
#include"SATMS.h"
class putImg
{
public:
	putImg(int xx, int yy);//在指定位置输出一张图片,x，y为横纵坐标，,最多输出8张图片
	putImg( putImg &p);
	~putImg();
	/*friend class ArrayofputImg;*/
	int getN() { return n; }
private:
	int x;
	int y;
	static int n;
};
int putImg::n = 0;
putImg::putImg(int xx,int yy){
	//在指定位置输出一张图片,x，y为横纵坐标,最多输出8张图片
	x = xx; y = yy;
	n++;
	PIMAGE imgsky = newimage(100, 50);//初始化
	switch (n)
	{
	case 1:getimage(imgsky, "D:\\Picture\\cat.jpg", 50, 50);//获取图片地址
		putimage(x, y, 50, 50, imgsky, 0, 0, 585, 720);//放置图片
		break;
	case 2:getimage(imgsky, "D:\\Picture\\sky.jpg", 50, 50);//获取图片地址
		putimage(x, y, 50, 50, imgsky, 0, 0, 585, 720);//放置图片
		break;
	case 3:getimage(imgsky, "D:\\Picture\\sky.jpg", 50, 50);//获取图片地址
		break;
	case 4:getimage(imgsky, "D:\\Picture\\sky.jpg", 50, 50);//获取图片地址
		break;
	default:
		break;
	}
	delimage(imgsky);//释放图片指针
}
putImg::putImg(putImg &p) {
	x = p.x; y = p.y;
	n = p.n;
}
putImg::~putImg()
{
}

//class ArrayofputImg {//图片数组类
//private:
//	int size;//图片数组大小
//	putImg *pI;//图片数组指针
//public:
//	ArrayofputImg(int size) {
//		pI = new putImg[size];
//	}
//	ArrayofputImg(ArrayofputImg &a) {
//		size = a.size;
//		pI = a.pI;
//	}
//	~ArrayofputImg(){}
//	putImg &element(int index) {
//		return pI[index];
//	}
//};
