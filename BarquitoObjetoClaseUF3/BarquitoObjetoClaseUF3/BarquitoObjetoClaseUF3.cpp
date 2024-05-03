#include <iostream>
#include "Barco.h"

using namespace std;

int aiCount, playerCount = 0;
int answer = 0;
string player;
Barco barcos[4];
string cpuNames[] = {"CPU-1", "CPU-2", "CPU-3", "CPU-4"};
int dado;
bool win = false;
bool ai = false;
bool moverse = true;
bool easy = false;
bool ending = false;

//logros
int achievements = 0;
bool aiImpossible = false;
bool closeOne = false;
bool revenge = false;
bool skillIssue = false;
bool betterTogether = false;
bool suicida = false;
bool oneHundred = false;

void logros(int pAchievements) {

    cout << "Logros desbloqueados: " << pAchievements << "/7\n\n";

    if (betterTogether)
    {
        cout << "FAMILIA: juega una partida con 4 jugadores.\n\n";
    }

    else
    {
        cout << "LOGRO BLOQUEADO\n\n";
    }

    if (revenge)
    {
        cout << "VENDETTA: ataca a un jugador que te ha atacado en el mismo turno.\n\n";
    }

    else
    {
        cout << "LOGRO BLOQUEADO\n\n";
    }

    if (skillIssue) {
        cout << "NEFASTO: pierde una partida en dificultad minima.\n\n";
    }

    else
    {
        cout << "LOGRO BLOQUEADO\n\n";
    }

    if (suicida)
    {
        cout << "KAMIKAZE: atacate a ti mismo.\n\n";
    }

    else
    {
        cout << "LOGRO BLOQUEADO\n\n";
    }

    if (closeOne) {
        cout << "AL LIMITE: gana una partida estando a menos de 10 metros del segundo\n\n";
    }

    else
    {
        cout << "LOGRO BLOQUEADO\n\n";
    }

    if (aiImpossible)
    {
        cout << "LEYENDA: gana una partida con la IA en dificultad maxima.\n\n";
    }

    else
    {
        cout << "LOGRO BLOQUEADO\n\n";
    }

    if (oneHundred)
    {
        cout << "PERFECCIONISTA: Completa el juego al 100%.\n\n";
    }

    else
    {
        cout << "???????????????\n\n";
    }

    system("pause");
    system("cls");
        
}


void tirarDados(int pIndex) {

    srand(time(0));
    dado = (rand() % 6) + 1;
    cout << "Jugador " << pIndex + 1 << ", pulsa cualquier tecla para tirar los dados: \n";
    system("pause");


    cout << "Has sacado un " << dado << "!\n\n";
    barcos[pIndex].setDado(dado);
    
}


void aiTirarDados(int pIndex) {
    dado = (rand() % 6) + 1;

    cout << barcos[pIndex].getNombre() << " ha sacado un " << dado << "!\n\n";
    barcos[pIndex].setDado(dado);
    system("pause");
}


void initialize() {
    win = false;

    for (int i = 0; i < 4; i++) {
        barcos[i] = Barco();
    }
}

