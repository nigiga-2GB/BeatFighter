#pragma once


class SerialManager
{
public:
	SerialManager();
	~SerialManager();

	int OpenPort(int port, int bps = 9600);
	int ClosePort(int port);

	int CheckRecv(int port);
	int Recv(int port, char buffer[], int size);
};