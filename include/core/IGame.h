//
// Created by Emmanuel Baah on 14.11.2023.
//

/*
 * This is an interface provides access to the basic functionality of the game engine.
 *
 * */
class IGame{
public:
    ~IGame(){};
    /*
     * This method provides access to run the game.
     * The main game loop is exists in this function
     *
     */
    virtual void Run() const = 0;
    /*
     * This method provides access to process the inputs to this game
     * Player inputs are to be handled here.
     */
    virtual void ProcessEvents() const = 0;
    /*
     * This method provides access to update the game state after each frame is rendered
     */
    virtual void Update() const = 0 ;

    /*
     * This method provides access to draw the different scenes of the game on the screen.
     */
    virtual void Render() const = 0;
};