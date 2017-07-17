
#include "MK64F12.h"


int main(void)
{

    /* Write your code here */
   	int Q = 0;
	int D = 127;
	int R = 0;
	int i = 0;

	/* This for loop should be replaced. By default this loop allows a single stepping. */
	for (;;) {


		for (i = 8; i >= 0; i--)
			{
				if (R >= 0)
				{
					R = (R << 2) | (D >> (i + i) & 3);
					R = R -( (Q << 2) | 1);
				}
				else
				{
					R = (R << 2) | (D >> (i + i) & 3);
					R = R + ((Q << 2) | 3);
				}
				if (R >= 0)
					Q = (Q << 1) | 1;
				else
					Q = (Q << 1) | 0;
			}

		if (R<0)
				R = R + ((Q << 1) | 1);
    }
    /* Never leave main */
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
