#pragma once
#include <string>
#include <vector>

struct Deal {
	std::string title;
	std::string steam_rating;
	double original_price;
	double sale_price;
	double deal_rating;
	int discount_percent;

	
};
std::vector<Deal> findDeal();
