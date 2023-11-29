#pragma once

class Location;
/**
 * @file Tile.h
 * @author Billy Ndegwah Micah
 *
 * Description: This file contains the declaration of the Tile class which represents
 * a single position tile in a 2D game map.
 *
 * Properties:
 * -----------
 * > _xPos: int - The x position of the tile in the map.
 * > _yPos: int - The y position of the tile in the map.
 * > _loc: Location* - The location of the tile in the map.
 * > _top: Tile* - The tile above this tile.
 * > _bottom: Tile* - The tile below this tile.
 * > _left: Tile* - The tile to the left of this tile.
 * > _right: Tile* - The tile to the right of this tile.
 *
 * Methods:
 * > Getters and Setters for the class attributes
 * > Tile(xPos: int, yPos: int) - Constructor for the Tile class.
 * > ~Tile() - Destructor for the Tile class.
 * > Tile(const T) - Copy constructor for the Tile class.
 * > Tile& operator=(const Tile&) - Assignment operator for the Tile class.
 * > bool operator==(const Tile&) - Equality operator for the Tile class.
 * > bool operator!=(const Tile&) - Inequality operator for the Tile class.
 * > Getters and Setters
 * > GetValue() - Returns the product of the x and y position of the tile in the map.
 * > GetPosition() - Returns the location of the tile in the map.
 * > SetPosition(xPos: int, yPos: int) - Sets the location of the tile in the map.
 * > HasTop() - Returns a boolean value indicating whether the current tile has a tile above it.
 * > HasBottom() - Returns a boolean value indicating whether the current tile has a tile below it.
 * > HasLeft() - Returns a boolean value indicating whether the current tile has a tile to the left of it.
 * > HasRight() - Returns a boolean value indicating whether the current tile has a tile to the right of it.
 */
class Tile
{
public:
	typedef Tile* TilePtr;
	TilePtr Sentinel;

protected:
	int _xPos;
	int _yPos;
	Location* _loc;
	Tile* _top;
	Tile* _bottom;
	Tile* _left;
	Tile* _right;

public:
	/**
	 * @brief This is the default constructor of the Tile class.
	*/
	Tile();

	/**
	 * @brief Overloaded constructor for the Tile class.
	 * @param xPos - The x position of the tile in the map (index in the 2d Array of position).
	 * @param yPos - The y position of the tile in the map (index in the 2d Array of position).
	*/
	Tile(int xPos, int yPos);

	/**
	 * @brief The destructor for the Tile class.
	*/
	~Tile();

	/**
	 * @brief Copy constructor for the Tile class.
	 * @param other - reference to the Tile object to copy.
	*/
	Tile(const Tile& other);

	/**
	 * @brief The assignment operator for the Tile class.
	 * @param  other - reference to the Tile object to copy.
	 * @return a Tile object which is a copy of the Tile object passed in.
	*/
	/*Tile& operator=(const Tile& other);*/

	/**
	 * @brief The comparator operator for the Tile class.
	 * @param  other - reference to the Tile object to compare.
	 * @return a boolean value indicating whether the two Tile objects are equal.
	*/
	bool operator==(const Tile& other) const;

	/**
	 * @brief The overloaded comparator operator for the Tile class.
	 * @param other - the Tile object to compare.
	 * @return - a boolean value indicating whether the two Tile objects are equal.
	*/
	// bool operator==(const Tile other) const;

	/**
	 * @brief The negation comparator operator for the Tile class.
	 * @param  other - reference to the Tile object to compare.
	 * @return a boolean value indicating whether the two Tile objects are not equal.
	*/
	bool operator!=(const Tile& other) const;

	//Tile* operator new(std::size_t size);
	//void operator delete(Tile* tile);

	/**
	 * @brief This operator overload allows the Tile object to be used as a Tile pointer.
	*/
	const Tile& operator*();

	/**
	 * @brief Thi function return the product of the x and y position of the tile in the map.
	 * @return an integer value representing the product of the x and y position of the tile in the map.
	*/
	int GetValue() const;

	/**
	 * @brief Location getter for the Tile class, containing the coordinate space the tile occupies.
	 * @return a location object containing the x,y position of the tile in the map.
	*/
	Location* GetPosition() const;

