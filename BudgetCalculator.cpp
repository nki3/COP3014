//
// Created by NateB on 1/23/2025.
//

#include "BudgetCalculator.h"

#include <iostream>
#include <iomanip>

int main() {
    int venue_cost, food_cost, entertainment_cost, tickets_sold, donations;

    const int ticket_price = 10;

    std::cout << "Enter the venue cost: ";
    std::cin >> venue_cost;
    std::cout << "Enter the food cost: ";
    std::cin >> food_cost;
    std::cout << "Enter the entertainment cost: ";
    std::cin >> entertainment_cost;
    std::cout << "Enter the number of tickets sold: ";
    std::cin >> tickets_sold;
    std::cout << "Enter the amount of donations: ";
    std::cin >> donations;

    int total_cost = venue_cost + food_cost +entertainment_cost;
    int total_income = tickets_sold*ticket_price + donations;

    return 0;
}