/*
Program Name: BoxVolumes_IntoToClasses.cpp
Author: Eisha Aqeel
Date: March 17, 2022
Description: Created a class called Box and gave it attributes, and calculated the boxes volumes. Also used getters and setters.
*/#include <string>
#include <cstdlib>
#include <iostream>
#include<list>

class Box {
	//attributes
private:
	double Height;
	double Width;
	double Depth;
public:
	//setter(mutator) method for the Height of Box
	void setHeight(double height) {
		if (height < MIN_VALUE) {
			Height = MIN_VALUE;
		}
		else {
			Height = height;
		}
	}
	//getter(accessor) method for the Height of Box
	double getHeight() const {
		return Height;
	}
	//setter(mutator) method for the Width of Box
	void setWidth(double width) {
		if (width < MIN_VALUE) {
			Width = MIN_VALUE;
		}
		else {
			Width = width;
		}
	}
	//getter(accessor) method for the Width of Box
	double getWidth() const {
		return Width;
	}
	//setter(mutator) method for the Depth of Box
	void setDepth(double depth) {
		if (depth < MIN_VALUE) {
			Depth = MIN_VALUE;
		}
		else {
			Depth = depth;
		}
	}
	//getter(accessor) method for the Depth of Box
	double getDepth() const {
		return Depth;
	}
	//declare minimum value allowed
	double MIN_VALUE = 0.01;
	//default construster
	Box() {
		Height = MIN_VALUE;
		Width = MIN_VALUE;
		Depth = MIN_VALUE;
	}
	//parameterized construster
	Box(double height, double width, double depth) {
		setHeight(height);
		setWidth(width);
		setDepth(depth);
	}
	//A method to get the volume of the box.
	double getVolume(double volume) {
		volume = Height * Width * Depth;
		return volume;
	}
};

int main()
{
	Box box1;
	box1.setHeight(1.0);
	box1.setWidth(1.0);
	box1.setDepth(1.0);
	Box box2;
	box2.setHeight(9.9);
	box2.setWidth(8.8);
	box2.setDepth(7.7);
	std::cout << "After Construction: " << std::endl;
	std::cout << "Box 1 has a height of " << box1.getHeight() << ", a width of " << box1.getWidth() << ", and a depth of " << box1.getDepth() <<
		". It's volume is " << box1.getVolume(box1.getHeight() * box1.getWidth() * box1.getDepth()) << std::endl;
	std::cout << "Box 2 has a height of " << box2.getHeight() << ", a width of " << box2.getWidth() << ", and a depth of " << box2.getDepth() <<
		". It's volume is " << box2.getVolume(box2.getHeight() * box2.getWidth() * box2.getDepth()) << std::endl;
	std::cout << "Set/Resize: " << std::endl;
	std::cout << "Enter dimensions of box 1: " << std::endl;
	std::cout << "Height: " << std::endl;
	double height;
	std::cin >> height;
	std::cout << "Width: " << std::endl;
	double width;
	std::cin >> width;
	std::cout << "Depth: " << std::endl;
	double depth;
	std::cin >> depth;

	box1.setHeight(height);
	box1.setWidth(width);
	box1.setDepth(depth);


	std::cout << "Enter dimensions of box 2: " << std::endl;
	std::cout << "Height: " << std::endl;
	double height2;
	std::cin >> height2;
	std::cout << "Width: " << std::endl;
	double width2;
	std::cin >> width2;
	std::cout << "Depth: " << std::endl;
	double depth2;
	std::cin >> depth2;

	box2.setHeight(height2);
	box2.setWidth(width2);
	box2.setDepth(depth2);

	std::cout << "After Set/Resize: " << std::endl;
	std::cout << "Box 1 was reset to have a height of " << box1.getHeight() << ", a width of " << box1.getWidth() << ", and a depth of " << box1.getDepth() <<
		". It's volume is " << box1.getVolume(box1.getHeight() * box1.getWidth() * box1.getDepth()) << std::endl;
	std::cout << "Box 2 was reset to have a height of " << box2.getHeight() << ", a width of " << box2.getWidth() << ", and a depth of " << box2.getDepth() <<
		". It's volume is " << box2.getVolume(box2.getHeight() * box2.getWidth() * box2.getDepth()) << std::endl;
}