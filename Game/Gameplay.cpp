#include"Gameplay.h"


const int MobHealth = 30;
const int MobMaxAttack = 2;
const int MobMinAttack = 1;
const int PlayerHealth = 30;
const int PlayerMaxAttack = 3;
const int PlayerMinAttack = 2;
const int PlayerDefence = 3;
const int MaxItems = 10;
const int MaxInventory = 10;



Gameplay::Gameplay(std::ifstream& in) : Field(in)
{

	Gamer.setPosition(Field.FindPlayer());
	Gamer.setMaxHealth(PlayerHealth);
	Gamer.setHealth(PlayerHealth);
	Gamer.setMaxAttack(PlayerMaxAttack);
	Gamer.setMinAttack(PlayerMinAttack);
	Gamer.setDefence(PlayerDefence);
}

Gameplay::~Gameplay()
{

}
void Gameplay::Play()
{
	for (size_t i = 0; i < 20; i++)
	{
		Field.PrintStartScreen();
		system("cls");

	}
	Field.PrintCommands();
	char move = 'w';
	while (move != 'o')
	{
		std::cin >> move;
		switch (move)
		{
		case 'w':
		{
			system("cls");
			
			Point Next(Gamer.getPosition().getX() - 1, Gamer.getPosition().getY());
			MobEncounter(Next);
			moveIt(Next);
			
			if (Gamer.getHealth() <= 0)
			{
				system("cls");
				Field.PrintEnd();
				std::cout << std::endl;
				move = 'o';
			}
			break;
		}
		case 'd':
		{
			system("cls");
		
			Point Next(Gamer.getPosition().getX(), Gamer.getPosition().getY() + 1);
			MobEncounter(Next);
			system("cls");
			if (Field.Field[Gamer.getPosition().getX()][Gamer.getPosition().getY() + 1] == '}')
			{
				if (Lvl==0)
				{
					std::ifstream is("LVL2.txt", std::ios::binary);
					Field.setField(is);

					is.close();
					Gamer.setPosition(Field.FindPlayer());
					std::cout << "HP: ";
					Gamer.PrintHealth();
					Field.Print();
					Lvl++;
					break;
				}
				else
				{
					system("cls");
					Field.PrintEnd();
					std::cout << std::endl;
					move = 'o';
					break;
				}
				system("cls");
				Field.PrintEnd();
				std::cout << std::endl;
				move = 'o';
				break;
			}
			moveIt(Next);
			
			if (Gamer.getHealth() <= 0)
			{
				system("cls");
				Field.PrintEnd();
				std::cout << std::endl;
				move = 'o';
			}
			break;
		}
		case 's':
		{
			system("cls");
			
			Point Next(Gamer.getPosition().getX() + 1, Gamer.getPosition().getY());
			MobEncounter(Next);
			system("cls");
			moveIt(Next);
			
			if (Gamer.getHealth() <= 0)
			{
				system("cls");
				Field.PrintEnd();
				std::cout << std::endl;
				move = 'o';
			}
			break;
		}
		case 'a':
		{
			system("cls");
			
			Point Next(Gamer.getPosition().getX(), Gamer.getPosition().getY() - 1);
			MobEncounter(Next);
			system("cls");
			if (Field.Field[Gamer.getPosition().getX()][Gamer.getPosition().getY() - 1] == '{')
			{
				system("cls");
				Field.PrintGoBack();
				std::cout << std::endl << std::endl << "Press Start!" << std::endl;
				break;
			}
			moveIt(Next);
			
			if (Gamer.getHealth() <= 0)
			{
				system("cls");
				Field.PrintEnd();
				std::cout << std::endl;
				move = 'o';
			}
			break;
		}
		case 'o':
		{
			system("cls");
			Field.PrintEnd();
			std::cout << std::endl;
			_sleep(1500);
			break;
		}
		case '\n':
		{
			system("cls");
			std::cout << "HP: ";
			Gamer.PrintHealth();
			Field.Print();
			break;
		}
		case 'h':
		{
			system("cls");
			Field.PrintCommands();
			std::cout << std::endl << "Press start to go back." << std::endl;
			break;
		}
		case 'r':
		{
			system("cls");
			std::ifstream is("LVL1.txt", std::ios::binary);
			Field.setField(is);
			is.close();
			std::cout << "HP: ";
			Gamer.PrintHealth();
			Field.Print();
			break;
		}
		case 'c':
		{
			system("cls");
			std::cout << "HP: ";
			Gamer.PrintHealth();
			Field.Print();
			std::cout << std::endl;
			Gamer.Print();
			break;
		}
		case 'i':
		{
			system("cls");
			Field.PrintAdd("Equipped.txt");
			Gamer.PrintEquipped();
			Field.PrintAdd("Inventory.txt");
			Gamer.PrintInventory();
			std::cout << std::endl << "Press Start to Return " << std::endl;
			break;
		}
		default:
		{
			system("cls");
			std::cout << "HP: ";
			Gamer.PrintHealth();
			Field.Print();
		}
		}
	}





}