	/**
	 * @brief Setter for the Tile class, containing the coordinate space the tile occupies.
	 * @param xPos - The x position of the tile in the map (index in the 2d Array of position).
	 * @param yPos - The y position of the tile in the map (index in the 2d Array of position).
	*/
	void SetPosition(int xPos, int yPos);

	/**
	 * @brief Setter for the Tile class, containing the coordinate space the tile occupies.
	 * @param loc - pointer to the location object containing the x,y position of the tile in the map.
	*/
	void SetPosition(Location* loc);

	/**
	 * @brief Getter for the Tile that sits above the current tile.
	 * @return a pointer to the Tile object that sits above the current tile.
	*/
	Tile* GetTop() const;

	/**
	 * @brief Setter for the Tile that sits above the current tile.
	 * @param top - the desired Tile object to set as the top tile.
	*/
	void SetTop(Tile* top);

	/**
	 * @brief Getter for the Tile that sits below the current tile.
	 * @return a pointer to the Tile object that sits below the current tile.
	*/
	Tile* GetBottom() const;

	/**
	 * @brief Setter for the Tile that sits below the current tile.
	 * @param bottom - the desired Tile object to set as the bottom tile.
	*/
	void SetBottom(Tile* bottom);

	/**
	 * @brief Getter for the Tile that sits to the left of the current tile.
	 * @return a pointer to the Tile object that sits to the left of the current tile.
	*/
	Tile* GetLeft() const;

	/**
	 * @brief Setter for the Tile that sits to the left of the current tile.
	 * @param left - the desired Tile object to set as the left tile.
	*/
	void SetLeft(Tile* left);

	/**
	 * @brief Getter for the Tile that sits to the right of the current tile.
	 * @return a pointer to the Tile object that sits to the right of the current tile.
	*/
	Tile* GetRight() const;

	/**
	 * @brief Setter for the Tile that sits to the right of the current tile.
	 * @param right - the desired Tile object to set as the right tile.
	*/
	void SetRight(Tile* right);

	/**
	 * @brief Getter for the boolean value indicating whether the current tile has a tile above it.
	 * @return a boolean value indicating whether the current tile has a tile above it.
	*/
	bool HasTop() const;

	/**
	 * @brief Getter for the boolean value indicating whether the current tile has a tile below it.
	 * @return a boolean value indicating whether the current tile has a tile below it.
	*/
	bool HasBottom() const;

	/**
	 * @brief Getter for the boolean value indicating whether the current tile has a tile to the left of it.
	 * @return a boolean value indicating whether the current tile has a tile to the left of it.
	*/
	bool HasLeft() const;

	/**
	 * @brief Getter for the boolean value indicating whether the current tile has a tile to the right of it.
	 * @return a boolean value indicating whether the current tile has a tile to the right of it.
	*/
	bool HasRight() const;

	/**
	 * @brief This method prints the neighbors of the current tile depending on the range passed in. The range
	 * is used to set how many tiles outwards from the current tile to get the neighbors from. If range=1 it prints
	 * the one immediate neighbor in each direction. If range=2 it prints the two immediate neighbors in each direction, etc.
	 * @param range - the range to get the neighbors from.
	*/
	void ShowNeighbors(int range) const;

	/**
	 * @brief Prints the current tile's position in the map. The print indicates using chevrons the direction of the neighbors
	 * if they exist. If the current tile has a neighbor above it, it prints a chevron pointing up, if it has a neighbor below it,
	 * if no neighbor exists in that direction, it prints a dash.
	*/
	void PrintTile() const;
};


/**
 * Location struct
 *
 * @brief The Location struct, containing the coordinate space the tile occupies. These
 * are also the indices of the tile in the 2D array of tiles.
 *
 * Properties:
 * x: int - The x position of the tile in the map (index in the 2d Array of position).
 * y: int - The y position of the tile in the map (index in the 2d Array of position).
*/
class Location
{
public:
	int x;
	int y;
	Location(int xPos, int yPos);
	~Location();
	const Location& operator*();

	/**
	 * @brief Prints the current location in the map. The print indicates using chevrons the direction of the neighbors
	*/
	void PrintLoc() const;
};

extern Tile::TilePtr Sentinel;