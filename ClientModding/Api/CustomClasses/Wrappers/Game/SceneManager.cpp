#include "SceneManager.h"
#include "../../../../MemoryHelper/PatternScan.h"
#include "../../../DelphiClasses/TLBSCamera.h"
#include "../../../DelphiClasses/TLBSRotDamper.h"

SceneManager::SceneManager()
{
	sceneManager = ***(TSceneManager****)PatternScan(
		"\xA1\x00\x00\x00\x00\x00\x00\x00\x00\x58\x00\x0F\x84\xBF",
		"x????????xxxxx",
		1);

	while (!sceneManager || !sceneManager->mapGrid)
		Sleep(500);

	for (int i = 0; i < sceneManager->mapGrid->getWidth(); i++)
	{
		for (int j = 0; j < sceneManager->mapGrid->getHeight(); j++)
		{
			sceneManager->mapGrid->setCellType(i, j, CellType::NOT_WALKABLE);
		}
	}
}

SceneManager& SceneManager::getInstance()
{
	static SceneManager instance;
	return instance;
}

short SceneManager::getMapHeight()
{
	if (!sceneManager || !sceneManager->mapGrid) return -1;
	return sceneManager->mapGrid->getHeight();
}

short SceneManager::getMapWidth()
{
	if (!sceneManager || !sceneManager->mapGrid) return -1;
	return sceneManager->mapGrid->getWidth();
}

CellType SceneManager::getCellTypeAt(short x, short y)
{
	if (!sceneManager || !sceneManager->mapGrid) return CellType{};
	return sceneManager->mapGrid->getCellType(x, y);
}

void SceneManager::setCellTypeAt(short x, short y, CellType cellType)
{
	if (!sceneManager || !sceneManager->mapGrid) return;
	sceneManager->mapGrid->setCellType(x, y, cellType);
}

void SceneManager::setMaxZoom(float z)
{
	if (sceneManager == nullptr) return;
	if (sceneManager->TLBSCameraPtr == nullptr) return;
	if (sceneManager->TLBSCameraPtr->ZoomRotDamper == nullptr) return;

	sceneManager->TLBSCameraPtr->ZoomRotDamper->max = z;
}

void SceneManager::setMinZoom(float z)
{
	if (sceneManager == nullptr) return;
	if (sceneManager->TLBSCameraPtr == nullptr) return;
	if (sceneManager->TLBSCameraPtr->ZoomRotDamper == nullptr) return;

	sceneManager->TLBSCameraPtr->ZoomRotDamper->min = z;
}

void SceneManager::setDefaultZoom(float z)
{
	if (sceneManager == nullptr) return;
	if (sceneManager->TLBSCameraPtr == nullptr) return;
	if (sceneManager->TLBSCameraPtr->ZoomRotDamper == nullptr) return;

	sceneManager->TLBSCameraPtr->ZoomRotDamper->def = z;
}