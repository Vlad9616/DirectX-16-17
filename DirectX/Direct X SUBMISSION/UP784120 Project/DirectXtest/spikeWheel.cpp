/*
Description: cpp file of spikeWheel.h
Last Modification Data: 20/03/2017
Status:Working
To Do:-
*/
#include "spikeWheel.h"
//SAME AS D4 BUT USING yAxis
void spikeWheel::verticalAtoB(float startPositon, float endPosition)
{
	{
		if (get_yAxis() == startPositon - 0.1f || end == false)
		{
			set_yAxis(get_yAxis() - 0.001f);
			if (get_yAxis() < startPositon)
			{
				end = true;
				start = false;
			}
		}

		if (get_yAxis() == endPosition-1.0f || start == false)
		{
			set_yAxis(get_yAxis() + 0.001f);
			if (get_yAxis() > endPosition)
			{
				end = false;
				start = true;
			}
		}
	}
}