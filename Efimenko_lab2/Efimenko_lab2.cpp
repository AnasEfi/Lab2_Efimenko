// Efimenko_lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "framework.h"
#include "Efimenko_lab2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Единственный объект приложения

CWinApp theApp;

void PrintMenu()
{
	cout << '\n' << "1.Добавить фрукт на тарелку" << endl
		<< "2.Показать фрукты на тарелке" << endl
		<< "3.Считать из файла тарелку салата из фруктов" << endl
		<< "4.Сохранить тарелку салата" << endl
		<< "==========================" << endl
		<<"5.Добавить описание Яблока"<<endl
		<< "5.Записать рецепт салата" << endl
		<< "6.Показать рецепт салата" << endl
		<< "7.Сохранить рецепт в файл" << endl
		<< "8.Считать рецепт из файла" << endl
		<< "9.Удалить рецепт" << endl
		<< "0.Выход" << '\n' << endl
		<< "Выберите действие:";
}

int main()
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(nullptr);

	if (hModule != nullptr)
	{
		// инициализировать MFC, а также печать и сообщения об ошибках про сбое
		if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
		{
			// TODO: вставьте сюда код для приложения.
			wprintf(L"Критическая ошибка: сбой при инициализации MFC\n");
			nRetCode = 1;
		}
		else
		{
			// TODO: вставьте сюда код для приложения.
			setlocale(LC_ALL, "rus");
			vector <shared_ptr <Fruit_Efimenko>> plate;
			//vector <Salad> book;
			while (true)
			{
				PrintMenu();
				switch (getCorrectNumber(0, 4))
				{
				case 1:
				{
					shared_ptr <Fruit_Efimenko> Fruit(new Fruit_Efimenko);
					cin >> *Fruit;
					plate.push_back(Fruit);
					break;
				}
				case 2:
				{
					if (!plate.size() == 0) {
						for (auto& Fruit : plate)
						{
							cout << *Fruit;
						}
					}
					else cout << "Тарелка пуста" << endl;
					break;
				}
				case 3:
				{
					string filename;
					cout<<"Введите имя файла : ";
					cin >> filename;
					CFile f(filename.c_str(), CFile::modeRead);
					CArchive ar(&f, CArchive::load);
					int n;
					ar >> n;
					for (int i = 0; i < n; ++i)
					{
						Fruit_Efimenko* Fruit;
						ar >> Fruit;
						shared_ptr<Fruit_Efimenko> smartFruit(Fruit);
						plate.push_back(smartFruit);
					}
					break;
				}
				case 4:
				{
					string filename;
					cout << "Имя файла: ";
					cin >> filename;

					CFile f(filename.c_str(), CFile::modeCreate | CFile::modeWrite);
					CArchive ar(&f, CArchive::store);
					ar << plate.size();
					for (auto o : plate)
					{
						ar << o.get();
					}
					break;
				}
				case 5:
				{

				}
				case 0: //выход
				{
					return 0;
				}
				default:
				{
					cout << "ошибка" << endl;
					break;
				}

				}
			}
			return 0;
		}
	}
	else
	{
		// TODO: измените код ошибки в соответствии с потребностями
		wprintf(L"Критическая ошибка: сбой GetModuleHandle\n");
		nRetCode = 1;
	}

	return nRetCode;
			}
