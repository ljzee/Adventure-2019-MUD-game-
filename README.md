# Babka group CMPT373 Project Yohoo

## Dependencies

This project requires:

1. C++17 or newer
2. Boost >= 1.66
3. CMake >= 3.12
4. NCurses (only tested with 6.1)

## Building with CMake

> git init

> git clone --single-branch --branch branchname https://csil-git1.cs.surrey.sfu.ca/373-19-1-babka/adventure2019

> mkdir build

> cd build

> cmake ../adventure2019

> make

> bin/mudserver 4000 ../web-socket-networking/webchat.html

URL:: http://localhost:4000/index.html

for multiple terminals:
> bin/chatclient localhost 4000
