#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

void onKeyPressedSource(const sf::Event::KeyPressed&, sf::RenderWindow&, sf::Shape*&, double&);

using namespace std::chrono;
using namespace std::this_thread;
const float GAME_TIME_INTERVAL = 16; // ms

int main()
{
    // create the window
    
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");
    sf::Shape* activeEntity = nullptr;
    double y_velocity = 0.0;
    double gravity_force = 0.0;
    int key_press_cntr = 50;

    // run the program as long as the window is open
    float circle_radius = 50.f;
	float x_orig = 0.0f;
    float y_orig = 0.0f;
    float x = x_orig;
    float y = y_orig + (circle_radius);
    float x_render = x;
    float y_render = y;


    // PHYSICS START

    const auto velocity = [&activeEntity](double time, double& y_velocity, float& y_pos)
        {
            float y_i = y_pos;
            y_pos = y_i + (y_velocity * time);

        };
    const auto isColliding = [&activeEntity](float& y_pos)
        {
            if (y_pos >= 600)
            {
                y_pos = 600;
                return true;
            }
            return false;
        };

    const auto gravity = [&activeEntity](double time, double& y_velocity)
        {

            float x = activeEntity->getPosition().x;;
            //std::cout << "time: " << time << "\n";

            double velocity_f = y_velocity + ((9.81 * 30) * time);
            y_velocity = velocity_f;
        };

    // PHYSICS END

    // GRAPHICS INTERFACE START 

    const auto onClose = [&window](const sf::Event::Closed&)
        {
            window.close();
        };

    const auto onKeyPressed = [&window, &activeEntity, &y_velocity](const sf::Event::KeyPressed& keyPressed)
        {
            onKeyPressedSource(keyPressed, window, activeEntity, y_velocity);
        };

    const auto onResize = [&window](const sf::Event::Resized& resized)
        {
            std::cout << "new width: " << resized.size.x << std::endl;
            std::cout << "new height: " << resized.size.y << std::endl;
        };

    const auto onFocusLost = [&window](const sf::Event::FocusLost&)
        {
            std::cout << "myGamePause\n";
        };
    const auto onFocusGained = [&window](const sf::Event::FocusGained&)
        {
            std::cout << "myGameResume\n";
        }; 

    // GRAPHICS INTERFACE START
    
    // RENDERING AND GAME LOOP
    const auto setPose = [&activeEntity](float& x_pos, float& y_pos, float& x_render_pos, float& y_render_pos)
        {
            x_render_pos = x_pos;
            y_render_pos = y_pos;
            activeEntity->setPosition({ x_render_pos, y_render_pos });
        };
    const auto setPoseProjected = [&activeEntity](double percent, float& x_pos, float& y_pos, float& x_render_pos, float& y_render_pos)
        {
            float new_x_pose = x_render_pos + percent * (x_pos - x_render_pos);
            float new_y_pose = y_render_pos + percent * (y_pos - y_render_pos);
            x_render_pos = new_x_pose;
            y_render_pos = new_y_pose;
            activeEntity->setPosition({ x_render_pos, y_render_pos });
        };


    sf::CircleShape shape(circle_radius);
    shape.setPosition({x, y});
    activeEntity = &shape;

    auto previous = high_resolution_clock::now();
    double lag = 0.0;
       
	bool colliding_check = false;
    int frame_count = 0;
    std::cout << "current: " << high_resolution_clock::now().time_since_epoch().count() << "\n";
    while (window.isOpen())
    {
        auto current = high_resolution_clock::now();
        double elapsed = double(duration_cast<microseconds>(current - previous).count()) / 1000;
        previous = current;
        lag += elapsed;
        //std::cout << "lag: " << lag << "\n";
        
        window.handleEvents(onClose, onKeyPressed, onResize, onFocusLost, onFocusGained);

        // clear the window with black color
        window.clear(sf::Color::Black);
        int temp = 0;
        while (lag >= GAME_TIME_INTERVAL)
        {
            window.handleEvents(onClose, onKeyPressed, onResize, onFocusLost, onFocusGained);
            gravity(GAME_TIME_INTERVAL / 1000, y_velocity);
			std::cout << "y_velocity: " << y_velocity << "\n";
            lag -= GAME_TIME_INTERVAL;
            velocity(GAME_TIME_INTERVAL / 1000, y_velocity, y);
            colliding_check = isColliding(y);
        }


        shape.setFillColor(sf::Color(100, 250, 50));
        if (colliding_check) {
            std::cout << "current: " << high_resolution_clock::now().time_since_epoch().count() << "\n";
            std::cout << "In  colliding check area\n";
            sleep_for(seconds(3));
			y = 0.0f;
            y_velocity = 0.0;
            previous = high_resolution_clock::now();
            setPose(x, y, x_render, y_render);
			lag = 0.0;
            colliding_check = false;
        }
        else {
            setPoseProjected(lag / GAME_TIME_INTERVAL, x, y, x_render, y_render);
        }
        window.draw(shape);
        
        // end the current frame
        window.display();
        /*if (frame_count == 0) {
            sleep_for(seconds(3));
            lag = 0.0;
        }
        frame_count++;*/

    }
}