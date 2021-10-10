#pragma once
class Fruit_Efimenko : public CObject
{
	DECLARE_SERIAL(Fruit_Efimenko);
public:
	string name;
	int amount = 0; //параметры по умолчанию
	double price = 0;
	Fruit_Efimenko();
	virtual ~Fruit_Efimenko();
	friend CArchive& operator << (CArchive& ar, string& s);
	friend CArchive& operator >> (CArchive& ar, string& s);

	virtual void Serialize(CArchive& ar);
	friend istream& operator >> (istream& in, Fruit_Efimenko& fruit);
	friend ostream& operator << (ostream& out, const Fruit_Efimenko& fruit);

};

