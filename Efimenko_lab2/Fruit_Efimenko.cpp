#include "pch.h"
#include "Fruit_Efimenko.h"

IMPLEMENT_SERIAL(Fruit_Efimenko, CObject, 1)

istream& operator >> (istream& in, Fruit_Efimenko& fruit)
{

	in.clear();
	cout << "Введите имя: ";
	in >> fruit.name;
	cout << "Введите кол-во: ";
	in >> fruit.amount;
	cout << "Введите стои-ть: ";
	in >> fruit.price;
	cout << "Фрукт добавлен" << endl;
	return in;
}

ostream& operator << (ostream& out, const Fruit_Efimenko& fruit)
{
	cout << "===================="<<'\n' << "Название: " << fruit.name << endl;
	cout << "Кол-во: " << fruit.amount << '\n' << "Цена: " << fruit.price << endl << endl;
	return out;
}

Fruit_Efimenko::Fruit_Efimenko()
{
}

Fruit_Efimenko::~Fruit_Efimenko()
{
}

CArchive& operator << (CArchive& ar, string& s)
{
	CString tmp(s.c_str());
	ar << tmp;
	return ar;
}
CArchive& operator >> (CArchive& ar, string& s)
{
	CString tmp;
	ar >> tmp;
	s = tmp;
	return ar;
}
void Fruit_Efimenko::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << name;
		ar << amount;
		ar << price;
	}
	else
	{
		ar >> name >> amount >> price;
	}
}

