#include "Canvas.h"
#include <cassert>
#include <sstream>

Canvas::Canvas(const unsigned int w, const unsigned int h): m_w(w), m_h(h)
{
	m_pixelData = new Color*[m_h];
	for (int i = 0; i < m_h; ++i)
	{
		m_pixelData[i] = new Color[m_w];
	}
}

Canvas::~Canvas()
{
	for (int i = 0; i < m_h; ++i)
	{
		delete[] m_pixelData[i];
	}

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
	assert(x >= 0 && x < m_w);
	assert(y >= 0 && y < m_h);

	m_pixelData[y][x] = c;
}

Color Canvas::PixelAt(unsigned x, unsigned y) const
{
	assert(x >= 0 && x < m_w);
	assert(y >= 0 && y < m_h);

	return m_pixelData[y][x];
}