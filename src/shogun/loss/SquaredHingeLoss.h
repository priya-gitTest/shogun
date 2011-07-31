/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2011 Shashwat Lal Das
 * Copyright (c) 2011 Berlin Institute of TechnosquaredHingey and Max-Planck-Society.
 */

#ifndef _SQUAREDHINGELOSS_H__
#define _SQUAREDHINGELOSS_H__

#include <shogun/loss/LossFunction.h>

namespace shogun
{

class CSquaredHingeLoss: public CLossFunction
{
public:
	/**
	 * Constructor
	 */
	CSquaredHingeLoss() {};

	/**
	 * Destructor
	 */
	~CSquaredHingeLoss() {};

	/**
	 * Get loss for an example
	 *
	 * @param prediction prediction
	 * @param label label
	 *
	 * @return loss
	 */
	float64_t loss(float64_t prediction, float64_t label);

	/**
	 * Get first derivative of the loss function
	 *
	 * @param prediction prediction
	 * @param label label
	 *
	 * @return first derivative
	 */
	virtual float64_t first_derivative(float64_t prediction, float64_t label);

	/**
	 * Get second derivative of the loss function
	 *
	 * @param prediction prediction
	 * @param label label
	 *
	 * @return second derivative
	 */
	virtual float64_t second_derivative(float64_t prediction, float64_t label);

	virtual const char* get_name() const { return "SquaredHingeLoss"; }
};

}

#endif
