// Battaglia navale Zorzi Luca - Zahid Mehdi 3^AIA

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <ctime>
using namespace std;

#define DIM 10
#define dimOrigine 2

// Struct
struct Nave
{
    int lunghezza = 0, origine[dimOrigine], verso = 0, direzione = 0; // Verso, direzione => 0 = orizzontale, destra/su, 1 = veritcale, sinistra/giù
};

struct NumNavi
{
    int naviLung4 = 1, naviLung3 = 2, naviLung2 = 3, naviLung1 = 4;
};

// Prototipi
void AnimazioneIniziale();
string ContenutoAsciiArt(ifstream&);
void VisualizzaAsciiArt(string);
void Riempi(char[][DIM]);
void StampaGriglia(char[][DIM]);
void CollocamentoNaviPlayer(char[][DIM], Nave, NumNavi&); // 1 nave - 4 celle, 2 navi - 3 celle, 3 navi - 2 celle, 4 navi - 1 cella
int Menu();
bool CalcoloCollisione(Nave);
void CollocamentoNaviPC(char[][DIM]);
void Battaglia(char[][DIM], char[][DIM]);

// MAIN
int main()
{
    int scelta;
    char matStatiP1[DIM][DIM], matStatiP2[DIM][DIM], matNaviPC[DIM][DIM];
    string percorsoFile;
    Nave naveP1, naveP2;
    NumNavi numNaviP1, numNaviP2;

    // Setup del gioco
    AnimazioneIniziale();
    Riempi(matStatiP1); // Riempimento della matrice del giocatore 1 di 'x' che indicano uno stato vuoto
    Riempi(matStatiP2); // Analogo ma del giocatore 2
    Riempi(matNaviPC); // Riempimento matrice del PC di 'x'

    do
    {
        scelta = Menu();

        switch (scelta)
        {
        case 1:
            break;
        case 2:
            system("cls");

            CollocamentoNaviPC(matNaviPC);

            CollocamentoNaviPlayer(matStatiP1, naveP1, numNaviP1);

            // StampaGriglia(matStati);

            cout << "\n\n";
            system("pause");
            break;
        case 3:
            system("cls");

            // Player 1
            cout << "Collocamento navi giocatore 1.\n";
            system("pause");

            for (int i = 0; i < 10; i++)
            {
                system("cls");
                CollocamentoNaviPlayer(matStatiP1, naveP1, numNaviP1);
                StampaGriglia(matStatiP1);
                system("pause");
            }

            // Player 2
            system("cls");
            cout << "Collocamento navi giocatore 2.\n";
            system("pause");

            for (int i = 0; i < 10; i++)
            {
                system("cls");
                CollocamentoNaviPlayer(matStatiP2, naveP2, numNaviP2);
                StampaGriglia(matStatiP2);
                system("pause");
            }

            system("cls");
            cout << "Griglia player 1.\n\n";
            StampaGriglia(matStatiP1);
            cout << "\n\nGriglia player 2.\n\n";
            StampaGriglia(matStatiP2);

            system("pause");
            break;
        }
    } while (scelta != 0);
}

void AnimazioneIniziale()
{
    string percorsoFile;

    for (int i = 0; i < 2; i++)
    {
        system("cls");
        percorsoFile = "fileTesto\\titoloIniziale.txt";
        VisualizzaAsciiArt(percorsoFile);
        Sleep(500);
        system("cls");
        percorsoFile = "fileTesto\\titoloIniziale2.txt";
        VisualizzaAsciiArt(percorsoFile);
        Sleep(500);
        system("cls");
        percorsoFile = "fileTesto\\titoloIniziale3.txt";
        VisualizzaAsciiArt(percorsoFile);
        Sleep(475);
    }
}

string ContenutoAsciiArt(ifstream& File)
{
    string linea = "", errore = "ERRORE file inesistente.";

    if (File)
    {
        while (File.good())
        {
            string tempLine;
            getline(File, tempLine);
            tempLine += "\n";

            linea += tempLine;
        }

        return linea;
    }
    else
    {
        return errore;
    }
}

