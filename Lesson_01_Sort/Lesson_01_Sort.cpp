#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    //Создание масива
    int n;
    cout << "Ведите размер массива -> ";
    cin >> n;
    int* A = new int[n];

    //Заполнение масива 
    int nn;
    cout << "1-радомные числа\n2-вручную\nВвод -> ";
    cin >> nn;
    switch (nn)
    {
        case 1:
        {
            for (int i = 0; i < n; i++)
            {
                A[i] = rand() % 100;
            }
        }
            break;

        case 2:
        {
            for (int i = 0; i < n; i++)
            {
                cout << "Ввод -> ";
                cin >> A[i];
            }
        }
            break;

        default:
            cout << "Число вне диапозона";
            break;
    }

    //Вывод масива
    cout << endl << "Вывод массива -> ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << "  ";
    }
    
    cout << endl << endl;

    //пузырковая сортировка
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++) {
            if (A[j] > A[j + 1]) {
                int b = A[j];
                A[j] = A[j + 1];
                A[j + 1] = b;
            }
        }
    }
    //Вывод сортированного масива
    cout << "Пузырковая сортировка -> ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << "  ";
    }
    cout << endl;

    //сортировкка выбором
    int count, key;
    for (int i = 0; i < n - 1; i++)
    {
        count = A[i]; 
        key = i;

        for (int j = i+1; j < n; j++)
        {
            if (A[j] < A[key]) key = j;
            if (key != i) {
                A[i] = A[key];
                A[key] = count;
            }
        }
    }

    //Вывод сортированного масива
    cout << "Сортировка выбором -> ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << "  ";
    }
    cout << endl;

    return 0;
}

