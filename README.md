# NostaleWidget

I have been asked multiple times the last days if there was a way to donate for this project. The answer was no.\
After thinking about it, I am happy to give you a way to donate [here](https://donner.croix-rouge.fr/urgence-ukraine/~mon-don?_cv=1).\
This is not for me, but at least you know what to do if you want to thank me for this project!\
(For french people, you need to know you can get a partial tax exemption by donating to an association)

## Features
### Big features
- [x] Discord integration (tutorial TODO)
- [x] Widget creation ([tutorial](https://github.com/ApourtArtt/NostaleWidget/wiki/Windows-and-widgets))
- [x] Widget modification (tutorial TODO)
- [x] Packet management and interaction ([tutorial](https://github.com/ApourtArtt/NostaleWidget/wiki/Packet-management))
- [x] Wings and Auras creation and modification ([tutorial](https://github.com/ApourtArtt/NostaleWidget/wiki/Wings-management))
- [x] Weapons and Armors rarity/upgrade addition and glowing modding ([tutorial](https://github.com/ApourtArtt/NostaleWidget/wiki/Stuff-management))

### Little features
- [x] Access to server and channel values in game
- [x] Change map fog color, intensity, objects color
- [x] Idle the game when not visible
- [x] See target/group HP/MP
- [ ] See cooldown timers
- [ ] Ctrl+Z while busy without breaking action
- [x] Add range for talking with NPC

### You can also submit your idea in the issues

## How to compile
I recommand using Visual Studio (2019 or 2022) - C++20 is supported

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


## Notes
Patterns are designed for the client version 3175.

## Contributors

[Flowx3](https://github.com/Flowx3)
[Hatz](https://github.com/hatz02)
[Limo96](https://github.com/Limo96)
