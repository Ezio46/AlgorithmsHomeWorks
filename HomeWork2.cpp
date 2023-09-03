#include <iostream>

using namespace std;

int quantity = 0;

int main() 
{
    setlocale(LC_ALL, "Russian");
	for (int i = 000000; i <= 999999; i++)
	{
        int num1 = i / 100000;
        int num2 = (i % 100000) / 10000;
        int num3 = (i % 10000) / 1000;
        int num4 = (i % 1000) / 100;
        int num5 = (i % 100) / 10;
        int num6 = i % 10;
        if (num1 + num2 + num3 == num4 + num5 + num6) 
        {
            quantity++;
        }
    }

    cout << "Количество счастливых билетов " << quantity << endl;
}
