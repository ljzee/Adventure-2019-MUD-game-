# adventure2019

To clone my branch:
git clone git@csil-git1.cs.surrey.sfu.ca:373-19-1-babka/adventure2019.git
git checkout starting_point

To build with cmake:
Create an out-of-source directory at the same level as adventure 2019

cmake ../adventure2019/starting_point/
make
bin/chatserver 4000 ../adventure2019/starting_point/webchat.html

On a web browser:

http://localhost:4000/index.html
