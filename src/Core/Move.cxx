#include "Move.hxx"

using namespace Hatac;

bool 
Move::operator == ( const Move & other ) const
{
	return this->x == other.x && this->y == other.y;
};

std::array<std::size_t, 2>
Move::as_array () const
{
	return { this->x, this->y };
};

std::pair<std::size_t, std::size_t>
Move::as_pair () const
{
	return { this->x, this->y };
};

