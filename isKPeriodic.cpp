#include"isKPeriodic.h"

void compLPS(const std::string& pat, std::size_t* lps) // Функция дополнительного массива 
{
    std::size_t j = 0;
    std::size_t i = 1;
    lps[0] = 0; // lps[0] всегда равен 0
    while (i < pat.size()) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0) {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}


void isKPeriodic(const std::string& str, int K) // Функция проверки кратности строки K
{
    if ((K <= 1) || (str.empty()) || (str.size() % K) || (K >= str.size())) // K не должно быть равно 0 и 1, строка не должна быть пустой, 
                                                                           // длина строки не делится на К без остатка, или Кратность К больше или равна исходной строке 
    {
        std::cout << "Ошибка ввода данных" << std::endl;
    }
    else
    {
        
        std::string pat; // Подстрока формируется из начальных символов строки в количестве K
        for (std::size_t s = 0; s < K; ++s)
            pat.push_back(str[s]);

        std::size_t* lps = new std::size_t[pat.size()];

        compLPS(pat, lps); // Создаём массив lps

        std::size_t i = 0;
        std::size_t j = 0;
        int count = 0; // Тут подсчет вхождений подстроки в исходную строку
        while (i < str.size()) {
            if (pat[j] == str[i])
            {
                j++;
                i++;
            }
            if (j == pat.size()) {
                count++; // Если совпадение найдено - увеличиваем счетчик вхождений
                j = lps[j - K];
            }
            else if (i < str.size() && pat[j] != str[i]) {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i = i + 1;
                }
            }
        }
        
        if ((static_cast<unsigned long long>(K) * count) == str.size()) // Если количество найденных совпадений, помноженное на К,
                                                                       // равно длине строки - то строка кратна К
            std::cout << "Строка " << str << " кратна K = " << K << std::endl;
        else
            std::cout << "Строка " << str << " не кратна K = " << K << std::endl;

        delete[] lps;
    }
}