#pragma once

#include "Entity.h"
#include <string>
#include <AnimationManager.h>

class Projectile : public Entity {
  public:
    Projectile();
    Projectile(int textureId, glm::vec4 uv, float width, float height, glm::vec2 position);
    Projectile(int textureId, glm::vec4 uv, float width, float height, glm::vec2 position, int source, float _damage);
    ~Projectile();

    bool update(float deltaTime) override;
    int getSource() { return _source; }
    float getDamage() { return _damage; }
    int getType() override { return ET_PROJECTILE; }
    void contact(Entity* e) override;

    void draw();

  protected:
    void createFixtures() override;

  private:
    int _source; //1 -> player, 2 -> enemies;
    float _damage;
    Ess2D::AnimationManager* _animationManager;

};

