/*
 * str1.h
 *
 *  Created on: 2018年9月16日
 *      Author: caryliao
 */

#pragma once

struct polar
{
  double distance;
  double angle;
};

struct rect
{
  double x;
  double y;
};

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);
void testPolar();

