#include <iostream>
#include <deque>
#include <set>
#include<vector>
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp> //稳定计时库
using namespace boost::asio;
using namespace std;
// using boost::asio;
enum {BUF_SIZE = 1024};
int main(void){
    io_context service;
    string host = "127.0.0.1";
    string port = "8081";
    ip::tcp::resolver resolver(service);
    auto endpoints = resolver.resolve(ip::tcp::v4(), host, port);

    ip::tcp::socket socket(service);
    connect(socket, endpoints);
    string data;
    cin >> data;
    write(socket,buffer(data,data.size()));
    //接受字符串

    try
    {
        std::size_t total_reply_length = 0;
        while (true) {
        std::array<char, BUF_SIZE> reply;
        std::size_t reply_length = socket.read_some(boost::asio::buffer(reply));

        std::cout.write(reply.data(), reply_length);

        total_reply_length += reply_length;
        if (total_reply_length >= data.size()) {
            break;
        }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }




    return 0;
}
