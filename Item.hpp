#ifndef ITEM_HPP
#define ITEM_HPP

#include <unordered_map>
#include "Image.hpp"

class Item {
private:
	int index;
	int NewIndex();
	std::string img;
public:
	std::string name;
	explicit Item(std::string name, std::string img);
	Item(const Item&) = default;
	Item& operator=(const Item&) = default;
	bool operator<(const Item& rhs);
	std::string GetImage() const;
};
#endif

