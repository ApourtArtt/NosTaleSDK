#include "NewCharacterStandardInfoWidget.h"
#include "../../../../MemoryHelper/PatternScan.h"
#include "../../../../Utils/Logger.h"

namespace
{
    constexpr int DEFAULT_WIDTH = 593;
    constexpr int RIGHT_PANEL_OFFSET = 80;
    constexpr int CHARACTER_WIDGET_OFFSET = 50;
    constexpr int LABELS_OFFSET = 40;
    constexpr int RESISTANCE_OFFSET = 80;
    constexpr int RESISTANCE_LABEL_OFFEST = 40;
    constexpr int EQUIPMENT_WIDGETS_SIZE = 17;
}

// TODO: Remove some magic numbers

NewCharacterStandardInfoWidget& NewCharacterStandardInfoWidget::getInstance()
{
    static NewCharacterStandardInfoWidget instance;
    return instance;
}

void NewCharacterStandardInfoWidget::makeBeautiful()
{
    if (characterStandardInfoWidget == nullptr) return;

    // If widget has been already resized
    if (characterStandardInfoWidget->getWidth() > DEFAULT_WIDTH) return;

    makeMainWidgetBeautiful();
    makeCharacterWidgetBeautiful();
    makePartnerWidgetBeautiful();
    makePetWidgetBeautiful();
}

TGameRootWidget* NewCharacterStandardInfoWidget::getGameRootWidget()
{
    if (characterStandardInfoWidget == nullptr) return nullptr;
    return (TGameRootWidget*)characterStandardInfoWidget->getParent();
}

void NewCharacterStandardInfoWidget::makeMainWidgetBeautiful()
{
    Border border;
    ImagePadding imgPadding;

    // Change main widget size
    characterStandardInfoWidget->incrementSize(CHARACTER_WIDGET_OFFSET, 0);

    // Move close button and question mark button
    characterStandardInfoWidget->closeButton->moveWidget(CHARACTER_WIDGET_OFFSET, 0);
    characterStandardInfoWidget->questionMarkButton->moveWidget(CHARACTER_WIDGET_OFFSET, 0);

    // Move right panel
    characterStandardInfoWidget->rightPanel->moveWidget(RIGHT_PANEL_OFFSET, 0);

    // Extend the middle pannel
    characterStandardInfoWidget->centerPanel->incrementSize(RIGHT_PANEL_OFFSET, 0);
}

void NewCharacterStandardInfoWidget::makeCharacterWidgetBeautiful()
{
    Border border;
    ImagePadding imgPadding;

    // Move all equipment stuff
    for (int i = 0; i < EQUIPMENT_WIDGETS_SIZE * 2; i++) // We multiply fby 2 to change the ControlWidgetEX and the TNTIconWidget
    {
        TLBSWidget* widget = *(TLBSWidget**)((DWORD)&characterStandardInfoWidget->weaponControlWidgetEx + i * 4);
        widget->moveWidget(RIGHT_PANEL_OFFSET, 0);
    }

    // Move the SP Color effect widgets
    characterStandardInfoWidget->characterSpLightEffect->moveWidget(RIGHT_PANEL_OFFSET, 0);
    characterStandardInfoWidget->characterSpLightEffect_2->moveWidget(RIGHT_PANEL_OFFSET, 0);

    // Move labels
    TEWLabels* infoLabels = characterStandardInfoWidget->playerInfoLabels;
    for (int i = 5; i < infoLabels->getNLines() - 7; i++)
    {
        if (i != infoLabels->getNLines() - 11 && i != infoLabels->getNLines() - 10)
        {
            TextPosition* textposition = infoLabels->getTextPosition(i);
            if (textposition == nullptr) continue;
            textposition->move(LABELS_OFFSET, 0);
        }

        if (i == infoLabels->getNLines() - 9 || i == infoLabels->getNLines() - 8)
        {
            TextPosition* textposition = infoLabels->getTextPosition(i);
            if (textposition == nullptr) continue;
            textposition->move(LABELS_OFFSET, 0);
        }
    }

    // Move light resistance icon
    characterStandardInfoWidget->lghtResistanceIconWidget->moveWidget(RESISTANCE_OFFSET, 0);

    // Move shadow resistance icon
    characterStandardInfoWidget->shadowResistanceIconWidget->moveWidget(RESISTANCE_OFFSET, 0);
}

