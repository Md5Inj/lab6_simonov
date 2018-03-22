#include <iostream>
#include <ctime>

using namespace std;

void setRandom(double* array, int N)
{
	for (int i = 0; i < N; i++)
	{
		array[i] = rand() % 10 - 5;
	}
}

void print(double* array, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int min(double* array, int N)
{
	int pos = 0; double min = array[0];
	for (int i = 0; i < N; i++)
	{
		if (abs(array[i]) < abs(min))
		{
			min = array[i];
			pos = i;
		}
	}

	return pos;
}

double sum(double* array, int N)
{
	double sum = 0;
	bool negative = false;
	for (int i = 0; i < N; i++)
	{
		if (negative) sum += abs(array[i]);
		if (array[i] < 0) negative = true;
	}

	return sum;
}

void delRange(double r1, double r2, double* array, int N)
{
	int count = 0;
	double* temp = new double[N];

	for (int i = 0; i < N; i++)
	{
		if (array[i] < r1 || array[i] > r2)
		{
			temp[count++] = array[i];
		}
	}

	for (int i = 0; i < count; i++)
	{
		array[i] = temp[i];
	}

	for (int i = count; i < N; i++)
	{
		array[i] = 0;
	}
}

int main()
{
	const int N = 10;
	double r1 = 0, r2 = 0;
	srand((unsigned)time(0));
	double array[N];
	setRandom(array, N);
	print(array, N);
	cout << "Position of min element from module is " << min(array, N) << endl;
	cout << "Sum of module of elements after first negative digit " << sum(array, N) << endl;
	cout << "Input range: "; cin >> r1 >> r2;
	delRange(r1, r2, array, N);
	print(array, N);
	system("pause");
    return 0;
}