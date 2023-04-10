#include <Windows.h>
#include "isKPeriodic.h"

int main()
{
    SetConsoleOutputCP(1251);
    std::string str; 
    int K; 
    char end;

    bool exit = false;

    do
    {
        std::cout << "������� ������: ";
        std::getline(std::cin, str);
        std::cout << "������� ��������� � ������������� ������ (K): ";
        std::cin >> K;

        isKPeriodic(str, K);

        std::cout << "\n����� (Y/N)? ";
        std::cin >> end;
        std::cin.ignore(32767, '\n');

        if (end == 'Y' || end == 'y')
            exit = true;

    } while (!exit);

    return 0;
}