void NewCharacterStandardInfoWidget::makePartnerWidgetBeautiful()
{
    Border border;
    ImagePadding imgPadding;

    // Move skill icons from sp skills
    for (int i = 0; i < PARTNER_ARRAY_SIZE; i++)
    {
        characterStandardInfoWidget->aPartnerSpSkillIconWidget[i].firstSkillIconWidget->moveWidget(RIGHT_PANEL_OFFSET, 0);
        characterStandardInfoWidget->aPartnerSpSkillIconWidget[i].secondSkillIconWidget->moveWidget(RIGHT_PANEL_OFFSET, 0);
        characterStandardInfoWidget->aPartnerSpSkillIconWidget[i].thirdSkillIconWidget->moveWidget(RIGHT_PANEL_OFFSET, 0);
    }

    // Move partner SP Icon
    for (int i = 0; i < PARTNER_ARRAY_SIZE; i++)
    {
        TNTIconWidget* partnerSpIcon = characterStandardInfoWidget->aPartnerSpIconWidget[i];
        partnerSpIcon->moveWidget(RIGHT_PANEL_OFFSET, 0);
    }

    // Move partner normal skills icons
    for (int i = 0; i < PARTNER_ARRAY_SIZE; i++)
    {
        characterStandardInfoWidget->aPartnerSkills[i].firstSkill->moveWidget(RIGHT_PANEL_OFFSET, 0);
        characterStandardInfoWidget->aPartnerSkills[i].secondSkill->moveWidget(RIGHT_PANEL_OFFSET, 0);
        
    }

    // Move partner sp skill level icons
    for (int i = 0; i < PARTNER_ARRAY_SIZE; i++)
    {
        characterStandardInfoWidget->aPartnerSpSkillLevel[i].firstSkillLevel->moveWidget(RIGHT_PANEL_OFFSET, 0);
        characterStandardInfoWidget->aPartnerSpSkillLevel[i].secondSkillLevel->moveWidget(RIGHT_PANEL_OFFSET, 0);
        characterStandardInfoWidget->aPartnerSpSkillLevel[i].thirdSkillLevel->moveWidget(RIGHT_PANEL_OFFSET, 0);
    }

    // Move partner sp automatic skill buttons
    for (int i = 0; i < PARTNER_ARRAY_SIZE; i++)
    {
        characterStandardInfoWidget->aPartnerSkillsAutomaticButtons[i].firstButton->moveWidget(RIGHT_PANEL_OFFSET, 0);
        characterStandardInfoWidget->aPartnerSkillsAutomaticButtons[i].secondButton->moveWidget(RIGHT_PANEL_OFFSET, 0);
        characterStandardInfoWidget->aPartnerSkillsAutomaticButtons[i].thirdButton->moveWidget(RIGHT_PANEL_OFFSET, 0);
    }

    // Move partner weapon and amor icons
    for (int i = 0; i < PARTNER_ARRAY_SIZE; i++)
    {
        characterStandardInfoWidget->aPartnerEquipmentIcons[i].weaponIcon->moveWidget(RIGHT_PANEL_OFFSET, 0);
        characterStandardInfoWidget->aPartnerEquipmentIcons[i].armorIcon->moveWidget(RIGHT_PANEL_OFFSET, 0);
    }

    // Move partner gloves and shoes icons
    for (int i = 0; i < PARTNER_ARRAY_SIZE; i++)
    {
        characterStandardInfoWidget->aPartnerResistanceIcons[i].glovesIcon->moveWidget(RIGHT_PANEL_OFFSET, 0);
        characterStandardInfoWidget->aPartnerResistanceIcons[i].shoesIcon->moveWidget(RIGHT_PANEL_OFFSET, 0);
    }

    // Move partner Custom panels widgets (armor, weapon, shoes, gloves, sp, spSkills and normal skills)
    for (int i = 0; i < PET_ARRAY_SIZE; i++)
    {
        TEWCustomPanelWidget* panel = characterStandardInfoWidget->aPartnerCustomPanelWidgets[i];
        if (!panel) continue;
        panel->moveWidget(RIGHT_PANEL_OFFSET, 0);
    }

    // Move partner SP Glow border effect control widgets
    characterStandardInfoWidget->partnerSpControlWidgetEx->moveWidget(RIGHT_PANEL_OFFSET, 0);
    characterStandardInfoWidget->partnerSpBorderEffectControlWidgetEx->moveWidget(RIGHT_PANEL_OFFSET, 0);

    // Move the information labels
    TEWLabels* partnerInfoLabels = characterStandardInfoWidget->partnerInfoLabels;
    partnerInfoLabels->incrementSize(RIGHT_PANEL_OFFSET, 0);

    for (int i = 5; i < 23; i++)
    {
        if (i == 19 || i == 20 || i == 22)
        {
            TextPosition* textPosition = partnerInfoLabels->getTextPosition(i);
            if (textPosition == nullptr) continue;
            textPosition->move(RIGHT_PANEL_OFFSET, 0);
        }

        else if (i == 15 || i == 16)
        {
            TextPosition* textPosition = partnerInfoLabels->getTextPosition(i);
            if (textPosition == nullptr) continue;
            textPosition->move(LABELS_OFFSET * 2, 0);
        }

        else if (i != 21 && i != 14 && i != 13)
        {
            TextPosition* textPosition = partnerInfoLabels->getTextPosition(i);
            if (textPosition == nullptr) continue;
            textPosition->move(LABELS_OFFSET, 0);
        }
    }

    // Move light resistance icon
    characterStandardInfoWidget->partnerLightResistanceIconWidget->moveWidget(RESISTANCE_OFFSET, 0);

    // Move shadow resistance icon
    characterStandardInfoWidget->partnerShadowResistanceIconWidget->moveWidget(RESISTANCE_OFFSET, 0);
}

