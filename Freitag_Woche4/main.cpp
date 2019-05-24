#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Person
{
public:
	string vorname;
	string nachname;

	void nameAnzeigen()
	{
		cout << "Vorname:  " << vorname << endl;
		cout << "Nachname: " << nachname << endl << endl;
	}
};




class Mann : public Person
{
public:

	int bartlaenge;

	void nameAnzeigen()
	{
		cout << "Herr " << vorname << " " << nachname << endl << endl;
	}
};


class Frau : public Person
{
public:
	void nameAnzeigen()
	{
		cout << "Frau " << vorname << " " << nachname << endl << endl;
	}
};






//------------------------------------------------------------------------------//
//			Main Function														//
//------------------------------------------------------------------------------//


int main()
{

	cout << "Programm zu Freitag Woche 4" << endl << endl;

	Person person1;
	person1.vorname = "Heinz";
	person1.nachname = "Mueller";
	person1.nameAnzeigen();

	Mann mann1;
	mann1.vorname = "Klaus";
	mann1.nachname = "Schmidt";
	mann1.bartlaenge = 20;
	mann1.nameAnzeigen();

	Frau frau1;
	frau1.vorname = "Lisa";
	frau1.nachname = "Meerbusch";
	frau1.nameAnzeigen();

	Mann mann2;
	mann2 = mann1;
	mann2.bartlaenge = 40;
	mann2.nameAnzeigen();

	Person person2;
	person2 = mann1;
	// person2.bartlange;	// personhat kein Attribut bartlaenge
	person2.nameAnzeigen();


	//Mann mann3;
	//mann3 = person1;	// Kopie in spezialisierte Klasse geht nicht;

	
	cout << "_______________________________________________jetzt mit Zeigern____________________________________________________" << endl << endl;


	// Zeiger auf eine Person
	Person* pPerson1;
	pPerson1 = &person1;
//	(*pPerson1).nameAnzeigen();		// Derefrenzierung des Zeigers um an das Obejkt zu kommen
	pPerson1->nameAnzeigen();		// Alternative Schreibweise

	// Zeiger auf eine Frau
	Frau* pFrau1;
	pFrau1 = &frau1;
	pFrau1->nameAnzeigen();

	// Unvollständiges Objekt
	Person* pPerson2;
	pPerson2 = &mann1;
	(*pPerson2).nameAnzeigen();



	// Unvollständige Kopie
	Person* pPerson3 = new Person;
	*pPerson3 = mann1;
	pPerson3->nameAnzeigen();
	delete pPerson3;



	system("pause");
	return 0;
}