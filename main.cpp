#include <iostream>
#include "Menu.h"

int main() {
    try {
        /// @brief Logical error on i/o operation
        ///        Fail() = true
        /// @param except, set to failbit, the error
        std::cin.exceptions(std::istream::failbit);

        main_menu();
    } catch (const std::exception &) {
        //unknownInput();
    }///#catch
}
