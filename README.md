# Communication-with-UDP-using-Boost.Asio-
Client-side and server-side communication Demo based on UDP communication principle and Boost.Asio


基于UDP和Boost.Asio的服务器端、客户端简单通信Demo


执行步骤：
1. 首先运行server.cpp文件+
2. 再运行client.cpp文件。提示“Please input：”，然后输入一段字符串。客户端会将该字符串发送至服务器端，服务器端将字符串打印到终端，同时将原字符串+服务器端ip地址连接后回传给客户端，并打印到客户端的终端界面。
3. 客户端可以发送多次消息，直至发送“end”时，客户端终止运行。


执行效果如下图所示：


客户端：


![image](https://user-images.githubusercontent.com/62458821/182094844-aa6479b7-361e-4ba2-a5d3-9a86ea185868.png)



服务器端：


![image](https://user-images.githubusercontent.com/62458821/182094897-9be63cc3-e81a-43e7-864a-3c9589bf0a1b.png)
