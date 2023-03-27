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
    int m_posx;
    int m_posy;

private:
    std::string m_name;
    sf::Texture m_texture;
    sf::Sprite m_sprite;

};

TarotCard::TarotCard(const std::string& name, const std::string& imageFileName, int m_posx, int m_posy)
    : m_name(name)
{
    m_texture.loadFromFile(imageFileName);
    m_sprite.setTexture(m_texture);
    m_sprite.setScale(0.4f, 0.4f);
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
    m_cards.push_back(new TarotCard("The Fool", "fool.jpg", 10, 10));
    m_cards.push_back(new TarotCard("The Magician", "magican.jpg", 160, 10));
    m_cards.push_back(new TarotCard("The High Priestess", "high-priestess.jpg", 310, 10));
    m_cards.push_back(new TarotCard("The Empress", "empress.jpg", 460, 10));
    m_cards.push_back(new TarotCard("The Emperor", "emperor.jpg", 610, 10));
    m_cards.push_back(new TarotCard("The Hierophant", "hierophant.jpg", 760, 10));
    m_cards.push_back(new TarotCard("The Lovers", "lovers.jpg", 910, 10));
    m_cards.push_back(new TarotCard("The Chariot", "chariot.jpg", 10, 260));
    m_cards.push_back(new TarotCard("Strength", "strength.jpg", 160, 260));
    m_cards.push_back(new TarotCard("The Hermit", "hermit.jpg", 310, 260));
    m_cards.push_back(new TarotCard("Wheel of Fortune", "wheel-of-fortune.jpg", 460, 260));
    m_cards.push_back(new TarotCard("Justice", "justice.jpg", 610, 260));
    m_cards.push_back(new TarotCard("The Hanged Man", "hanged-man.jpg", 760, 260));
    m_cards.push_back(new TarotCard("Death", "death.jpg", 910, 260));
    m_cards.push_back(new TarotCard("Temperance", "temperance.jpg", 10, 510));
    m_cards.push_back(new TarotCard("The Devil", "devil.jpg", 160, 510));
    m_cards.push_back(new TarotCard("The Tower", "tower.jpg", 310, 510));
    m_cards.push_back(new TarotCard("The Star", "star.jpg", 460, 510));
    m_cards.push_back(new TarotCard("The Moon", "moon.jpg", 610, 510));
    m_cards.push_back(new TarotCard("The Sun", "sun.jpg", 760, 510));
    m_cards.push_back(new TarotCard("Judgement", "judgement.jpg", 910, 510));
    m_cards.push_back(new TarotCard("The World", "world.jpg", 910, 760));
   
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
    auto iterator = m_cards.begin();
    std::advance(iterator, 7);
    m_cards.erase(iterator, m_cards.end());
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
    void renderExplanation(std::string text);
    TarotCard* getPrediction();
    sf::RenderWindow m_window;
    sf::Font m_font;
    sf::Text m_buttonText;
    sf::Text m_button1Text;
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RectangleShape m_buttonShape;
    sf::RectangleShape m_button1Shape;
    sf::RectangleShape m_button2Shape;
    sf::RectangleShape m_button3Shape;
    sf::RectangleShape m_button4Shape;
    sf::RectangleShape m_button5Shape;
    sf::RectangleShape m_button6Shape;
    sf::RectangleShape m_button7Shape;
    sf::RectangleShape m_button8Shape;
    sf::RectangleShape m_button9Shape;
    sf::RectangleShape m_button10Shape;
    sf::RectangleShape m_button11Shape;
    sf::RectangleShape m_button12Shape;
    sf::RectangleShape m_button13Shape;
    sf::RectangleShape m_button14Shape;
    sf::RectangleShape m_button15Shape;
    sf::RectangleShape m_button16Shape;
    sf::RectangleShape m_button17Shape;
    sf::RectangleShape m_button18Shape;
    sf::RectangleShape m_button19Shape;
    sf::RectangleShape m_button20Shape;
    sf::RectangleShape m_button21Shape;
    sf::RectangleShape m_button22Shape;
    TarotDeck m_deck;
    TarotCard* m_prediction;
    TarotCard* m_explanation;

};
TarotGame::TarotGame()
//: m_window(sf::VideoMode(desktop.width, desktop.height), "Tarot Game", sf::Style::Fullscreen)
    : m_window(sf::VideoMode(1060, 1000), "Tarot Game")
    , m_font()
    , m_buttonText()
    , m_buttonShape(sf::Vector2f(120.f, 100.f))
    , m_button1Text()
    , m_button1Shape(sf::Vector2f(140, 240))
    , m_button2Shape(sf::Vector2f(140, 240))
    , m_button3Shape(sf::Vector2f(140, 240))
    , m_button4Shape(sf::Vector2f(140, 240))
    , m_button5Shape(sf::Vector2f(140, 240))
    , m_button6Shape(sf::Vector2f(140, 240))
    , m_button7Shape(sf::Vector2f(140, 240))
    , m_button8Shape(sf::Vector2f(140, 240))
    , m_button9Shape(sf::Vector2f(140, 240))
    , m_button10Shape(sf::Vector2f(140, 240))
    , m_button11Shape(sf::Vector2f(140, 240))
    , m_button12Shape(sf::Vector2f(140, 240))
    , m_button13Shape(sf::Vector2f(140, 240))
    , m_button14Shape(sf::Vector2f(140, 240))
    , m_button15Shape(sf::Vector2f(140, 240))
    , m_button16Shape(sf::Vector2f(140, 240))
    , m_button17Shape(sf::Vector2f(140, 240))
    , m_button18Shape(sf::Vector2f(140, 240))
    , m_button19Shape(sf::Vector2f(140, 240))
    , m_button20Shape(sf::Vector2f(140, 240))
    , m_button21Shape(sf::Vector2f(140, 240))
    , m_button22Shape(sf::Vector2f(140, 240))
    , m_deck()
    , m_prediction(nullptr)
    , m_explanation(nullptr)
{
    m_font.loadFromFile("Arial.ttf"); 
    if (!m_font.loadFromFile("Arial.ttf"))
    {

    }
    sf::Texture texture;
    if (!texture.loadFromFile("fon.png"))
    {

    }
    sf::Sprite background(texture);
    m_window.draw(background);
    m_buttonText.setFont(m_font);
    m_buttonText.setString("Generate");
    m_buttonText.setCharacterSize(24);
    m_buttonText.setFillColor(sf::Color::Red);
    m_buttonText.setPosition(40, 850);

    m_button1Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button1Shape.setPosition(10, 10);

    m_button2Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button2Shape.setPosition(160, 10);

    m_button3Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button3Shape.setPosition(310, 10);

    m_button4Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button4Shape.setPosition(460, 10);

    m_button5Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button5Shape.setPosition(610, 10);

    m_button6Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button6Shape.setPosition(760, 10);

    m_button7Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button7Shape.setPosition(910, 10);

    m_button8Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button8Shape.setPosition(10, 260);

    m_button9Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button9Shape.setPosition(160, 260);

    m_button10Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button10Shape.setPosition(310, 260);

    m_button11Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button11Shape.setPosition(460, 260);

    m_button12Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button12Shape.setPosition(610, 260);

    m_button13Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button13Shape.setPosition(760, 260);

    m_button14Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button14Shape.setPosition(910, 260);

    m_button15Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button15Shape.setPosition(10, 510);

    m_button16Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button16Shape.setPosition(160, 510);

    m_button17Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button17Shape.setPosition(310, 510);

    m_button18Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button18Shape.setPosition(460, 510);

    m_button19Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button19Shape.setPosition(610, 510);

    m_button20Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button20Shape.setPosition(760, 510);

    m_button21Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button21Shape.setPosition(910, 510);

    m_button22Shape.setFillColor(sf::Color(100, 100, 100, 0));
    m_button22Shape.setPosition(910, 760);

    m_buttonShape.setFillColor(sf::Color(100, 100, 100));
    m_buttonShape.setOutlineColor(sf::Color::White);
    m_buttonShape.setOutlineThickness(2.f);
    m_buttonShape.setPosition(40, 850);
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

            else if (m_button1Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("Gaining freedom, liberation from destructive relationships, an\nimportantturn in love, a call to take a decisive step and move to\na new stage of relationships - or abandon them altogether");
            }

            else if (m_button2Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("Blind love, passionate relationships, strong infatuation, the\ndesire to turn a blind eye to the shortcomings of the beloved and\nthe exaggeration of his merits");
            }

            else if (m_button3Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("Secrecy in love, unwillingness to talk about feelings\nsincerely, self-absorption, secret romance");
            }

            else if (m_button4Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("Relationships develop quickly and bring satisfaction,\nthere is a great passion in them");
            }

            else if (m_button5Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("It symbolizes a reliable connection that stems not so much\nfrom romantic feelings as from mutual respect and sober calculation.");
            }

            else if (m_button6Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("Improving relationships with a partner, their increasing\nvalue for everyone");
            }

            else if (m_button7Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("It symbolizes trust, a strong feeling, positive emotions,\nhas the meaning of established, strong, harmonious relationships");
            }

            else if (m_button8Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("New love, rapid development of relationships, changing\nthe direction of relationships");
            }

            else if (m_button9Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("Overcoming obstacles, a strong alliance, reciprocity.");
            }

            else if (m_button10Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("Resentment and tears, troubles in love, a long period of\nloneliness. Feelings are rejected by others, hence loneliness and\nmisunderstanding, self-absorption as a defensive reaction");
            }

            else if (m_button11Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("Speedy happy changes in your personal life, unexpected\nluck and luck in love");
            }

            else if (m_button12Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("A very positive symbol that hints at the honesty and\ndecency of the relationship. Indicates the need to respect the partner's\nopinion, to make concessions for the sake of maintaining\na strong, stable relationship");
            }

            else if (m_button13Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("The card indicates a lot of temptations, depression\nand worries, unreasonable sacrifice. You cannot manage the situation so\nthat it is resolved in your favor.");
            }

            else if (m_button14Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("Everything is bad (((The collapse of hopes and the\nbreakup of relationships, the collapse of love hopes, irreversible changes\nin love. For relationships, this is one of the worst tarot\ncards that can only fall out in divination");
            }

            else if (m_button15Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("Balance, gaining self-confidence, condescension to\nthe weaknesses of the partner. Even if the relationship now leaves much\nto be desired, the map indicates that gradually everything\nwill change and will come to the right track.");
            }

            else if (m_button16Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("Treachery and vindictiveness, abuse of other people's\nfeelings. For a fortune-teller, the card indicates a connection or\nacquaintance with a dangerous person whose actions cannot\nbe predicted.");
            }

            else if (m_button17Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("In no scenario does the appearance of the Tower promise\njoy and peace. In a love relationship, the meaning of the Tower tarot\ncard indicates the inevitability of loss and disappointment,\nwhich neither your status nor material well-being can prevent.");
            }

            else if (m_button18Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("The Star card indicates dreaminess, looseness, the\ndiscovery of a person's own attractiveness, sexuality, a wonderful\nrelationship with a partner.");
            }

            else if (m_button19Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("Lack of sincerity in a relationship. There is a high\nprobability that your feelings are being cleverly manipulated.");
            }

            else if (m_button20Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("The first thing that the Higher Powers are in a hurry\nto tell about: a fortune—teller is a person who deserves personal\nhappiness.  Mb will have a baby.");
            }

            else if (m_button21Shape.getGlobalBounds().contains(mousePos))
            {

                renderExplanation("In the personal relations of the fortune-teller, some\nimportant, fateful changes are coming; whatever happens, everything\nwill be for the better!");
            }

            else if (m_button22Shape.getGlobalBounds().contains(mousePos))
            {
                renderExplanation("Indicates a person's willingness to settle down, start\na family. It is important that it will be built on the basis of\nproven, deep feelings, respect, trust and tenderness.");
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
    m_buttonText.setString("Your\nDestiny");
    m_buttonText.setCharacterSize(24);
    m_buttonText.setFillColor(sf::Color::Red);
    m_window.draw(m_buttonText);
    m_window.draw(m_button1Shape);
    m_window.draw(m_button2Shape);
    m_window.draw(m_button3Shape);
    m_window.draw(m_button4Shape);
    m_window.draw(m_button5Shape);
    m_window.draw(m_button6Shape);
    m_window.draw(m_button6Shape);
    m_window.draw(m_button7Shape);
    m_window.draw(m_button8Shape);
    m_window.draw(m_button9Shape);
    m_window.draw(m_button10Shape);
    m_window.draw(m_button11Shape);
    m_window.draw(m_button12Shape);
    m_window.draw(m_button13Shape);
    m_window.draw(m_button14Shape);
    m_window.draw(m_button15Shape);
    m_window.draw(m_button16Shape);
    m_window.draw(m_button17Shape);
    m_window.draw(m_button18Shape);
    m_window.draw(m_button19Shape);
    m_window.draw(m_button20Shape);
    m_window.draw(m_button21Shape);
    m_window.draw(m_button22Shape);
}

void TarotGame::renderPrediction()
{
    m_window.draw(m_prediction->getSprite());
}

void TarotGame::renderExplanation(std::string text)
{                                       
    sf::Text predictionText;
    predictionText.setFont(m_font);
    predictionText.setString(text);
    predictionText.setCharacterSize(24);
    predictionText.setFillColor(sf::Color::White);
    predictionText.setPosition(185, 850);
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
