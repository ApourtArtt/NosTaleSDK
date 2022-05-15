# Connection

Gives access to some session-related informations. This object is accessible through `connection`.

## ServChan

Accessed through `connection.servChan`
This object gives access to the server and channel ID, like :
```cpp
std::cout
    << "We are on server " << connection.servChan.GetServer()
    << " and on channel "  << connection.servChan.GetChannel();
```
