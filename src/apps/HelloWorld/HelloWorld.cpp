#include <iostream>

#include "HelloWorldConfig.h"

int main(int argc, char **argv) {
    std::cout << "Hello, world!" << std::endl;
    // report version
    std::cout << argv[0] << " Version " << Version::HelloWorld_VERSION_MAJOR << "."
              << Version::HelloWorld_VERSION_MINOR << std::endl;
    return 0;
}