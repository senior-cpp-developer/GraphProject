# GraphProject

#About
It is a simple library for handling and analyzing graphs. Definitely not the fastest or memory efficient one, 
but still does the job, and is (in my opinion) easy to understand.
The [main.cpp](https://github.com/senior-cpp-developer/GraphProject/blob/master/main.cpp) provides simple
demo (it is also available as binary in [releases](https://github.com/senior-cpp-developer/GraphProject/releases)).

## Build instructions
Clone repo, open unpacked directory and then:
```shell
cmake -DCMAKE_BUILD_TYPE=Release && make && ./GraphProject
```

## Usage
Simply run the binary. It is also possible to specify adjacency list (JSON) location as a program argument:
```shell
./GraphProject <filename>
```

## Thanks
* The great and easy to use [JSON library](https://github.com/nlohmann/json)