void startGame() {

    cout << "La carrera va a comenzar! Gana el primero que llegue a la meta situada a 100 metros!\n\n";

    while (!win)
    {
        for (int i = 0; i < playerCount; i++)
        {

            cout << barcos[i].getNombre() << ", que vas a hacer?\n1 - Tirar los dados\n2 - Atacar a otro jugador\n";
            cin >> answer;

            if (answer == 1)
            {
                tirarDados(i);
                cout << "Quieres utilizar el nitro para duplicar el valor de tus dados?\n1 - Si\n2 - No\n";
                cin >> answer;

                if (answer == 1)
                {

                    if (barcos[i].getNitro() <= 0)
                    {
                        cout << "No tienes el nitro recargado!";
                        barcos[i].setDistancia(barcos[i].getDistancia() + barcos[i].getDado() + barcos[i].getVelocidad());
                        barcos[i].setNitro(barcos[i].getNitro() + 1);
                    }

                    else
                    {
                        barcos[i].setDistancia(barcos[i].getDistancia() + barcos[i].getVelocidad() + barcos[i].getDado() * 2);
                        barcos[i].setNitro(barcos[i].getNitro() - 1);
                    }

                }

                else
                {
                    barcos[i].setDistancia(barcos[i].getDistancia() + barcos[i].getDado() + barcos[i].getVelocidad());

                    if (barcos[i].getNitro() < 3)
                    {
                        barcos[i].setNitro(barcos[i].getNitro() + 1);
                    }
                }

                barcos[i].setVelocidad(barcos[i].getVelocidad() + 1);
            }

            else
            {
                cout << "A que jugador quieres atacar?\n";

                for (int j = 0; j < playerCount + aiCount; j++)
                {
                    if (j != i)
                    {
                        cout << j + 1 << ". " << barcos[j].getNombre() << ": a " << 100 - barcos[j].getDistancia() << " metros de la meta con una velocidad de " << barcos[j].getVelocidad() << " metros extra por tirada.\n\n";
                    }
                }
                cin >> answer;
                answer--;

                if (answer == i)
                {
                    
                    cout << "Te estas atacando a ti mismo, melon.\n\n";

                    if (!suicida)
                    {
                        suicida = true;
                        achievements++;
                    }
                 
                }

                else
                {

                    tirarDados(i);
                    cout << "Reduces la velocidad de " << barcos[answer].getNombre() << " " << barcos[i].getDado() << " puntos!\n\n";       
                    barcos[answer].setVelocidad(barcos[answer].getVelocidad() - barcos[i].getDado());              

                    barcos[answer].setAtacado(i);
                    barcos[i].setAtaque(answer);

                    if (barcos[answer].getVelocidad() < 0)
                    {
                        barcos[answer].setVelocidad(0);
                    }

                    if (barcos[i].getAtaque() == barcos[i].getAtacado() && !revenge)
                    {
                        revenge = true;
                        achievements++;
                    }
         
                }


            }
            
            if (barcos[i].getDistancia() >= 100)
            {
                cout << "Tras este turno, has llegado a la meta!\n\n";
            }

            else
            {
                cout << "Tras este turno, te situas a " << 100 - barcos[i].getDistancia() << " metros de la meta!\n\n";
            }
            

            if (barcos[i].getDistancia() >= 100)
            {
                cout << "\nHa ganado " << barcos[i].getNombre() << "!\n";
                barcos[i].setDistancia(100);
                win = true;

                if (ai == true && barcos[3].getNombre()._Equal("ULTRA CPU-4") && !aiImpossible)
                {
                    aiImpossible = true;
                    achievements++;
                }

                if (!closeOne)
                {
                    for (int k = 0; k < playerCount + aiCount; k++)
                    {
                        if (k != i && barcos[i].getDistancia() - barcos[k].getDistancia() < 10) {
                            closeOne = true;
                            achievements++;
                        }
                    }
                }

                if (ending && !oneHundred)
                {
                    achievements++;
                    oneHundred = true;
                    cout << "Has compleado el juego al 100%. Felicidades!\n\n";
                }

                i = playerCount;
            }        

        }

        if (!win && ai)
        {

            for (int i = playerCount; i < 4; i++)
            {

                for (int j = 0; j < playerCount + aiCount; j++)
                {
                    if (j != i) {

                        if ((barcos[j].getVelocidad() > 2 && barcos[j].getDistancia() > barcos[i].getDistancia()) || barcos[j].getVelocidad() > 4)
                        {
                            aiTirarDados(i);
                            cout << barcos[i].getNombre() << " ha atacado a " << barcos[j].getNombre() << " y le ha bajado la velocidad " << barcos[i].getDado() << " puntos!\n\n";
                            moverse = false;
                            barcos[j].setVelocidad(barcos[j].getVelocidad() - barcos[i].getDado());

                            barcos[i].setAtaque(j);
                            barcos[j].setAtacado(i);

                            if (barcos[j].getVelocidad() < 0)
                            {
                                barcos[j].setVelocidad(0);
                            }

                            j = playerCount + aiCount;
                        }
                    }
                }

                if (moverse)
                {
                    aiTirarDados(i);

                    if (barcos[i].getNitro() > 0 && barcos[i].getDado() > 2)
                    {
                        barcos[i].setDistancia(barcos[i].getDistancia() + barcos[i].getDado() * 2 + barcos[i].getVelocidad());
                        barcos[i].setNitro(barcos[i].getNitro() - 1);
                    }

                    else
                    {
                        barcos[i].setDistancia(barcos[i].getDistancia() + barcos[i].getDado() + barcos[i].getVelocidad());

                        if (barcos[i].getNitro() < 3)
                        {
                            barcos[i].setNitro(barcos[i].getNitro() + 1);
                        }

                    }

                    barcos[i].setVelocidad(barcos[i].getVelocidad() + 1);

                }

                moverse = true;

                if (barcos[i].getDistancia() >= 100)
                {
                    cout << "Ha ganado " << barcos[i].getNombre() << "! Ya me joderia que me ganase una IA.";
                    i = 4;
                    win = true;

                    if (easy && !skillIssue)
                    {
                        skillIssue = true;
                        achievements++;
                    }
                }

            }   

        }

        if (!win)
        {
            system("cls");

            cout << "------------------------------------------\n\n";
            cout << "Estadisticas:\n\n";

            for (int i = 0; i < playerCount; i++)
            {
                barcos[i].getAttributes();
            }

            if (ai)
            {
                for (int i = playerCount; i < 4; i++)
                {
                    barcos[i].getAttributes();
                }
            }

            cout << "------------------------------------------\n\n";

        }
        
    }

}


