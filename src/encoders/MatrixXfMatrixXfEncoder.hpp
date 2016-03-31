/*!
 * \file MatrixXfMatrixXfEncoder.hpp
 * \brief 
 * \author tkornuta
 * \date Mar 29, 2016
 */

#ifndef SRC_AUTO_ENCODERS_SINGLECHANNELMATRIXBATCHENCODER_H_
#define SRC_AUTO_ENCODERS_SINGLECHANNELMATRIXBATCHENCODER_H_

#include <encoders/MatrixXfSDREncoder.hpp>

namespace mic {
namespace encoders {

/*!
 * \brief Encoder responsible for encoding single channel (float) matrices (e.g. grayscale images) into SDRs.
 * There is no learning (auto-encoding), instead it simply transforms floats from matrix to vector.
 * \author tkornuta
 */
class MatrixXfMatrixXfEncoder : public mic::encoders::MatrixXfSDREncoder<mic::types::MatrixXf> {
public:

	/*!
	 * Default constructor. Sets the encoding parameters.
	 * @param sdr_length_ SDR length.
	 * @param matrix_width_ Width of the matrix.
	 * @param matrix_height_ Height of the matrix.
	 */
	MatrixXfMatrixXfEncoder(size_t sdr_length_, size_t matrix_height_, size_t matrix_width_) : MatrixXfSDREncoder(sdr_length_),
		matrix_height(matrix_height_),
		matrix_width(matrix_width_)
	{
//		std::cout<<" Hello MatrixXfMatrixXfEncoder\n";
	};

	/// Default destructor - empty.
	~MatrixXfMatrixXfEncoder() { }

	/*!
	 * @brief Method responsible for encoding of input data sample into SDR (a 1D matrix - vector of floats).
	 * @param[in] sample_ Shared pointer to a matrix.
	 * @return Shared pointer to SDR - here in the form of 1D matrix (cols,1) of floats. Memory to this variable must be assigned earlier.
	 */
	virtual std::shared_ptr<mic::types::MatrixXf> encodeSample(const std::shared_ptr<mic::types::MatrixXf>& sample_);

	/*!
	 * Method responsible for decoding of SDR into data.
	 * @param[in] sdr_ Shared pointer to SDR (1D matrix).
	 * @return Shared pointer to a 2D matrix.
	 */
	virtual std::shared_ptr<mic::types::MatrixXf> decodeSample(const std::shared_ptr<mic::types::MatrixXf>& sdr_);

protected:
	/// Height of the matrix - number of rows.
	size_t matrix_height;

	/// Width of the matrix - number of columns.
	size_t matrix_width;

};



} /* namespace encoders */
} /* namespace mic */

#endif /* SRC_AUTO_ENCODERS_SINGLECHANNELMATRIXBATCHENCODER_H_ */
