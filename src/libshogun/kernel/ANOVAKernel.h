/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2011 Andrew Tereskin
 * Copyright (C) 2011 Berlin Institute of Technology and Max-Planck-Society
 */

#include "lib/config.h"

#ifndef ANOVAKERNEL_H_
#define ANOVAKERNEL_H_

#include "lib/common.h"
#include "kernel/DotKernel.h"
#include "features/Features.h"
#include "features/SimpleFeatures.h"

namespace shogun
{

class CDistance;

/** @brief ANOVA kernel
 *
 * Formally described as
 *
 * \f[
 * 		K_d(x,z) = \sum_{1\le i_1<i_2<\dots<i_d\le n} \prod_{j=1}^d x_{i_j} z_{i_j}
 * \f]
 * with d(cardinality)=1 by default
 * this function is computed recusively
 */

class CANOVAKernel: public CDotKernel
{
public:
	/** default constructor */
	CANOVAKernel();

	/** constructor
	 * @param cache size of cache
	 * @param d kernel parameter cardinality
	 */
	CANOVAKernel(int32_t cache, int32_t d);

	/** constructor
	 * @param l features left-side
	 * @param r features right-side
	 * @param d kernel parameter cardinality
	 */
	CANOVAKernel(
		CSimpleFeatures<float64_t>* l, CSimpleFeatures<float64_t>* r, int32_t d, int32_t cache);

	/** initialize kernel with features
	 * @param l features left-side
	 * @param r features right-side
	 * @return true if successful
	 */
	virtual bool init(CFeatures* l, CFeatures* r);

	/**
	 * @return kernel type
	 */
	inline virtual EKernelType get_kernel_type() { return K_ANOVA; }

	/**
	 * @return type of features
	 */
	inline virtual EFeatureType get_feature_type() { return F_DREAL; }

	/**
	 * @return class of features
	 */
	inline virtual EFeatureClass get_feature_class() { return C_SIMPLE; }

	/**
	 * @return name of kernel
	 */
	inline virtual const char* get_name() const { return "ANOVAKernel"; }

	virtual ~CANOVAKernel();

	/** getter for degree parameter
	 *  @return kernel parameter cardinality
	 */
	inline int32_t get_cardinality() { return this->cardinality; }
	
	/** setter for degree parameter
	 *  @param value kernel parameter cardinality
	 */
	inline void set_cardinality(int32_t value) { this->cardinality = value; }
protected:

	/**
	 * compute kernel for specific feature vectors
	 * corresponding to [idx_a] of left-side and [idx_b] of right-side
	 * @param idx_a left-side index
	 * @param idx_b right-side index
	 * @return kernel value
	 */
	virtual float64_t compute(int32_t idx_a, int32_t idx_b);

	void init();

	float64_t compute_recursive1(float64_t* avec, float64_t* bvec, int32_t len, int32_t d);
	float64_t compute_recursive2(float64_t* avec, float64_t* bvec, int32_t len, int32_t d);
public:
	float64_t compute_rec1(int32_t idx_a, int32_t idx_b);
	float64_t compute_rec2(int32_t idx_a, int32_t idx_b);
	
protected:
	/// degree parameter of kernel
	int32_t cardinality;
	
	/// array for compute_recursive1
	float64_t** DP;
	
	/// arrays for compute_recursive2
	float64_t* KD;
	float64_t* KS;
	float64_t* vec_pow;
};
}

#endif /* ANOVAKERNEL_H_ */
