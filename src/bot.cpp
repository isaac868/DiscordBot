#include <iostream>
#include "atlstr.h"
#include <cpprest\ws_msg.h>
#include <cpprest\ws_client.h>

using WSClient   = web::websockets::client::websocket_client;
using WSOMessage = web::websockets::client::websocket_outgoing_message;
using WSIMessage = web::websockets::client::websocket_incoming_message;

int main()
{
    WSClient client;

    client.connect(_T("wss://echo.websocket.org/")).wait();

    WSOMessage msg;
    msg.set_utf8_message("test");
    client.send(msg).then([]() { std::cout << "sending\n"; });

    std::cout<<client.receive().then([](WSIMessage msg) {
                        return msg.extract_string();
                    }).get();

    return 0;
}