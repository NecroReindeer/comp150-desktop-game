#pragma once


class LevelCell;

class Room
{
public:
	Room();
	~Room();

private:
	std::vector<std::shared_ptr<LevelCell>> containedCells;
};

