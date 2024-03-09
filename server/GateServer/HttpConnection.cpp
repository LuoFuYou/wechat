#include "HttpConnection.h"

HttpConnection::HttpConnection(net::io_context& ioc):_socket(ioc)
{

}

tcp::socket& HttpConnection::GetSocket()
{
	return _socket;
}

//�������������ӵ����ݽ�������
void HttpConnection::Start()
{
	auto self = shared_from_this();
	http::async_read(_socket, _buffer, _request, [self](beast::error_code ec,
		std::size_t bytes_transferred) {
			try {
				if (ec) {
					std::cout << "http read err is " << ec.what() << std::endl;
					return;
				}

				//�������������
				boost::ignore_unused(bytes_transferred);
				self->HandleReq();
			}
			catch (std::exception& exp) {
				std::cout << "exception is " << exp.what() << std::endl;
			}
		}
	);
}
