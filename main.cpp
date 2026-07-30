#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int planszabomb[4][4] = {{0,0,0,0},
                             {0,0,0,0},
                             {0,0,0,0},
                             {0,0,0,0}};

    int planszaodkryta[4][4] = {{0,0,0,0},
                                {0,0,0,0},
                                {0,0,0,0},
                                {0,0,0,0}};

    int planszazakryta[4][4] = {{0,0,0,0},
                                {0,0,0,0},
                                {0,0,0,0},
                                {0,0,0,0}};

    int wybor;
    int x, y;
    int odkryte = 0;

    // MENU
    cout << "===== SAPER 4x4 =====" << endl;
    cout << "1. Nowa gra" << endl;
    cout << "2. Tutorial" << endl;
    cout << "3. Wyjscie" << endl;
    cout << "Wybor: ";
    cin >> wybor;


    if (wybor == 2)
    {
        cout << endl;
        cout << "===== TUTORIAL =====" << endl;
        cout << "Plansza ma rozmiar 4x4." << endl;
        cout << "Podajesz numer wiersza i kolumny." << endl;
        cout << "Jesli trafisz na bombe (*) przegrywasz." << endl;
        cout << "Musisz odkryc 12 bezpiecznych pol, aby wygrac." << endl;
        cout << endl;

        cout << "1. Graj" << endl;
        cout << "2. Wyjscie" << endl;
        cin >> wybor;

        if (wybor != 1)
        {
            return 0;
        }
    }

    else if (wybor == 3)
    {
        cout << "Koniec gry!" << endl;
        return 0;
    }

    else if (wybor != 1)
    {
        cout << "Niepoprawny wybor!" << endl;
        return 0;
    }


    srand(time(0));


    // LOSOWANIE BOMB

    int bomby = 0;

    while (bomby < 4)
    {
        x = rand() % 4;
        y = rand() % 4;

        if (planszabomb[x][y] == 0)
        {
            planszabomb[x][y] = 1;
            bomby++;
        }
    }


    // OBLICZANIE LICZB

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            if (planszabomb[i][j] == 1)
            {
                planszaodkryta[i][j] = 9;
            }

            else
            {
                int licznik = 0;

                if (i-1>=0 && j-1>=0 && planszabomb[i-1][j-1]==1)
                    licznik++;

                if (i-1>=0 && planszabomb[i-1][j]==1)
                    licznik++;

                if (i-1>=0 && j+1<4 && planszabomb[i-1][j+1]==1)
                    licznik++;

                if (j-1>=0 && planszabomb[i][j-1]==1)
                    licznik++;

                if (j+1<4 && planszabomb[i][j+1]==1)
                    licznik++;

                if (i+1<4 && j-1>=0 && planszabomb[i+1][j-1]==1)
                    licznik++;

                if (i+1<4 && planszabomb[i+1][j]==1)
                    licznik++;

                if (i+1<4 && j+1<4 && planszabomb[i+1][j+1]==1)
                    licznik++;


                planszaodkryta[i][j] = licznik;
            }
        }
    }



    // GRA

    while (1)
    {

        cout << endl;
        cout << "   0 1 2 3" << endl;


        for (int i = 0; i < 4; i++)
        {
            cout << i << "  ";

            for (int j = 0; j < 4; j++)
            {

                if (planszazakryta[i][j] == 0)
                {
                    cout << "# ";
                }

                else
                {
                    if (planszaodkryta[i][j] == 9)
                    {
                        cout << "* ";
                    }

                    else
                    {
                        cout << planszaodkryta[i][j] << " ";
                    }
                }

            }

            cout << endl;
        }



        cout << endl;
        cout << "Podaj wiersz (0-3): ";
        cin >> x;

        cout << "Podaj kolumne (0-3): ";
        cin >> y;



        if (x < 0 || x > 3 || y < 0 || y > 3)
        {
            cout << "Zle wspolrzedne!" << endl;
        }


        else if (planszazakryta[x][y] == 1)
        {
            cout << "To pole jest juz odkryte!" << endl;
        }


        else
        {

            planszazakryta[x][y] = 1;


            if (planszabomb[x][y] == 1)
            {
                cout << endl;
                cout << "Trafiles bombe!" << endl;
                cout << "Przegrales!" << endl;
                cout << endl;


                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (planszabomb[i][j] == 1)
                        {
                            cout << "* ";
                        }
                        else
                        {
                            cout << planszaodkryta[i][j] << " ";
                        }
                    }

                    cout << endl;
                }

                break;
            }


            else
            {
                odkryte++;


                if (odkryte == 12)
                {
                    cout << endl;
                    cout << "GRATULACJE!" << endl;
                    cout << "Wygrales sapera!" << endl;
                    break;
                }
            }
        }
    }


    return 0;
}