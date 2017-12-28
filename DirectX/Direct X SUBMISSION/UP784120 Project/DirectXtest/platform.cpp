/*
Description: cpp file of platform.h
Last Modification Data:
Status: Working
To Do: Add frame rate
*/
//D4-Moving platforms
#include "platform.h"
void platform::moveAtoB(float startPositon,float endPosition)
{
	{
		if (get_xAxis() == startPositon-0.1f || end == false)
		{
			set_xAxis(get_xAxis() + 0.001f);
			set_yAxis(-1.25f);


			if (get_xAxis() > 10.0f)
			{
				end = true;
				start = false;
			}
		}

		if (get_xAxis() == 10.0f || start == false)
		{
			set_xAxis(get_xAxis() - 0.001f);
			set_yAxis(-1.25f);

			if (get_xAxis() < 6.0f)
			{
				end = false;
				start = true;
			}
		}
	}
}