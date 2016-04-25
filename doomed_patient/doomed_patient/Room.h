#pragma once


class LevelCell;

class Room
{
public:
	Room();
	~Room();
	bool corridor;

private:
	std::vector<std::shared_ptr<LevelCell>> containedCells;
};

