//Conecta 4
//Creado por Ulises Gilberto Lugo Fletes A00344441
#include <iostream>

using namespace std;

//Funcion que inicializa el tablero con ---- y tambien inicializa todas las capacidades de las columnas con 6
void inicializarTablero(char tablero[7][7],int columna[]){
    for(int i=0;i<7;i++)
        for(int j=0; j<7;j++)
            tablero[i][j]='-';

    for(int i=0;i<7;i++)
        columna[i]=6;

}

//Funcion que muestra el tablero cada vez que se mete una ficha
void muestraTablero(char tablero[7][7]){
    for(int i=1; i<=7; i++)
        cout << i << " ";

    cout << endl;

    for(int i=0; i<7;i++){
        for(int j=0; j<7;j++)
            cout << tablero[i][j] << " ";
        cout << endl;
    }
}

//funcion que pide y valida la columna que el jugador mete
void pedirValidarCol(int &columna,int turno){
    if(turno%2==0)
        cout << "Turno del jugador 2" << endl;
    else
        cout << "Turno del jugador 1" << endl;
    do{
        cout << "Ingresa columna: ";
        cin >> columna;
    }while(columna<1 || columna>7);
}

//Funcion que inserta la ficha que el jugador acaba de meter, ya sea el 1 o el 2
void insertarFicha(char tablero[7][7],int &columna, int capacidadCol[],int turno, int &renglon){
    if(capacidadCol[columna-1]>=0){
        renglon = capacidadCol[columna-1];
        columna = columna-1;
        if(turno%2==1)
            tablero[renglon][columna]=111;
        else
            tablero[renglon][columna]=254;
    //Despues de insertar la ficha, le resta un espacio a la capacidad de esa columna
        capacidadCol[columna]--;
    }
    else{
        cout << endl << "!!!!Columna llena!!!!" << endl << "Pierdes el turno :/" << endl << endl;
        renglon = -1;
        columna= columna-1;
    }

}

//Funcion que checa si con la ficha que acaba de poner, el jugador gana horizontalmente
bool checarHorizontal(char tablero[7][7], int columna, int renglon){
    int contadorFichas, espacios;
    //Inicializamos el contador Fichas en 1 porque sabemos que minimo esta la ficha que se acaba de meter
    contadorFichas = 1;
    espacios = 0;
    while(tablero[renglon][columna+espacios]==tablero[renglon][columna+espacios+1]){
        if(columna+espacios>=6)
            break;
        contadorFichas++;
        espacios++;
        if(contadorFichas==4){
            return true;
            break;
        }
    }
    espacios = 0;
    while(tablero[renglon][columna-espacios]==tablero[renglon][columna-espacios-1]){
        if(columna-espacios<=0)
            break;
        contadorFichas++;
        espacios++;
        if(contadorFichas==4){
            return true;
            break;
        }
    }
    return false;
}

//Funcion que checa si con la ficha puesta junta 4 verticalmente (para abajo)
bool checarVertical(char tablero[7][7], int columna, int renglon){
    int contadorFichas, espacios;
    //Inicializamos el contador Fichas en 1 porque sabemos que minimo esta la ficha que se acaba de meter
    contadorFichas = 1;
    espacios = 0;
    while(tablero[renglon+espacios][columna]==tablero[renglon+espacios+1][columna]){
        contadorFichas++;
        espacios++;
        if(contadorFichas==4){
            return true;
            break;
        }
    }
    return false;
}

//Checa la diagonal izquierda arriba y derecha abajo
bool checarDiagon1(char tablero[7][7], int columna, int renglon){
    int contadorFichas,espacios;
    contadorFichas=1;
    espacios=0;
    while(tablero[renglon-espacios][columna-espacios]==tablero[renglon-espacios-1][columna-espacios-1]){
        if(renglon-espacios<=0)
            break;
        espacios++;
        contadorFichas++;
        if(contadorFichas==4){
            return true;
            break;
        }
    }
    espacios=0;
    while(tablero[renglon+espacios][columna+espacios]==tablero[renglon+espacios+1][columna+espacios+1]){
        if(renglon+espacios>=6)
            break;
        espacios++;
        contadorFichas++;
        if(contadorFichas==4){
            return true;
            break;
        }
    }
    return false;
}

//Checa la diagonal derecha arriba e izquierda abajo
bool checarDiagon2(char tablero[7][7], int columna, int renglon){
    int contadorFichas,espacios;
    contadorFichas=1;
    espacios=0;
    while(tablero[renglon-espacios][columna+espacios]==tablero[renglon-espacios-1][columna+espacios+1]){
        if(renglon-espacios<=0)
            break;
        espacios++;
        contadorFichas++;
        if(contadorFichas==4){
            return true;
            break;
        }
    }
    espacios=0;
    while(tablero[renglon+espacios][columna-espacios]==tablero[renglon+espacios+1][columna-espacios-1]){
        if(renglon+espacios>=6)
            break;
        espacios++;
        contadorFichas++;
        if(contadorFichas==4){
            return true;
            break;
        }
    }
    return false;
}

//funcion que checa si alguien gana
bool fichaGanadora(char tablero[7][7], int columna, int capacidadCol[7], int renglon){

        //Checar horizontal izqierda y derecha
        if (checarHorizontal(tablero,columna, renglon))
            return true;

        //checar   vertical abajo
        else if (checarVertical(tablero,columna, renglon))
            return true;

        //checar diagonal 1 izquierda arriba y derecha abajo
        else if (checarDiagon1(tablero,columna,renglon))
            return true;
        //checar diagonal 2 derecha arriba e izquierda abajo
        else if (checarDiagon2(tablero,columna,renglon))
            return true;

    return false;
}

//Funcion que checa si el tablero esta lleno
bool tableroLleno(int capacidadCol[]){
    int contador=0;
    for(int i=0;i<7;i++){
        if(capacidadCol[i]<
           0)
            contador++;
    }
    if(contador==7)
        return true;
    else
        return false;
}

int main()
{
    int columna,turno,capacidadCol[7],renglon;
    char tablero[7][7], seguir;
    turno = 0;

    inicializarTablero(tablero,capacidadCol);
    muestraTablero(tablero);
    do{
        turno++;
        pedirValidarCol(columna,turno);
        insertarFicha(tablero,columna,capacidadCol,turno,renglon);
        muestraTablero(tablero);
        if(fichaGanadora(tablero,columna,capacidadCol,renglon)){
            if(turno%2==0)
                cout << "Juego terminado!" << endl << "El jugador 2 ha ganado" << endl;
            else
                cout << "Juego terminado!" << endl << "El jugador 1 ha ganado" << endl;
            seguir=110;
        }
        else{
            if(tableroLleno(capacidadCol)){
                cout << "Juego terminado!" << endl << "El tablero esta lleno, nadie ha ganado" << endl;
                seguir=110;
            }
            else{
                do{
                cout << "Quieres seguir jugando (s/n)? ";
                cin >> seguir;
                }while(seguir!=110 && seguir!=78 && seguir!=115 && seguir!=83);
            }
        }
    }while(seguir!=110 && seguir!=78);
    return 0;
}
