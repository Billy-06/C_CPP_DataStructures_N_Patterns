#pragma once
#include "Tile.h"
#include "Iterator2D.h"
#include "Queue.h"
#include "QueueNode.h"

#include <iostream>
#include <cstdlib>
/**
 * @file TileSpace.h
 * @author Billy Ndegwah Micah
 *
 * Description: This file contains the declaration of the TileSpace class which represents a subtree of the tiles
 * used in creating the map in the 2D game space.
 *
 * Properties:
 * > _entryPoint: Tile* - The entry point of the subtree, entry to the 2D map.
 * > _exitOne: Tile* - The first option for an exit point from the 2D map.
 * > _exitTwo: Tile* - The second option for an exit point from the 2D map.
 * > _exitThree: Tile* - The third option for an exit point from the 2D map.
 * > _exitFour: Tile* - The fourth option for an exit point from the 2D map.
 * > _tileBag: Iterator2D* - The iterator for the 2D array of tiles. Used for
 *		searching through the 2D array of tiles.
 * >
 *
 * Methods:
 * > Getters and Setters for the class attributes
 * > TileSpace() - Constructor for the TileSpace class.
 * > TileSpace(grid2D: int**, rows: int, cols: int) - Overloaded constructor for the TileSpace class.
 * > ~TileSpace() - Destructor for the TileSpace class.
 * > TileSpace(const TileSpace&) - Copy constructor for the TileSpace class.
 */
template <typename T>
class TileSpace
{
private:
	Tile* _entryPoint;
	Tile* _exitOne;
	Tile* _exitTwo;
	Tile* _exitThree;
	Iterator2D<Tile*> _tileBag;
	int** _grid2D;
	int _rows;
	int _cols;

public:
	/**
	 * @brief Default constructor for the TileSpace class.
	*/
	TileSpace()
	{
		int** grid2D = new int* [5];


		for (int i = 0; i < 5; i++)
		{
			grid2D[i] = new int[5];
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; i < 5; i++)
			{
				grid2D[i][j] = i;
			}
		}

		_grid2D = grid2D;

		_rows = 5;
		_cols = 5;
		Iterator2D<int>* posNumber = new Iterator2D<int>(grid2D, _rows, _cols);
		Tile** _tileArray = new Tile* [static_cast<int>(posNumber->GetRows()) * posNumber->GetCols()];

