#include <iostream>
#include <string.h>
#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>


using namespace std;
using namespace boost::asio;


int main() 
{
    try {
        cout << "UDP Server Start ......" << endl;
        
        // 具体的服务器地址与端口
        io_service ios;
        ip::udp::socket sock(ios, ip::udp::endpoint(ip::udp::v4(), 6699));

        while (true) 
        {
            // 接收远程连接进来的端点
            ip::udp::endpoint ep;
            // 接受client端的message
            char message[100];
            string message_str;
            string send_message;

            // 接受client端的消息
            boost::system::error_code ec;
            sock.receive_from(buffer(message), ep, 0, ec);
            message_str = message;

            // 拼接message和本地ip
            send_message = message_str + "(From Server:" + sock.local_endpoint().address().to_string() + ")";
            
            // 打印client的消息
            if (ec && ec != error::message_size) {
                throw boost::system::system_error(ec);
            }
            cout << "------------------------------------------" << endl;
            cout << "Receive from " << ep.address() << ":" << message_str << endl;
            cout << "send to " << ep.address() << ":" << send_message << endl;
            sock.send_to(buffer(send_message), ep);
        }
    }
    catch (std::exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}