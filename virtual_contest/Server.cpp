/*#include <stdio.h>
#include <winsock2.h>
#include <string>
#include <iostream>
#include <chrono>

#define SEND_SIZE 256
#define BUFFER_SIZE 256

int main()
{
	WSADATA wsaData;
	SOCKET sock0;
	struct sockaddr_in addr;
	struct sockaddr_in client;
	int len;
	SOCKET sock;
	int status;
	int numrcv;
	char message[SEND_SIZE];
	char buffer[BUFFER_SIZE];

	//���Ԍv���p
	std::chrono::system_clock::time_point  start, end;

	// winsock2�̏�����
	WSAStartup(MAKEWORD(2, 0), &wsaData);
	// �\�P�b�g�̍쐬
	sock0 = socket(AF_INET, SOCK_STREAM, 0);
	// �\�P�b�g�̐ݒ�
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	bind(sock0, (struct sockaddr *)&addr, sizeof(addr));

	// TCP�N���C�A���g����̐ڑ��v����҂�
	listen(sock0, 5);
	printf("�N���C�A���g�̐ڑ���ҋ@���ł��B\n");
	// TCP�N���C�A���g����̐ڑ��v�����󂯕t����
	len = sizeof(client);
	sock = accept(sock0, (struct sockaddr *)&client, &len);
	printf("�N���C�A���g�ɐڑ����܂����B \n");

	while (true)
	{
		end = std::chrono::system_clock::now();  // �v���I������
		double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //�����ɗv�������Ԃ��~���b�ɕϊ�
		start = std::chrono::system_clock::now(); // �v���J�n����

												  //��M
												  //�o�ߎ��Ԃ������Ă���B
		numrcv = recv(sock, buffer, BUFFER_SIZE, 0);
		//�T�[�o�iUnity���當���������ė��Ȃ���ΏI���j
		if (numrcv == 0 || numrcv == -1) {
			status = closesocket(sock); break;
		}
		//Unity����double�^�̐��l�������Ă����Ƃ��͂��̂܂܂ł悢
		std::string buffer_str = buffer;
		double receive_num = std::stod(buffer_str.c_str());
		printf("�o�ߎ��� : %lf �b \n", receive_num);


		//���M�������f�[�^��message�ɂԂ�����
		//����̓v���O������������̎��Ԃ𑗂��Ă݂�B�i���x1ms�j
		sprintf_s(message, "speed:%lf ms, frequency:%lf \n", elapsed, 1 / (elapsed / 1000));
		send(sock, message, SEND_SIZE, 0);
		printf("���M\n");


		//�T�[�o��������Ƃ��ɂ�ESC������
		if (GetKeyState(VK_ESCAPE) < 0) break;
	}

	// TCP�Z�b�V�����̏I��
	closesocket(sock);
	// winsock2�̏I������
	WSACleanup();

	return 0;
}*/