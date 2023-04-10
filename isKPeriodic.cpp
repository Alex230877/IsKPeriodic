#include"isKPeriodic.h"

void compLPS(const std::string& pat, std::size_t* lps) // ������� ��������������� ������� 
{
    std::size_t j = 0;
    std::size_t i = 1;
    lps[0] = 0; // lps[0] ������ ����� 0
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


void isKPeriodic(const std::string& str, int K) // ������� �������� ��������� ������ K
{
    if ((K <= 1) || (str.empty()) || (str.size() % K) || (K >= str.size())) // K �� ������ ���� ����� 0 � 1, ������ �� ������ ���� ������, 
                                                                           // ����� ������ �� ������� �� � ��� �������, ��� ��������� � ������ ��� ����� �������� ������ 
    {
        std::cout << "������ ����� ������" << std::endl;
    }
    else
    {
        
        std::string pat; // ��������� ����������� �� ��������� �������� ������ � ���������� K
        for (std::size_t s = 0; s < K; ++s)
            pat.push_back(str[s]);

        std::size_t* lps = new std::size_t[pat.size()];

        compLPS(pat, lps); // ������ ������ lps

        std::size_t i = 0;
        std::size_t j = 0;
        int count = 0; // ��� ������� ��������� ��������� � �������� ������
        while (i < str.size()) {
            if (pat[j] == str[i])
            {
                j++;
                i++;
            }
            if (j == pat.size()) {
                count++; // ���� ���������� ������� - ����������� ������� ���������
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
        
        if ((static_cast<unsigned long long>(K) * count) == str.size()) // ���� ���������� ��������� ����������, ����������� �� �,
                                                                       // ����� ����� ������ - �� ������ ������ �
            std::cout << "������ " << str << " ������ K = " << K << std::endl;
        else
            std::cout << "������ " << str << " �� ������ K = " << K << std::endl;

        delete[] lps;
    }
}