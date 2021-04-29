#include "ImageController.h"
#include <iostream>

ImageController::ImageController() {
	//loadImages();
}


bool ImageController::loadImages() {

	for(size_t i = 0; i < cntImages; ++i){
		ImageController::instance()->buttonImg[i] = new Image();
		ImageController::instance()->buttonImg[i]->loadFromFile(paths[i]);
	}
	return true;
}