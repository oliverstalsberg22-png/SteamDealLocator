#include "steam_api.h"
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <iostream>
using json = nlohmann::json;

std::vector<Deal> findDeal() {
	cpr::Response r = cpr::Get(cpr::Url{ ("https://www.cheapshark.com/api/1.0/deals?storeID=1&upperPrice=15") });
	// CheapSharkData
	json CSData = json::parse(r.text);
	std::vector<Deal> deals;
	for (auto& game : CSData) {
		Deal d;
		d.title = game["title"].get<std::string>();
		d.original_price = std::stof(game["normalPrice"].get<std::string>());
		d.sale_price = std::stof(game["salePrice"].get<std::string>());
		d.steam_rating = game["steamRatingText"].get<std::string>();
		d.discount_percent = std::stoi(game["savings"].get<std::string>());
		d.deal_rating = std::stof(game["dealRating"].get<std::string>());
		deals.push_back(d);
	}



	return deals;
}