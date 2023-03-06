//
// Created by Severin on 06.03.2023.
//

#include "TileMap.h"

namespace kke {
    void TileMap::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = &texture;
        target.draw(vertices, states);
    }

    TileMap::TileMap(sf::Texture& texture, int tileWidth, int tileHeight, const int* tiles, int width, int height) : texture(texture), tileWidth(tileWidth), tileHeight(tileHeight), width(width), height(height) {
        vertices.setPrimitiveType(sf::Quads);
        vertices.resize(width * height * 4);

        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // get the current tile number
                int tileNumber = tiles[i + j * width];
                Set(i, j, tileNumber);
            }

    }

    void TileMap::Resize(int w, int h) {
        width = w;
        height = h;
        vertices.resize(width * height * 4);
    }

    void TileMap::Set(unsigned int x, unsigned int y, unsigned int index) {
        // find its position in the tileset texture
        int tu = index % (texture.getSize().x / tileWidth);
        int tv = index / (texture.getSize().x / tileWidth);

        // get a pointer to the current tile's quad
        sf::Vertex* quad = &vertices[(x + y * width) * 4];

        // define its 4 corners
        quad[0].position = sf::Vector2f(x * tileWidth, y * tileHeight);
        quad[1].position = sf::Vector2f((x + 1) * tileWidth, y * tileHeight);
        quad[2].position = sf::Vector2f((x + 1) * tileWidth, (y + 1) * tileHeight);
        quad[3].position = sf::Vector2f(x * tileWidth, (y + 1) * tileHeight);

        // define its 4 texture coordinates
        quad[0].texCoords = sf::Vector2f(tu * tileWidth, tv * tileHeight);
        quad[1].texCoords = sf::Vector2f((tu + 1) * tileWidth, tv * tileHeight);
        quad[2].texCoords = sf::Vector2f((tu + 1) * tileWidth, (tv + 1) * tileHeight);
        quad[3].texCoords = sf::Vector2f(tu * tileWidth, (tv + 1) * tileHeight);
    }

} // kke