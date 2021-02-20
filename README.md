### Simple TCP Server

#### Compiling
Note: You need CMake version 3.14 and Boost version 1.75 
* clone this repo
* `cd` into it
* `mkdir build && cd bulid`
* `cmake ..`
* `make`

At this point you should have a `client` and `server` executable in the root of the repo.

#### Usage
* Run on instance of the `server` and as many `client`s as you like
* On the `client` side you can type commands such as `REGISTER Bob` etc
