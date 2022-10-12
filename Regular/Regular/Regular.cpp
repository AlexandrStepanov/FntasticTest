// Regular.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;
//вывод строки на экран
void CoutText(string& s, const int len)
{
    cout<<endl;
    for (int i = 0; i < len; i++)
        cout << s[i];
}
//инициализация случайной строки
void gen_random(string &s,const int len) {
    string alphanum="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < len; ++i)
        s[i] = alphanum[rand() % alphanum.length()];
    }
//перевод строки в верхний регистр
void Upper(string& s,const int len)
{
    for (int i = 0; i < len; i++)
        s[i] = toupper(s[i]);
}
//первый алгоритм по заданию, простой, проходиться по строке и ищет повторы
void VersionOne(string s, const int len)
{
    int count = 0,i=0;
    bool flag = false;
    while (count != len) 
    {
        while ((s[i] == '(' or s[i] == ')') and i<len) 
        { 
            i++; 
        }
        for (int j = i + 1; j < len; j++)
            if (s[i] == s[j]) 
            { 
                s[j] = ')';
                count++;
                flag = true; 
            }
        if (flag)
        { 
            s[i] = ')';
            count++;
        }
        else 
        { 
            s[i] = '(';
            count++;
        }
        i++;
        flag = false;
    }
    CoutText(s,len);
}

//вторая версия
void VersionTwo(string s, const int len)
{

}
// основной код
int main()
{
    unsigned int start_time;
    unsigned int end_time;
    unsigned int search_time;
    srand(time(NULL));
    const int N = 100;
    string text;
    text=new char[N];
    int MenuParameter = 1;
    while (MenuParameter) 
    {
        gen_random(text, N);
        CoutText(text, N);
        Upper(text, N);
        //CoutText(text, N);
        start_time = clock();
        VersionOne(text, N);
        end_time = clock();
        cout << endl;
        search_time = end_time - start_time;
        cout << "time=" << search_time / 1000.0<<endl;
        cout << "0 - exit, another num - next string" << endl;
        cin >> MenuParameter;
    }
}
