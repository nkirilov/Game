#include"Map.h"
#include<stdlib.h>
#include<time.h>

const unsigned Rows = 40;
const unsigned Columns = 76;
const unsigned trueRows = Rows / 2;
const unsigned trueColumns = Columns / 2;
const int MaxItems = 10;

Map::Map(std::ifstream& in)
{
	Field = NULL;
	setField(in);
	
	ItemsOnMap = new Item*[MaxItems];
	std::ifstream is("Items on map.txt", std::ios::binary);
	setIOM(is);
	is.close();
}

Map::~Map()
{

	for (size_t i = 0; i < Rows; ++i)
	{
		delete[]Field[i];
	}
	delete[]Field;
	delete[]ItemsOnMap;
}
///
///Sets the map from file
///
void Map::setField(std::ifstream& in)
{
	if (in)
	{
		in.seekg(0, in.end);
		int size = in.tellg();
		in.seekg(0, in.beg);
		char* temp = new char[size];
		in.read((char*)temp, size);
		int lines = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (temp[i] == '\n')
			{
				lines++;
			}
		}
		if (Field != NULL)
		{
			freeField();
		}

		Field = new char*[Rows];
		for (size_t i = 0; i < Rows; i++)
		{
			Field[i] = new char[Columns];
		}
		int i = 0;
		int p = 0;
		int j = 0;
		while (temp[i] != '\0' && j < trueRows)
		{
			if (temp[i] == '\n')
			{
				j++;
				p = 0;
				i++;
			}
			Field[j][p] = temp[i];
			i++;
			p++;
		}
		delete[]temp;
	}

}
///
///Clears the map
///
void Map::freeField()
{
	for (size_t i = 0; i < Rows; ++i)
	{
		delete[] Field[i];
	}

	delete[] Field;
}

///
///Prints the map
///
void Map::Print()
{
	
	
	for (size_t j = 0; j < trueRows; j++)
	{

		for (size_t p = 0; p < trueColumns; p++)
		{
			Field[FindPlayer().getX()][FindPlayer().getY()] = (char)1;
			std::cout << Field[j][p];

		}
		std::cout << std::endl;

	}
}
///
///Finds the possition of the player on the map
///
Point Map::FindPlayer()
{
	Point pos(0,0);
	for (size_t j = 0; j < trueRows; j++)
	{

		for (size_t p = 0; p < trueColumns; p++)
		{
			if (Field[j][p] == '@')
			{
				pos.setX(j);
				pos.setY(p);
				
				
			}
			 
			
		}

	}
	return pos;
}

///
///Prints the start screen
///
void Map::PrintStartScreen()
{
	PrintAdd("StartScreen.txt");
}
///
///Prints the Help menu
///
void Map::PrintCommands()
{
	PrintAdd("Contrtols And Legend.txt");
}
///
///Prints the exit screen
///
void Map::PrintEnd()
{
	PrintAdd("That's All Folks!.txt");
}
///
///Prints Easter Egg
///
void Map::PrintGoBack()
{
	PrintAdd("GoBack.txt");
}
///
///Prints to console from file
///
void Map::PrintAdd(char* dir)
{
	std::ifstream is(dir, std::ios::binary);
	if (is)
	{

		is.seekg(0, is.end);
		int length = is.tellg();
		is.seekg(0, is.beg);

		char* buffer = new char[length];

		is.read((char*)buffer, length);

		for (size_t i = 0; i < length; i++)
		{
			if (buffer[i] == '@')
			{
				buffer[i] = (char)1;
			}
		}
		if (is)
		{
			for (size_t i = 0; i < length; i++)
			{
				std::cout << buffer[i];
			}
		}
		else
			std::cout << "error: only " << is.gcount() << " could be read";
		is.close();



		delete[] buffer;
	}
}

///
///Sets the items which can be found on the map
///
void Map::setIOM(std::istream& in)
{
	for (size_t i = 0; i < 10; i++)
	{
		int id;
		in >> id;
		if (id==0)
		{
			int at;
			in >> at;
			int eq;
			in >> eq;
			bool a;
			if (eq == 0)
			{
				a = false;
			}
			else
			{
				a = true;
			}
			int len;

			in >> len;

			char* name = new char[len];
			in.get(name, len);
			ItemsOnMap[i] = new Weapon(name, id,a, at);
			delete[] name;
		}
		if (id >= 1 && id <= 6)
		{
			int def;
			in >> def;
			int eq;
			in >> eq;
			bool a;
			if (eq == 0)
			{
				a = false;
			}
			else
			{
				a = true;
			}
			int len;

			in >> len;

			char* name = new char[len];
			in.get(name, len);
			ItemsOnMap[i] = new Armor(name, id, a, def);
			delete[] name;
		}
		
	}
	
}
///
///Prints the characteristics of the items on the map
///
void Map::PrintIOM()
{
	for (size_t i = 0; i < 10; i++)
	{
		ItemsOnMap[i]->Print();
	}
}
Item* Map::getItem(int num)
{
	return ItemsOnMap[num];
}