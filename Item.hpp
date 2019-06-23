#ifndef ITEM_HPP
#define ITEM_HPP

#include <unordered_map>

class Item {
private:
	std::string name;
	std::string img;
public:
	explicit Item(std::string name, std::string img);
};
#endif

