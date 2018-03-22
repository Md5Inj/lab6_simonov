#include <iostream>
#include <cstdarg>
using namespace std;

double findCount(int x, int n, ...)
{
    va_list vl;
    va_start(vl, n);
    int arg = 0, count = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        arg = va_arg(vl, int);
        if (arg < 0 && arg % 2 != 0)
        {
            count++;
            sum += arg;
        }
    }
 
    va_end(vl);
    if (count != 0)
        return sum / count;
    else
        return 0;
}

int main()
{
    int X = 3;
    cout << "findCount(X, 3, -5, 2, -13): ";
    cout << findCount(X, 3, -5, 2, -13) << endl;
    system("read _");
    return 0;
}