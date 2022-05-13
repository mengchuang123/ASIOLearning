#include <iostream>
#include <deque>
#include <set>
#include<vector>
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp> //稳定计时库
using namespace boost::asio;
using namespace std;
enum {BUF_SIZE = 1024};
//同步服务器端
void Session(ip::tcp::socket socket){
    //通过move转移语义，将acceptor.accept()的值直接转移给Session的参数没有内存拷贝开销
    // boost::array<char,BUF_SIZE> data;
    vector<char> data(BUF_SIZE);
    boost::system::error_code ec;
    try
    {
        while(true){
            int btye_size = socket.read_some(buffer(data),ec);
            if(ec==error::eof){
                cout << "tcp close" << endl;
                break;
            }
            else if(ec){
                throw boost::system::system_error(ec);
            }
            write(socket,buffer(data,btye_size));

        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}

int main()
{
    io_context ioc;
    string sport;
    cout << "port:" ;
    cin >> sport;
    int port = stoi(sport);
    // steady_timer   
    ip::tcp::acceptor acceptor(ioc,ip::tcp::endpoint(ip::tcp::v4(), port));
    try
    {
        //每次只能处理一次连接，因为acceptor.accept会发生阻塞
        while(true){
            Session(acceptor.accept());
        }
    }
    catch(const std::exception& e)
    {
        printf("error1");
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}