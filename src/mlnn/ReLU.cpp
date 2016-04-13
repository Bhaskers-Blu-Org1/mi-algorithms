/*!
 * \file ReLU.cpp
 * \brief 
 * \author tkornut
 * \date Mar 31, 2016
 */

#include <mlnn/ReLU.hpp>

namespace mic {
namespace mlnn {


ReLU::ReLU(size_t inputs, size_t outputs, size_t batch_size) :
	Layer(inputs, outputs, batch_size, "relu") {

}


void ReLU::forward(bool apply_dropout) {

	// y = rectify(x);

	// Access the data of both matrices.
	float* x = s['x']->data();
	float* y = s['y']->data();

	for (int i = 0; i < s['x']->rows() * s['x']->cols(); i++) {
		y[i] = fmaxf(x[i], 0.0f);
	}//: for

}

void ReLU::backward() {

	// dx.array() = derivative_ReLU(y).array() * dy.array();

	// Access the data of matrices.
	float* gx = g['x']->data();
	float* gy = g['y']->data();
	float* y = s['y']->data();

	for (int i = 0; i < g['x']->rows() * g['x']->cols(); i++) {

		// Calculate the ReLU y derivative.
		float dy = (float)(y[i] > 0);
		// Calculate the gradient.
		gx[i] = dy * gy[i];

	}//: for

}

} /* namespace mlnn */
} /* namespace mic */
