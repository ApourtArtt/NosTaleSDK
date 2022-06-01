# NostaleWidget

## How to compile
I recommand using Visual Studio (2019 or 2022) - C++17 and above is supported

### 1) You should add Discord SDK
Create a folder in `C:` named `code`. Unzip the [Discord SDK](https://dl-game-sdk.discordapp.net/2.5.6/discord_game_sdk.zip) in this folder, name it `discordsdk`. You should have a path : `C:\code\discordsdk`.\
Go back on Visual Studio :
- Adding Discord headers :
  - Right click on the project, Properties
  - Go to C/C++ -> General
  - Add `C:\code\discordsdk\cpp` to "Other Include folders"
- Adding Discord library :
  - Still in the Properties windows, go to Linker -> General
  - Add `C:\code\discordsdk\lib\x86` to "Additional library folder"

You will also need to copy `C:\code\discordsdk\lib\x86\discord_game_sdk.dll` into Nostale folder.

### 2) You should build the final DLL as 32 bits


## Contributors

[Flowx3](https://github.com/Flowx3)
