class Component
{
public:
    Component(Component *parent);

    // Main methods for each component
    void virtual load(int time) = 0;
    void virtual update(int time) = 0;
    void virtual render(int time) = 0;

private:

    // Parent component of this component
    Component *parent_component;
    // Time of this component's creation
    int created_time;
}