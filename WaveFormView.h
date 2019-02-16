#pragma once
#include "../vstgui4/vstgui/vstgui.h"

namespace VSTGUI {

class CWaveFormView : public CView
{
public:
	CWaveFormView(const CRect& size);
	CRect size;
	virtual void draw(CDrawContext *pContext);	///< called if the view should draw itself

	//pendulum coordinates
	float x1;
	float x2;
	float y1;
	float y2;
	void setCoordinates(float input_x1, float input_y1, float input_x2, float input_y2, float h1x, float h1y, float h2x, float h2y, float d1, float d2);
	float hx1;
	float hy1;
	float hx2;
	float hy2;
	float distance1;
	float distance2;
};

}
