// Lab2CodInfo.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma pack(push,1)
#include "pch.h"
#include <iostream>
#include <fstream>

typedef struct
{
unsigned int    bfType;
unsigned long   bfSize;
unsigned int    bfReserved1;
unsigned int    bfReserved2;
unsigned long   bfOffBits;
} BITMAPFILEHEADER;

typedef struct
{
	unsigned int    biSize;
	int             biWidth;
	int             biHeight;
	unsigned short  biPlanes;
	unsigned short  biBitCount;
	unsigned int    biCompression;
	unsigned int    biSizeImage;
	int             biXPelsPerMeter;
	int             biYPelsPerMeter;
	unsigned int    biClrUsed;
	unsigned int    biClrImportant;
} BITMAPINFOHEADER;

typedef struct
{
	int   rgbBlue;
	int   rgbGreen;
	int   rgbRed;
	int   rgbReserved;
} RGBQUAD;
#pragma pop

static unsigned short read_u16(FILE *fp);
static unsigned int   read_u32(FILE *fp);
static int            read_s32(FILE *fp);

void printBMPHeader(std::string path) {
	std::ifstream read(path, std::ios::binary);
	if (read) {
		BITMAPFILEHEADER fh;
		
		read.read((char*)&fh, sizeof(BITMAPFILEHEADER));
		//if (fh.bfType != 0x4D42) {
			std::cout << "Not BMP file\n";
			//return;
		//}
		std::cout << "Size of file = " << fh.bfSize << "\nImage start at = " << fh.bfOffBits << std::endl;
		BITMAPINFOHEADER fih;
		read.read((char*)&fih, sizeof(BITMAPINFOHEADER));
		std::cout << "Wigth of image = " << fih.biWidth << "\nHeight of image = " << fih.biHeight << "\nPlanes = " << fih.biPlanes << "\nBit in pixel = " << fih.biBitCount << "\nType of compession = " << fih.biCompression
			<< "\nX resolution = " << fih.biXPelsPerMeter << "\nY resolution = " << fih.biYPelsPerMeter << "\nUsed colors = " << fih.biClrUsed << "\nImportant colors = " << fih.biClrImportant << std::endl;
	}
}

int main()
{
	printBMPHeader("H:\\bmp.bmp");
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
