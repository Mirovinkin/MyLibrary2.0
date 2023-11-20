// MyLibrary2.0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
//#include <cstdlib>
#include <ctype.h>
#include <fstream>
#include <map>
#include <vector>

using namespace std;
template<typename T>
class Library
{
private:
    map<T, vector<T>> _russianEnglish;
public:
    Library() {};
	void AddWord(const T& Word)
	{
		for(auto item : _russianEnglish)
		{
			item.first = Word;
		}
	}
	void AddTransToWord(const T& Word,const T& Trans)
	{
		for (auto item : _russianEnglish)
		{
			
			item.second.push_back(item.first == Word ? Trans : throw exception("No Word found"));
		}
	}

	void DeleteWord(const T& Word)
	{
		auto iter = _russianEnglish.begin();
		if(_russianEnglish.find(Word))
		{
			_russianEnglish.erase(iter + _russianEnglish.find(Word));
		}
	}

	void DeleteTranslation( const T& Word, const T& Trans)
	{
		for(auto item : _russianEnglish)
		{
			if (item.first == Word) {
				for (auto trans : item.second)
				{
					if (trans == Trans)
					{
						auto myiter = find(item.second.begin(), item.second.end(), Trans);
						while (myiter) {
							item.second.erase(item.second.begin() + myiter);
							myiter = find(item.second.begin(), item.second.end(), Trans);
						}
					}
				}
			}
		}
	}

	void EditWord(const T& Word, const T& NewWord)
	{
		auto iter = _russianEnglish.begin();
		for (auto item : _russianEnglish) {
			if (_russianEnglish.find(Word))
			{
				vector<string> temp = _russianEnglish.second();
				_russianEnglish.erase(iter + _russianEnglish.find(Word));
				item.first = NewWord;
				item.second[NewWord] = temp;
			}
		}
	}
	void EditTranslation(const T& Word, const T& Trans, const T& NewTrans)
	{
		DeleteTranslation(Word, Trans);
		AddTransToWord(Word, NewTrans);
	}

};

int main()
{
    std::cout << "Hello World!\n";
}
