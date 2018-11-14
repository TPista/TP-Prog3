//TP CALCULADORA
//INTEGRANTES: CARRO,AGUSTÌN ; CARLOS, RODRIGUEZ ; TOMAS, PISTARELLI ; DIEGO, MONTI.

#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;
/* Operadores matematicos */
#define N_operators 6
const string signos[N_operators] = {"+", "-", "*", "/", "%", "^"};
int precedences[N_operators] = {1, 1, 2, 2, 2, 3};

bool operador( const string );
int precedencia( const string );


int main() {

    string infijo, postfijo, token;
    stack <string> standby;
    stack <double> result;
    size_t i;
    char c;
    double A, B;

    /* Cadena de entrada */
    cout << "Intro expresion infija:";
    getline( cin, infijo );
    cout << endl;

    /*
      PRIMERA PARTE: Procesar la cadena infijo, y crear posfijo
     */
    for ( i = 0; i < infijo.size(); i++ ) {
        /* esto debe cambiar luego a un token o palabra devuelta por
         * el analizador léxico */
        c = infijo[i];
        token.clear();
        token += c;			

        /* es un espacio: despreciar */
        if ( c == ' ' ) continue;

        cout << "Analizando token: '" << c << "'" << endl;

        /* es un carácter numérico: pasar al posfijo */
        if ( c >= '0' && c <= '9' ) {
            cout << "\tes numero: pasado a posfijo" << endl << endl;
            postfijo = postfijo + " " + c;
            continue;
        }

        /* si se lee un operador: sacar de la pila y pasar al postfijo
         * todos los operadores con una precedencia mayor o igual a la
         * suya, y depositar el mismo en la pila */
        if ( operador( token ) ) {
            cout << "\tes operador:" << endl;
            while ( !standby.empty() && precedencia( standby.top() )
                                        >= precedencia( token ) ) {
                cout << "\tpasado operador '" + standby.top() +
                        "' de la pila a posfijo" << endl;
                postfijo = postfijo + " " + standby.top();
                standby.pop();
            }
            standby.push( token );
            cout << "\tcolocar '" << token << "' en la pila" << endl << endl;
            continue;
        }

        /* si se lee "(": colocar en la pila */
        if ( token == "(") {
            cout << "pasado a posfijo" << endl << endl;
            standby.push( token );
            continue;
        }

        /* si se lee ")": retirar de la pila hasta encontrar '(', y pasar
         * los elementos retirados a posfijo, luego descartar el "(" */
        if ( token == ")" ) {
            while ( !standby.empty() && standby.top() != "(" ) {
                cout << "\tpasado operador '" + standby.top() +
                        "' de la pila a posfijo" << endl << endl;
                postfijo = postfijo + " " + standby.top();
                standby.pop();
            }
            if ( !standby.empty() )
                standby.pop();	/* descartar el "(" */
        }
    }

    /* extraer de la pila cualquier operador restante y pasarlo a la cadena posfijo */
    while ( !standby.empty() ) {
        cout << "Pasado operador '" + standby.top() +
                "' de la pila a posfijo" << endl << endl;
        postfijo = postfijo + " " + standby.top();
        standby.pop();
    }

    /* Imprimir el posfijo */
    cout << "Posfijo es: \n\t" << postfijo << endl << endl;

    /*
      SEGUNDA PARTE: Procesar la cadena posfijo, y devolver resultado
     */

    A = 0;
    cout << "Evaluando la expresion ..." << endl;
    for ( i = 0; i < postfijo.size(); i++ ) {

        c = postfijo[i];
        token.clear();
        token += c;

        /* si se lee un operando (caracter numerico), depositar en la pila */
        if ( c >= '0' && c <= '9' ) {
            result.push( c - '0' );
            continue;
        }

        /* si se lee un operador binario, poner en A y B los últimos dos argumentos
         * de la pila y operarlos, guardando el resultado en la pila */
        if ( operador( token ) ) {
            if ( !result.empty() ) {
                B = result.top();
                result.pop();
            }
            else {
                cout << "Argumentos insuficientes para '" << c << "'" << endl;
                return -1;
            }

            if ( !result.empty() ) {
                A = result.top();
                result.pop();
            }
            else {
                cout << "Argumentos insuficientes para '" << c << "'" << endl;
                return -1;
            }

            cout << "\toperar " << A << token << B << " = ";
            if ( token == "+" ) {
                A += B;
                result.push( A );
            }
            else if ( token == "-" ) {
                A -= B;
                result.push( A );
            }
            else if ( token == "*" ) {
                A *= B;
                result.push( A );
            }
            else if ( token == "/" ) {
                A /= B;
                result.push( A );
            }
            else if ( token == "%" ) {
                A = (int )A % (int )B;
                result.push( A );
            }
            else if ( token == "^" ) {
                A = pow(A, B);
                result.push( A );
            }
            cout << A << endl;
        }
    }

    if ( !result.empty() )
        cout << endl << "El resultado es: " << result.top() << endl;

    return 0;
};

/* Verdadero si el token corresponde a un operador. */
bool operador( const string token ) {

    for ( int i = 0; i < N_operators; i++ )
        if ( signos[i] == token )
            return true;

    return false;
}

/* Devuelve la precedencia del operador descrito por el
 * string token (-1 si no es un operador) */
int precedencia( const string token ) {

    for ( int i = 0; i < N_operators; i++ )
        if ( signos[i] == token )
            return precedences[i];

    return -1;
}
