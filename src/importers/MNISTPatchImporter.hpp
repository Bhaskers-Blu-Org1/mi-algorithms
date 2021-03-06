/*!
 * Copyright (C) tkornuta, IBM Corporation 2015-2019
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*!
 * \file MNISTPatchImporter.hpp
 * \brief 
 * \author tkornuta
 * \date Mar 27, 2017
 */

#ifndef SRC_importers_MNISTPATCHIMAGEIMPORTER_HPP_
#define SRC_importers_MNISTPATCHIMAGEIMPORTER_HPP_

#include <importers/Importer.hpp>
#include <types/MNISTTypes.hpp>

namespace mic {
namespace importers {

/*!
 * \brief Importer responsible for importing/loading MNIST images with labels.
 * \author tkornuta
 */
class MNISTPatchImporter : public mic::importers::Importer<mic::types::MatrixXf, unsigned int> {
public:
	/*!
	 * Constructor. Sets MNIST image default properties. Registers properties.
	 * @param node_name_ Name of the node in configuration file.
	 */
	MNISTPatchImporter(std::string node_name_ = "mnist_patch_importer");

	/*!
	 * Virtual destructor. Empty.
	 */
	virtual ~MNISTPatchImporter() { };

	/*!
	 * Method responsible for importing/loading the MNIST dataset.
	 * @return TRUE if data loaded successfully, FALSE otherwise.
	 */
	bool importData();

	/*!
	 * Sets data filename (with path). DEPRICATED (should be used only for testing purposes).
	 * @param data_filename_ Path and filename
	 */
	void setDataFilename(std::string data_filename_) {
		data_filename = data_filename_;
	}

	/*!
	 * Sets labels filename (with path). DEPRICATED (should be used only for testing purposes).
	 * @param labels_filename_ Path and filename
	 */
	void setLabelsFilename(std::string labels_filename_) {
		labels_filename = labels_filename_;
	}

	/*!
	 * Method responsible for initialization of all variables that are property-dependent - here not required, yet empty.
	 */
	virtual void initializePropertyDependentVariables() { };

	/*!
	 * Returns the patch size.
	 */
	size_t getPatchSize() { return patch_size; }

private:
	/*!
	 * Width of MNIST image.
	 */
	size_t image_width;

	/*!
	 * Height of MNIST image.
	 */
	size_t image_height;

	/*!
	 * Property: directory/Name of file containing images (binary datafile).
	 */
	mic::configuration::Property<std::string> data_filename;

	/*!
	 * Property: directory/Name of file containing labels.
	 */
	mic::configuration::Property<std::string> labels_filename;

	/*!
	 * Property: patch size (width & height).
	 */
	mic::configuration::Property<size_t> patch_size;

	/*!
	 * Property: maximum number of samples (limitation, from 1 to 60000). If <=0 then there is no limitation.
	 */
	mic::configuration::Property<int> samples_limit;
};

} /* namespace importers */
} /* namespace mic */


#endif /* SRC_importers_MNISTPATCHIMAGEIMPORTER_HPP_ */
