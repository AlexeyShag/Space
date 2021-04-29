#ifndef _IMAGECONTROLLER_H_
#define _IMAGECONTROLLER_H_

#include <string>

#include <Image.h>

enum ImageType{
    nothing = 0,
    buttonImage1 = 1,
    starImage = 2,
    whiteStarImage = 3,
    spaceship = 4
};

class ImageController {
private:
    ImageController();
    static const size_t cntImages = 5;
    inline static const std::string paths[5] = {
        "../src/img/button.png",
        "../src/img/button.png", 
        "../src/img/star.png",
        "../src/img/white_star.png",
        "../src/img/spaceship.png"
    };
    
public:
    static ImageController* instance(){
        static ImageController inst;
        return &inst;
    }

    bool loadImages();

    Image* buttonImg[cntImages];
};

//Image* ImageController::buttonImg[cntImages] = {nullptr};



#endif