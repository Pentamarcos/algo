#include <iostream>
#include <fstream>
#include <vector>
#include <cliente.h>
#include <string.h>

using namespace std;

int main()
{
    string nombreArchivoO("/home/alumno/TP2/clientes.txt");       // "F:\\Bibliotecas\\Documents\\Marcos\\Materias\\Segundo ano\\Informatica 2\\Tps\\Tp2\\clientes.txt"
    string nombreArchivoI("/var/log/squid/access.log");         // "F:\\Bibliotecas\\Documents\\Marcos\\Materias\\Segundo ano\\Informatica 2\\Tps\\Tp2\\access.log"

    vector<string> lineas;
    vector<Cliente> clientes;

    string linea;

    int cantL;
    int cantC;

    ifstream archivoI(nombreArchivoI);

    ofstream archivoO;
    archivoO.open(nombreArchivoO);

    if (!archivoI.is_open())
    {

        cerr << "El archivo - '"
             << nombreArchivoI << "' - no se puede abrir." << endl;

        return EXIT_FAILURE;

    }

    while (getline(archivoI, linea))
    {
        char * datos[10];

        int i = 0;

        lineas.push_back(linea);

        char * clinea = new char [linea.length()+1];

        strcpy(clinea, linea.c_str());

        char * informacionLinea = strtok (clinea, " ");
        while (informacionLinea != 0)
        {
            datos[i] = informacionLinea;
            informacionLinea = strtok(NULL, " ");

            i++;
        }

        //cout << datos[1] << ' ';
        //cout << datos[2] << endl;
        //system("pause");

        Cliente clienteA;

        clienteA.setCantInfo(std::atoi(datos[1]));
        clienteA.setDirIp(datos[2]);

        clientes.push_back(clienteA);

        delete[] clinea;

    }

    cantL = lineas.size();
    cantC = clientes.size();

    for (int i = 0 ; i < cantC ; i++)
    {
        string mandar;

        string ip = clientes[i].getDirIp();

        //cout << clientes[i].getDirIp() << endl;
        //cout << clientes[i].getCantInfo() << endl;
        //system("pause");

        string bytes = " bytes.";
        string direccionCliente = "Direccion IP del cliente: ";
        string infoCliente = ", informacion transmitida del cliente: ";

        string cant = std::to_string(clientes[i].getCantInfo());

        mandar = direccionCliente + ip + infoCliente + cant + bytes;

        if (archivoO.is_open())
        {

            archivoO << mandar << endl;
            //cout << mandar << endl;

        }
        else
        {
            cerr << "El archivo - '"
                 << nombreArchivoO << "' - no se puede abrir." << endl;
        }

        //cout << mandar << endl;
        //cout << lineas[i] << endl;
        //system("pause");

    }

    cout << cantL << endl;
    cout << cantC << endl;

    archivoO.close();
    archivoI.close();

    return EXIT_SUCCESS;
}
