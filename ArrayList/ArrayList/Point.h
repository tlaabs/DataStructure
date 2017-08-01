#ifndef __POINT_H__
#define __POINT_H__

typedef struct _point {
	int xpos;
	int ypos;
}Point;

void SetPointPos(Point* ppos, int xpos, int ypos);
void ShowPointPos(Point* ppos);
int PointComp(Point * ppos1, Point * ppos2);
#endif