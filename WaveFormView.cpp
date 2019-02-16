#include "WaveFormView.h"

namespace VSTGUI {

CWaveFormView::CWaveFormView(const VSTGUI::CRect& input_size)
: CView(input_size)
{
	size = input_size;
}

void CWaveFormView::setCoordinates(float input_x1, float input_y1, float input_x2, float input_y2, float h1x, float h1y, float h2x, float h2y, float d1, float d2)
{
	// pendulum coordinates to display from physical model
	x1 = input_x1;
	y1 = input_y1;
	x2 = input_x2;
	y2 = input_y2;

	// harmonic coordinates calculated with distance slider
	hx1 = h1x;
	hy1 = h1y;
	hx2 = h2x;
	hy2 = h2y;

	// distance from x2,y2 to harmonics 1 and 2
	distance1 = d1;
	distance2 = d2;
}

void CWaveFormView::draw(CDrawContext* pContext)
{
	// --- bitmap, if one
	if(getDrawBackground())
	{
		getDrawBackground()->draw(pContext, size);
	}
	else
	{		
		// --- setup the backround rectangle
		pContext->setLineWidth(5);
		pContext->setFillColor(CColor(200, 200, 200, 255)); // light grey
		pContext->setFrameColor(CColor(0, 0, 0, 255)); // black
		
		// --- draw the rect filled (with grey) and stroked (line around rectangle)
		pContext->drawRect(size, kDrawFilledAndStroked);

		// --- this will be the line color when drawing lines
		//     alpha value is 200, so color is semi-transparent
		pContext->setFrameColor(CColor(0, 0, 255, 200)); 

		float width = size.right - size.left;
		float originX = width / 2;
		float originY = 300;

		// pendulum points
		const CPoint p1(originX, originY);
		const CPoint p2(x1 + originX, y1 + originY);
		const CPoint p3(x2 + originX, y2 + originY);

		// harmonic circles width corresponding to distance to pendulum p3
		float gainRadius = 2.67;
		float harmonic1diameter = distance1 * gainRadius;
		float harmonic2diameter = distance2 * gainRadius;
		float harmonic1radius = harmonic1diameter / 2.00;
		float harmonic2radius = harmonic2diameter / 2.00;
		const CRect harmonicBubbleRectangle1(hx1 + originX - harmonic1radius, hy1 + originY, hx1 + originX + harmonic1radius, hy1 + originY + harmonic1diameter);
		const CRect harmonicBubbleRectangle2(hx2 + originX - harmonic2radius, hy2 + originY, hx2 + originX + harmonic2radius, hy2 + originY + harmonic2diameter);

		// --- draw lines
		pContext->drawLine(p1, p2);
		pContext->drawLine(p2, p3);
		// --- draw harmonics
		pContext->drawEllipse(harmonicBubbleRectangle1);
		pContext->drawEllipse(harmonicBubbleRectangle2);
	}
	setDirty (false);
}

}