#include <iostream>
#include <locale>

using namespace std;

void remove(char* exp, unsigned short int* startindex, unsigned short int* count)
{
    unsigned short int i = 0;
    unsigned short int sum = 0;
    while (exp[i] != '*')
    {
        i++;
        sum++;
    }
    char* new_exp = new char[sum + 1];
    cout << sum;
    
    
    for (int i = *startindex; i < *count + *startindex; i++)
    {
        exp[i] = ' ';
    }
    unsigned short int j = *startindex;

    for (i = 0; i < *startindex; i++)
        new_exp[i] = exp[i];

    for (i = *startindex; i < sum; i++)
    {
        j = j + 1;
        for (j; j < sum; j++)
            if (exp[j] != ' ')
            {
                swap(new_exp[i], exp[j]);
                i++;
            }
    }
    cout << new_exp;
    delete[] new_exp;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    unsigned short int startindex;
    unsigned short int count;
    unsigned short int size;
    cout << "Введите длину выражения" << endl;
    cin >> size;
    /*
    if (size < 2)
        size = size + 1;
    */
    char* exp = new char[size + 1];
    exp[size] = '*';
    cout << "Введите строку" << endl;
    for (int i = 0; i < size; i++)
        cin >> exp[i];
    /*cin >> exp;*/
    cout << "Введите номер начального символа и количество символов" << endl;
    cin >> startindex >> count;
    /*cout << exp << exp[size + 1];*/
    while (startindex > size || count > (size - startindex))
    {
        startindex = 0;
        count = 0;
        cout << "Повторите ввод" << endl;
        cin >> startindex >> count;
    }
    remove(exp, &startindex, &count);
    cout << endl;
    cout << exp;
    delete[] exp;
    return 0;
}
