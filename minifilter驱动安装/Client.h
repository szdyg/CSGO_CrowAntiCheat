#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma once
#include "stdafx.h" 

#include <winsock2.h>
#include<iostream>

#define MAX_BUFFER_LEN 8196    
#define DEFAULT_PORT          12345                      // 默认端口
#define DEFAULT_LOCAL_IP            _T("127.0.0.1")            // 默认IP地址
#define DEFAULT_SERVER_IP    _T("192.168.0.104") 
#define DEFAULT_THREADS       100                        // 默认并发线程数
#define DEFAULT_MESSAGE       _T("Hello!")   // 默认的发送信息


class CClient
{
public:
	CClient(void);
	~CClient(void);

public:
	// 加载Socket库
	bool LoadSocketLib();
	// 卸载Socket库，彻底完事
	void UnloadSocketLib() { WSACleanup(); }
	// 设置连接IP地址
	void SetIP(const CString& strIP) { m_strServerIP = strIP; }
	// 设置监听端口
	void SetPort(const int& nPort) { m_nPort = nPort; }
	void SockSendMessage(const CString& strMessage);
	// 向服务器进行连接
	bool ConnetToServer();
private:

	CString   m_strServerIP;                                // 服务器端的IP地址
	CString   m_strLocalIP;                                 // 本机IP地址								
	SOCKET    sClient;                                 		//连接所用套节字      
	int       m_nPort;                                      // 监听端口
};
