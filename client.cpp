#include <iostream>
#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>
#include <string.h>

using namespace std;
using namespace boost::asio;

int main() {
    try 
    {
        cout << "UDP Client Start ......" << endl;
       
        while (true)
        {
            // 传递给Server的message
            char message[100] = "";
            // 输入想要发送给server端的message
            cout << "------------------------------------------" << endl;
            cout << "Please input:";
            cin.getline(message, 100);
            //cin >> message;
            if (strcmp(message, "end") == 0)
            {
                break;
            }

            // 选择接口
            io_service ios;
            ip::udp::endpoint send_ep(ip::address::from_string("127.0.0.1"), 6699);

            // 创建socket对话并发送message
            ip::udp::socket sock(ios);
            sock.open(ip::udp::v4());
            sock.send_to(buffer(message), send_ep);

            // 接收server端的消息
            vector<char> v(100, 0);
            ip::udp::endpoint recv_ep;
            sock.receive_from(buffer(v), recv_ep);
            cout << "Receive from " << recv_ep.address() << ":" << &v[0] << endl;
        }
    }
    catch (exception& e) {
        cerr << e.what() << endl;
    }
    return 0;
}