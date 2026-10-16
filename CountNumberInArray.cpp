#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void vValidation(int& Number)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Must be a Number: ";
		cin >> Number;
	}
}

void vNumberZone(int& Number, int From, int To)
{
	while (Number < From || Number > To)
	{
		cout << "Must be (" << From << "-" << To << "): ";
		cin >> Number;
		vValidation(Number);
	}
}

int iReadNumber(string Text)
{
	int Number;

	cout << Text;
	cin >> Number;
	vValidation(Number);

	return Number;
}

int iGetRandNum(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

void vGenerateRandomMatrix(int Arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Cols; i++)
	{
		for (short j = 0; j < Rows; j++)
		{
			Arr[i][j] = iGetRandNum(0, 9);
		}
	}
}

void vPrintArray(int Arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Cols; i++)
	{
		for (short j = 0; j < Rows; j++)
		{
			printf(" %d    ", Arr[i][j]);
		}
		cout << endl;
	}
}

int iCountNumberInMatrix(int Arr[3][3], short Rows, short Cols, int Number)
{
	int Counter = 0;
	for (short i = 0; i < Cols; i++)
	{
		for (short j = 0; j < Rows; j++)
		{
			if (Arr[i][j] == Number)
				Counter++;
		}
	}

	return Counter;
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[3][3];
	int Number, NumberCounter;
	short Rows = 3, Cols = 3;

	vGenerateRandomMatrix(Arr, Rows, Cols);
	cout << "-Matrix:\n";
	vPrintArray(Arr, Rows, Cols);

	Number = iReadNumber("\nEnter a number to count in matrix: ");
	vNumberZone(Number, 0, 9);
	NumberCounter = iCountNumberInMatrix(Arr, Rows, Cols, Number);
	cout << "\nNumber " << Number << " Count in matrix is " << NumberCounter << "\n\n";

	return 0;
}
