#include "SkillsCooldown.h"
#include "../../../MemoryHelper/PatternScan.h"
#include "../../../MemoryHelper/Patch.h"
#include <iostream>

constexpr int HOOK_SIZE = 6;
DWORD TNTQuickSlotWidgetAddress;
DWORD TNTNewCharacterSkillInfoWidgetAddress;
TEWLabel* label;
TNTTimeAniIcon* icon;
int8_t state;

void __declspec(naked) hideSkillLabelsHook()
{
	__asm
	{
		mov state, al;
		mov icon, ebx;
	}

	if (state == 0 && icon->isOnCooldown)
	{
		if ((DWORD)icon->getParent() == TNTQuickSlotWidgetAddress)
			label = QuickSlotWidget::getInstance().getCooldownLabel(icon);

		else if ((DWORD)icon->getParent() == TNTNewCharacterSkillInfoWidgetAddress)
			label = NewCharacterSkillInfoWidget::getInstance().getCooldownLabel(icon);

		label->setVisible(false);
	}

	__asm
	{
		ret;
	}
}

void skillCooldownHook()
{
	// Since this is not a naked function we can declare local variables
	TNTTimeAniIcon* m_icon;
	TEWLabel* m_label;
	int m_currentCooldown;
	int m_minutes;
	int m_seconds;
	wchar_t* m_text;

	__asm
	{
		mov m_icon, ebx;
	}

	m_currentCooldown = (m_icon->coolDownTime - m_icon->currentCoolDownTime);

	if (m_currentCooldown > 0)
	{
		if ((DWORD)m_icon->getParent() == (DWORD)TNTQuickSlotWidgetAddress)
			m_label = QuickSlotWidget::getInstance().getCooldownLabel(m_icon);

		else if ((DWORD)m_icon->getParent() == TNTNewCharacterSkillInfoWidgetAddress)
			m_label = NewCharacterSkillInfoWidget::getInstance().getCooldownLabel(m_icon);

		else
			return;

		m_currentCooldown = m_currentCooldown / 1000;
		m_minutes = (m_currentCooldown / 60);
		m_seconds = (m_currentCooldown % 60);
		m_text = m_label->getText();
		swprintf_s(m_text, 10, L"%02d:%02d", m_minutes, m_seconds);

		if (!m_label->isVisible())
			m_label->setVisible(true);
	}
}

SkillsCooldown::SkillsCooldown()
{
	getAddresses();
	hookFunctions();
}

SkillsCooldown::~SkillsCooldown()
{
	for (int i = 0; i < HOOK_NUMBER; i++)
		delete trmpHook[i];
}

void SkillsCooldown::getAddresses()
{	
	hookAddress[0] = (DWORD)PatternScan(
		"\x01\x83\x00\x00\x00\x00\x8b\x8b",
		"xx????xx",
		0
	);

	hookAddress[1] = (DWORD)PatternScan(
		"\x88\x83\x00\x00\x00\x00\x84\xc0\x74\x00\xe8\x00\x00\x00\x00\x89\x83\x00\x00\x00\x00\x5b",
		"xx????xxx?x????xx????x",
		0
	);

	TNTQuickSlotWidgetAddress = QuickSlotWidget::getInstance().getTNTQuickSlotWidgetAddress();
	TNTNewCharacterSkillInfoWidgetAddress = NewCharacterSkillInfoWidget::getInstance().getTNTNewCharacterSkillInfoWidgetAddress();
}

void SkillsCooldown::hookFunctions()
{
	trmpHook[0] = new TrampolineHook((LPVOID)hookAddress[0], skillCooldownHook, HOOK_SIZE);
	trmpHook[1] = new TrampolineHook((LPVOID)hookAddress[1], hideSkillLabelsHook, HOOK_SIZE);
}
