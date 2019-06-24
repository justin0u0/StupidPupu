#include "Item.hpp"

Item::Item(std::string name, std::string img) : name(name), img(img) {
	index = NewIndex();
}
int Item::NewIndex() {
	static int index = 0;
	return ++index;
}
bool Item::operator<(const Item& rhs) {
	return index < rhs.index;
}
std::string Item::GetImage() const {
	return img;
}

