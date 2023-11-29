#include "Tile.h"

#include <iostream>

using namespace std;

Tile::TilePtr Sentinel = (class Tile*)malloc(sizeof(class Tile));

Tile::Tile()
{
	Sentinel = (class Tile*)malloc(sizeof(class Tile));


	_xPos = -1;
	_yPos = -1;
	_loc = new Location(-1, -1);
	_top = Sentinel;
	_bottom = Sentinel;
	_left = Sentinel;
	_right = Sentinel;
}

Tile::Tile(int xPos, int yPos)
{
	Sentinel = (class Tile*)malloc(sizeof(class Tile));

	_xPos = xPos;
	_yPos = yPos;
	_loc = new Location(xPos, yPos);
	_top = Sentinel;
	_bottom = Sentinel;
	_left = Sentinel;
	_right = Sentinel;
}

Tile::~Tile()
{
	delete _loc;
	delete _top;
	delete _bottom;
	delete _left;
	delete _right;
}

Tile::Tile(const Tile& other)
{
	Sentinel = other.Sentinel;
	_xPos = other._xPos;
	_yPos = other._yPos;
	_loc = other._loc;
	_top = other._top;
	_bottom = other._bottom;
	_left = other._left;
	_right = other._right;
}

//Tile& Tile::operator=(const Tile& other)
//{
//	_xPos = other._xPos;
//	_yPos = other._yPos;
//	_loc = other._loc;
//	_top = other._top;
//	_bottom = other._bottom;
//	_left = other._left;
//	_right = other._right;
//
//	return *this;
//}

bool Tile::operator==(const Tile& other) const
{
	return (
		_xPos == other._xPos &&
		_yPos == other._yPos &&
		_loc == other._loc &&
		_top == other._top &&
		_bottom == other._bottom &&
		_left == other._left &&
		_right == other._right
	);
}

bool Tile::operator!=(const Tile& other) const
{
	return !(*this == other);
}

//Tile* Tile::operator new(size_t size)
//{
//	return new Tile(-1, -1);
//}
//
//void Tile::operator delete(Tile* tile)
//{
//	delete tile;
//}

const Tile& Tile::operator*()
{
	return *this;
}


int Tile::GetValue() const
{
	return _xPos * _yPos;
}


Location* Tile::GetPosition() const
{
	return _loc;
}

void Tile::SetPosition(Location* loc)
{
	_loc = loc;
}

void Tile::SetPosition(int xPos, int yPos)
{
	_loc = new Location(xPos, yPos);
}

Tile* Tile::GetTop() const
{
	return _top;
}

void Tile::SetTop(Tile* top)
{
	_top = top;
}

Tile* Tile::GetBottom() const
{
	return _bottom;
}

void Tile::SetBottom(Tile* bottom)
{
	_bottom = bottom;
}

Tile* Tile::GetLeft() const
{
	return _left;
}

void Tile::SetLeft(Tile* left)
{
	_left = left;
}

Tile* Tile::GetRight() const
{
	return _right;
}

void Tile::SetRight(Tile* right)
{
	_right = right;
}

bool Tile::HasTop() const
{
	return _top != nullptr || _top != Sentinel;
}


bool Tile::HasBottom() const
{
	return _bottom != nullptr || _bottom != Sentinel;
}

bool Tile::HasLeft() const
{
	return _left != nullptr || _left != Sentinel;
}

bool Tile::HasRight() const
{
	return _right != nullptr || _right != Sentinel;
}


void Tile::ShowNeighbors(int range) const
{
	if (range == 0)
	{
		cout << "Tile at (" << _xPos << ", " << _yPos << ") has no neighbors." <<  endl;
		return;
	}

	cout << "Tile at (" << _xPos << ", " << _yPos << ") has neighbors: " <<  endl;

	if (HasTop())
	{
		cout << "Top: (" << _top->GetPosition()->x << ", " << _top->GetPosition()->y << ")" <<  endl;
	}
	else
	{
		cout << "Top: None" <<  endl;
	}

	if (HasBottom())
	{
		cout << "Bottom: (" << _bottom->GetPosition()->x << ", " << _bottom->GetPosition()->y << ")" <<  endl;
	}
	else
	{
		cout << "Bottom: None" <<  endl;
	}

	if (HasLeft())
	{
		cout << "Left: (" << _left->GetPosition()->x << ", " << _left->GetPosition()->y << ")" <<  endl;
	}
	else
	{
		cout << "Left: None" <<  endl;
	}

	if (HasRight())
	{
		cout << "Right: (" << _right->GetPosition()->x << ", " << _right->GetPosition()->y << ")" <<  endl;
	}
	else
	{
		cout << "Right: None" <<  endl;
	}
}

void Tile::PrintTile() const
{
	cout << "============\n";
	cout << "|| Tile at (" << _xPos << ", " << _yPos << ")||\n";
	cout << "============" << endl;
}


Location::Location(int x, int y)
{
	this->x = x;
	this->y = y;
}

Location::~Location() = default;

const Location& Location::operator*()
{
	return *this;
}

void Location::PrintLoc() const
{
	cout << "(" << x << ", " << y << ")___________" << endl;
}