void VisualizzaAsciiArt(string percorso)
{
    string asciiArt;
    ifstream asciiArtFile(percorso);

    asciiArt = ContenutoAsciiArt(asciiArtFile);
    cout << asciiArt;

    asciiArtFile.close();
}


void Riempi(char matStati[][DIM])
{
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            matStati[i][j] = 'x';
        }
    }
}

void StampaGriglia(char matStati[][DIM])
{
    char lettera = 65;

    cout << "    ";

    for (int i = 0; i < DIM; i++)
    {
        cout << i << "   ";
    }

    cout << "\n";

    for (int i = 0; i < DIM; i++)
    {
        cout << lettera++ << " ";
        cout << "| ";

        for (int j = 0; j < DIM; j++)
        {
            cout << matStati[i][j] << " | ";
        }
        cout << "\n";
    }
}

void CollocamentoNaviPlayer(char matStati[][DIM], Nave nave, NumNavi& numNavi)
{
    int colonna, rigaIndice;
    char rigaScelta, carattere = 219;
    bool flagOverflow = false, giaDecrementato = false, numBarcheNullo = false;
    string percorsoFile;

    do
    {
        flagOverflow = false, giaDecrementato = false;

        do
        {
            system("cls");
            cout << "Hai a disposizione:\n- " << numNavi.naviLung1 << " navi lunghe 1 cella.\n- "
                << numNavi.naviLung2 << " navi lunghe 2 celle.\n- " << numNavi.naviLung3 << " navi lunghe 3 celle.\n- "
                << numNavi.naviLung4 << " navi lunghe 4 celle.";
            cout << "\nInserisci dimensione nave da posizionare: ";
            cin >> nave.lunghezza;

            /*
            switch (nave.lunghezza)
            {
                case 1:
                    if (numNavi.naviLung1 <= 0)
                    {
                        numBarcheNullo = true;
                    }

                    break;

                case 2:
                    if (numNavi.naviLung2 <= 0)
                    {
                        numBarcheNullo = true;
                    }

                    break;

                case 3:
                    if (numNavi.naviLung3 <= 0)
                    {
                        numBarcheNullo = true;
                    }

                    break;

                case 4:
                    if (numNavi.naviLung1 <= 0)
                    {
                        numBarcheNullo = true;
                    }

                    break;
            }
            */

        } while (nave.lunghezza < 1 || nave.lunghezza > 4 /*|| numBarcheNullo == true*/);

        do
        {
            system("cls");
            cout << "Inserisci le coordinate del punto in cui posizionare la nave\nCoordinata colonna(0 - 9): ";
            cin.clear();
            cin >> colonna;

            cout << "Coordinata riga(A - J): ";
            cin.clear();
            cin >> rigaScelta;

            rigaScelta = toupper(rigaScelta);
        } while (rigaScelta < 'A' || rigaScelta > 'J' || colonna < 0 || colonna > 9);

        rigaIndice = rigaScelta - 65;

        nave.origine[0] = rigaIndice;
        nave.origine[1] = colonna;

        if (nave.lunghezza != 1)
        {
            do
            {
                system("cls");
                cout << "Inserisci il verso della nave (0 = orizzontale, 1 = verticale)\nVerso: ";
                cin >> nave.verso;
            } while (nave.verso < 0 || nave.verso > 1);

            if (nave.verso == 0)
            {
                do
                {
                    system("cls");
                    cout << "Inserisci la direzione (0 = destra, 1 = sinistra)\nDirezione: ";
                    cin >> nave.direzione;
                } while (nave.direzione < 0 || nave.direzione > 1);
            }
            else if (nave.verso == 1)
            {
                do
                {
                    system("cls");
                    cout << "Inserisci la direzione (0 = su, 1 = giu')\nDirezione: ";
                    cin >> nave.direzione;
                } while (nave.direzione < 0 || nave.direzione > 1);
            }
        }

        // Calcola se la nave collidera' con il bordo
        flagOverflow = CalcoloCollisione(nave);

        // Posizionamento nave
        for (int i = 0; i < nave.lunghezza; i++)
        {
            // Orizzontale
            if (nave.verso == 0)                     // Sono stati utilizzati diversi else-if che pur non essendo
            {                                        // necessari li abbiamo inseriti per motivi di chiarezza e sicurezza
                if (nave.direzione == 0)
                {
                    colonna++; // Stampa verso destra
                    nave.origine[1] = colonna - 1;
                }
                else if (nave.direzione == 1)
                {
                    colonna--; // Stampa verso sinistra
                    nave.origine[1] = colonna + 1;
                }
            }
            // Verticale
            else if (nave.verso == 1)
            {
                if (nave.direzione == 0)
                {
                    rigaIndice--; // Stampa verso l'alto
                    nave.origine[0] = rigaIndice + 1;
                }
                else if (nave.direzione == 1)
                {
                    rigaIndice++; // Stampa verso il basso
                    nave.origine[0] = rigaIndice - 1;
                }
            }
            

            if (flagOverflow == true)
            {
                continue;
            }
            else
            {
                if (matStati[nave.origine[0]][nave.origine[1]] == carattere)
                {
                    cout << "Errore! In questa posizione e' gia' presente una nave!";
                    flagOverflow = true;
                    system("pause");
                    break;
                }
                else
                {
                    matStati[nave.origine[0]][nave.origine[1]] = carattere;

                    if (giaDecrementato == false)
                    {
                        switch (nave.lunghezza)
                        {
                            case 1:
                                numNavi.naviLung1--;
                                break;
                            case 2:
                                numNavi.naviLung2--;
                                break;
                            case 3:
                                numNavi.naviLung3--;
                                break;
                            case 4:
                                numNavi.naviLung4--;
                                break;
                        }

                        giaDecrementato = true;
                    }
                }
            }

        }
    } while (flagOverflow == true);
}

