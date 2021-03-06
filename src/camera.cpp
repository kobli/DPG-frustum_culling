#include "camera.hpp"
#include "utils.hpp"
#include "libs.hpp"

const float CAM_NEAR = 10.0f;
const float CAM_FAR = 10000000.0f;

Camera::Camera():
	_lookDir{glm::vec3(1,0,0)},
	_up{glm::vec3(0,1,0)}, 
	_fov{glm::radians(60.0f)}
{
	_proj = glm::perspective(_fov, 1.0f, CAM_NEAR, CAM_FAR);
	updateView();
}

void Camera::setPosition(const glm::vec3& pos) {
	_position = pos;
	updateView();
}

void Camera::setLookDir(const glm::vec3& dir) {
	_lookDir = glm::normalize(dir);
	updateView();
}

void Camera::move(glm::vec3 delta) {
	_position += delta;
	updateView();
}

void Camera::rotateHoriz(float delta) {
	_lookDir = glm::normalize(glm::rotateY(_lookDir, delta));
	updateView();
}

glm::mat4 Camera::getViewProjection() const {
	return _proj*_view;
}

glm::vec3 Camera::getPosition() const {
	return _position;
}

glm::vec3 Camera::getLookDir() const {
	return _lookDir;
}

float Camera::getNear() const {
	return CAM_NEAR;
}

float Camera::getFar() const {
	return CAM_FAR;
}

void Camera::updateView() {
	_view	= glm::lookAt(_position, _position+getLookDir(), _up);
}

void Camera::setUpVector(const glm::vec3& up) {
	_up = up;
	updateView();
}

glm::vec3 Camera::getUpVector() const {
	return _up;
}

void Camera::setFOV(float fov) {
	_fov = fov;
	_proj = glm::perspective(_fov, 1.0f, CAM_NEAR, CAM_FAR);
	updateView();
}
