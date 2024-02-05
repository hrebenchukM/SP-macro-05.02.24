// определение символической константы _UNICODE
#define _CRT_SECURE_NO_WARNINGS
#define _UNICODE
#include <iostream>
#include <tchar.h>// для макросов windows
using namespace std;

//1
void ReplaceSpacesWithTabs(TCHAR* str) {
    while (*str) {
        if (*str == _T(' ')) {
            *str = _T('\t');
        }
        str++;
    }
}



//2
void countCharacters(const TCHAR* inputString, int& letterCount, int& digitCount, int& otherCount) {
    while (*inputString) {
        TCHAR currentChar = *inputString;

        if ((currentChar >= _T('A') && currentChar <= _T('Z')) || (currentChar >= _T('a') && currentChar <= _T('z'))) {
            ++letterCount;
        }
        else if (currentChar >= _T('0') && currentChar <= _T('9')) {
            ++digitCount;
        }
        else {
            ++otherCount;
        }

        ++inputString;
    }
}
int main()
{

    TCHAR inputString[] = _T("Hello123 World");

   //1
    ReplaceSpacesWithTabs(inputString);

   //1
    wcout << _T("New string: ") << inputString << endl;

    int letterCount = 0;
    int digitCount = 0;
    int otherCount = 0;

    //2
    countCharacters(inputString, letterCount, digitCount, otherCount);

    //2
    wcout << _T("Letters: ") << letterCount << endl;
    wcout << _T("Digits: ") << digitCount << endl;
    wcout << _T("Other characters: ") << otherCount << endl;




}