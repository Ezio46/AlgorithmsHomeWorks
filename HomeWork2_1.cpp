#include <iostream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int N0 = 10;
    int N = 2 * N0; 

    vector<vector<long long>> SumQuantity(N + 1, vector<long long>(N * 9 + 1, 0));
    // SumQuantity - количество способов получить сумму j при количестве цифр i
    
    // Тривиальные случаи
    for (int j = 0; j <= 9; j++) {
        SumQuantity[1][j] = 1;
    }

    // Вычисление SumQuantity[i][j] для всех i > 1 и j
    // в соответствии с рекурентной формулой:
    //            9
    //    Nn(k) = ∑ Nn–1(k – l);
    //          l = 0

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= N * 9; j++) {
            for (int l = 0; l <= 9; l++) {
                if (j >= l) {
                    SumQuantity[i][j] += SumQuantity[i - 1][j - l];
                }
            }
        }
    }

    long long quantity = 0; 

    for (int j = 0; j <= N * 9; j++) {
        quantity += SumQuantity[N0][j] * SumQuantity[N0][j];
    }

    cout << "Количество счастливых " << N << "-значных билетов: " << quantity << endl;

    return 0;
}