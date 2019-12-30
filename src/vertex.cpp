#include "../include/vertex.hpp"

bool floatIsBetween(const float value, const int min, const int max){
	if(value >= min && value <= max)
		return true;
	return false;
}