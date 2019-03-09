
#include"stdafx.h"
#include"Client.h"

CClient::CClient(void) :
	m_strServerIP(DEFAULT_SERVER_IP),
	m_strLocalIP(DEFAULT_LOCAL_IP),
	m_nPort(DEFAULT_PORT)

{
}

CClient::~CClient(void)
{

}

////////////////////////////////////////////////////////////////////
// 初始化WinSock 2.2
bool CClient::LoadSocketLib()
{
	WSADATA wsaData;
	int nResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (NO_ERROR != nResult)
	{
		return false; // 错误
	}
	return true;
}

void CClient::SockSendMessage(const CString & strMessage)
{
	send(sClient, strMessage, strMessage.GetLength(), 0); //sClient指明用哪个连接发送； szMessage指明待发送数据的保存地址 ；strlen(szMessage)指明数据长度 
}

bool CClient::ConnetToServer()
{
	// 创建客户端套节字      
	sClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //AF_INET指明使用TCP/IP协议族；      
														 //SOCK_STREAM, IPPROTO_TCP具体指明使用TCP协议   
	if (INVALID_SOCKET == sClient)
	{
		printf("错误：初始化Socket失败，错误信息：%d\n", WSAGetLastError());
		return false;
	}
	//保存远程服务器的地址信息      
	SOCKADDR_IN server;
	// 指明远程服务器的地址信息(端口号、IP地址等)      
	memset(&server, 0, sizeof(SOCKADDR_IN)); //先将保存地址的server置为全0      
	server.sin_family = PF_INET; //声明地址格式是TCP/IP地址格式      
	server.sin_port = htons(m_nPort); //指明连接服务器的端口号，htons()用于 converts values between the host and network byte order      
	//指明连接服务器的IP地址      
	//结构SOCKADDR_IN的sin_addr字段用于保存IP地址，sin_addr字段也是一个结构体，sin_addr.s_addr用于最终保存IP地址      
	//inet_addr()用于将 形如的"127.0.0.1"字符串转换为IP地址格式 
	server.sin_addr.s_addr = inet_addr(m_strServerIP);   

	// 开始连接服务器
	//连到刚才指明的服务器上      
	//连接后可以用sClient来使用这个连接      
	//server保存了远程服务器的地址信息 
	if (SOCKET_ERROR == connect(sClient, (struct sockaddr *) &server, sizeof(SOCKADDR_IN)))
	{
		closesocket(sClient);
		printf("错误：连接至服务器失败！\n");
		return false;
	}

	return true;
}