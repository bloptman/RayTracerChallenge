#ifndef CANVAS_H
#define CANVAS_H

#include "Color.h"
#include <string>

const std::string PPM_MAGIC_NUMBER = "P3";
const int MAX_COLOR_VALUE = 255;

class Canvas
{
public:
	Canvas(const unsigned int w, const unsigned int h);
	~Canvas();

	unsigned int Width() const;
	unsigned int Height() const;

	void WritePixel(unsigned int x, unsigned y, const Color& c);
	Color PixelAt(unsigned int x, unsigned int y) const;


private:
	unsigned int m_w;
	unsigned int m_h;
	Color** m_pixelData;
};

#endif