		for (int i = 0; i < 5; i++)
		{
			_tileArray[i] = new Tile[5];
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; i < 5; i++)
			{
				Tile* item = new Tile(i,j);
				_tileArray[i][j] = *item;
			}
		}

		_tileBag = Iterator2D<Tile*>(&_tileArray, _rows, _cols);

		while (!_tileBag.ReachedEnd())
		{
			Tile* tile = new Tile(_tileBag.GetCurrentRow(), _tileBag.GetCurrentColumn());
			
			if (tile->GetPosition()->x == 0 && tile->GetPosition()->y == 0)
			{
				_entryPoint = tile;
			}
			else if (tile->GetPosition()->x == 0 && tile->GetPosition()->y == _cols)
			{
				_exitOne = tile;
			}
			else if (tile->GetPosition()->x == _rows && tile->GetPosition()->y == 0)
			{
				_exitTwo = tile;
			}
			else if (tile->GetPosition()->x == _rows && tile->GetPosition()->y == _cols)
			{
				_exitThree = tile;
			}

			++_tileBag;
		}

	}

	/**
	 * @brief Overloaded constructor for the TileSpace class.
	 * @param grid2D - the 2D array of tiles.
	 * @param rows - the number of rows in the 2D array of tiles.
	 * @param cols - the number of columns in the 2D array of tiles.
	*/
	TileSpace(int** grid2D, int rows, int cols)
	{
		_grid2D = grid2D;
		_rows = rows;
		_cols = rows;
		Iterator2D<int>* posNumber = new Iterator2D<int>(grid2D, rows, cols);
		Tile** _tileArray = new Tile * [static_cast<int>(posNumber->GetRows()) * posNumber->GetCols()];

		for (int i = 0; i < 5; i++)
		{
			_tileArray[i] = new Tile[5];
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; i < 5; i++)
			{
				Tile* item = new Tile(i, j);
				_tileArray[i][j] = *item;
			}
		}

		_tileBag = Iterator2D<Tile*>(&_tileArray, rows, cols);
		_tileBag.GetCurrentItem()->PrintTile();

		while (!_tileBag.ReachedEnd())
		{
			Tile* tile = new Tile(_tileBag.GetCurrentRow(), _tileBag.GetCurrentColumn());
			
			if (tile->GetPosition()->x == 0 && tile->GetPosition()->y == 0)
			{
				_entryPoint = tile;
			}
			else if (tile->GetPosition()->x == 0 && tile->GetPosition()->y == _cols)
			{
				_exitOne = tile;
			}
			else if (tile->GetPosition()->x == _rows && tile->GetPosition()->y == 0)
			{
				_exitTwo = tile;
			}
			else if (tile->GetPosition()->x == _rows && tile->GetPosition()->y == _cols)
			{
				_exitThree = tile;
			}

			++_tileBag;
		}

	}

	/**
	 * @brief Default destructor for the TileSpace class.
	*/
	~TileSpace()
	{
		// delete _tileBag;
		delete _entryPoint;
		delete _exitOne;
		delete _exitTwo;
		delete _exitThree;
	}

	/**
	 * @brief Copy constructor for the TileSpace class.
	 * @param other - the TileSpace object to be copied.
	*/
	TileSpace(const TileSpace& other)
	{
		_grid2D = other._grid2D;
		_rows = other._rows;
		_cols = other._cols;
		_tileBag = other._tileBag;
		_entryPoint = other._entryPoint;
		_exitOne = other._exitOne;
		_exitTwo = other._exitTwo;
		_exitThree = other._exitThree;
	}

	/**
	 * @brief This function overloads the assignment operator for the TileSpace class.
	*/
	const TileSpace<T>& operator *()
	{
		return *this;
	}

	/**
	 * @brief Getter for the entry point of the Tile subtree.
	 * @return a pointer to the entry point of the Tile subtree.
	*/
	Tile* GetEntryPoint() const
	{
		return _entryPoint;
	}

	/**
	 * @brief Setter for the entry point of the Tile subtree.
	 * @param entryPoint - the desired entry point of the Tile subtree.
	*/
	void SetEntryPoint(Tile* entryPoint)
	{
		_entryPoint = entryPoint;
	}

	/**
	 * @brief Getter for the first exit point which is a Tile subtree.
	 * @return  a pointer to the first exit point which is a Tile subtree.
	*/
	Tile* GetExitOne() const
	{
		return _exitOne;
	}

	/**
	 * @brief Setter for the first exit point which is a Tile subtree.
	 * @param exitOne - the desired first exit point which is a Tile subtree.
	*/
	void SetExitOne(Tile* exitOne)
	{
		_exitOne = exitOne;
	}

	/**
	 * @brief Getter for the second exit point which is a Tile subtree.
	 * @return a pointer to the second exit point which is a Tile subtree.
	*/
	Tile* GetExitTwo() const
	{
		return _exitTwo;
	}

	/**
	 * @brief Setter for the second exit point which is a Tile subtree.
	 * @param exitTwo - the desired second exit point which is a Tile subtree.
	*/
	void SetExitTwo(Tile* exitTwo)
	{
		_exitTwo = exitTwo;
	}

	/**
	 * @brief Getter for the third exit point which is a Tile subtree.
	 * @return a pointer to the third exit point which is a Tile subtree.
	*/
	Tile* GetExitThree() const
	{
		return _exitThree;
	}

	/**
	 * @brief Setter for the third exit point which is a Tile subtree.
	 * @param exitThree - the desired third exit point which is a Tile subtree.
	*/
	void SetExitThree(Tile* exitThree)
	{
		_exitThree = exitThree;
	}

	/**
	 * @brief Getter for the iterator for the 2D array of tiles.
	 * @return a pointer to the 2D iterator for the 2D array of tiles.
	*/
	Iterator2D<T>* GetTileBag() const
	{
		return _tileBag;
	}

	/**
	 * @brief Setter for the iterator for the 2D array of tiles.
	 * @param tileBag - the desired iterator for the 2D array of tiles.
	*/
	void SetTileBag(Iterator2D<T>* tileBag)
	{
		_tileBag = tileBag;
	}

	/**
	 * @brief This function prints the 2D array of tiles.
	*/
	void PrintTileSpace() const
	{
		std::cout << "TileSpace Map" << std::endl;
		std::cout << std::endl;
		
		std::cout << "==============================================================================" << std::endl;
		std::cout << "=______________________________________________||||_______________________||||" << std::endl;
		std::cout << "=______________________________________________||||_______________________||||" << std::endl;
		std::cout << "=______________________________________________||||_______________________||||" << std::endl;
		std::cout << "=______________________________________________||||_______________________||||" << std::endl;
		std::cout << "=______________________________________________||||_______________________||||" << std::endl;
		std::cout << "=______________________________________________||||_______________________||||" << std::endl;
		std::cout << "=______________________________________________||||_______________________||||" << std::endl;
		std::cout << "=______________________________________________||||_______________________||||" << std::endl;
		std::cout << "=______________________________________________||||_______________________||||" << std::endl;
		std::cout << "=_________________________________________________________________________||||" << std::endl;
		std::cout << "=___________________||||__________________________________________________||||" << std::endl;
		std::cout << "=___________________||||__________________________________________________||||" << std::endl;
		std::cout << "=___________________||||__________________________________________________||||" << std::endl;
		std::cout << "=___________________||||__________________________________________________||||" << std::endl;
		std::cout << "=___________________||||__________________________________________________||||" << std::endl;
		std::cout << "=___________________||||__________________________________________________||||" << std::endl;
		std::cout << "=___________________||||__________________________________________________||||" << std::endl;
		std::cout << "=___________________||||__________________________________________________||||" << std::endl;
		std::cout << "=___________________||||__________________________________________________||||" << std::endl;
		std::cout << "=___________________||||__________________________________________________||||" << std::endl;
		std::cout << "=___________________||||______________________________________________________" << std::endl;
		std::cout << "=___________________||||______________________________________________________" << std::endl;
		std::cout << "====================||||======================================================" << std::endl;
		std::cout << "==============================================================================" << std::endl;
	}


};