void NewCharacterStandardInfoWidget::makePetWidgetBeautiful()
{
    Border border;
    TEWLabels* petInfoLabels = characterStandardInfoWidget->petInfoLabels;

    // Move labels
    for (int i = 5; i < 19; i++)
    {
        if (i == 15 || i == 16)
        {
            TextPosition* textPosition = petInfoLabels->getTextPosition(i);
            if (textPosition == nullptr) continue;
            textPosition->move(LABELS_OFFSET * 2, 0);
        }

        else if (i != 14 && i != 13)
        {
            TextPosition* textPosition = petInfoLabels->getTextPosition(i);
            if (textPosition == nullptr) continue;
            textPosition->move(LABELS_OFFSET, 0);
        }
    }

    // Move light resistance icon
    characterStandardInfoWidget->petLightResistanceIconWidget->moveWidget(RESISTANCE_OFFSET, 0);

    // Move shadow resistance icon
    characterStandardInfoWidget->petShadowResistanceIconWidget->moveWidget(RESISTANCE_OFFSET, 0);
}

NewCharacterStandardInfoWidget::NewCharacterStandardInfoWidget()
{
    getAddresses();
    makeBeautiful();
}

void NewCharacterStandardInfoWidget::getAddresses()
{
    auto address = PatternScan(
        "\xa1\x00\x00\x00\x00\x8b\x00\x8b\x80\x00\x00\x00\x00\xe8\x00\x00\x00\x00\x33\xd2\x8b\xc6",
        "x????xxxx????x????xxxx", 1);

    if (address == nullptr)
    {
        characterStandardInfoWidget = nullptr;
        return;
    }

    characterStandardInfoWidget = ***(TNTNewCharacterStandardInfoWidget****)address;
}
