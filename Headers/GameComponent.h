class GameComponent
{
public:
    GameComponent(GameComponent* parent);

private:
    // Parent Component
    GameComponent* parent_component;
};