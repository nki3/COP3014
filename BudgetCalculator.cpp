//
// Created by NateB on 1/23/2025.
//

#include "BudgetCalculator.h"

#include <iostream>
#include <iomanip>
#include <utility>
#include <format>

void print_table(std::string table_name, std::string column_name, std::pair<std::string, int> rows[], int row_length) {

    const int name_width = 18;
    const int value_width = 7;

    auto print_row = [](std::string name, std::string value) {
    std::cout << std::left << std::setw(name_width) << name
        << std::right << std::setw(value_width) << value << std::endl;
    };

    print_row(table_name, column_name);
    print_row("------------", "-------");
    for (int i = 0; i < row_length-1; i++) {
        print_row(rows[i].first, std::to_string(rows[i].second));
    }
    print_row("------------", "-------");
    print_row(rows[row_length-1].first, std::to_string(rows[row_length-1].second));
}


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
    int profit = total_income - total_cost;
    std::string profit_formatted = (profit < 0) ? std::format("-${}", abs(profit)) : std::format("${}", abs(profit));

    std::pair<std::string, int> costs[] = {
        {"Venue", venue_cost},
        {"Food", food_cost},
        {"Entertainment", entertainment_cost},
        {"Total Cost", total_cost}
    };

    std::pair<std::string, int> income[] = {
        {"Tickets", tickets_sold},
        {"Donation", donations},
        {"Total", total_income}
    };

    std::cout << std::endl;
    print_table("Costs", "Amount", costs, 4);
    std::cout << std::endl;
    print_table("Income", "Amount", income, 3);
    std::cout << std::endl << "Total Raised for Spud4Kids: " << profit_formatted << std::endl;

    return 0;
}