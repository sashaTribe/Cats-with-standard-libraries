#include "cat.h"
#include <iostream>
using namespace std;
// Default constructor
Cat::Cat() {
    name = "Tom";
    lives = 9;
    std::cout << "Default constructor called..." << std::endl;
}

// Constructor 1


// Constructor 2
Cat::Cat(const std::string& name, unsigned int lives) {
    this->name = name;
    this->lives = lives;
    std::cout << "Constructor called with name and lives..."  << std::endl;
}

bool operator==(const Cat& lhs, const Cat& rhs){
    if ((lhs.get_name() == rhs.get_name()) && (lhs.get_lives() == rhs.get_lives())){
        return true;
    } else {
        return false;
    }
}

bool operator<(const Cat& lhs, const Cat& rhs){
    if (lhs.get_name() < rhs.get_name() ){
        return true;
    }else if (lhs.get_name() == rhs.get_name()){
        if (lhs.get_lives() < rhs.get_lives()){
            return true;
        }else {
            return false;
        }
    }else {
        return false;
    }
}


// Getter for name
const std::string& Cat::get_name() const {
    return name;
}

// Getter for lives
const unsigned int& Cat::get_lives() const {
    return lives;
}
std::ostream &operator<<(std::ostream &os, const Cat& cat){
    os << cat.get_name() << " has " << cat.get_lives() << " lives...";
    return os;
}
// Setter for name
void Cat::set_name(const std::string& name) {
    this->name = name;
    std::cout << "set_name called..." << std::endl;
}

// Setter for lives
void Cat::set_lives(const unsigned int& lives) {
    std::cout << "set_lives called..." << std::endl;
    if (lives >= this->lives) {
        return;
    }
    this->lives = lives;
    if (lives == 0 && name != "The Cat formerly known as " + name) {
        std::string former_name = "The Cat formerly known as " + name;
        set_name(former_name);
    }
}
// struct hash<Cat>{
//     size_t operator()(const Cat &obj) const{
//         size_t name_hash = hash<std::string>{}(obj.get_name());
//         size_t lives_hash = hash<unsigned int>{}(obj.get_lives());
//         unsigned int unsigned_hash = static_cast<unsigned int>(name_hash ^ (lives_hash << 1));
//         return unsigned_hash;

//     }
// }


/* namespace std { 
    template <>
    struct hash <Cat> {
        size_t operator()(const Cat &obj) const{
            size_t name_hash = hash<std::string>{}(obj.get_name());
            size_t lives_hash = hash<unsigned int>{}(obj.get_lives());
            unsigned int unsigned_hash = static_cast<unsigned int>(name_hash ^ (lives_hash << 1));
            return unsigned_hash;
        }
    };
} */
