#pragma once

#include "core.hpp"
#include "renderer.hpp"

using NoStack = Tags::NoStack;
using Stack = Tags::Stack;
using Event = Tags::Event;
using Effect = Tags::Effect;

enum class Movements
{
    NONE = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

enum class Actions
{
    NONE = 0,
    SHOOT,
    QUIT,
};

struct PlayerComponent
{
};

struct AIComponent
{
};

struct LeftAlienComponent : Stack
{
};

struct RightAlienComponent : Stack
{
};

struct HiveComponent
{
    Bounds bounds{};
};

struct HiveAIComponent
{
    EntityId hiveId;

    HiveAIComponent(EntityId _hiveId) : hiveId(_hiveId)
    {
    }
};

struct PlayerInputEvent : Event
{
    Movements movement = Movements::NONE;
    Actions action = Actions::NONE;

    PlayerInputEvent(Movements _movement, Actions _action) : movement(_movement), action(_action)
    {
    }
    PlayerInputEvent(Movements _movement) : movement(_movement)
    {
    }
    PlayerInputEvent(Actions _action) : action(_action)
    {
    }
};

struct AIInputEvent : Event
{
    Movements movement = Movements::NONE;
    Actions action = Actions::NONE;

    AIInputEvent(Movements _movement, Actions _action) : movement(_movement), action(_action)
    {
    }
    AIInputEvent(Movements _movement) : movement(_movement)
    {
    }
    AIInputEvent(Actions _action) : action(_action)
    {
    }
};

struct AIMovementEffect : Effect
{
};

struct HiveMovementEffect : Effect
{
    float moveInterval{0.5f};
    Movements movement;
    Movements nextMove;

    HiveMovementEffect(Movements _movement) : movement(_movement), Effect(0.5f)
    {
    }
};

struct MovementEffect : Effect
{
    Vector2 trajectory;

    MovementEffect(Vector2 _trajectory) : trajectory(_trajectory)
    {
    }
};

struct MovementComponent
{
    Vector2 speeds;

    MovementComponent()
    {
    }
    MovementComponent(Vector2 _speeds) : speeds(_speeds)
    {
    }
};

struct MovementEvent : Event
{
    Vector2 coords;

    MovementEvent()
    {
    }
    MovementEvent(Vector2 _coords) : coords(_coords)
    {
    }
};

struct PositionComponent
{
    Bounds bounds;

    PositionComponent(Bounds _bounds) : bounds(_bounds)
    {
    }
};

struct PositionEvent : Event
{
    Vector2 coords;

    PositionEvent(Vector2 _coords) : coords(_coords)
    {
    }
};

struct CollisionCheckEvent : Event, NoStack
{
    Bounds bounds;

    CollisionCheckEvent(Bounds _bounds) : bounds(_bounds)
    {
    }
};

struct DeathEvent : Event
{
    EntityId dealerId;

    DeathEvent(EntityId _dealerId) : dealerId(_dealerId)
    {
    }
};

struct DeathComponent
{
};

struct DamageComponent
{
    float amount;

    DamageComponent(float _amount) : amount(_amount)
    {
    }
};

struct AttackComponent
{
    Movements direction;

    AttackComponent(Movements _direction) : direction(_direction)
    {
    }
};

struct AttackEvent : Event
{
};

struct AttackEffect : Effect
{
    EntityId attackId;

    AttackEffect(EntityId _attackId) : attackId(_attackId)
    {
    }
};

struct GameComponent
{
    Bounds bounds;
    bool isGameOver{};
    int currentStage{1};

    GameComponent(Bounds _bounds) : bounds(_bounds)
    {
    }
};

struct GameMetaComponent
{
    Vector2 screen;
    float deltaTime{};

    GameMetaComponent(Vector2 _screen) : screen(_screen)
    {
    }
};

enum class GameEvents
{
    NONE = 0,
    NEXT_STAGE,
    GAME_OVER,
    QUIT,
};

struct GameEvent : Event
{
    GameEvents event;
    GameEvent(GameEvents _event) : event(_event)
    {
    }
};

struct SpriteComponent
{
    Renderer::RGBA rgba;

    SpriteComponent(Renderer::RGBA _rgba) : rgba(_rgba)
    {
    }
};

struct ProjectileComponent
{
    Movements movement;

    ProjectileComponent(Movements _movement) : movement(_movement)
    {
    }
};

struct PointsComponent
{
    int points;
    int multiplier{1};

    PointsComponent(int _points) : points(_points)
    {
    }
    PointsComponent(int _points, int _multiplier) : points(_points), multiplier(_multiplier)
    {
    }
};