///
///Duel with monster
///
void Gameplay::MobEncounter(Point pos)
{
	if (Field.Field[pos.getX()][pos.getY()] == '*')
	{
		Mob.setHealth(MobHealth);
		Mob.setMaxHealth(MobHealth);
		Mob.setMaxAttack(MobMaxAttack);
		Mob.setMinAttack(MobMinAttack);
		Mob.setName("Goblin Warrior");
		srand(time(NULL));
		while (Gamer.getHealth()>0 && Mob.getHealth()>0)
		{
			int var = rand() % 10 + 1;
			if (var >= 1 && var <= 5)
			{
				system("cls");
				if (Gamer.getHealth() <= (Gamer.getMaxHealth() / 4))
				{
					Gamer.PrintHealth();
					Gamer.Print();
					std::cout << "    VS    " << std::endl;
					Mob.PrintHealth();
					Mob.Print();
					std::cout << std::endl << std::endl << "Do you want to heal?(y/n)" << std::endl;
					char Answer;
					std::cin >> Answer;
					switch (Answer)
					{
					case 'Y':case 'y':
					{
						Gamer.setHealth(Gamer.getMaxHealth());
						break;
					}
					
					default:
					{
						Mob.setHealth(Mob.getHealth() - Gamer.getMinAttack());
						Gamer.PrintHealth();
						Gamer.Print();
						std::cout << "    VS    " << std::endl;
						Mob.PrintHealth();
						Mob.Print();
						break;
					}
						
					}


				}
				else
				{
					Mob.setHealth(Mob.getHealth() - Gamer.getMinAttack());
					Gamer.PrintHealth();
					Gamer.Print();
					std::cout << "    VS    " << std::endl;
					Mob.PrintHealth();
					Mob.Print();
				}
				
			}
			if (var >= 6 && var <= 9)
			{
				system("cls");
				if (Gamer.getHealth() <= (Gamer.getMaxHealth() / 4))
				{
					Gamer.PrintHealth();
					Gamer.Print();
					std::cout << "    VS    " << std::endl;
					Mob.PrintHealth();
					Mob.Print();
					std::cout << std::endl << std::endl << "Do you want to heal?(y/n)" << std::endl;
					char Answer;
					std::cin >> Answer;
					switch (Answer)
					{
					case 'Y':case 'y':
					{
						Gamer.setHealth(Gamer.getMaxHealth());
						break;
					}
					case 'N':case 'n':
					{
						Mob.setHealth(Mob.getHealth() - Gamer.getMaxAttack());
						Gamer.PrintHealth();
						Gamer.Print();
						std::cout << "    VS    " << std::endl;
						Mob.PrintHealth();
						Mob.Print();
						break;
					}
					default:
					{
						Mob.setHealth(Mob.getHealth() - Gamer.getMaxAttack());
						Gamer.PrintHealth();
						Gamer.Print();
						std::cout << "    VS    " << std::endl;
						Mob.PrintHealth();
						Mob.Print();
						break;
					}

					}


				}
				else
				{
					Mob.setHealth(Mob.getHealth() - Gamer.getMaxAttack());
					Gamer.PrintHealth();
					Gamer.Print();
					std::cout << "    VS    " << std::endl;
					Mob.PrintHealth();
					Mob.Print();
				}
			}
			if (var == 10)
			{
				system("cls");
				if (Gamer.getHealth() <= (Gamer.getMaxHealth() / 4))
				{

					Gamer.PrintHealth();
					Gamer.Print();
					std::cout << "    VS    " << std::endl;
					Mob.PrintHealth();
					Mob.Print();
					std::cout << std::endl << std::endl << "Do you want to heal?(y/n)" << std::endl;
					char Answer;
					std::cin >> Answer;
					switch (Answer)
					{
					case 'Y':case 'y':
					{
						Gamer.setHealth(Gamer.getMaxHealth());
						break;
					}
					case 'N':case 'n':
					{
						Mob.setHealth(Mob.getHealth() - 3*Gamer.getMaxAttack());
						Gamer.PrintHealth();
						Gamer.Print();
						std::cout << "    VS    " << std::endl;
						Mob.PrintHealth();
						Mob.Print();
						break;
					}
					default:
					{
						Mob.setHealth(Mob.getHealth() - 3*Gamer.getMaxAttack());
						Gamer.PrintHealth();
						Gamer.Print();
						std::cout << "    VS    " << std::endl;
						Mob.PrintHealth();
						Mob.Print();
						break;
					}

					}


				}
				else
				{
					Mob.setHealth(Mob.getHealth() - 3*Gamer.getMaxAttack());
					Gamer.PrintHealth();
					Gamer.Print();
					std::cout << "    VS    " << std::endl;
					Mob.PrintHealth();
					Mob.Print();
				}
			}
			if (Gamer.getDefence() >= 3 * Mob.getMaxAttack())
			{
				system("cls");
				Gamer.setHealth(Gamer.getHealth() - Mob.getMinAttack());
				Gamer.PrintHealth();
				Gamer.Print();
				std::cout << "    VS    " << std::endl;
				Mob.PrintHealth();
				Mob.Print();
			}
			else
			{
				system("cls");
				Gamer.setHealth(Gamer.getHealth() - Mob.getMaxAttack());
				Gamer.PrintHealth();
				Gamer.Print();
				std::cout << "    VS    " << std::endl;
				Mob.PrintHealth();
				Mob.Print();
			}


		}

	}

}
///
///Moves a player to a possition
///
void Gameplay::moveIt(Point next)
{
	if (Field.Field[next.getX()][next.getY()] != '='
		&& Field.Field[next.getX()][next.getY()] != '|'
		&& Field.Field[next.getX()][next.getY()] != '+')
	{
		if (Field.Field[next.getX()][next.getY()] == 'H')
		{
			Gamer.Heal();
		}
		if (Field.Field[next.getX()][next.getY()] == 'i')
		{
			if (Gamer.getUsed() >= MaxInventory)
			{
				system("cls");
				std::cout << "Inventory Full!" << std::endl;
				Field.Field[next.getX()][next.getY()] = '@';
				Field.Field[Gamer.getPosition().getX()][Gamer.getPosition().getY()] = 'i';
				Gamer.setPosition(next);
				std::cout << "HP: ";
				Gamer.PrintHealth();
				Field.Print();

			}
			else
			{
				int var = rand() % 10;
				Gamer.Add(*Field.getItem(var));
				Field.Field[next.getX()][next.getY()] = '@';
				Field.Field[Gamer.getPosition().getX()][Gamer.getPosition().getY()] = ' ';
				Gamer.setPosition(next);
				std::cout << "HP: ";
				Gamer.PrintHealth();
				Field.Print();
			}

		}
		else
		{
			Field.Field[next.getX()][next.getY()] = '@';
			Field.Field[Gamer.getPosition().getX()][Gamer.getPosition().getY()] = ' ';
			Gamer.setPosition(next);
			std::cout << "HP: ";
			Gamer.PrintHealth();
			Field.Print();
		}

	}
	else
	{
		Field.Field[Gamer.getPosition().getX()][Gamer.getPosition().getY()] = '@';
		std::cout << "HP: ";
		Gamer.PrintHealth();
		Field.Print();
	}

}