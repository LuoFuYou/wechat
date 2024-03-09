#include "CServer.h"
#include <iostream>
#include "HttpConnection.h"
CServer::CServer(unsigned short& port) :_ioc(1),
_acceptor(_ioc, { net::ip::make_address("0.0.0.0"), port }) {
	
}

void CServer::Listen()
{
	auto http_con_ptr = std::make_shared<HttpConnection>(_ioc);
	_acceptor.async_accept(http_con_ptr->GetSocket(), [http_con_ptr, this](beast::error_code ec) {
		try {
			//���������������ӣ���������������
			if (ec) {
				Listen();
				return;
			}

			//���������ӣ�����HpptConnection�����������
			http_con_ptr->Start();
			//��������
			Listen();
		}
		catch (std::exception& exp) {
			std::cout << "exception is " << exp.what() << std::endl;
			Listen();
		}
	});
}

