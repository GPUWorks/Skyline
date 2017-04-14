#pragma once
#include "Entity.h"
#include "ProjectileSpawner.h"
#include "Game.h"
#include <AnimationManager.h>

class SpaceshipA : public Entity {
  public:
    SpaceshipA();
    SpaceshipA(int textureId, glm::vec4 uv, float width, float height, glm::vec2 position, float angle);
    ~SpaceshipA();

  protected:
    void draw() override;
    bool update(float deltaTime) override;

    void setIsFiring(bool isFiring) { _isFiring = isFiring; }

    int getType() override { return ET_SPACESHIP_A; }

  private:
    void initAnimations();
    void initThruster();
    void initProjectileSpawner();

    float _fireRate = 8.0f;
    bool _isFiring = false;
    ProjectileSpawner _projectileSpawnerLeft;
    ProjectileSpawner _projectileSpawnerRight;
    Ess2D::AnimationManager* _animationManager;
    Ess2D::AnimationManager* _thrusterAnimationManager;
    Ess2D::AnimationManager* _muzzleLeftAnimationManager;
    Ess2D::AnimationManager* _muzzleRightAnimationManager;

    glm::vec2 _projectileSpawnerLeftPosition;
    glm::vec2 _projectileSpawnerRightPosition;

    float _horizontalScaleFactor = 1.0f;

    float _thrusterHeight = 50.0f;
    float _thrusterWidth = 40.2f;

};

