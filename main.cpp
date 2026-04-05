#include <iostream>
using namespace std;

void mostrarTablero(int tablero[3][3]) {
    cout << "\nTablero:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool hayGanador(int tablero[3][3], int jugador) {
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) {
            return true;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (tablero[0][j] == jugador && tablero[1][j] == jugador && tablero[2][j] == jugador) {
            return true;
        }
    }

    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) {
        return true;
    }

    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador) {
        return true;
    }

    return false;
}

bool hayEmpate(int tablero[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int tablero[3][3];
    int jugador = 1;
    int fila, columna;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = 0;
        }
    }

    cout << "=== TRES EN RAYA ===" << endl;
    mostrarTablero(tablero);

    while (true) {
        cout << "Turno del jugador " << jugador << endl;
        cout << "Ingrese fila (0 a 2): ";
        cin >> fila;
        cout << "Ingrese columna (0 a 2): ";
        cin >> columna;

        if (fila < 0 || fila > 2 || columna < 0 || columna > 2) {
            cout << "Posicion fuera de rango. Intente de nuevo.\n";
            continue;
        }

        if (tablero[fila][columna] != 0) {
            cout << "Casilla ocupada. Intente de nuevo.\n";
            continue;
        }

        tablero[fila][columna] = jugador;
        mostrarTablero(tablero);

        if (hayGanador(tablero, jugador)) {
            cout << "Gana el jugador " << jugador << endl;
            break;
        }

        if (hayEmpate(tablero)) {
            cout << "Empate" << endl;
            break;
        }

        if (jugador == 1) {
            jugador = 2;
        } else {
            jugador = 1;
        }
    }

    return 0;
}
