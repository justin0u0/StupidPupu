#include "Item.hpp"

Item::Item(std::string name, std::string img) : name(name), img(img) {}
int Item::NewIndex() {
	static int index = 0;
	return ++index;
}

