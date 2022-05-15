# PacketManager

It is useful for modding some things. Example : there is no packet in game for changing map fog color. If we want the server to set it to clients, we need the server to send the packet, and the client to handle it. \
Sending the packet from game server is out of scope of this documentation and not handled in the client modding project. \
The only work required in the client modding project, is to handle the packet received by the game server.

## How to read sent/received packets :

```cpp
// Read a received packet (ex: mv) :
packetMng.Subscribe(PacketType::RCVD, "mv", [&](std::string& Packet)
{
    // Do whatever you want with the packet, you can print it for example
    std::cout << "Received : " << Packet << std::endl;
});

// Read a sent packet (ex: walk) :
packetMng.Subscribe(PacketType::SENT, "walk", [&](std::string& Packet)
{
    std::cout << "Sent : " << Packet << std::endl;
});
```

## How to send/receive a packet :

```cpp
// Send a packet (example: preq). It is the packet sent to trigger a portal (to change map)
packetMng.Send("preq");

// Receive a packet (example: gold)
packetMng.Receive("gold 1500000 0");
```

## How to add the above functionality ?

Let's do the example described in the introduction : we are receiving a packet from the game server telling the client modding project to change the color of the map fog color. \
First, we need to know the packet structure, you can't guess it. It is maybe documented in the Game Server project, but you can just ask me.
The packet will probably be something like `map_fog_color [red_value] [green_value] [blue_value]`. Example : `map_fog_color 255 0 0` set the map fog to completely red. \
We have the header : `map_fog_color` and we know there are 3 parameters splitted by space. We can start writing it.
```cpp
packetMng.Subscribe(PacketType::Rcvd /* We are receiving it from Game server */, "map_fog_color" /* The packet header */, [&](std::string& Packet)
{
    // Packet will be something like "map_fog_color 255 0 0"
    auto packs = Split(Packet, " "); // Split packet by space, so we can access every parameters easily
    // packs is a list of string : packs[0] = "map_fog_color", packs[1] = "255" (red), packs[2] = "0" (green), packs[3] = "0" (blue)
    // Since they are strings, we must convert red green and blue to integer value (from 0 to 255)
    // uint8_t is exactly the value we want : 0 to 255 (1 byte, 8 bits)
    uint8_t red = ToNumber(packs[1]);
    uint8_t green = ToNumber(packs[2];
    uint8_t blue = ToNumber(packs[3]);
    
    // Now, we are perfectly handling the packet structure, the only thing left to do is to use those values.
    // mapCom  is documented here : https://github.com/DitzProject/ClientModdingAPI/tree/main/ClientModding/Api/CustomClasses/MapCommon
    // Set red value :
    mapCom.fog.SetRed(red);
    mapCom.fog.SetGreen(green);
    mapCom.fog.SetBlue(blue);
    
    // Done ! Everytime you'll receive the packet "map_fog_color [red] [green] [blue]", the fog color will be changed to the wanted values
});
```

Note that it can be written shorter :
```cpp
packetMng.Subscribe(PacketType::Rcvd, "map_fog_color", [&](std::string& Packet)
{
    auto packs = Split(Packet, " ");
    mapCom.fog.SetRed(ToNumber(packs[1]));
    mapCom.fog.SetGreen(ToNumber(packs[2]));
    mapCom.fog.SetBlue(ToNumber(packs[3]));
});
```
