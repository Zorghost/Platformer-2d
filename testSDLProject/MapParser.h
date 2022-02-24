#pragma once
#include <map>
#include <string>
#include "GameMap.h"
#include "TileLayer.h"
#include "tinyxml/tinyxml.h"

class MapParser
{
public :
	bool Load();
	void Clean();
	inline GameMap* GetMap(std::string id ) {	return m_MapDict[id]; }
	inline static MapParser* GetInstance() { return s_Instance = (GetInstance != nullptr) ? s_Instance : new MapParser(); }
	static MapParser* s_Instance;
private : 
	bool Parse(std::string id , std::string source );
	Tileset ParseTileset(TiXmlElement* xmlTileset);
	TileLayer* ParseTileLayer(TiXmlElement* xmlLayer, TilesetList tilesets, int tilesize, int rowcount, int colcount);
private :
	MapParser();
	
	std::map<std::string, GameMap*> m_MapDict;
};