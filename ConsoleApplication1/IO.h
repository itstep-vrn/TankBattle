INDX( 	 L!')           (   8   �       � j"\on()P   rd                    �    �K�&��K�&��K�&��K�&�                       S e c u r e B o r w s e r                   �    �K�&��K�&��K�&��K�&�                       S E C U R E ~ 1                     �K�&��K�&��K�&��K�&�                       S E C U R E ~ 1                     �K�&��K�&��K�&��K�&�                       S E C U R E ~ 1                     �K�&��K�&��K�& �K�&�                       S E C U R E ~ 1                     �K�&��K�&��K�&��K�&�                       S E C U R E ~ 1                     e, (WORD)((4 << 4) | 15));
					cout << board.GetCoordinate(i, j);
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					cout << "|";
				}
				else if (board.GetCoordinate(i, j) == 'T' && tank.GetPlayerIndex() == 2)
				{
					SetConsoleTextAttribute(hConsole, (WORD)((2 << 4) | 1));
					cout << board.GetCoordinate(i, );
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					cout << "|";
				}
				else if (board.GetCoordinate(i, j) == '*')
				{

					SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 4));
					cout << board.GetCoordinate(i, j);
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					cout << "|";

				}
				else
				{
					cout << board.GetCoordinate(i, j);
					cout << "|";
				}
				//cout << "|\t|";
			}
			cout << "\t\t|";
			cout << "\n";
			cout <<  t\t ---------" << "\n";
		}
	}
	static void ShowShot(int damage, Tank tank1, Tank tank2)// ��� ����������� �������� � ���������� ����� �����
	{
		cout << tank1.GetName() << " Good shot !!!" << "\n";
		cout << "Tank - " << tank2.GetName() << " Have damage - " << damage << " .HP " << tank2.GetName() << "= " << tank2.GetHP() << "\n";

	}
	static void MoveMine(Mine& mine, Board& boardMovedPlayer, Board& boardEnemy, Board& boardMine, Tank& tankMovedPlayer, Tank& tankEnemy,int changed)
	{
		HANDLE hC sole = GetStdHandle(STD_OUTPUT_HANDLE);
		char move;
		do
		{
			boardEnemy.ClearBoard();
			boardMovedPlayer.ClearBoard();
			system("cls");
			if (changed == 1)
			{
				boardEnemy.ClearBoard();
				boardEnemy.TempBoard(tankEnemy.GetCoordinateX(), tankEnemy.GetCoordinateY(), 'T');
				boardEnemy.TempBoard(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');	
			}
			else if (changed == 2)
			{
				boardMovedPlayer.ClearBoard();
				boardMovedPlayer.TempBoard(tankMovedPlayer.GetCoordinateX , tankMovedPlayer.GetCoordinateY(), 'T');
				boardMovedPlayer.TempBoard(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');
			}
		
		
		//IO::ShowBoard(boardMovedPlayer, tankMovedPlayer);
		//IO::ShowBoard(boardEnemy, tankEnemy);
			cout << "__________________________________________" << endl;
		    cout << "|                                        |" << endl;
				SetConsoleTextAttribute(hConsole, (WORD)((4 << 4) | 15));
				cout << "\tPlayer name - " << tankMovedPlayer.GetName(); cout << "  H =" << tankMovedPlayer.GetHP() << endl;
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));cout << "|";		
				IO::ShowBoard(boardMovedPlayer, tankMovedPlayer);
				IO::ShowBoard(boardEnemy, tankEnemy);
				SetConsoleTextAttribute(hConsole, (WORD)((2 << 4) | 1));
				cout << "\tPlayer name - " << tankEnemy.GetName(); cout << "  HP =" << tankEnemy.GetHP() << endl;
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));cout << "|";
			
		cout << "      _                                     " << endl;
		cout << "     |W|                                     "                                     << endl;
		cout << "   -------              -                    " << endl;
		cout << "   |A|D|S| - to MOVIE  |M| - Chek your MINE  " <<endl;
		cout << "   -------              -                    " << endl;
		

		

			
			if (changed==1)
			{
				move = _getch();
				switch (move)
				{
				case 's':
					mine.MoveDown(boardEnemy);
					break;
				case 'w':
					mine.MoveUp(boa Enemy);
					break;
				case 'a':
					mine.MoveLeft(boardEnemy);
					break;
				case 'd':
					mine.MoveRight(boardEnemy);
					break;
				case 'm':
					boardMine.SetCoordinate(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');
				}
			}
			else if (changed == 2)
			{
				move = _getch();
				switch (move)
				{
				case 's':
					mine.MoveDown(boardMovedPlayer);
					break;
				case 'w':
					mine.MoveUp(boardMovedPlayer);
					break;
				case 'a':
					mine.MoveLeft(boardMovedPlayer);
					break;
				case 'd':
					mine.MoveRight(boardMovedPlayer);
					break;
				case 'm':
					boardMine.SetCoordinate(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');
				}
			}
		} while (move != 'm');
	}
	static void MoveTank(Tank& tank1,Tank& tank2, Board& board1,Board& board2)//������� ��� ����������� �������� �����
		{
			char move;
			move = _getch();
			switch (move)
			{
			case 's':
				tank1.MoveDown(board1);
				break;
			case 'w':
				tank1.MoveUp(board1);
				break;
			case 'a':
				tank1.MoveLeft(board1);
				break;
			case 'd':
				tank1.MoveRight(board1);
				break;
			}
		}
	static void OkrasLogoTank(char logo[][100]) {// ���� ��������
		HANDLE consoleOutput;
		consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

		for (int i = 0; i < 13; i++) {
			if (i % 2 == 0) {
				SetConsoleTextAttribute(consoleOutput, 12); //����� ������� ��� ��������� ������ ������ 
				cout << "\t" << logo[i] << endl;
				SetConsoleTextAttribute(consoleOutput, 15); //���������� ����� ����
			}
			else {
				SetConsoleTextAttribute(consoleOutput, 10); //����� ������� ��� ��������� ������ ������
				cout << "\t" << logo[i] << endl;
				SetConsoleTextAttribute(consoleOutput, 15); //���������� ����� ����
			}
		}
	}

	static void LogoTank() { // �������
		char Logo[15][100] = {
			" #######     ###        ##      ##   ##   ##           #############                         ",
			"   ##      ##   ##     # ##    ##   ##  ##           ####################################### ",
			"  ##     ## ### ##    ##  ##  ##   ## ##            ##################                       ",
			" ##    ## ##### ##   ##    # ##   ##   ##       ###########################                  ",
			"##   ##         ##  ##      ##   ##     ##    #################################              ",
			"                                             #***O*******O*******O*******O****#              ",
			"                                              #***O*****O*******O*******O****#               ",
			"                                               ##############################                ",
			"                    ######          ###     #######  ##                                      ",
			"                   ##    ##       ##   ##     ##    ##                                       ",
			"                  ########      ## ### ##    ##    ##                                        ",
			"                 ##      ##   ## ##### ##   ##    ##                                         ",
			"                ##########  ##         ##  ##    ########                                    ",
		};
		OkrasLogoTank(Logo);
	}

	static void ShowMineStat(Tank tank, Mine mine)
    {
		cout << "Tank - " << tank.GetName() << " Have damage - " << mine.GetDamageMine() << " By mine!!! " << " HP " << tank.GetName() << " = " << tank.GetHP() << endl;
		system("pause");
	}

	static void Interface(Board board1,Board board2,Tank tank1,Tank tank2)
	{
		system("cls");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		board1.ClearBoard();
		board2.ClearBoard();
		cout << "__________________________________________" << endl;
		cout << "|                                        |" << endl;
         cout<< "|                                        |";
		SetConsoleTextAttribute(hConsole, (WORD)((4 << 4) | 15));
		cout << "\tPlayer name - " << tank1.GetName(); cout << "  HP = " << tank1.GetHP() << endl;
		cout << "\t  Inicative = " << tank1.GetOngoingIniciative() << endl;
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); cout << "|";
		IO::ShowBoard(board1, tank1);
		IO::ShowBoard(board2, tank2);
		SetConsoleTextAttribute(hConsole, (WORD)((2 << 4) | 1));
		cout << "|\tPlayer name - " << tank2.GetName(); cout << "  HP = " << tank2.GetHP() << endl;
		cout << "\t  Inicative = "  << tank2.GetOngoingIniciative() << endl;
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));cout << "|";
		cout << "      _                                 " << endl;
		cout << "     |W|                                " << endl;
		cout << "   -------             -----            " << endl;
		cout << "   |A|D|S| - to MOVIE |SPACE| - to SHOT|" <<endl;
		cout << "   -------             -----            " << endl;
		cout << "   -                     - "              << endl;
		cout << "  |M| - Chek your MINE  |H| - to HEAL"    <<endl;
		cout << "   -                     - "              << endl;

		



	}
};