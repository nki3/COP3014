//
// Created by NateB on 3/24/2025.
//

#include <iomanip>
#include <iostream>
#include <cmath>

std::string names[10];
int quantities[10];
double prices[10];

void addItem(int index, std::string name, int quantity, double price) {
    names[index] = name;
    quantities[index] = quantity;
    prices[index] = price;
}

void displayReceipt(std::string names[], int quantities[], double prices[], int itemCount) {

    const int name_width = 21;
    const int quantity_width = 5;
    const int total_width = 14;

    // Define lambda expression (synonymous with an anonymous function) for outputting a single formatting row with two columns
    // https://learn.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170
    auto print_row = [](const std::string& name, const std::string& quantity, const std::string& total_price) {
        std::cout << std::left << std::setw(name_width) << name <<
            std::left << std::setw(quantity_width) << quantity <<
                std::left << std::setw(total_width) << total_price
        << std::endl;
    };

    // Table header
    print_row("Item", "Qty", "Total Price");
    std::cout << std::string(name_width, '-') + std::string(quantity_width, '-') + std::string(total_width, '-');
    std::cout << std::endl;

    // Different items
    for (int i = 0; i < itemCount; i++) {
        // Format the total price
        double total_price = prices[i] * quantities[i];
        std::stringstream price_formatted;
        if (total_price < 0) {
            price_formatted << "-";
        }
        price_formatted << "$" << std::setprecision(2) << std::fixed << fabs(total_price);

        print_row(names[i], std::to_string(quantities[i]), price_formatted.str());
    }

}


int main() {
    std::cout << "Welcome to SpudMart!" << std::endl << std::endl;

    int items = 0;
    while (items < 10) {
        std::string name;
        int quantity;
        double price;
        std::cout << "Enter item name (or 'exit' to finish): ";
        std::getline(std::cin, name);
        if (name == "exit") {
            break;
        }
        std::cout << "Enter quantity: ";
        std::cin >> quantity;
        std::cin.ignore();
        std::cout << "Enter price per item: ";
        std::cin >> price;
        std::cin.ignore();
        std::cout << std::endl;
        addItem(items, name, quantity, price);
        items++;
    }

    std::cout << std::endl << "Your SpudMart Receipt:" << std::endl << std::endl;

    displayReceipt(names, quantities, prices, items);

    // Calculate grand total
    double grand_total = 0;
    for (int i = 0; i < items; i++) {
        grand_total += quantities[i] * prices[i];
    }

    // Format the grand total
    std::stringstream grand_total_formatted;
    if (grand_total < 0) {
        grand_total_formatted << "-";
    }
    grand_total_formatted << "$" <<std::setprecision(2) << std::fixed << fabs(grand_total);

    std::cout << std::endl << "Grand Total: " << grand_total_formatted.str() << std::endl;

    return 0;
}
