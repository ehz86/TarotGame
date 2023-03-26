
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class TarotCard
{
public:
    TarotCard(const std::string& name, const std::string& imageFileName, int m_posx, int m_posy);

    const std::string& getName() const;
    const sf::Texture& getTexture() const;
    const sf::Sprite& getSprite() const;
    int m_posx = 50;
    int m_posy = 100;
    
private:
    std::string m_name;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
   
};

TarotCard::TarotCard(const std::string& name, const std::string& imageFileName,int m_posx,int m_posy)
    : m_name(name)
{
    m_texture.loadFromFile(imageFileName);
    m_sprite.setTexture(m_texture);
    m_sprite.setScale(0.4f,0.4f);
    m_sprite.setPosition(m_posx, m_posy);
}

const std::string& TarotCard::getName() const
{   
    return m_name;
}

const sf::Texture& TarotCard::getTexture() const
{   
    return m_texture;
}

const sf::Sprite& TarotCard::getSprite() const
{
    return m_sprite;
}

class TarotDeck
{
public:
    TarotDeck();
    void shuffle();
    TarotCard* drawCard();

private:
    std::vector<TarotCard*> m_cards;
};

TarotDeck::TarotDeck()
{
    m_cards.push_back(new TarotCard("The Fool", "fool.jpg",10,0));
    m_cards.push_back(new TarotCard("The Magician", "magican.jpg",140,0));
    m_cards.push_back(new TarotCard("The High Priestess", "high-priestess.jpg",270,0));
    m_cards.push_back(new TarotCard("The Empress", "empress.jpg",400,0));
    m_cards.push_back(new TarotCard("The Emperor", "emperor.jpg", 530, 0));
    m_cards.push_back(new TarotCard("The Hierophant", "hierophant.jpg", 660, 0));
    m_cards.push_back(new TarotCard("The Lovers", "lovers.jpg", 790, 0));
    /*m_cards.push_back(new TarotCard("The Chariot", "chariot.jpg"));
    m_cards.push_back(new TarotCard("Strength", "strength.jpg"));
    m_cards.push_back(new TarotCard("The Hermit", "hermit.jpg"));
    m_cards.push_back(new TarotCard("Wheel of Fortune", "wheel-of-fortune.jpg"));
    m_cards.push_back(new TarotCard("Justice", "justice.jpg"));
    m_cards.push_back(new TarotCard("The Hanged Man", "hanged-man.jpg"));
    m_cards.push_back(new TarotCard("Death", "death.jpg"));
    m_cards.push_back(new TarotCard("Temperance", "temperance.jpg"));
    m_cards.push_back(new TarotCard("The Devil", "devil.jpg"));
    m_cards.push_back(new TarotCard("The Tower", "tower.jpg"));
    m_cards.push_back(new TarotCard("The Star", "star.jpg"));
    m_cards.push_back(new TarotCard("The Moon", "moon.jpg"));
    m_cards.push_back(new TarotCard("The Sun", "sun.jpg"));
    m_cards.push_back(new TarotCard("Judgement", "judgement.jpg"));
    m_cards.push_back(new TarotCard("The World", "world.jpg"));
    */
    shuffle();
}

void TarotDeck::shuffle()
{
    srand(time(nullptr));
    for (int i = 0; i < m_cards.size(); i++)
    {
        int j = rand() % m_cards.size();
        std::swap(m_cards[i], m_cards[j]);
    }
}

TarotCard* TarotDeck::drawCard()
{
    if (m_cards.size() == 0)
    {
        return nullptr;
    }
    TarotCard* card = m_cards.back();
    m_cards.pop_back();

    return card;
}

class TarotGame
{
public:
    TarotGame();
    void run();

private:
    void processEvents();
    void handleEvents(const sf::Event& event);
    void update();
    void render();
    void renderButton();
    void renderPrediction();
    TarotCard* getPrediction();
    sf::RenderWindow m_window;
    sf::Font m_font;
    sf::Text m_buttonText;
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RectangleShape m_buttonShape;
    TarotDeck m_deck;
    TarotCard* m_prediction;
};
TarotGame::TarotGame()
    //: m_window(sf::VideoMode(desktop.width, desktop.height), "Tarot Game", sf::Style::Fullscreen)
    : m_window(sf::VideoMode(1200, 900), "Tarot Game")
    , m_font()
    , m_buttonText()
    , m_buttonShape(sf::Vector2f(120.f, 50.f))
    , m_deck()
    , m_prediction(nullptr)
{
    m_font.loadFromFile("Arial.ttf");
    if (!m_font.loadFromFile("Arial.ttf"))
    {
        
    }
   
    m_buttonText.setFont(m_font);
    m_buttonText.setString("Generate");
    m_buttonText.setCharacterSize(24);
    m_buttonText.setFillColor(sf::Color::Red);
    m_buttonText.setPosition(360, 510);


    m_buttonShape.setFillColor(sf::Color(100, 100, 100));
    m_buttonShape.setOutlineColor(sf::Color::White);
    m_buttonShape.setOutlineThickness(2.f);
    m_buttonShape.setPosition(350, 500);
}

void TarotGame::run()
{
    while (m_window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void TarotGame::processEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        handleEvents(event);
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }
        
    }
}
int count = 0;
void TarotGame::handleEvents(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {

        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2f mousePos(sf::Mouse::getPosition(m_window));
            if (m_buttonShape.getGlobalBounds().contains(mousePos))
            {
       
                m_prediction = getPrediction();
            }
        }
    }
   
}

void TarotGame::update()
{
}

void TarotGame::render()
{
    //m_window.clear(sf::Color(50, 50, 50));

    if (m_prediction)
    { 
            renderPrediction();
  
       
    }
    else
    {
        renderButton();
    }

    m_window.display();
}

void TarotGame::renderButton()
{
    m_window.draw(m_buttonShape);
    sf::Text buttonText;
    m_buttonText.setFont(m_font);
    m_buttonText.setString("Generate");
    m_buttonText.setCharacterSize(24);
    m_buttonText.setFillColor(sf::Color::Red);
    m_window.draw(m_buttonText);
}

void TarotGame::renderPrediction()
{

    for (int i = 0; i < 7; i++) {

        m_window.draw(m_prediction->getSprite());
    }
    sf::Text predictionText;
    predictionText.setFont(m_font);
    predictionText.setString(m_prediction->getName());
    predictionText.setCharacterSize(24);
    predictionText.setFillColor(sf::Color::White);
    predictionText.setPosition(400.f, 300.f);
    predictionText.setOrigin(predictionText.getLocalBounds().width / 2.f, predictionText.getLocalBounds().height / 2.f);
    m_window.draw(predictionText);
}

TarotCard* TarotGame::getPrediction()
{   
    return m_deck.drawCard();

}

int main()
{
    TarotGame game;
    game.run();
    return 0;
}


