#include "rest.h"

#include <iostream>

Result Rest::perform(Engine&) {
    std::cout << "I rested \n";
    return success();
}
