
#include <unordered_map>
#include <iostream>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include <vector>

class A {
public:
    A(int k) :k(k){};
    int k;

    int getK() const {
        return k;
    }
};


void stringSplit(const std::string& str) {
    std::vector<std::string> credentials(2);
    boost::char_separator<char> sep{" "};
    boost::algorithm::split(credentials, str, boost::is_any_of(" "));
    for(std::string k: credentials) {
        std::cout << k << std::endl;
    }

}

int main() {
    A b{1};
    std::cout << b.getK() << std::endl;

}