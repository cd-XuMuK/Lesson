#include <iostream>

using namespace std;



void qsortRecursive(int* mas, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    int mid = mas[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (mas[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while (mas[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if (j > 0) {
        //"Левый кусок"
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {
        //"Првый кусок"
        qsortRecursive(&mas[i], size - i);
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    //Создание масива
    int n;
    cout << "Ведите размер массива -> ";
    cin >> n;
    int* A = new int[n];

    int end = sizeof(A) / sizeof(A[0]);

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

    ////пузырковая сортировка
    //for (int i = 0; i < n; i++)
    //{
    //    for (int j = 0; j < n - 1; j++) {
    //        if (A[j] > A[j + 1]) {
    //            int b = A[j];
    //            A[j] = A[j + 1];
    //            A[j + 1] = b;
    //        }
    //    }
    //}
    ////Вывод сортированного масива
    //cout << "Пузырковая сортировка -> ";
    //for (int i = 0; i < n; i++)
    //{
    //    cout << A[i] << "  ";
    //}
    //cout << endl;

    ////сортировкка выбором
    //int count, key;
    //for (int i = 0; i < n - 1; i++)
    //{
    //    count = A[i]; 
    //    key = i;

    //    for (int j = i+1; j < n; j++)
    //    {
    //        if (A[j] < A[key]) key = j;
    //        if (key != i) {
    //            A[i] = A[key];
    //            A[key] = count;
    //        }
    //    }
    //}

    ////Вывод сортированного масива

    qsortRecursive(A, n);

    cout << "Сортировка выбором -> ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << "  ";
    }
    cout << endl;



    return 0;
}

