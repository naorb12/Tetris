#ifndef _Point
#define _Point

class Point
{
private:
	int x;
	int y;

public:

	Point();
	Point(int newX, int newY);

	// Getter functions
	int getX() const;
	int getY() const;

	// Setter functions
	void setXAndY(int newX, int newY);
	void setX(int newX);
	void setY(int newY);

	// add functions
	void addToX(int addX);
	void addToY(int addY);
	void addToXAndY(int addX, int addY);
};

#endif
