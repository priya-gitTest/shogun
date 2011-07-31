/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2011 Shashwat Lal Das
 * Copyright (c) 2011 Berlin Institute of Technology and Max-Planck-Society.
 */

#include <shogun/loss/LogLossMargin.h>

using namespace shogun;

float64_t CLogLossMargin::loss(float64_t prediction, float64_t label)
{
	float64_t z = prediction * label;
	if (z >= 1)
		return log(1+exp(1-z));
	return 1-z + log(1+exp(z-1));
}

float64_t CLogLossMargin::first_derivative(float64_t prediction, float64_t label)
{
	float64_t z = prediction * label;
	if (z < 1)
		return -1 / (exp(z-1) + 1);
	float64_t ez = exp(1-z);
	return -ez / (ez + 1);
}

float64_t CLogLossMargin::second_derivative(float64_t prediction, float64_t label)
{
	float64_t z = prediction * label;
	float64_t ez = exp(z-1);

	return ez / (ez + 1)*(ez + 1);
}
