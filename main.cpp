#include<iostream>
//#include<DxLib.h>
#include "System.h"
//#include<erslib.h>


int main(void)
{
	//システム初期化
	if (SYSTEM->Initialize())
	{
		//メイン関数実行
		SYSTEM->Main();
	}

	//システム終了処理
	SYSTEM->Finalize();
	
	return 0;
}


//#define BUFSIZE 5000
/*
int main(void)
{
	char moji;
	int port = 3;
	char buf[1000];

	int e = ERS_Open(port, BUFSIZE, BUFSIZE);
	ERS_Config(port, ERS_9600);

	if (e == 0)
	{
		std::cout << "オープンできた" << std::endl;
	}
	else if (e == 1)
	{
		std::cout << "ポート番号が範囲外" << std::endl;
		return -1;
	}
	else if (e == 2)
	{
		std::cout << "すでにオープンされてる" << std::endl;
		return -2;
	}
	else if (e == 3)
	{
		std::cout << "他で使用中か装備されてない" << std::endl;
		return -3;
	}
	else if (e == 4)
	{
		std::cout << "指定のボーレートでオープンできなかった" << std::endl;
		return -4;
	}
	
	while (1)
	{
		if (ERS_CheckRecv(port) > 0)
		{
			e = ERS_Recv(port, buf, 1);
			e = ERS_Send(port, buf, 1);

			if (buf[0] == 'S')
			{
				std::cout << "S";
			}
			else if (buf[0] == 'B')
			{
				std::cout << "B";
			}
		}
	}

	ERS_Close(port);

    return 0;
}
*/