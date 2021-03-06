# Snake
Snake game in c++ using graphics library dynamically at runtime

#### NOTE THIS WAS BUILT ON MAC AND WAS NOT MADE FOR CROSS PLATFORM

## SETUP

To setup the game have the following
```
brew
cmake
clang++
```
now run the following commands
```
git clone https://github.com/ChazniK/nibbler.git && cd nibbler
make
```

if you have all the depencies mentioned above it will attempt to download  
the required graphics library needed.
This part will take few seconds to compile.  
After compiling you can now run  
```
./nibbler
```

## MENU
running nibbler you'll start off at menu in which you can set some settings,  
select single player or multiplayer.  

The settings menu will allow you to change amount of lives,  
the difficulty(this increase your speed more).  
You can also change the default screen resolution here.  

## CONTROLS
```
ESC = exit game/menu
F1 = use sfml graphics library
F2 = use sdl graphics library
F3 = use glfw graphics library
ARROW_UP = move up
ARROW_DOWN = move down
ARROW_LEFT = move left
ARROW_RIGHT = move right
BUTTON_W = move player 2 up
BUTTON_A = move player 2 left
BUTTON_S = move player 2 down
BUTTON_D = move player 2 right
ENTER = select option in menu
```

## Multiplayer over local lan

It's possible to create a local lan of the snake game. one starts as the server  
and the other connects to it as a client. For not the ip will be set to a hardcoded  
default value of "10.204.0.10" and port "2000" change this in the source code  
to your local lan or prefered ip, recompile and run it again with the new settings.  
To change it look in the LIB1/Display.hpp for "\_ip = "10.204.0.19"" and "\_port = 200".  

## SHOWCASE

### Single player mode
  
This shows the snake game running and changing between 3 different graphics library on runtime.

<img src="gif/single_player_mode.gif" />

### Multiplayer mode
  
This shows the snake game running in multiplayer mode and changing between 3 different graphics library on runtime.

<img src="gif/multiplayer_mode.gif" />

### Local Multiplayer mode
  
This shows one snake game running as a host and the second connecting to the host on a local IP. 

<img src="gif/local_lan_multiplayer.gif" />

## AUTHOR
Chazni - logic  
Marco - graphics
