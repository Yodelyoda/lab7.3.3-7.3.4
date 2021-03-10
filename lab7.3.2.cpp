#include <iostream>
#include <iomanip>
#include <time.h>
#include <algorithm>
using namespace std;
void Sort(int** a, const int rowCount, const int colCount);
int negcol(int** a, const int rowCount, const int colCount);

void InputRow(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << "a[" << rowNo << "][" << colNo << "] = ";
	cin >> a[rowNo][colNo];
	if (colNo < colCount - 1)
		InputRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}


void InputRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	InputRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		InputRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}
void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < colCount - 1)
		PrintRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	PrintRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		PrintRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}
void Sort(int** a, const int rowCount, const int colCount)
{
	int  rows, cols;
	for (rows = 0; rows < rowCount; rows++)
		sort(a[rows], a[rows] + colCount);
}
int negcol(int** a, const int rowCount, const int colCount)
{
	int foundColumn = 0;
	bool flag;
	for (int i = 0; i < colCount; i++) {
		for (int j = 0; j < rowCount; j++) {
			if (a[j][i] >= 0) {
				flag = true;
				continue;
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag)
			foundColumn = i + 1;
	}
	if (foundColumn)
		cout << "Column number " << foundColumn << " hasn't any negative numbers.\n";
	else
		cout << "All columns contains negative numbers.\n";
	return 0;
}
int main()
{
	int n, k;
	cout << "rowCount = "; cin >> n;//rowCount
	cout << "colCount = "; cin >> k;//colCount
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];
	InputRows(a, n, k, 0);
	PrintRows(a, n, k, 0);
	negcol(a, n, k);
	Sort(a, n, k);
	PrintRows(a, n, k, 0);


	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}