void howManyPlayers(int pAnswer) {

    for (int i = 0; i < pAnswer; i++) {
        cout << "Introduce el nombre de tu barco, jugador " << i + 1 << ": ";
        cin >> player;
        barcos[i].setNombre(player);
    }

    if (pAnswer < 4)
    {
        cout << "Quieres que el resto de barcos sean controlados por una IA?\n1 - Si\n2 - No\n";
        cin >> answer;
    }

    else {

        if (!betterTogether)
        {
            betterTogether = true;
            achievements++;
        }

    }
   
    if (answer == 1)
    {
        ai = true;

        for (int i = 4; i > -1 + pAnswer; i--)
        {
            if (i == 4) {

                aiCount = i - pAnswer;

                if (i - pAnswer > 1)
                {
                    cout << "Los " << i - pAnswer << " barcos restantes seran controlados por una IA. Que dificultad quieres que tenga?\n1 - Facil\n2 - Normal\n3 - Dificil\n4 - Imposible\n";

                    if (achievements == 6)
                    {
                        cout << "5 - ??????\n";
                    }

                    cin >> answer;
                }

                else
                {
                    cout << "El barco restante sera controlado por una IA. Que dificultad quieres que tenga?\n1 - Facil\n2 - Normal\n3 - Dificil\n4 - Imposible\n";

                    if (achievements == 6)
                    {
                        cout << "5 - ??????\n";
                    }

                    cin >> answer;
                }

                i--;

            } 

            switch (answer) {
            case 1:
                easy = true;
                barcos[i].setNombre(cpuNames[i]);
                break;

            case 2:
                barcos[i] = Barco(1, 0, 1, cpuNames[i]);
                break;
       
            case 3:
                barcos[i] = Barco(2, 0, 2, cpuNames[i]);
                break;
            case 4:
                barcos[i] = Barco(3, 0, 3, cpuNames[i]);
                barcos[i].setNombre("ULTRA " + barcos[i].getNombre());
                break;
            case 5:

                if (achievements == 6)
                {
                    barcos[i] = Barco(3, 10, 5, cpuNames[i]);
                    barcos[i].setNombre("&/??@%&-" + i);
                }

                else {
                    cout << "Prueba de nuevo cuando hayas completado el juego.\n";
                }
            }
             
        }

    }

}

void game() {

    initialize();

    cout << "Bienvenido a la gran carrera de barcos! Cuantos jugadores van a jugar?\n1 - 1 jugador\n2 - 2 jugadores\n3 - 3 jugadores\n4 - 4 jugadores\n";
    cin >> answer;

    if (answer == 1 || answer == 2 || answer == 3 || answer == 4)
    {
        playerCount = answer;
        howManyPlayers(playerCount);
        startGame();
    }

    else
    {
        cout << "Eres muy bobo. Sin jugar te quedas.\n";
    }
   


}

int main()
{
    while (answer != 2)
    {
        game();
        system("pause");
        system("cls");
        easy = false;

        if (achievements >= 6)
        {
            ending = true;
        }

        cout << "Quieres volver a jugar?\n1 - Si\n2 - No\n3 - Ver logros\n";
        cin >> answer;
        if (answer == 3)
        {
            logros(achievements);
            answer = -100;
        }

    }
    
}


