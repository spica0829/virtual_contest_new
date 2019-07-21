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

	//時間計測用
	std::chrono::system_clock::time_point  start, end;

	// winsock2の初期化
	WSAStartup(MAKEWORD(2, 0), &wsaData);
	// ソケットの作成
	sock0 = socket(AF_INET, SOCK_STREAM, 0);
	// ソケットの設定
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	bind(sock0, (struct sockaddr *)&addr, sizeof(addr));

	// TCPクライアントからの接続要求を待つ
	listen(sock0, 5);
	printf("クライアントの接続を待機中です。\n");
	// TCPクライアントからの接続要求を受け付ける
	len = sizeof(client);
	sock = accept(sock0, (struct sockaddr *)&client, &len);
	printf("クライアントに接続しました。 \n");

	while (true)
	{
		end = std::chrono::system_clock::now();  // 計測終了時間
		double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //処理に要した時間をミリ秒に変換
		start = std::chrono::system_clock::now(); // 計測開始時間

												  //受信
												  //経過時間が送られてくる。
		numrcv = recv(sock, buffer, BUFFER_SIZE, 0);
		//サーバ（Unityから文字が送られて来なければ終了）
		if (numrcv == 0 || numrcv == -1) {
			status = closesocket(sock); break;
		}
		//Unityからdouble型の数値が送られてきたときはこのままでよい
		std::string buffer_str = buffer;
		double receive_num = std::stod(buffer_str.c_str());
		printf("経過時間 : %lf 秒 \n", receive_num);


		//送信したいデータをmessageにぶち込む
		//今回はプログラム一周期分の時間を送ってみる。（精度1ms）
		sprintf_s(message, "speed:%lf ms, frequency:%lf \n", elapsed, 1 / (elapsed / 1000));
		send(sock, message, SEND_SIZE, 0);
		printf("送信\n");


		//サーバを閉じたいときにはESCを押す
		if (GetKeyState(VK_ESCAPE) < 0) break;
	}

	// TCPセッションの終了
	closesocket(sock);
	// winsock2の終了処理
	WSACleanup();

	return 0;
}*/