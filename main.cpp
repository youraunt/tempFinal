#include <iostream>
#include "Menus.h"
int main() {
    try {
        /// @brief Logical error on i/o operation
        ///        Fail() = true
        /// @param except, set to failbit, the error
        std::cin.exceptions(std::istream::failbit);

        enter_program();
    } catch (const std::exception &) {
        //unknownInput();
    }///#catch
}
