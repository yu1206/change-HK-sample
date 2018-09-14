
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include "opencv\cv.h"
#include "opencv\highgui.h"
using namespace cv;
using namespace std;
int test21(int argc, char *argv[])
{
	int classlabel = 11; 
	string  labelpath = "I:\\calibration\\港澳车牌\\biaoji\\1\\0_text.txt";
	string  labelpathone = "I:/calibration/港澳车牌/biaoji/1/0_one.txt";
	string imagepath = "I:/calibration/港澳车牌/biaoji/1/";

	fstream finRead;
	finRead.open(labelpath, ios::in);
	if (!finRead.is_open())
	{
		cout << "finRead 文件数据打开错误！" << endl;
		system("pause");
		return false;
	}

	fstream finWrite;
	finWrite.open(labelpathone, ios::out);
	if (!finWrite.is_open())
	{
		cout << "finRead 文件数据打开错误！" << endl;
		system("pause");
		return false;
	}

	string line;
	while (getline(finRead, line))
	{
		if (line.empty())
		{
			break;
		}
		fstream fin1;
		fin1.open(line);
		cout << line.c_str() << endl;
		if (!fin1.is_open())
		{
			cout << "error" << endl;
			cout << line.c_str() << endl;
			cout << "fin1 文件数据打开错误！" << endl;
			system("pause");
			return false;
		}
		string line1;
		while (getline(fin1, line1))
		{
			string name; int label; int x1, y1, x2, y2;
			stringstream str_s(line1);
			str_s >> name>>label >> x1 >> y1 >> x2 >> y2;
			if (label == classlabel)
			{
				string temp = name;
				temp.replace(name.find_last_of("."), 4, ".jpg");

				temp = imagepath + temp;
				finWrite << temp << " " << label << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

				/*Mat img = imread(temp.c_str());
				string temp1 = name;
				temp1.replace(name.find_last_of("."), 4, ".jpg");
				string path12 = imagepath + "saveimg/" + temp1;
				imwrite(path12.c_str(), img);*/
			}
			
		}
		fin1.close();
	}
	finRead.close();
	finWrite.close();
	return 0;
}
