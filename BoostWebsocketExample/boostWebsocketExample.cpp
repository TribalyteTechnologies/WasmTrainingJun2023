#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/beast.hpp>

int main(int argc, char** argv) {
    try {
        std::string host = "127.0.0.1";
        std::string port = "3333";
        std::string message = "Hello World!";

        boost::asio::io_context ioContext;
        boost::asio::ip::tcp::resolver resolver{ioContext};
        boost::beast::websocket::stream<boost::asio::ip::tcp::socket> webSocket{ioContext};

        auto const results = resolver.resolve(host, port);

        auto endPoint = boost::asio::connect(webSocket.next_layer(), results);

        host += ':' + std::to_string(endPoint.port());

        webSocket.set_option(boost::beast::websocket::stream_base::decorator(
            [](boost::beast::websocket::request_type& req) {
                req.set(boost::beast::http::field::user_agent,
                    std::string(BOOST_BEAST_VERSION_STRING) +
                        " websocket-client-coro");
            }));

        webSocket.handshake(host, "/");

        webSocket.write(boost::asio::buffer(message));

        boost::system::error_code errorCode;
        webSocket.close(boost::beast::websocket::close_code::normal, errorCode);
    }
    catch(std::exception const& e) {
        std::cerr << "There was an error: " << e.what() << std::endl;
        return -1;
    }
    return 0;
}
