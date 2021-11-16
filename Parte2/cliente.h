#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente
{

private:

    std::string dirIp;
    int cantInfo;

public:

    //Constructor y destructor

    Cliente();

    //Setters

    void setDirIp(std::string direccion);
    void setCantInfo(int informacion);

    //Getters

    std::string getDirIp();
    int getCantInfo();

};

#endif // CLIENTE_H
