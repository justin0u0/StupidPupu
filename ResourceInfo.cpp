#include "ResourceInfo.hpp"

ResourceInfo::ResourceInfo(std::string type, std::string img, int maximum_hp, int universality, std::string item)
	: type(type), img(img), maximum_hp(maximum_hp), universality(universality) , item(item) {
}

