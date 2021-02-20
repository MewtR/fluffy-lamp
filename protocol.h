#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>
#include "user.h"


std::string handle_request(std::string, std::map<boost::uuids::uuid, User>&);
std::string register_user(std::string, std::map<boost::uuids::uuid, User>&);
std::string list(std::map<boost::uuids::uuid, User>&);

#endif /* PROTOCOL_H */
