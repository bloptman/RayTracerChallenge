#include "Canvas.h"
#include <cassert>
#include <sstream>
#include <fstream>

Canvas::Canvas(const unsigned int w, const unsigned int h): m_w(w), m_h(h)
{
	// Allocate array for each row of pixel data
	// of the Canvas
	m_pixelData = new Color*[m_h];

	// Allocate array the pixel data of that row
	for (int i = 0; i < m_h; ++i)
	{
		m_pixelData[i] = new Color[m_w];
	}
}

Canvas::~Canvas()
{
	// Deallocate array for the pixel data for each row
	for (int i = 0; i < m_h; ++i)
	{
		delete[] m_pixelData[i];
	}

	// Deallocate the array for the rows of pixel data
	// of the Canvas
	delete[] m_pixelData;
}


unsigned int Canvas::Width() const
{
	return m_w;
}

unsigned int Canvas::Height() const
{
	return m_h;
}

void Canvas::WritePixel(unsigned x, unsigned y, const Color& c)
{
	// Pixel location to write must be within the 
	// bounds of the Canvas

	//assert(x >= 0 && x < m_w);
	//assert(y >= 0 && y < m_h);

	if (x < 0 || x >= m_w) return;
	if (y < 0 || y >= m_h) return;

	m_pixelData[y][x] = c;
}

Color Canvas::PixelAt(unsigned x, unsigned y) const
{
	// Pixel location to retrieve must be within the
	// bound of the Canvas
	assert(x >= 0 && x < m_w);
	assert(y >= 0 && y < m_h);

	return m_pixelData[y][x];
}

std::string Canvas::DebugString() const
{
	std::stringstream stream;

	for (int i = 0; i < m_h; ++i)
	{
		for (int j = 0; j < m_w; ++j)
		{
			stream << PixelAt(j, i) << " ";
		}

		stream << "\n";
	}

	stream << "\n";

	return stream.str();
}

std::ostream& operator<<(std::ostream& os, const Canvas& c)
{
	os << c.DebugString() << std::endl;
	return os;
}

void Export(const Canvas& c, std::string fileName)
{
	std::ofstream file;

	file.open(fileName);
	file << CanvasToPPM(c);
	file.close();
}

std::string CanvasToPPM(const Canvas& c)
{
	std::stringstream stream;

	stream << Construct_PPM_Header(c);
	
	for (int i = 0; i < c.Height(); ++i)
	{
		stream << Construct_PPM_Row(c, i);
	}

	stream << "\n";

	return stream.str();
}

std::string Construct_PPM_Header(const Canvas& c)
{
	// Constructs a string in the proper format
	// of a PPM Header
	std::stringstream stream;

	stream << PPM_MAGIC_NUMBER << "\n";
	stream << c.Width() << " " << c.Height() << "\n";
	stream << MAX_COLOR_VALUE << "\n";

	return stream.str();
}

std::string Construct_PPM_Row(const Canvas& c, unsigned int row)
{
	std::string rowString = "";

	for (int i = 0; i < c.Width(); ++i)
	{
		// Get the Color of a pixel at location (i, row)
		// Then scale the value of that Color to be within [0, MAX_COLOR_VALUE)]
		// Finally, output that Color as a formated std::string
		rowString = rowString + ((c.PixelAt(i, row)).ScaleColorValue(MAX_COLOR_VALUE)).CanvasOutputString();
	}

	// Add a newline at the end of a row
	rowString + "\n";

	return rowString;
}

