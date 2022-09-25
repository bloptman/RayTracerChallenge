#include "pch.h"

TEST(CanvasTests, CreateBlankCanvas)
{
	int w = 10;
	int h = 20;

	Canvas c(w, h);

	for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < h; ++j)
		{
			EXPECT_TRUE(c.PixelAt(i, j) == Color(0, 0, 0));
		}
	}
}

TEST(CanvasTests, WritePixelToCanvas)
{
	Canvas c(10, 20);
	Color r(1, 0, 0);

	c.WritePixel(2, 3, r);

	EXPECT_TRUE(c.PixelAt(2, 3) == r);
}
