/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Error
*/

#ifndef ERROR_HPP_
    #define ERROR_HPP_

    #include <iostream>
    #include <ostream>

namespace err {
    class ErrorTypeFile : public std::exception {
        public:
            ErrorTypeFile() {}
            const char *what() const noexcept override {
                return "Error: Not a valid .cfg file";
            }
        private:
            std::string _message;
    };
    class ErrorFileNotExist : public std::exception {
        public:
            ErrorFileNotExist() {}
            const char *what() const noexcept override {
                return "Error: file not exist";
            }
        private:
            std::string _message;
    };
    class ErrorNotEnoughArg : public std::exception {
        public:
            ErrorNotEnoughArg() {}
            const char *what() const noexcept override {
                return "Error: not enough argument";
            }
        private:
            std::string _message;
    };
    class ErrorTooMuchArg : public std::exception {
        public:
            ErrorTooMuchArg() {}
            const char *what() const noexcept override {
                return "Error: Too much arguments";
            }
        private:
            std::string _message;
    };
    class ErrorColorNotInRange : public std::exception {
        public:
            ErrorColorNotInRange() {}
            const char *what() const noexcept override {
                return "Error: RGB color not in range : 0-255";
            }
        private:
            std::string _message;
    };
    class ErrorRadius : public std::exception {
        public:
            ErrorRadius() {}
            const char *what() const noexcept override {
                return "Error: Radius must be superior to 0";
            }
        private:
            std::string _message;
    };
    class ErrorSpecular : public std::exception {
        public:
            ErrorSpecular() {}
            const char *what() const noexcept override {
                return "Error: Specular must be between 0 and 1";
            }
        private:
            std::string _message;
    };
    class ErrorWindowResolution : public std::exception {
        public:
            ErrorWindowResolution() {}
            const char *what() const noexcept override {
                return "Error: Window resolution must be higher to 0 x 0";
            }
        private:
            std::string _message;
    };
    class ErrorFieldOfViewNotInRange : public std::exception {
        public:
            ErrorFieldOfViewNotInRange() {}
            const char *what() const noexcept override {
                return "Error: Field of view must be between 0 and 180";
            }
        private:
            std::string _message;
    };
    class ErrorAmbientNotInRange : public std::exception {
        public:
            ErrorAmbientNotInRange() {}
            const char *what() const noexcept override {
                return "Error: Ambient must be between 0 and 1";
            }
        private:
            std::string _message;
    };
    class ErrorDiffuseNotInRange : public std::exception {
        public:
            ErrorDiffuseNotInRange() {}
            const char *what() const noexcept override {
                return "Error: Diffuse must be between 0 and 1";
            }
        private:
            std::string _message;
    };
    class ErrorIntensityNotPositive : public std::exception {
        public:
            ErrorIntensityNotPositive() {}
            const char *what() const noexcept override {
                return "Error: Intensity must be positive";
            }
        private:
            std::string _message;
    };
    class ErrorSize : public std::exception {
        public:
            ErrorSize() {}
            const char *what() const noexcept override {
                return "Error: Size must be positive";
            }
        private:
            std::string _message;
    };
    class ErrorTransparency : public std::exception {
        public:
            ErrorTransparency() {}
            const char *what() const noexcept override {
                return "Error: Transparency must be between 0 and 1";
            }
        private:
            std::string _message;
    };
    class ErrorThresholdNotInRange : public std::exception {
        public:
            ErrorThresholdNotInRange() {}
            const char *what() const noexcept override {
                return "Error: Threshold must be between 0 and 1";
            }
        private:
            std::string _message;
    };
    class ErrorSigmaNotPositive : public std::exception {
        public:
            ErrorSigmaNotPositive() {}
            const char *what() const noexcept override {
                return "Error: Sigma must be positive";
            }
        private:
            std::string _message;
    };
    class ErroraGaussianBlurRadius : public std::exception {
        public:
            ErroraGaussianBlurRadius() {}
            const char *what() const noexcept override {
                return "Error: Radius must be positive";
            }
        private:
            std::string _message;
    };
     class ErroraGaussianBlurSigma : public std::exception {
        public:
            ErroraGaussianBlurSigma() {}
            const char *what() const noexcept override {
                return "Error: Sigma must be between 0 and 1";
            }
        private:
            std::string _message;
    };
    class ErrorHeight : public std::exception {
        public:
            ErrorHeight() {}
            const char *what() const noexcept override {
                return "Error: Height must be positive";
            }
        private:
            std::string _message;
    };
}

#endif /* !ERROR_HPP_ */
