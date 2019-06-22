#ifndef RESOURCEINFO_HPP
#define RESOURCEINFO_HPP

#include <string>

struct ResourceInfo {
	// type name of resource info
	std::string type;
	// image of this type of resource
	std::string img;
	// maximum health point of this type of resource
	int maximum_hp;
	// the universality of this type of resource
	// the higher the value, the more this type of resource appear
	int universality;
	explicit ResourceInfo(std::string type, std::string img, int maximum_hp, int universality);
	ResourceInfo(const ResourceInfo&) = default;
	ResourceInfo& operator=(const ResourceInfo&) = default;
};
#endif

