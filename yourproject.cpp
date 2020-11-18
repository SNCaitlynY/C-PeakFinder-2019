#include<iostream>
#include<cstring>
#include<string>
#include<fstream> 
#include<vector>
using namespace std;
int main(int argc, char *argv[])
{
	int row;
	int column;
	vector<int>r;
	vector<int>c;
	ifstream filein;
	ofstream fileout;
	string name = "./";
	string id = argv[1];
	string matrix = "/matrix.data";
	string fin = "/final.peak";
	string in = name + id + matrix;
	string out = name + id + fin;
	filein.open(in.c_str());
	if (filein)
	{
		filein >> row >> column;
		int mat[row][column];
		while (!filein.eof())
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					filein >> mat[i][j];
				}
			}
		}
		filein.close();

		fileout.open(out.c_str());
		int count = 0;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				if (j == column -1 || mat[i][j] >= mat[i][j + 1])
					if (j == 0 || mat[i][j] >= mat[i][j - 1])
						if (i == row - 1 || mat[i][j] >= mat[i + 1][j])
							if (i == 0 || mat[i][j] >= mat[i - 1][j])
							{
								count++;
								r.push_back(i);
								c.push_back(j);
							}
		fileout << count << endl;
		cout << count << endl;
		for (int i = 0; i < r.size(); i++) 
		{
				fileout << r[i] + 1 << " ";
				cout << r[i] + 1 << " ";
				fileout << c[i] + 1 << " ";
				cout << c[i] + 1 << " ";
				fileout << endl;
				cout << endl;
		}
		fileout.close();
	}
	return 0;
}
