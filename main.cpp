#include<iostream>
//#include<DxLib.h>
#include "System.h"
//#include<erslib.h>


int main(void)
{
	//�V�X�e��������
	if (SYSTEM->Initialize())
	{
		//���C���֐����s
		SYSTEM->Main();
	}

	//�V�X�e���I������
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
		std::cout << "�I�[�v���ł���" << std::endl;
	}
	else if (e == 1)
	{
		std::cout << "�|�[�g�ԍ����͈͊O" << std::endl;
		return -1;
	}
	else if (e == 2)
	{
		std::cout << "���łɃI�[�v������Ă�" << std::endl;
		return -2;
	}
	else if (e == 3)
	{
		std::cout << "���Ŏg�p������������ĂȂ�" << std::endl;
		return -3;
	}
	else if (e == 4)
	{
		std::cout << "�w��̃{�[���[�g�ŃI�[�v���ł��Ȃ�����" << std::endl;
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