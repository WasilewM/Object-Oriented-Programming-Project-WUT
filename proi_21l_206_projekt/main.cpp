#include <iostream>
#include "test_simulation.h"
#include "simulation.h"

enum main_menu {
    test_simulation_option,
    simulation_option,
    exit_program
};

int main()
{
    bool if_main_menu_option_correct = false;

    while (!if_main_menu_option_correct) {
        std::cout << "Welcome to the automatic passenger boarding program." << std::endl;
        std::cout << "In order to proceed please choose option from available shown below:" << std::endl;
        std::cout << "0. Test simulation (part of the tests prepared for the project)" << std::endl;
        std::cout << "1. Simulation" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::string user_choice = "";
        std::cin >> user_choice;


        try {
            int numeric_choice = stoi(user_choice);
            
            if (numeric_choice == main_menu::test_simulation_option) {
                test_simulation();
                if_main_menu_option_correct = true;
            }
            else if (numeric_choice == main_menu::simulation_option) {
                std::cout << "Please enter the number of time intervals you want to proceed:" << std::endl;
                std::string time_intervals = "";
                std::cin >> time_intervals;
                int numeric_time = stoi(time_intervals);
                if (numeric_time < 0) {
                    numeric_time = 0;
                }

                std::cout << "Please enter the number of clerks you want to proceed:" << std::endl;
                std::string clerks = "";
                std::cin >> clerks;
                int clerks_number = stoi(clerks);
                if (clerks_number < 0) {
                    clerks_number = 3;
                }
                Data data(numeric_time, clerks_number);
                if_main_menu_option_correct = true;
            }
            else if (numeric_choice == main_menu::exit_program) {
                std::cout << "Thank you for choosing our product. Have a nice day!" << std::endl;
                if_main_menu_option_correct = true;
            }
            else {
                std::cout << "Invalid option. Please try agian next time." << std::endl;
            }

            std::cout << "Program has ended. Have a nice day!" << std::endl;
            std::cout << "-----------------------------------" << std::endl;
            std::cout << "-----------------------------------" << std::endl;
            std::cout << "-----------------------------------" << std::endl;
            std::cout << "-----------------------------------" << std::endl;
            std::cout << "-----------------------------------" << std::endl;
        }
        catch (std::invalid_argument const& e) {
            std::cout << "Wrong input value - input value must be integer" << std::endl;
        }
        catch (std::out_of_range const& e) {
            std::cout << "Value out of range" << std::endl;
        }
    }

    return 0;
}
