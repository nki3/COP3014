//
// Created by NateB on 1/24/2025.
//

#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

const double coffee_price = 2;
const double tea_price = 1.5;
const double cake_price = 3;
const double muffin_price = 2.5;

int coffee_amt = 0, tea_amt = 0, cake_amt = 0, muffin_amt = 0;

// Table for the items and prices
std::pair<std::string, double> items[] = {
    {"Coffee", coffee_price},
    {"Tea", tea_price},
    {"Cake", cake_price},
    {"Muffin", muffin_price}
};

// Function to accept only values that match a given array of integers and ask again in the case of anything else
int acceptable_int(const std::string& prompt, const std::vector<int>& acceptable) {
    int input;
    while (true) {
        std::cout << std::endl << prompt;
        std::cin >> input;

        for (const int i : acceptable) {
            if (i == input) {
                return input;
            }
        }
    }
}

// Function to only accept a y or n input and ask again in the case of anything else
bool yes_or_no(const std::string& prompt) {

    std::string input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;

        if (input == "y") {
            return true;
        }
        if (input == "n") {
            return false;
        }
    }
}

/*
 * Function to associate the address of a specific item to a specific number
 * This allows us to reference variables throughout the code through arbitrary numbers,
 * which is arguably less clean and can be confusing, but very useful because
 * the task is to have the user input an *integer* and interpret it as a specific item.
 * https://learn.microsoft.com/en-us/cpp/cpp/pointers-cpp?view=msvc-170
 */
int* get_item_pointer(const int item) {
    switch (item) {
        case 1: return &coffee_amt;
        case 2: return &tea_amt;
        case 3: return &cake_amt;
        case 4: return &muffin_amt;
        default: return nullptr;
    }
}

void display_menu() {
    const int name_width = 13;
    const int price_width = 4;

    // Define lambda function (synonymous with an anonymous functor) for outputting a single formatting row with two columns
    auto display_menu_item = [](const int index, const std::string& name, const double& price) {
        std::string left_column = std::to_string(index) + ". " + name;
        std::cout << std::left << std::setw(name_width) << left_column
            << std::right << "- $ " << std::setw(price_width) << std::setprecision (2) << std::fixed << price << std::endl;
    };

    std::cout << "Menu:" << std::endl;

    // Loop through the items table and display it for the user
    for (int i = 0; i < 4; i++) {
        display_menu_item(i+1, items[i].first, items[i].second);
    }

    int item = acceptable_int("Select an item (1-4): ", std::vector<int>{1,2,3,4});
    int quantity = 0;
    while (quantity < 1) {
        std::cout << "Enter quantity: ";
        std::cin >> quantity;
    }

    // Add the quantity to whichever variable is associated with the item number the user selected
    *get_item_pointer(item) += quantity;
}

void display_order_summary() {
    const int column_width = 10;

    // Table header
    std::cout << std::left << std::setw(column_width) << "Item"
    << std::setw(column_width) << "Quantity"
    << std::setw(column_width) << "Price" << std::endl;
    std::cout << "------------------------------" << std::endl;

    // Loop through items and display their corresponding totals
    for (int i = 0; i < 4; i++) {
        std::string left_column = items[i].first;
        int item_amt = *get_item_pointer(i+1);
        std::cout
            << std::left << std::setw(column_width) << items[i].first
            << std::left << std::setw(column_width) << item_amt
            << std::left << "$" << std::setw(column_width-1) << std::setprecision (2) << std::fixed << items[i].second*item_amt << std::endl;
    }
}

int main() {
    std::cout << "Welcome to the SpudBucks!" << std::endl;

    bool finished = false;
    while (!finished) {
        display_menu();
        std::cout << std::endl;
        finished = !yes_or_no("Do you want to add to the order? (y/n): ");
    }

    std::cout << std::endl << "Your Order Summary: " << std::endl;
    display_order_summary();

    double total_price = coffee_amt*coffee_price +
        tea_amt*tea_price +
        cake_amt*cake_price +
        muffin_amt*muffin_price;

    std::cout << std::endl << "Total Price: $" << total_price << std::endl;
    std::cout << "Thank you for visiting!" << std::endl;

    return 0;
}