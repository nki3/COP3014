//
// Created by NateB on 3/1/2025.
//

#include <iomanip>
#include <iostream>

// Function for displaying the quality of the harvest
void displayMessage(int count) {
    std::string message = "Harvest Message: ";
    if (count < 100) {
        message += "This year is not a good harvest";
    } else if (count < 500) {
        message += "This year had an average harvest";
    } else {
        message += "This year had a great harvest";
    }
    std::cout << message << std::endl;
}

// Function for displaying the total value of the spuds
double calculateTotalValue(double weight, double pricePerPound) {
    return weight * pricePerPound;
}

int main() {
    int spudTotal;
    double averageWeight;
    double pricePerPound;

    // Gets user input
    std::cout << "Welcome to the SpudCulator!" << std::endl << std::endl;
    std::cout << "Enter the total number of spuds: ";
    std::cin >> spudTotal;
    std::cout << "Enter the average weight of a spud (lbs): ";
    std::cin >> averageWeight;
    std::cout << "Enter the price per pound of spuds ($): ";
    std::cin >> pricePerPound;

    double totalWeight = averageWeight * spudTotal;
    double totalValue = calculateTotalValue(totalWeight, pricePerPound);
    std::cout << "Total weight of the harvest: " << std::setprecision(3) << std::fixed << totalWeight << " lbs" << std::endl;
    std::cout << "Total value of the harvest: $" << std::setprecision(2) << std::fixed << totalValue << std::endl;

    std::cout << std::endl;
    displayMessage(spudTotal);
    return 0;
}