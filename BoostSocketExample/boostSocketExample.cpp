#include <iostream>
#include <string>
#include <boost/asio.hpp>


int main() {
    std::string host = "127.0.0.1";
    unsigned short port = 3333;
  try {
    boost::asio::ip::tcp::endpoint endPoint(boost::asio::ip::address::from_string(host), port);
    boost::asio::io_service ioService;
    boost::asio::ip::tcp::socket socket(ioService);
    socket.connect(endPoint);
    std::string message = "Hello World";
    boost::system::error_code error;
    size_t bytesSent = socket.write_some(boost::asio::buffer(message), error);
    std::cout << "Send message: " << message << std::endl;
    socket.close();
  } catch (boost::system::system_error &e) {
    std::cout << "An error has occured! Code = " << e.code() << ". Message: " << e.what() << std::endl;
    return e.code().value();
  }
    return 0;
}
