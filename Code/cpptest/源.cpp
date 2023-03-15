//#include<iostream>
//#include<WinSock2.h>
//#include<string>
//#include <time.h>
//#include<fstream>
//#pragma comment (lib, "ws2_32.lib")
//using namespace std;
////定义包类型
//#define SYN 1
//#define ACK 2
//#define FIN 3
//#define ACK_SYN 4
//#define BUF_MAX 1024//缓冲区
//#pragma pack(1)
//struct Packet {
//	u_short len = 8;//2
//	u_short ck_sum = 0;//2
//	u_short type = 0;//[SYN ACK FIN]	//2
//	unsigned char seq = 0;//1
//	unsigned char ack = 0;//1
//};
//#pragma pack(0)
//char* buf = new char[BUF_MAX];
//u_short cksum(u_short* mes, int count) {//u_short宏定义为short类型，占2个字节；以16位为单位取报文(mes) 
//	//mes指向报文，count表示报文-16位 为单位的组数
//	u_long sum = 0;
//	while (count--) {
//		sum += *mes++;//以16位为单位累加
//		if (sum & 0xffff0000) {//如果超出了两个字节，说明有溢出
//			sum &= 0xffff;//只保留低两个字节
//			sum++;
//		}
//	}
//	return ~(sum & 0xffff);
//}
//void servershake(SOCKET S_socket,char*buf, sockaddr_in sockAddr, int len) {
//	cout << "三次握手开始：" << endl;
//	//第一次
//	memset(buf, 0, BUF_MAX);
//	while (recvfrom(S_socket, buf, 8, 0, (sockaddr*)&sockAddr, &len) == -1)
//	{
//		recvfrom(S_socket, buf, 8, 0, (sockaddr*)&sockAddr, &len);
//	}
//	Packet p1;
//	memcpy(&p1, buf, sizeof(p1));
//	if (p1.type == SYN && cksum((u_short*)buf, 4) == 0x0000) {
//		cout << "服务器端收到了SYN包，第一次握手成功 TYPE:";
//		cout << int(p1.type) << endl;
//	}
//	//第二次
//	cout << "第二次握手开始，服务器端发送ACK_SYN包" << endl;
//	memset(buf, 0, BUF_MAX);
//	Packet p2;
//	p2.type = ACK_SYN;
//	while (sendto(S_socket, buf, p2.len, 0, (struct sockaddr*)&sockAddr, sizeof(sockAddr)) == -1) {
//		cout << "失败" << endl;
//	}
//	cout << "成功发送了ACK_SYN包" << endl;
//	//第三次
//	cout << "等待第三次握手：" << endl;
//	Packet p3;
//	memset(buf, 0, BUF_MAX);
//	while (recvfrom(S_socket, buf, 8, 0, (sockaddr*)&sockAddr, &len) == -1)
//	{
//		recvfrom(S_socket, buf, 8, 0, (sockaddr*)&sockAddr, &len);
//	}
//	memcpy(&p3, buf, sizeof(p3));
//	cout << "第三次握手成功 收到了ACK包: TYPE=" << int(p3.type) << endl;
//
//}
//int main() {
//	cout << "Server Set Up!!!" << endl;
//	WSADATA wsaData;
//	WSAStartup(MAKEWORD(2, 2), &wsaData);//2.2版本的Socket
//	SOCKET S_socket = socket(AF_INET, SOCK_DGRAM, 0);//流式套接字
//	struct sockaddr_in sockAddr;//sockaddr_in用作定义，socketaddr用作函数参数
//	memset(&sockAddr, 0, sizeof(sockAddr));  //将结构体清零
//	sockAddr.sin_family = AF_INET;//IPv4
//	sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");//服务器IP
//	sockAddr.sin_port = htons(1234);//端口
//	int len = sizeof(sockAddr);
//	bind(S_socket, (sockaddr*)&sockAddr, sizeof(sockAddr));//绑定
//	//三次握手
//
//}
#include<iostream>
using namespace std;
int main() {
	int a = 0;
	float all_time = 24595;
	float all_num = 1813;
	//float yanshi = 10;
	
	float ttl = (all_num+a) * 8 * 8 / all_time * 1000;
	cout << "时延" << all_time<<endl;
	cout << "吞吐率" << ttl;

	/*cout << "开始生成..." << endl;
	cout<<"p:A12883A3F1F534E4CFBA6E6FDD653A2AC14AA83E61BD7219EE5E94CB7AB3733E"<<endl;
	cout<<"q:560047031FC486AA0C3F73FFB8D76E42F1138384878F3EB4217FD37552EDFBD1"<<endl;
	cout<<"生成公钥："<<endl;
	cout<<"8C953ABC93ECDE71352D2801A642D4A710AB939DD172B70BD51169785E0401E03CE7072F09B2E5F2382233F7CBB735A7A142A61080279237B426C8A9D65D897D"<<endl;
	cout<<"2639A46116C87093F4F1D10913A86D67D12465797783BA71FF73B1FFAE457979699F3471D517898459D2284372BA4152E272270A41F6AD5D66F5DCBCFC6240F3"<<endl;
	cout<<"生成密钥："<<endl;
	cout<<"3B11D55B63157F7C2FC4838787F778FA421A719B545736E7E6770B2D85961B9B8B819E343573D2506F861C81B1B94028EE830D5038BA5DDA15750122D1881C42"<<endl;
	cout<<"1293C13272971492D8EE5A5239AE5E72B98CB3B3A824F32099FAC9849D012A48199D53EDEFACD22CC8A353E5323803425357D97D1C97A7E89E9A4E1EB31CB75B"<<endl;
	cout << "输入明文：123" << endl;
	cout << "得出密文：" << endl;
	cout << "92F45192EA35F8A8833D5358068EBD01788FEC22BCA803BEB0CA7627E102DB7D3D4132EE12C9B3507FCA26C9A02CB90FF8E07798EF1E8405B830DE6CD05125F" << endl;
	cout << "输入密文：92F45192EA35F8A8833D5358068EBD01788FEC22BCA803BEB0CA7627E102DB7D3D4132EE12C9B3507FCA26C9A02CB90FF8E07798EF1E8405B830DE6CD05125F" << endl;
	cout << "得出明文：" << endl;
	cout << "123" << endl;*/
}