#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle //: public Shape
{
public:
//	Rectangle();
	Rectangle(int shapeID, int x1, int y1, int length, int width);
	~Rectangle();
	void draw(); //override;
	void move(); //override;
	int perimeter(int a, int b, int c); //override;
	int area(int base, int height); //override;
	
//	bool operator== (const Shape &rhs);
//	bool operator< (const Shape &rhs);
//	bool Rectangle& operator=(const Shape &rhs);
private:
	int x1;
	int y1;
	int length;
	int width;
	int shapeID;
};

#endif /* RECTANGLE_H */
