#ifndef CAT_H
#define CAT_H
#include <iostream>
#include <string>
#include <sstream>

class Cat {
public:
    Cat();
    Cat(const std::string& name, unsigned int lives);

    
    //bool operator==(const Cat& lhs, const Cat& rhs);
    const std::string& get_name() const;
    const unsigned int& get_lives() const;
    void set_name(const std::string& name);
    void set_lives(const unsigned int& lives);
    friend bool operator==(const Cat& lhs, const Cat& rhs);
    friend bool operator<(const Cat& lhs, const Cat& rhs);
    friend std::ostream &operator <<(std::ostream &os, const Cat& cat);

private:
    std::string name;
    unsigned int lives;

};

namespace std {
    template <>
    struct hash <Cat>{
        size_t operator()(const Cat &obj) const {
            std:stringstream stream;

            stream << obj;

            return std::hash<std::string>()(stream.str());
        }
    };
};
#endif 