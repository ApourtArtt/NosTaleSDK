#pragma once
#include "../../../DelphiClasses/TSceneManager.h"

/**
 * @brief Singleton wrapper around the game TSceneManager structure.
 */
class SceneManager
{
public:
	SceneManager(SceneManager& other) = delete;
	void operator=(const SceneManager& other) = delete;
	static SceneManager& getInstance();

	short getMapHeight();
	short getMapWidth();
	CellType getCellTypeAt(short x, short y);
	void setCellTypeAt(short x, short y, CellType cellType);

	void setMaxZoom(float z);
	void setMinZoom(float z);
	void setDefaultZoom(float z);

private:
	SceneManager();
	TSceneManager* sceneManager;
};