#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");
    sf::Shape* activeEntity = nullptr;


    const auto onClose = [&window](const sf::Event::Closed&)
        {
            window.close();
        };

    const auto onKeyPressed = [&window, &activeEntity](const sf::Event::KeyPressed& keyPressed)
        {
            std::cout << "I am in onKeyPressed func\n";
            if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
                window.close();
            if (keyPressed.scancode == sf::Keyboard::Scan::W)
            {
                std::cout << "the W key was pressed" << std::endl;
                std::cout << "scancode: " << static_cast<int>(keyPressed.scancode) << std::endl;
                std::cout << "code: " << static_cast<int>(keyPressed.code) << std::endl;
                std::cout << "control: " << keyPressed.control << std::endl;
                std::cout << "alt: " << keyPressed.alt << std::endl;
                std::cout << "shift: " << keyPressed.shift << std::endl;
                std::cout << "system: " << keyPressed.system << std::endl;
                std::cout << "description: " << sf::Keyboard::getDescription(keyPressed.scancode).toAnsiString() << std::endl;
                std::cout << "localize: " << static_cast<int>(sf::Keyboard::localize(keyPressed.scancode)) << std::endl;
                std::cout << "delocalize: " << static_cast<int>(sf::Keyboard::delocalize(keyPressed.code)) << std::endl;
                if (activeEntity != nullptr)
                {
                    float x = activeEntity->getPosition().x;
                    float y = activeEntity->getPosition().y;
                    std::cout << "--------\nThe active entity is moved from position: x:" << x << " ,y: " << y << std::endl;
                    y = y - 50.f;
                    activeEntity->setPosition({ x,y });
                    std::cout << "to position: x:" << x << " ,y: " << y << std::endl << "--------" << std::endl;
                }
            }
            if (keyPressed.scancode == sf::Keyboard::Scan::D)
            {
                std::cout << "the D key was pressed" << std::endl;
                std::cout << "scancode: " << static_cast<int>(keyPressed.scancode) << std::endl;
                std::cout << "code: " << static_cast<int>(keyPressed.code) << std::endl;
                std::cout << "control: " << keyPressed.control << std::endl;
                std::cout << "alt: " << keyPressed.alt << std::endl;
                std::cout << "shift: " << keyPressed.shift << std::endl;
                std::cout << "system: " << keyPressed.system << std::endl;
                std::cout << "description: " << sf::Keyboard::getDescription(keyPressed.scancode).toAnsiString() << std::endl;
                std::cout << "localize: " << static_cast<int>(sf::Keyboard::localize(keyPressed.scancode)) << std::endl;
                std::cout << "delocalize: " << static_cast<int>(sf::Keyboard::delocalize(keyPressed.code)) << std::endl;
                if (activeEntity != nullptr)
                {
                    float x = activeEntity->getPosition().x;
                    float y = activeEntity->getPosition().y;
                    std::cout << "--------\nThe active entity is moved from position: x:" << x << " ,y: " << y << std::endl;
                    x = x + 25;
                    activeEntity->setPosition({ x,y });
                    std::cout << "to position: x:" << x << " ,y: " << y << std::endl << "--------" << std::endl;
                }
            }
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

    /* const auto onTextEntered = [&window](const sf::Event::TextEntered& textEntered)
         {
             if (textEntered.unicode < 128)
             std::cout << "ASCII character typed: " << static_cast<char>(textEntered.unicode) << std::endl;
         };*/

         // run the program as long as the window is open
    float circle_radius = 50.f;
    sf::CircleShape shape(circle_radius);
    shape.setPosition({ 0, 600.f - (circle_radius * 2) });
    activeEntity = &shape;
    while (window.isOpen())
    {
        window.handleEvents(onClose, onKeyPressed, onResize, onFocusLost, onFocusGained);

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...

        // set the shape color to green
        shape.setFillColor(sf::Color(100, 250, 50));

        window.draw(shape);

        // end the current frame
        window.display();
    }
}