int Menu()
{
    int scelta;
    string percorsoFile;

    do
    {
        system("cls");
        percorsoFile = "fileTesto\\titolo.txt";
        VisualizzaAsciiArt(percorsoFile);

        cout << "\n-----------------------------------------------------------------";
        cout << "\n| 0- Esci.\t\t\t\t\t\t\t|";
        cout << "\n| 1- Regole.\t\t\t\t\t\t\t|";
        cout << "\n| 2- Gioca contro il PC.\t\t\t\t\t|";
        cout << "\n| 3- Gioca contro un amico.\t\t\t\t\t|";
        cout << "\n-----------------------------------------------------------------";
        cout << "\nInserisci la tua scelta: ";
        cin >> scelta;
    } while (scelta < 0 || scelta > 3);

    return scelta;
}

bool CalcoloCollisione(Nave nave)
{
    bool collisioneTrovata = false;

    if (nave.verso == 0) // Orizzontale
    {
        if (nave.direzione == 0) // Destra
        {
            /*
            cout << "\n" << nave.origine[1] << "\n";
            system("pause");
            */

            if (nave.origine[1] + nave.lunghezza > 10)
            {
                collisioneTrovata = true;
            }
        }
        else // Sinistra
        {
            if (nave.origine[1] - nave.lunghezza < 0)
            {
                collisioneTrovata = true;
            }
        }
    }
    else // Verticale
    {
        if (nave.direzione == 0) // Alto
        {
            if (nave.origine[1] - nave.lunghezza < 0)
            {
                collisioneTrovata = true;
            }
        }
        else // Basso
        {
            if (nave.origine[1] + nave.lunghezza > 10)
            {
                collisioneTrovata = true;
            }
        }
    }

    return collisioneTrovata;
}

// DA FARE
void CollocamentoNaviPC(char matNaviPC[][DIM])
{
    int dimNave = 1, numNavi = 10, x, y;
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        x = rand()%10, y = rand()%10;


    }
}

void Battaglia(char matStatiP1[][DIM], char matStatiP2[][DIM])
{

}