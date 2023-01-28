#include "Transform.h"

glm::mat4 Transform::GetTransform()
{
    model = glm::translate(glm::mat4(1.f), this->position) *  glm::rotate(glm::mat4(1.f), glm::radians(this->rotate_angle), this->rotate_axis) * glm::scale(glm::mat4(1.f), this->size); 
    return projection * model;
}

void Transform::CalculateProjection(const int &screen_width, const int &screen_height)
{
    this->projection = glm::ortho(0.f, (float)screen_width, (float)screen_height, 0.f, -1.f, 1.f);
}