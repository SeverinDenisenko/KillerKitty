//
// Created by Severin on 06.03.2023.
//

#ifndef KILLERKITTY_TILEMAP_H
#define KILLERKITTY_TILEMAP_H

#include <Entity.h>

namespace kke {

    class TileMap : public Entity {
    public:
        TileMap(sf::Texture& texture, std::string filename);

        void Resize(int width, int height);
        void Set(unsigned int layer, unsigned int x, unsigned int y, int index);

    protected:

        void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const override;

    private:
        std::vector<sf::VertexArray> vertices;
        sf::Texture& texture;
        int tileWidth;
        int tileHeight;
        int width;
        int height;
    };

} // kke

#endif //KILLERKITTY_TILEMAP_H
