#include "ngon_random.h"

#include <random>

static std::random_device rd;
static std::mt19937 gen(rd());

int random_number(int start, int end)
{
	std::uniform_int_distribution<int> dis(start, end);

	return dis(gen);
}