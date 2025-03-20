#include "SerialManager.h"

#include<erslib.h>

SerialManager::SerialManager()
{

}

SerialManager::~SerialManager()
{
	ERS_CloseAll();
}

int SerialManager::OpenPort(int port, int bps)
{
	return ERS_Open(port, bps);
}

int SerialManager::ClosePort(int port)
{
	return ERS_Close(port);
}

int SerialManager::CheckRecv(int port)
{
	return ERS_CheckRecv(port);
}

int SerialManager::Recv(int port, char buffer[], int size)
{
	return ERS_Recv(port, buffer, size);
}