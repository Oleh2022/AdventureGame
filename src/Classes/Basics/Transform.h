#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform
{
private:
    glm::mat4 projection, model;
    glm::vec3 position, size, rotate_axis = glm::vec3(0.0f, 0.0f, 1.0f);
    float rotate_angle = 0.f;
public:
    // Transform()
    glm::mat4 GetTransform();
    void CalculateProjection(const int &screen_width, const int &screen_height);

    void SetPosition(const glm::vec2 &value) { this->position = glm::vec3(value.x, value.y, 0.f); }
    void AddToPosition(const glm::vec2 &value) { this->position += glm::vec3(value.x, value.y, 0.f); }
    glm::vec2 GetPosition() { return this->position; }

    void SetSize(const glm::vec2 &value) { this->size = glm::vec3(value.x, value.y, 1.f); }
    glm::vec2 GetSize() { return this->size; }

    void SetRotateAxis(const glm::vec3 &value) { this->rotate_axis = value; }
    glm::vec2 GetRotateAxis() { return this->rotate_axis; }

    void SetRotateAngle(const float &value) { this->rotate_angle = value; }
    float GetRotateAngle() { return this->rotate_angle; }

    void SetProjection(const glm::mat4 &value) { this->projection = value; }
    glm::mat4 GetProjection() { return this->projection; }
};