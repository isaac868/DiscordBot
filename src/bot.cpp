#include <iostream>
#include "atlstr.h"
#include <cpprest\ws_msg.h>
#include <cpprest\ws_client.h>

using WSClient      = web::websockets::client::websocket_callback_client;
using WSOMessage    = web::websockets::client::websocket_outgoing_message;
using WSIMessage    = web::websockets::client::websocket_incoming_message;
using WSCloseStatus = web::websockets::client::websocket_close_status;

//https://discordapp.com/api/
int main()
{
    WSClient client;

    std::atomic<bool> open = true;

    client.set_message_handler([](const WSIMessage& msg) { std::cout << msg.extract_string().get() << std::endl; });
    client.set_close_handler([&open](WSCloseStatus close_status, const utility::string_t& reason, const std::error_code& error) { std::cout << 
        static_cast<int>(close_status) << std::endl << error.category().name() << std::endl << error.value() << std::endl << error.message(); std::wcout<<reason; open = false; });

    client.connect(_T("wss://gateway.discord.gg")).wait();

    WSOMessage msg;
    msg.set_utf8_message("test");

    //client.send(msg).then([]() { std::cout << "sending\n"; });

    //std::cout<<client.receive().then([](WSIMessage msg) {
    //                    return msg.extract_string();
    //                }).get();

    //client.send(msg).then([]() { std::cout << "sending\n"; });

    while (open)
    {
    }

    client.close();
    return 0;
}