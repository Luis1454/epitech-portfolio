/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** recup_camera
*/

#ifndef RECUP_CAMERA_HPP_
    #define RECUP_CAMERA_HPP_

    #include "IParsingSection.hpp"
    #include "StringUtils.hpp"

    typedef struct camera_s {
        int width;
        int height;
        float pos_x;
        float pos_y;
        float pos_z;
        float rot_x;
        float rot_y;
        float rot_z;
        float dir_x;
        float dir_y;
        float dir_z;
        float fov;
    } camera_t;

class recup_camera : public IParsingSection<camera_t> {
    public:
        recup_camera();
        ~recup_camera();
        void set_info(std::vector<std::string> tokens) override;
        camera_t get_info() const override;
    private:
        camera_t extract_camera_info(const std::string& token, camera_t camera);
        camera_t _camera;
        StringUtils _stringutils;
};

#endif /* !RECUP_CAMERA_HPP_ */
