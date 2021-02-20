#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>
#include "user.h"


std::string handle_request(std::string);

#endif /* PROTOCOL_H */
