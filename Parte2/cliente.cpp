#include "cliente.h"

#include <string>

Cliente :: Cliente()
{

}

void Cliente :: setDirIp(std::string direccion)
{
    this->dirIp = direccion;
}

void Cliente :: setCantInfo(int informacion)
{
    this->cantInfo = informacion;
}

std::string Cliente :: getDirIp()
{
    return this->dirIp;
}

int Cliente :: getCantInfo()
{
    return this->cantInfo;
}
