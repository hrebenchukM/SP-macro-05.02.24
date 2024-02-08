// определение символической константы _UNICODE
#define _CRT_SECURE_NO_WARNINGS
#define _UNICODE
#include <iostream>
#include <tchar.h>// для макросов windows


#include <locale>

using namespace std;

//1
void ReplaceSpacesWithTabs(TCHAR* str) {
    while (*str) {
        if (*str == _TEXT(' ')) {
            *str = _TEXT('\t');
        }
        str++;
    }
}



//2
void countCharacters( TCHAR* inputString, int& letterCount, int& digitCount, int& otherCount) {
    while (*inputString) {
        TCHAR currentChar = *inputString;

        if ((currentChar >= _TEXT('A') && currentChar <= _TEXT('Z')) || (currentChar >= _TEXT('a') && currentChar <= _TEXT('z'))) {
            letterCount++;
        }
        else if (currentChar >= _TEXT('0') && currentChar <= _TEXT('9')) {
            digitCount++;
        }
        else {
            otherCount++;
        }

        inputString++;
    }
}


//3
bool isWhitespace(TCHAR c) {
    return c == _TEXT(' ') || c == _TEXT('\t') || c == _TEXT('\n') || c == _TEXT('\r');
}

int countWords( TCHAR* sentence) {
    int wordCount = 0;
    bool inWord = false;

    while (*sentence) {
        if (isWhitespace(*sentence)) {
            inWord = false;
        }
        else if (!inWord) {
            inWord = true;
            wordCount++;
        }

        ++sentence;
    }

    return wordCount;
}

//4
bool isVowelRussian(TCHAR c) {
  
    return (c >= _TEXT('а') && c <= _TEXT('я')) || (c >= _TEXT('А') && c <= _TEXT('Я')) || c == _TEXT('ё') || c == _TEXT('Ё');
}


int countVowelsRussian(TCHAR* text) {
    int vowelCount = 0;

    while (*text) {
        if (isVowelRussian(*text)) {
            vowelCount++;
        }

       text++;
    }

    return vowelCount;
}


//6
void removeCharByIndex(_TCHAR* str, int index) {
    if (index >= 0 && index < _tcslen(str)) {
        _tcscpy(&str[index], &str[index + 1]);
    }
}

//7
void removeCharacter(_TCHAR* str, _TCHAR charToRemove) {
    _TCHAR* pos = _tcschr(str, charToRemove);

    while (pos != nullptr) {

        _tcscpy(pos, pos + 1);

        pos = _tcschr(str, charToRemove);

    }
}




//8
void insertCharAtPosition(_TCHAR* str, int position, _TCHAR charToInsert) {

    if (position >= 0 && position <= _tcslen(str)) {

        for (int i = _tcslen(str); i > position; i--) {
            str[i] = str[i - 1];
        }
        str[position] = charToInsert;
    }
    else {
        wcout << _TEXT("Ошибка") << endl;
    }
}

int main()
{

    TCHAR inputString[] = _TEXT("Hello123 World");

   //1
    ReplaceSpacesWithTabs(inputString);
    wcout << _TEXT("New string: ") << inputString << endl;
    int letterCount = 0;
    int digitCount = 0;
    int otherCount = 0;

    //2
    countCharacters(inputString, letterCount, digitCount, otherCount);
    wcout << _TEXT("Letters: ") << letterCount << endl;
    wcout << _TEXT("Digits: ") << digitCount << endl;
    wcout << _TEXT("Other characters: ") << otherCount << endl;


    //3
    TCHAR sentence[] = _TEXT("Step-the best.");
    int wordCount = countWords(sentence);
    wcout << _TEXT("Number of words: ") << wordCount << endl;

 
    //4
    setlocale(LC_ALL, "Russian");
    _TCHAR szBuf[1000];
    wcout << _TEXT("Введите текст: ");
    wcin.getline(szBuf, _tcslen(szBuf));
    int vowelCount = countVowelsRussian(szBuf);
    wcout << _TEXT("Количество гласных: ") << vowelCount << endl;



    //6
    _TCHAR szBuf2[1000];
    wcout << _TEXT("Введите текст: ");
    wcin.getline(szBuf2, _tcslen(szBuf2));
    int indexToRemove;
    wcout << _TEXT("Введите номер символа для удаления: ");
    wcin >> indexToRemove;
    removeCharByIndex(szBuf2, indexToRemove);
    wcout << _TEXT("Результат после удаления : ") << szBuf2 << endl;



    //7
    _TCHAR charToRemove;
    wcout << _TEXT("Введите символ для удаления: ");
    wcin >> charToRemove;
    removeCharacter(szBuf2, charToRemove);
    wcout << _TEXT("Результат после удаления : ") << szBuf2 << endl;


    //8

    int positionToInsert;
    wcout << _TEXT("Введите позицию для вставки: ");
    wcin >> positionToInsert;

    _TCHAR charToInsert;
    wcout << _TEXT("Введите символ для вставки: ");
    wcin >> charToInsert;

    insertCharAtPosition(szBuf2, positionToInsert, charToInsert);

    wcout << _TEXT("Результат после вставки: ") << szBuf2 << endl;

}



























//// определение символической константы _UNICODE
//#define _CRT_SECURE_NO_WARNINGS
//#define _UNICODE
//#include <iostream>
//#include <tchar.h>// для макросов windows
//using namespace std;
//
//void main()
//{
//	_TCHAR szBuf3[15] = _TEXT("Hello,");
//	_tcscat(szBuf3, _TEXT(" world!"));
//	wcout << szBuf3 << '\n';
//	cout << "The size of array: " << sizeof(szBuf3) << " bytes\n"; // 30 байт
//
//	unsigned short s = 34;
//	cout << s << endl; // Ansi
//	wcout << szBuf3 << endl; // Ansi Unicode
//
//
//	system("pause");
//}
//














//
//
//// отсутствие символической константы 
//#define _UNICODE
//#include <iostream>
//#include <tchar.h>
//using namespace std;
//
//void main()
//{
//	_TCHAR szBuf3[15] = _TEXT("Hello");
//	_tcscat(szBuf3, _TEXT(" world!"));
//	wcout << szBuf3 << '\n';
//	cout << "The size of array: " << sizeof(szBuf3) << " bytes\n"; // 15 байт
//}
//
