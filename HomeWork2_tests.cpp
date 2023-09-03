#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    vector<int> N_in; 
    vector<long long> N_out;

    for (int i = 0; i <= 9; i++) {

        string filenameIn = "test." + to_string(i) + ".in";
        ifstream file1(filenameIn);

        string filenameOut = "test." + to_string(i) + ".out";
        ifstream file2(filenameOut);

        if (!file1 || !file2) {
            cerr << "Не удалось открыть один из файлов: " << endl;
            return 1;
        }

        int N;
        long long M;
        if (file1 >> N && file2 >> M) {
            N_in.push_back(N);
            N_out.push_back(M);
        }
        else {
            cerr << "Ошибка чтения значения N или M из файла" << endl;
        }

        file1.close();
        file2.close();

    }

    for (int i = 0; i < N_in.size(); i++) {
        int N0 = N_in[i];

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

        if (quantity == N_out[i]) cout << "Тест для " << N << "-значных билетов " << "пройден" << endl;
        else cout << "Тест не пройден  " << endl;
    }


    return 0;
}