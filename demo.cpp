#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"
#include "gdiplus.h"
#pragma  comment(lib,"gdiplus.lib")

using namespace std;
using namespace Gdiplus;

void picTOtxt(wchar_t* picPath, string txtPath)
{
	GdiplusStartupInput gdiplusstartupinput;
	ULONG_PTR gdiplustoken;
	GdiplusStartup(&gdiplustoken, &gdiplusstartupinput, nullptr);

	wstring infilename(picPath);
	string outfilename(txtPath);
	//¶ÁÍ¼Æ¬
	Bitmap* bmp = new Bitmap(infilename.c_str());
	UINT height = bmp->GetHeight();
	UINT width = bmp->GetWidth();
	cout << "width:" << width << ",height:" << height << endl;

	Color color;
	ofstream fout(outfilename.c_str());

	for (int y = 0; y < height; y++)
	for (int x = 0; x < width; x++)
	{
		bmp->GetPixel(x, y, &color);
		fout << (int)color.GetRed() << "," << endl;
		fout << (int)color.GetGreen() << "," << endl;
		fout << (int)color.GetBlue() << "," << endl;
	}
	fout.close();

	delete bmp;
	GdiplusShutdown(gdiplustoken);
}

int main()
{
	picTOtxt(L"1.JPG", "color.txt");
	return 0;

}