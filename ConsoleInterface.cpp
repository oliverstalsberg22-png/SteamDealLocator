#include "ConsoleInterface.h"
#include <iostream>

void displayMenu(const std::vector<Deal>& deals) {
	// Menu
	
	int choice{};
	do {
		std::cout << "Steam Discount Finder:" << std::endl;
		std::cout << "1. View All Deals" << std::endl;
		std::cout << "2. View Games at A Above Certain Discount Percentage" << std::endl;
		std::cout << "3. View Games at A Certain Price Point" << std::endl;
		std::cout << "4. View Games with at A Certain Deal Rating (0-9.9)" << std::endl;
		std::cout << "5. View Games with a Certain Steam Rating ('Very Positive', 'Overwhelmingly Positive', 'Mostly Positive', 'Positive' 'Mixed', 'Mostly Negative', 'Very Negative', 'Overwhelmingly Negative')" << std::endl;
		std::cout << "0. Exit" << std::endl;

		std::cin >> choice;

		switch (choice) {
		case 1: {
			for (auto& d : deals) {
				std::cout << d.title << " - " << "rating: " << d.steam_rating << " - " << "original price: " << d.original_price << " - " << "sale price: " << d.sale_price << " - " << "deal rating: " << d.deal_rating << " - " << "discount percentage: %" << d.discount_percent << std::endl;
				std::cout << "\n";
			}
			break;
		}
		case 2: {
			int percentage{};
			std::cout << "Enter Percentage (Whole Number): " << std::endl;
			std::cin >> percentage;
			bool found1 = false;
			for (auto& d : deals) {
				if (d.discount_percent >= percentage) {
					std::cout << d.title << " - " << "rating: " << d.steam_rating << " - " << "original price: " << d.original_price << " - " << "sale price: " << d.sale_price << " - " << "deal rating: " << d.deal_rating << " - " << "discount percentage: %" << d.discount_percent << std::endl;
					std::cout << "\n";
					found1 = true;
				}
			}
			if (!found1) {
				std::cout << "No games found with a discount percentage of " << percentage << "% or higher." << std::endl;
			}
			break;
		}
		case 3: {
			float price{};
			std::cout << "Enter Price Point (Whole Number): " << std::endl;
			std::cin >> price;
			bool found2 = false;
			for (auto& d : deals) {
				if (d.sale_price <= price) {
					std::cout << d.title << " - " << "rating: " << d.steam_rating << " - " << "original price: " << d.original_price << " - " << "sale price: " << d.sale_price << " - " << "deal rating: " << d.deal_rating << " - " << "discount percentage: %" << d.discount_percent << std::endl;
					std::cout << "\n";
					found2 = true;
				}
			}
			if (!found2) {
				std::cout << "No games found with a sale price of $" << price << " or higher." << std::endl;
			}
			break;
		}
		case 4: {
			float deal_rating{};
			std::cout << "Enter Deal Rating (Whole Number 0-9.9): " << std::endl;
			std::cin >> deal_rating;
			bool found2 = false;
			for (auto& d : deals) {
				if (d.deal_rating >= deal_rating) {
					std::cout << d.title << " - " << "rating: " << d.steam_rating << " - " << "original price: " << d.original_price << " - " << "sale price: " << d.sale_price << " - " << "deal rating: " << d.deal_rating << " - " << "discount percentage: %" << d.discount_percent << std::endl;
					std::cout << "\n";
					found2 = true;
				}

			}
			if (!found2) {
				std::cout << "No games found with a deal rating of " << deal_rating << " or higher." << std::endl;
			}
			break;
		}
		case 5: {
			std::string steam_rating{};
			std::cout << "Enter Steam Rating (Very Positive, Overwhelmingly Positive, Mostly Positive, Positive, Mixed, Mostly Negative, Very Negative, Overwhelmingly Negative): " << std::endl;
			std::getline(std::cin, steam_rating);
			bool found3 = false;
			for (auto& d : deals) {
				if (d.steam_rating == steam_rating) {
					std::cout << d.title << " - " << "rating: " << d.steam_rating << " - " << "original price: " << d.original_price << " - " << "sale price: " << d.sale_price << " - " << "deal rating: " << d.deal_rating << " - " << "discount percentage: %" << d.discount_percent << std::endl;
					std::cout << "\n";
					found3 = true;
				}
			}
			if (!found3) {
				std::cout << "No games found with a steam rating of " << steam_rating << "." << std::endl;
			}
			break;
		}
		case 0: {
			std::cout << "Exiting..." << std::endl;
			break;
		}
		}

	} while (choice != 0);
}