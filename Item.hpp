#ifndef ITEM_HPP
#define ITEM_HPP

#include <unordered_map>
#include "Image.hpp"

class Item {
private:
	std::string name;
	std::string img;
	int index;
	int NewIndex();
public:
	explicit Item(std::string name, std::string img);
	Item(const Item&) = default;
	Item& operator=(const Item&) = default;
	bool operator<(const Item& rhs);
	std::string GetName() const;
	std::string GetImage() const;
};
#endif

